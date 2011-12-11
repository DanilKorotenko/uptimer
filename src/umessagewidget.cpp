#include "umessagewidget.h"

UMessageWidget::UMessageWidget(QWidget *parent) : QWidget(parent)
{
	QGridLayout *topLayout = new QGridLayout(this);

	topLayout->addWidget(new QLabel(tr("Mesage text:"),this),0,0,1,1);

	QLineEdit *messageTextEdit = new QLineEdit(this);
	topLayout->addWidget(messageTextEdit,0,1,1,2);

	QCheckBox *enablingCheckBox = new QCheckBox(tr("Enabled"),this);
	topLayout->addWidget(enablingCheckBox,1,0,1,1);

	QCheckBox *regularCheckBox = new QCheckBox(tr("Regular"),this);
	topLayout->addWidget(regularCheckBox,1,1,1,1);

	topLayout->addWidget(new QLabel(tr("Time:"),this),1,2,1,1);

	QTimeEdit *messageTime = new QTimeEdit(this);
	topLayout->addWidget(messageTime,1,2,1,1);

	this->setLayout(topLayout);
}
