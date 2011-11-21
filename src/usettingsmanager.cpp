#include "usettingsmanager.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
USettingsManager *USettingsManager::_sharedManager = NULL;

////////////////////////////////////////////////////////////////////////////////
// Implementation

USettingsManager *USettingsManager::sharedManager()
{
	if (_sharedManager == NULL)
	{
		_sharedManager = new USettingsManager;
//		_sharedManager->loadSettings();
	}
	return _sharedManager;
}

USettingsManager::USettingsManager(QObject *parent) : QObject(parent)
{
}
