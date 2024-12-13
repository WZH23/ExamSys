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
