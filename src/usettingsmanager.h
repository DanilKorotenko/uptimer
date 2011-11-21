#ifndef USETTINGSMANAGER_H
#define USETTINGSMANAGER_H

#include <QObject>

class USettingsManager : public QObject
{
	Q_OBJECT
public:
	static USettingsManager *sharedManager();

protected:
	USettingsManager(QObject *parent = 0);

private:
	static USettingsManager *_sharedManager;

};

#endif // USETTINGSMANAGER_H
