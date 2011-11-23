#ifndef USETTINGSMANAGER_H
#define USETTINGSMANAGER_H

#include <QObject>

////////////////////////////////////////////////////////////////////////////////
struct USettingsData
{
	bool runAtStart;
	bool showRegularMessage;
	QString regularMessageText;
};

////////////////////////////////////////////////////////////////////////////////
class USettingsManager : public QObject
{
	Q_OBJECT
public:
	static USettingsManager *sharedManager();

	bool isRunsAtStart();
	void setRunAtStart(bool flag);

	void saveSettingsFromData(USettingsData data);

protected:
	USettingsManager(QObject *parent = 0);

private:
	static USettingsManager *_sharedManager;
};

#endif // USETTINGSMANAGER_H
