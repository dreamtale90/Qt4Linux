#include <QMessageBox>
#include <QTextStream>
#include <QDockWidget>
#include <QFileDialog>
#include <QMenuBar>
#include "mainwindow.h"

MainWindow::MainWindow()
{
	textEdit = new QPlainTextEdit;
	setCentralWidget(textEdit);

	createActions();
	createMenus();
	createToolBars();
	createStatusBar();
	createDockWindows();

	readSettings();

	connect(textEdit->document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));

	setCurrentFile("");
	setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if(maybeSave())
	{
		writeSettings();
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void MainWindow::newFile()
{
	if(maybeSave())
	{
		textEdit->clear();
		setCurrentFile("");
	}
}

void MainWindow::open()
{
	if(maybeSave())
	{
		QString fileName = QFileDialog::getOpenFileName(this);
		if(!fileName.isEmpty())
		{
			loadFile(fileName);
		}
	}
}

bool MainWindow::save()
{
	if(curFile.isEmpty())
	{
		return saveAs();
	}
	else
	{
		return saveFile(curFile);
	}
}

bool MainWindow::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this);
	if(fileName.isEmpty())
	{
		return false;
	}

	return saveFile(fileName);
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About Application"),
			tr("The <b>Application</b> example demonstrates how to "
				"write modern GUI application using Qt, with a menu bar."
				"toolbars, and a status bar."));
}

void MainWindow::documentWasModified()
{
}


void MainWindow::createActions()
{
	//new file action
	newAct = new QAction(QIcon(":/images/new.png"), tr("&新建"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("新建一个文本"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

	//open file action
	openAct = new QAction(QIcon(":/images/open.png"), tr("&打开..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("打开已经存在的文件"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

	//save file action
	saveAct = new QAction(QIcon(":/images/save.png"), tr("&保存"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("保存文本到硬盘"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

	//save as action
	saveAsAct = new QAction(tr("另存为..."), this);
	saveAsAct->setShortcuts(QKeySequence::SaveAs);
	saveAsAct->setStatusTip(tr("保存文本为另外一个名字"));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

	//exit action
	exitAct = new QAction(tr("&退出"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("退出窗口"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	//cut action
	cutAct = new QAction(QIcon(":/images/cut.png"), tr("剪&切"), this);
	cutAct->setShortcuts(QKeySequence::Cut);
	cutAct->setStatusTip(tr("剪切当前文本选择的区域"));
	connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

	//copy action
	copyAct = new QAction(QIcon(":/images/copy.png"), tr("&复制"), this);
	copyAct->setShortcuts(QKeySequence::Copy);
	copyAct->setStatusTip(tr("复制当前文本选择的区域"));
	connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

	//paste action
	pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&粘贴"), this);
	pasteAct->setShortcuts(QKeySequence::Paste);
	pasteAct->setStatusTip(tr("粘贴文本到当前选择的区域"));
	connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

	//about action
	aboutAct = new QAction(tr("&关于"), this);
	aboutAct->setStatusTip(tr("有关信息"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	//设置剪切和粘贴的bool值
	cutAct->setEnabled(false);
	copyAct->setEnabled(false);

	//建立信号与槽连接，使能剪切和粘贴动作
	connect(textEdit, SIGNAL(copyAvailable(bool)), cutAct, SLOT(setEnabled(bool)));
	connect(textEdit, SIGNAL(copyAvailable(bool)), copyAct, SLOT(setEnabled(bool)));
}

void MainWindow::createMenus()
{
	//创建文件(fileMenu)菜单，添加相应动作
	fileMenu = menuBar()->addMenu(tr("&文件"));
	fileMenu->addAction(newAct);
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);

	//创建编辑(editMenu)菜单，添加相应动作
	editMenu = menuBar()->addMenu(tr("&编辑"));
	editMenu->addAction(cutAct);
	editMenu->addAction(copyAct);
	editMenu->addAction(pasteAct);

	//创建视图(viewMenu)菜单
	viewMenu = menuBar()->addMenu(tr("&视图"));

	//添加菜单栏下面的分割线
	menuBar()->addSeparator();

	//创建帮助(helpMenu)菜单，添加相应动作
	helpMenu = menuBar()->addMenu(tr("&帮助"));
	helpMenu->addAction(aboutAct);
}

void MainWindow::createToolBars()
{
	//创建文件工具栏，添加相应动作
	fileToolBar = addToolBar(tr("文件"));
	fileToolBar->addAction(newAct);
	fileToolBar->addAction(openAct);
	fileToolBar->addAction(saveAct);

	//创建编辑工具栏，添加相应动作
	editToolBar = addToolBar(tr("编辑"));
	editToolBar->addAction(cutAct);
	editToolBar->addAction(copyAct);
	editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage(tr("准备"));
}

void MainWindow::createDockWindows()
{
	QDockWidget *dock = new QDockWidget(tr("Customers"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	customerList = new QListWidget(dock);
	customerList->addItems(QStringList()
			<< "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
			<< "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
			<< "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
			<< "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
			<< "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
			<< "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");

	dock->setWidget(customerList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());

	dock = new QDockWidget(tr("Paragraphs"), this);
	paragraphsList = new QListWidget(dock);
	paragraphsList->addItems(QStringList()
			<< "Thank you for your payment which we have received today."
			<< "Your order has been dispatched and should be with you "
				"within 28 days."
			<< "We have dispatched those items that were in stock. The "
				"rest of your order will be dispatched once all the "
				"remaining items have arrived at our warehouse. No "
				"additional shipping charges will be made."
			<< "You made a small overpayment(less than $5)which we "
				"will keep on account for you, or return at your request."
			<< "You made a small underpayment(less than $1), but we have "
				"sent your order anyway. We'll add this underpayment to "
				"your next bill."
			<< "Unfortunately you did not send enough money. Plesase remit "
				"an additional $. Your order will be dispatched as soon as "
				"the complete amount has been received."
			<< "You made an overpayment(more than $5). Do you wish to "
				"buy more items, or should we return the excess to you?");

	dock->setWidget(paragraphsList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());
}

void MainWindow::readSettings()
{
#if 0
	QFile f(".layout_settings");
	if(f.open(IO_WriteOnly))
	{
		QTextStream ts(&f);
		ts << *mainWindow;
		f.close();
	}
#endif
}

void MainWindow::writeSettings()
{
#if 0
	QFile f(".layout_settings");
	if(f.open(IO_ReadOnly))
	{
		QTextStream ts(&f);
		ts >> *mainWindow;
		f.close();
	}
#endif
}

bool MainWindow::maybeSave()
{
	if(textEdit->document()->isModified())
	{
		QMessageBox::StandardButton ret;
		ret = QMessageBox::warning(this, tr("Application"),
				tr("The document has been modified.\n"
					"Do you want to save your changes?"),
				QMessageBox::Save | QMessageBox::Discard |QMessageBox::Cancel);

		if(ret == QMessageBox::Save)
		{
			return save();
		}
		else if(ret == QMessageBox::Cancel)
		{
			return false;
		}
	}

	return true;
}

void MainWindow::loadFile(const QString &fileName)
{
}

bool MainWindow::saveFile(const QString &fileName)
{
	return false;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
}

QString MainWindow::strippedName(const QString &fullFileName)
{
}
