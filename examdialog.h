#ifndef EXAMDIALOG_H
#define EXAMDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QStringList>
#include <QButtonGroup>

class ExamDialog : public QDialog
{
    Q_OBJECT
public:
    ExamDialog(QWidget* parent = nullptr);
    ~ExamDialog();
    void initTimer();               //初始化计时器
    void initLayout();              //初始化布局管理器
    bool initTextEdig();            //初始化文本编辑器
    void initButtons();             //初始化按钮及标签
    bool hasNoSelect();             //判断题目是否有未完成的
private:
    QTimer *m_timer;      //计时器
    int m_time_cost;    //考试已用时

    QTextEdit* m_text_edit;     //考试题库显示
    QLabel* m_title_labels[10]; //题目标签
    QRadioButton* m_radioBtns[32];//单选题按钮
    QButtonGroup* m_btnGroups[9];   //单选按钮分组,不添加该分组所有radiobutton只能选中其中一个
    QCheckBox* m_checkBtns[4];      //多选题按钮
    QRadioButton* m_radioA;     //判断题A选项
    QRadioButton* m_radioB;     //判断题B选项
    QGridLayout* m_layout;      //布局管理器
    QStringList m_answer;       //答案的链表
private slots:
    void freshTime();
};

#endif // EXAMDIALOG_H
