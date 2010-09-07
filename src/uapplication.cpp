#include "uapplication.h"

UApplication::UApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
	this->configureTrayIcon();
}

UApplication::~UApplication()
{
	delete quitAction;
	delete trayMenu;
}

//Private methods
void UApplication::configureTrayIcon()
{
	quitAction = new QAction(tr("&Quit"), this);
	connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	trayMenu = new QMenu();
	trayMenu->addAction(quitAction);

	trayIcon.setIcon(QIcon(":/icons/Clock.ico"));
	trayIcon.setContextMenu(trayMenu);
	trayIcon.show();
}
