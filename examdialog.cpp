#include "examdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QPalette>
#include <QPushButton>

ExamDialog::ExamDialog(QWidget* parent):QDialog(parent)
{
    //设置字体大小
    QFont font;
    font.setPointSize(12);
    this->setFont(font);

    //设置窗体背景颜色
    setPalette(QPalette(QColor(209,215,255)));

    setWindowTitle("考试已用时: 0分0秒");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    this->resize(800,800);
    initTimer();
    initLayout();
    if(! initTextEdig())
    {
        QMessageBox::information(this,"提示","读取题库失败");
        QTimer::singleShot(0, qApp,SLOT(quit()));//间隔0s，当前的应用程序执行退出操作
    }
    initButtons();
}

ExamDialog::~ExamDialog()
{

}

void ExamDialog::initTimer()
{
    m_time_cost = 0;
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    m_timer->start();

    QObject::connect(m_timer, &QTimer::timeout, this, &ExamDialog::freshTime);
}

void ExamDialog::initLayout()
{
    m_layout = new QGridLayout(this);
    m_layout->setSpacing(10);                   //设置控件间的间距
    m_layout->setSpacing(10);                   //设置窗体与控件间的间隙
}

bool ExamDialog::initTextEdig()
{
    QString strLine;                    //保存文件中读取到的一行数据
    QStringList strList;                //保存读取到的答案行
    QString fileName = "./account/exam.txt";//读取文件要根据左侧的项目-构建和运行-运行里的工作目录来判断当前所处的路径
    QFile file(fileName);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    auto res = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(res)
    {
        m_text_edit = new QTextEdit(this);
        m_text_edit->setReadOnly(true);
        QString strText;                    //用于保存显示到文本编辑器的数据
        QStringList strList;
        int lines = 0;
        while(!stream.atEnd())
        {
            strLine = stream.readLine();
            if(lines == 0)
            {
                lines ++;
                continue;
            }
            if(strLine.contains("答案"))
            {
                strText += "\n";
                strList = strLine.split(" ");
                m_answer.append(strList[1]);
                lines++;
                continue;
            }
            strText += strLine;
            strText += "\n";
            ++lines;
        }
        m_text_edit->setText(strText);
        //从第0行、第0列开始添加该控件，占据1行10列
        m_layout->addWidget(m_text_edit,0,0,1,10);
        file.close();
        //qDebug() << "m_answer = " << m_answer;
        return true;
    }
    else
    {
        return false;
    }
}

void ExamDialog::initButtons()
{
    QStringList strList = {"A","B","C","D"};
    for (int i = 0; i < 10; ++i)
    {
        //初始化题目标签
        m_title_labels[i] = new QLabel(this);
        m_title_labels[i]->setText("第" + QString::number(i + 1) + "题");
        //从第1行、第i列开始添加该控件，占据1行1列（默认，可以不填参数）
        m_layout->addWidget(m_title_labels[i],1,i);

        if(i < 8)
            m_btnGroups[i] = new QButtonGroup(this);

        //初始化判断题
        if(i == 9)
        {
            m_radioA = new QRadioButton(this);
            m_radioB = new QRadioButton(this);
            m_radioA->setText("正确");
            m_radioB->setText("错误");

            m_layout->addWidget(m_radioA,2,i);
            m_layout->addWidget(m_radioB,3,i);

            m_btnGroups[8] = new QButtonGroup(this);
            m_btnGroups[8]->addButton(m_radioA);
            m_btnGroups[8]->addButton(m_radioB);
            //return;   //return会直接结束函数，不进行pushbutton的构造
            break;
        }

        //初始化选择题
        for(int j = 0; j < 4; j ++)
        {
            //多选题
            if(i == 8)
            {
                m_checkBtns[j] = new QCheckBox(this);
                m_checkBtns[j]->setText(strList[j]);
                m_layout->addWidget(m_checkBtns[j],2+j,8);
                m_layout->addWidget(m_checkBtns[j],2+j,8);
            }
            else//单选题
            {
                m_radioBtns[4 * i + j] = new QRadioButton(this);
                m_radioBtns[4 * i + j]->setText(strList.at(j));
                m_layout->addWidget(m_radioBtns[4 * i + j],2+j,i);

                m_btnGroups[i]->addButton(m_radioBtns[4 * i + j]);
            }
        }
    }

    QPushButton* submitBtn = new QPushButton(this);
    submitBtn->setText("提交");
    submitBtn->setFixedSize(100,35);
    //不添加this，会有警告Pass a context object as 3rd connect parameter
    //这是因为lambda表达式涉及到了上下文，需要在connect的第三个参数位置传入上下文对象，
    //一旦第三参数对象被销毁了，则该lambda表达式将不会执行，以达到避免崩溃的目的
    QObject::connect(submitBtn,&QPushButton::clicked,this,[this](){
        if(hasNoSelect())
        {
            QMessageBox::information(this,"提示","有未完成的题目，请完成考试");
            return;
        }

        int scores = 0;
        for(int i = 0; i < 10; ++i)
        {
            //计算单选题
            if(i < 8)
            {
                if(m_btnGroups[i]->checkedButton()->text() == m_answer.at(i))
                {
                    qDebug() << i;
                    scores += 10;
                }
            }
            //计算多选题
            if(i == 8)
            {
                auto answer = m_answer.at(i);

                bool hasA = answer.contains("A");
                bool hasB = answer.contains("B");
                bool hasC = answer.contains("C");
                bool hasD = answer.contains("D");

                bool checkA = m_checkBtns[0]->isChecked();
                bool checkB = m_checkBtns[1]->isChecked();
                bool checkC = m_checkBtns[2]->isChecked();
                bool checkD = m_checkBtns[3]->isChecked();

                if(hasA != checkA) continue;
                if(hasB != checkB) continue;
                if(hasC != checkC) continue;
                if(hasD != checkD) continue;

                scores += 10;
            }

            //计算判断题
            if(i == 9)
            {
                auto answer = m_answer.at(9);
                if(m_btnGroups[8]->checkedButton()->text() == answer)
                {
                    scores += 10;
                }
            }
        }
        if(scores < 100)
        {
            auto res = QMessageBox::information(this,"提示","您的分数是: " + QString::number(scores) + "分,是否重新考试？"
                                     ,QMessageBox::Ok | QMessageBox::No);
            qDebug() << res;
            if(res == QMessageBox::Ok)
                return;
            else
                close();
        }
        else
        {
            QMessageBox::information(this,"提示","您的分数是: " + QString::number(scores));
            close();
        }

    });

    m_layout->addWidget(submitBtn,6,9);

}

bool ExamDialog::hasNoSelect()
{
    int radioSelect = 0;
    for(int i = 0; i < 8 ; ++i)
    {
        if(m_btnGroups[i]->checkedButton() != nullptr)
            ++radioSelect;
    }
    //判断单选按钮
    if(radioSelect != 8)
        return true;

    //判断多选按钮
    int checkSelects = 0;
    for(int i = 0; i < 4; ++i)
    {
        if(m_checkBtns[i]->isChecked())
            ++checkSelects;
    }
    if(checkSelects <= 1)
        return true;

    //判断题
    if(!m_radioA->isChecked() && !m_radioB->isChecked())
        return true;

    return false;
}

void ExamDialog::freshTime()
{
    m_time_cost ++;
    QString min = QString::number(m_time_cost / 60);
    QString sec = QString::number(m_time_cost % 60);
    setWindowTitle("考试已用时: " + min + "分" + sec + "秒");
}
