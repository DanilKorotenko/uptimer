#ifndef UOPTIONSDIALOG_H
#define UOPTIONSDIALOG_H

#include <QtGui>

#include "usettingsmanager.h"

class UOptionsDialog : public QDialog
{
	Q_OBJECT
public:
	explicit UOptionsDialog(QDialog *parent = 0);

public slots:
	void accept();

private slots:
	void slotRunAtStartChecked(bool state);
	void slotShowRegularMessageChecked(bool state);

private: //Methods
	QGroupBox *createRunAtStartBox();
	QGroupBox *createMessagesBox();

private: //Data
	USettingsData _settingsData;
};

#endif // UOPTIONSDIALOG_H
