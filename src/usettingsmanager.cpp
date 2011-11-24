#include "usettingsmanager.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
USettingsManager *USettingsManager::_sharedManager = NULL;

static QString const kShowRegularMessageKey = "ShowRegularMessageKey";
static QString const kRegularMessageTextKey = "RegularMessageTextKey";
static QString const kRegularMessageTimeKey = "RegularMessageTimeKey";

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

	settings->setValue(kShowRegularMessageKey, data.showRegularMessage);
	settings->setValue(kRegularMessageTextKey, data.regularMessageText);
	settings->setValue(kRegularMessageTimeKey, data.regularMessageTime);

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

bool USettingsManager::showRegularMessage()
{
	return settings->value(kShowRegularMessageKey, QVariant(false)).toBool();
}

QString USettingsManager::regularMessageText()
{
	return settings->value(kRegularMessageTextKey, tr("Time is gone")).toString();
}

QTime USettingsManager::regularMessageTime()
{
	return settings->value(kRegularMessageTimeKey, QTime()).toTime();
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
USettingsManager::USettingsManager(QObject *parent) : QObject(parent)
{
	settings = new QSettings(qApp->organizationName(), qApp->applicationName(),
		this);
}
