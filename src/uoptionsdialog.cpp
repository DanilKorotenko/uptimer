#include "uoptionsdialog.h"
#include "usettingsmanager.h"

////////////////////////////////////////////////////////////////////////////////
// Implementation UOptionsDialog
UOptionsDialog::UOptionsDialog(QDialog *parent) : QDialog(parent)
{
	QVBoxLayout *topLayout = new QVBoxLayout(this);

	QGroupBox *runAtStartBox = new QGroupBox(tr("Run At Start"), this);
	QVBoxLayout *runAtStartBoxLayout = new QVBoxLayout(this);
	QCheckBox *runAtStartCheckbox = new QCheckBox(tr("Run At System Start"),
		runAtStartBox);
	runAtStartCheckbox->setChecked(
		USettingsManager::sharedManager()->isRunsAtStart());
	connect(runAtStartCheckbox, SIGNAL(stateChanged(int)), this,
		SLOT(slotRunAtStartChecked(int)));
	runAtStartBoxLayout->addWidget(runAtStartCheckbox);
	runAtStartBox->setLayout(runAtStartBoxLayout);
	topLayout->addWidget(runAtStartBox);

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

	QDialog::accept();
}

// Private Slots
void UOptionsDialog::slotRunAtStartChecked(int state)
{
	USettingsManager::sharedManager()->setRunAtStart(Qt::Checked == state);
}
