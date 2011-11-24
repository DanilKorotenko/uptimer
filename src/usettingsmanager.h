#ifndef USETTINGSMANAGER_H
#define USETTINGSMANAGER_H

#include <QtCore>

////////////////////////////////////////////////////////////////////////////////
struct USettingsData
{
	bool runAtStart;
	bool showRegularMessage;
	QString regularMessageText;
	QTime regularMessageTime;
};

////////////////////////////////////////////////////////////////////////////////
class USettingsManager : public QObject
{
	Q_OBJECT
public:
	static USettingsManager *sharedManager();

	bool isRunsAtStart();
	void setRunAtStart(bool flag);

	bool showRegularMessage();
	QString regularMessageText();
	QTime regularMessageTime();

	void saveSettingsFromData(USettingsData data);

protected:
	USettingsManager(QObject *parent = 0);

private:
	static USettingsManager *_sharedManager;
	QSettings *settings;
};

#endif // USETTINGSMANAGER_H
