#ifndef USETTINGSMANAGER_H
#define USETTINGSMANAGER_H

#include <QObject>

class USettingsManager : public QObject
{
	Q_OBJECT
public:
	static USettingsManager *sharedManager();

	bool isRunsAtStart();
	void setRunAtStart(bool flag);

protected:
	USettingsManager(QObject *parent = 0);

private:
	static USettingsManager *_sharedManager;
};

#endif // USETTINGSMANAGER_H
