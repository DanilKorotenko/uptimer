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
	USettingsData settingsData;
	settingsData.runAtStart = _runAtStartCheckbox->isChecked();
	settingsData.showRegularMessage = _showRegularMessageCheckbox->isChecked();
	settingsData.regularMessageText = _regularMessageText->text();
	settingsData.regularMessageTime = _regularMessageTime->time();

	USettingsManager::sharedManager()->saveSettingsFromData(settingsData);

	QDialog::accept();
}

//Private methods
QGroupBox *UOptionsDialog::createRunAtStartBox()
{
	QGroupBox *runAtStartBox = new QGroupBox(tr("Run At Start"), this);
	QVBoxLayout *runAtStartBoxLayout = new QVBoxLayout(runAtStartBox);
	_runAtStartCheckbox = new QCheckBox(tr("Run At System Start"),
		runAtStartBox);
	_runAtStartCheckbox->setChecked(
		USettingsManager::sharedManager()->isRunsAtStart());
	runAtStartBoxLayout->addWidget(_runAtStartCheckbox);
	runAtStartBox->setLayout(runAtStartBoxLayout);

	return runAtStartBox;
}

QGroupBox *UOptionsDialog::createMessagesBox()
{
	QGroupBox *messagesBox = new QGroupBox(tr("Messages"), this);
	QVBoxLayout *topBoxLayout = new QVBoxLayout(messagesBox);

	QHBoxLayout *regularMessageGroup = new QHBoxLayout(messagesBox);

	_showRegularMessageCheckbox = new QCheckBox(tr("Show this message:"),
		messagesBox);
	_showRegularMessageCheckbox->setChecked(
		USettingsManager::sharedManager()->showRegularMessage());
	regularMessageGroup->addWidget(_showRegularMessageCheckbox);

	_regularMessageText = new QLineEdit(messagesBox);
	_regularMessageText->setText(
		USettingsManager::sharedManager()->regularMessageText());
	regularMessageGroup->addWidget(_regularMessageText);

	regularMessageGroup->addWidget(new QLabel(tr("every:"), this));

	_regularMessageTime = new QTimeEdit(this);
	_regularMessageTime->setTime(
		USettingsManager::sharedManager()->regularMessageTime());
	regularMessageGroup->addWidget(_regularMessageTime);

	topBoxLayout->addLayout(regularMessageGroup);

	messagesBox->setLayout(topBoxLayout);
	return messagesBox;
}

