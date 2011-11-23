#include "uapplication.h"

#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QSettings>
#include <QDir>

#include "usysteminfo.h"
#include "usettingsmanager.h"
#include "uoptionsdialog.h"

#include <qdebug.h>

////////////////////////////////////////////////////////////////////////////////
// Implementation UApplication
UApplication::UApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
	this->setQuitOnLastWindowClosed(false);

	this->setApplicationName("UpTimer");
	this->setOrganizationName("Danil Korotenko");

	this->configureTrayIcon();

	_timer = new QTimer();
	connect(_timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
	_timer->start(1000);

	_systemInfo = new USystemInfo(this);
}

UApplication::~UApplication()
{
	delete _trayMenu;
	delete _trayIcon;
	delete _timer;
	delete _systemInfo;
}

//Private methods
void UApplication::configureTrayIcon()
{
	_trayMenu = new QMenu();
	_trayMenu->addAction(tr("&Quit"),qApp,SLOT(quit()));
	_trayMenu->addAction(tr("Options..."),this,SLOT(slotShowOptionsDialog()));

	_trayIcon = new QSystemTrayIcon(this);
	_trayIcon->setIcon(QIcon(":/icons/Clock.ico"));
	_trayIcon->setContextMenu(_trayMenu);
	_trayIcon->setToolTip(QString("tool tip"));

	_trayIcon->show();
}

void UApplication::slotTimeout()
{
	_trayIcon->setToolTip(_systemInfo->getSystemUptimeString());
}

void UApplication::slotShowOptionsDialog()
{
	UOptionsDialog dialog;
	dialog.exec();
}
