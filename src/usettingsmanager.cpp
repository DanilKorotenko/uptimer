#include "usettingsmanager.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
USettingsManager *USettingsManager::_sharedManager = NULL;

static QString const kMessagesKey = "MessagesKey";
static QString const kMessageEnableKey = "MessageEnableKey";
static QString const kMessageRegularKey = "MessageRegularKey";
static QString const kMessageTimeKey = "MessageTimeKey";
static QString const kMessageTextKey = "MessageTextKey";

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

	_settings->beginWriteArray(kMessagesKey);
	for (int i = 0; i < data.messages.size(); ++i)
	{
		_settings->setArrayIndex(i);
		_settings->setValue(kMessageEnableKey, data.messages.at(i).enable);
		_settings->setValue(kMessageRegularKey, data.messages.at(i).regular);
		_settings->setValue(kMessageTimeKey, data.messages.at(i).time);
		_settings->setValue(kMessageTextKey, data.messages.at(i).text);
	}
	_settings->endArray();
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

QList<UMessageEntry> USettingsManager::messages()
{
	QList<UMessageEntry> result;

	int size = _settings->beginReadArray("logins");
	for (int i = 0; i < size; ++i)
	{
		_settings->setArrayIndex(i);
		UMessageEntry messageEntry;
		messageEntry.enable = _settings->value(kMessageEnableKey).toBool();
		result.append(messageEntry);
	}
	_settings->endArray();

	return result;
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
USettingsManager::USettingsManager(QObject *parent) : QObject(parent)
{
	_settings = new QSettings(qApp->organizationName(), qApp->applicationName(),
		this);
}
