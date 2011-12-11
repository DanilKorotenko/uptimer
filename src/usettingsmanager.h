#ifndef USETTINGSMANAGER_H
#define USETTINGSMANAGER_H

#include <QtCore>

////////////////////////////////////////////////////////////////////////////////
struct UMessageEntry
{
	bool enable;
	bool regular;
	QTime time;
	QString text;
};

struct USettingsData
{
	bool runAtStart;
	QList<UMessageEntry> messages;
};

////////////////////////////////////////////////////////////////////////////////
class USettingsManager : public QObject
{
	Q_OBJECT
public:
	static USettingsManager *sharedManager();

	bool isRunsAtStart();
	void setRunAtStart(bool flag);

	QList<UMessageEntry> messages();

	void saveSettingsFromData(USettingsData data);

protected:
	USettingsManager(QObject *parent = 0);

private:
	static USettingsManager *_sharedManager;
	QSettings *_settings;
};

#endif // USETTINGSMANAGER_H
