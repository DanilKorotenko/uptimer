#include "uoptionsdialog.h"

////////////////////////////////////////////////////////////////////////////////
// Implementation UOptionsDialog
UOptionsDialog::UOptionsDialog(QDialog *parent) : QDialog(parent)
{
	QVBoxLayout *topLayout = new QVBoxLayout(this);

	topLayout->addWidget(this->createRunAtStartBox());
	topLayout->addWidget(this->createMessagesBox());

	QDialogButtonBox *buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
	connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
	connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));

	topLayout->addWidget(buttonBox);

	this->setLayout(topLayout);
}

// Public Slots
void UOptionsDialog::accept()
{
	// save settings
	USettingsManager::sharedManager()->saveSettingsFromData(_settingsData);

	QDialog::accept();
}

// Private Slots
void UOptionsDialog::slotRunAtStartChecked(bool state)
{
	_settingsData.runAtStart = state;
}

void UOptionsDialog::slotShowRegularMessageChecked(bool state)
{
	_settingsData.showRegularMessage = state;
}

//Private methods
QGroupBox *UOptionsDialog::createRunAtStartBox()
{
	QGroupBox *runAtStartBox = new QGroupBox(tr("Run At Start"), this);
	QVBoxLayout *runAtStartBoxLayout = new QVBoxLayout(runAtStartBox);
	QCheckBox *runAtStartCheckbox = new QCheckBox(tr("Run At System Start"),
		runAtStartBox);
	runAtStartCheckbox->setChecked(
		USettingsManager::sharedManager()->isRunsAtStart());
	connect(runAtStartCheckbox, SIGNAL(toggled(bool)), this,
		SLOT(slotRunAtStartChecked(bool)));
	runAtStartBoxLayout->addWidget(runAtStartCheckbox);
	runAtStartBox->setLayout(runAtStartBoxLayout);

	return runAtStartBox;
}

QGroupBox *UOptionsDialog::createMessagesBox()
{
	QGroupBox *messagesBox = new QGroupBox(tr("Messages"), this);
	QVBoxLayout *topBoxLayout = new QVBoxLayout(messagesBox);

	QHBoxLayout *regularMessageGroup = new QHBoxLayout(messagesBox);
	QCheckBox *showRegularMessageCheckbox =
		new QCheckBox(tr("Show this message:"), messagesBox);
	connect(showRegularMessageCheckbox,SIGNAL(toggled(bool)), this,
		SLOT(slotShowRegularMessageChecked(bool)));
	regularMessageGroup->addWidget(showRegularMessageCheckbox);

	topBoxLayout->addLayout(regularMessageGroup);

	messagesBox->setLayout(topBoxLayout);
	return messagesBox;
}
