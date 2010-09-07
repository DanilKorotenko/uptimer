#include "usysteminfo.h"

USystemInfo::USystemInfo(QObject *parent) : QObject(parent)
{
}

QString USystemInfo::getSystemUptimeString()
{
	//to be implemented...
	return QString("System uptime coming soon...");
}
