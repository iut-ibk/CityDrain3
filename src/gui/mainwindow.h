#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
	class MainWindow;
}

struct MainWindowPrivate;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();

protected:
	void changeEvent(QEvent *e);

private:
	Ui::MainWindow *ui;
	MainWindowPrivate *priv;

public Q_SLOTS:
	void on_actionAdd_Plugin_activated();
	void on_pluginsAdded();
};

#endif // MAINWINDOW_H
