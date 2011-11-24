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

//Methods
	void configureTrayIcon();
	void acceptSettings();

private slots:
	void slotTimeout();
	void slotShowOptionsDialog();
};

#endif // UAPPLICATION_H
