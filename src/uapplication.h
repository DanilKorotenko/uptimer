#ifndef UAPPLICATION_H
#define UAPPLICATION_H

#include <QApplication>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>

class UApplication : public QApplication
{
	Q_OBJECT
public:
	UApplication(int argc, char *argv[]);
	~UApplication();

signals:

public slots:

private:
//Data
	QSystemTrayIcon trayIcon;
	QMenu *trayMenu;

//Actions
	QAction *quitAction;

//Methods
	void configureTrayIcon();
};

#endif // UAPPLICATION_H
