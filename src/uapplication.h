#ifndef UAPPLICATION_H
#define UAPPLICATION_H

#include <QApplication>
#include <QSystemTrayIcon>

class UApplication : public QApplication
{
	Q_OBJECT
public:
	UApplication(int argc, char *argv[]);

signals:

public slots:

private:
//Data
	QSystemTrayIcon trayIcon;

//Methods
	void configureTrayIcon();
};

#endif // UAPPLICATION_H
