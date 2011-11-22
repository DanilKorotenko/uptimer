#include "uapplication.h"

#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QSettings>
#include <QDir>

#include "usysteminfo.h"
#include "usettingsmanager.h"

#include <qdebug.h>

////////////////////////////////////////////////////////////////////////////////
// Implementation UApplication
UApplication::UApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
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
	delete _quitAction;
	delete _trayMenu;
	delete _trayIcon;
	delete _timer;
	delete _systemInfo;
	delete _optionsMenu;
}

//Private methods
void UApplication::configureTrayIcon()
{
	_quitAction = new QAction(tr("&Quit"), this);
	connect(_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	_trayMenu = new QMenu();
	_trayMenu->addAction(_quitAction);

	_optionsMenu = new QMenu(tr("Options"));
	QAction *startWithSystemAction = new QAction(tr("Start with sysem"), this);
	startWithSystemAction->setCheckable(true);
	startWithSystemAction->setChecked(
		USettingsManager::sharedManager()->isRunsAtStart());
	connect(startWithSystemAction,SIGNAL(toggled(bool)),this,
		SLOT(slotToggleStartWithSystem(bool)));
	_optionsMenu->addAction(startWithSystemAction);

	_trayMenu->addMenu(_optionsMenu);

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

void UApplication::slotToggleStartWithSystem(bool togled)
{
	USettingsManager::sharedManager()->setRunAtStart(togled);
}
