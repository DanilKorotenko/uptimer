#include "uapplication.h"

UApplication::UApplication(int argc, char *argv[]) : QApplication(argc, argv)
{
	this->configureTrayIcon();
}

//Private methods
void UApplication::configureTrayIcon()
{
	trayIcon.setIcon(QIcon(":/icons/Clock.ico"));
	trayIcon.show();
}
