#include "usettingsmanager.h"

#include <QtCore>
#include <QtGui>

////////////////////////////////////////////////////////////////////////////////
// Constants
USettingsManager *USettingsManager::_sharedManager = NULL;

////////////////////////////////////////////////////////////////////////////////
// Implementation

USettingsManager *USettingsManager::sharedManager()
{
	if (_sharedManager == NULL)
	{
		_sharedManager = new USettingsManager();
	}
	return _sharedManager;
}

// Public Methods
void USettingsManager::saveSettingsFromData(USettingsData data)
{
	this->setRunAtStart(data.runAtStart);

	QSettings destSettings(qApp->organizationName(), qApp->applicationName(),
		this);
	destSettings.setValue(QString("showRegularMessage"),
		data.showRegularMessage);

}

// Settings getters and setters
bool USettingsManager::isRunsAtStart()
{
	bool result = false;

	#ifdef Q_WS_WIN
		QSettings regSettings(
			"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
			QSettings::NativeFormat);
		result = regSettings.contains(qApp->applicationName());
	#endif

	return result;
}

void USettingsManager::setRunAtStart(bool flag)
{
	#ifdef Q_WS_WIN
		QSettings regSettings(
			"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
			QSettings::NativeFormat);

		if (flag)
		{
			regSettings.setValue(qApp->applicationName(),
				QDir::toNativeSeparators(qApp->applicationFilePath()));
		}
		else
		{
			regSettings.remove(qApp->applicationName());
		}
	#endif
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
USettingsManager::USettingsManager(QObject *parent) : QObject(parent)
{
}
