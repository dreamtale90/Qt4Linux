#include <QMainWindow>
#include <QPlainTextEdit>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QListWidget;
//class QToolBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void newFile();
	void open();
	bool save();
	bool saveAs();
	void about();
	void documentWasModified();

private:
	void createActions();
	void createMenus();
	void createToolBars();
	void createStatusBar();
	void readSettings();
	void writeSettings();
	void createDockWindows();
	bool maybeSave();
	void loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);
	QString strippedName(const QString &fullFileName);

	QPlainTextEdit *textEdit;
	QString curFile;
	QListWidget *customerList;
	QListWidget *paragraphsList;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *helpMenu;
	QMenu *viewMenu;

	QToolBar *fileToolBar;
	QToolBar *editToolBar;

	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *exitAct;
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
	QAction *aboutAct;
};

