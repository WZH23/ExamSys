Qt5.15.2

## 标准对话框

### QFileDialog:文件对话框

静态函数:

getOpenFileName():选择打开一个文件

getOpenFileNames():选择打开一个文件

getSaveFileName():选择保存一个文件

getExistingDirectory:选择一个已有的目录

getOpenFileUrl:选择一个打开文件，可选择远程网络文件

### QColorDialog:颜色对话框

静态函数:

getColor():选择颜色

### QFontDialog:字体对话框

静态函数:

QFontDialog::getFont():选择字体

### QInputDialog:输入对话框

静态函数:

getText():输入单行文字

getInt():输入整数

getDouble():输入浮点数

getItem():从一个下拉列表框中选择输入

getMultiLineText():输入多行字符串

### QMessageBox:消息框

静态函数:

information():信息提示对话框

question():询问并获取是否确认的对话框

warning():警告信息提示对话框

critical():错误信息提示对话框

about():设置自定义信息的关于对话框

aboutQt:关于Qt的对话框

## 文件处理

QFile 类用于文件操作，它提供了读写文件的接口，可以读写文件、二进制文件和 Qt 资源文件。
处理文本文件和二进制文件，可以使用 QTextStream 类和 QDataStream 类。处理临时文件可以使用 QTemporaryfile,获
取信息可以使用 QFileInfo，处理目录可以使用 QDir，监视文件和目录变化可以使用 QFileSystemWatcher.

*****

```C++
//将数数字（整数、浮点数、有符号、无符号等）转换为 QString 类型，而基数可以简单的理解为进制。
QString QString::number(long n, int base = 10)：
    
/*
返回一个 size() 宽度的字符串，其中包含填充字符，后跟该字符串。 例如：
QString s =“apple”;
QString t = s.rightJustified(8，'.'); // t ==“ ...apple”
如果 truncate 为 false 并且字符串的 size() 大于 width，则返回的字符串是该字符串的副本。
如果 truncate 为 true，并且字符串的 size() 大于 width，则结果字符串在位置 width 处被截断。
QString str = “Pineapple”;
str = str.rightJustified(5，'.'，true); // str ==“Pinea”
*/
QString QString::rightJustified(int width, QChar fill = QLatin1Char(' '), bool truncate = false) const：

/*
将当前字段的宽度设置为 width 。 如果 width 为 0 ( 默认值 )，则字段宽度等于生成的文本的长度。
注意：字段宽度适用于调用此函数后附加到此流的每个元素 ( 例如，它也填充 endl )。 此行为不同于 STL 中的类似类，在 STL 中，字段宽度仅适用于下一个元素。
*/
void QTextStream::setFieldWidth(int width)：
    
//将填充字符设置为 ch。 默认值为 ASCII 空格字符 (' ') 或 QChar(0x20)。 生成文本时，此字符用于填充字段中的空格，即超过 fieldWidth() 的部分
void QTextStream::setPadChar(QChar ch) ：
    
//将字段对齐方式设置为 mode。 与 setFieldWidth() 一起使用时，此函数允许您生成格式化的输出，其中文本左对齐，右对齐或居中对齐。 
QTextStream :: setFieldAlignment(QTextStream :: FieldAlignment mode)：
```

*****
