#ifndef USYSTEMINFO_H
#define USYSTEMINFO_H

#include <QObject>

class USystemInfo : public QObject
{
	Q_OBJECT
public:
	USystemInfo(QObject *parent = 0);

	QString getSystemUptimeString();
};

#endif // USYSTEMINFO_H
