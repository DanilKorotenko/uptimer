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

private: //Methods
	QGroupBox *createRunAtStartBox();
	QGroupBox *createMessagesBox();

private:
	QCheckBox *_runAtStartCheckbox;
//	QCheckBox *_showRegularMessageCheckbox;
//	QLineEdit *_regularMessageText;
//	QTimeEdit *_regularMessageTime;
};

#endif // UOPTIONSDIALOG_H
