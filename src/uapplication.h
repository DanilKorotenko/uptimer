#ifndef UAPPLICATION_H
#define UAPPLICATION_H

#include <QApplication>

class QAction;
class QMenu;
class QSystemTrayIcon;
class QTimer;

class USystemInfo;

class UApplication : public QApplication
{
	Q_OBJECT
public:
	UApplication(int argc, char *argv[]);
	~UApplication();

private:
//Data
	QSystemTrayIcon *_trayIcon;
	QMenu *_trayMenu;
	QTimer *_timer;

	USystemInfo *_systemInfo;

//Actions
	QAction *_quitAction;

//Methods
	void configureTrayIcon();

private slots:
	void slotTimeout();
};

#endif // UAPPLICATION_H
