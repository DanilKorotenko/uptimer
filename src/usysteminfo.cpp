#include "usysteminfo.h"

#include <QDateTime>

#ifdef Q_WS_WIN
	#include <windows.h>
#endif

USystemInfo::USystemInfo(QObject *parent) : QObject(parent)
{
}

QString USystemInfo::getSystemUptimeString()
{
	QString result = tr("System uptime is unknown.");

	#ifdef Q_WS_WIN
		unsigned long systemTime = GetTickCount();
//		systemTime = systemTime / 100;
		QDateTime dateTime(QDate(0,0,0),QTime(0,0));

		dateTime = dateTime.addMSecs(systemTime);

		result = tr("%1 years %2 month %3 days %4 hours %5 minutes %6 seconds")
				.arg(dateTime.date().year())
				.arg(dateTime.date().month())
				.arg(dateTime.date().day())
				.arg(dateTime.time().hour())
				.arg(dateTime.time().minute())
				.arg(dateTime.time().second());
	#endif

	return result;
}
