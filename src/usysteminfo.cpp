#include "usysteminfo.h"

#include <QDateTime>

#ifdef Q_WS_WIN
	#include <windows.h>
#endif

////////////////////////////////////////////////////////////////////////////////
// Constants
static quint16 const mssecsInSec = 1000;
static quint16 const mssecsInMin = mssecsInSec * 60;
static quint32 const mssecsInHour = mssecsInMin * 60;
static quint32 const mssecsInDay = mssecsInHour * 24;
static quint32 const mssecsInMonth = mssecsInDay * 31;

////////////////////////////////////////////////////////////////////////////////
// Implementation USystemInfo
USystemInfo::USystemInfo(QObject *parent) : QObject(parent)
{
}

QString USystemInfo::getSystemUptimeString()
{
	QString result = tr("System uptime is unknown.");

	#ifdef Q_WS_WIN
		DWORD systemTime = GetTickCount();
		QDateTime dateTime(QDate(1,1,1),QTime(0,0));

		dateTime = dateTime.addMSecs(systemTime);

		if (systemTime < mssecsInDay)
		{
			result = tr("%1 hours %2 minutes %3 seconds")
				.arg(dateTime.time().hour())
				.arg(dateTime.time().minute())
				.arg(dateTime.time().second());
		}
		else if (systemTime < mssecsInMonth)
		{
			result = tr("%1 days %2 hours %3 minutes %4 seconds")
				.arg(dateTime.date().day())
				.arg(dateTime.time().hour())
				.arg(dateTime.time().minute())
				.arg(dateTime.time().second());
		}
		else
		{
			result = tr("%1 month %2 days %3 hours %4 minutes %5 seconds")
				.arg(dateTime.date().month())
				.arg(dateTime.date().day())
				.arg(dateTime.time().hour())
				.arg(dateTime.time().minute())
				.arg(dateTime.time().second());
		}

	#endif

	return result;
}
