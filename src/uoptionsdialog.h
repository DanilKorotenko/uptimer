#ifndef UOPTIONSDIALOG_H
#define UOPTIONSDIALOG_H

#include <QtGui>

class UOptionsDialog : public QDialog
{
	Q_OBJECT
public:
	explicit UOptionsDialog(QDialog *parent = 0);

public slots:
	void accept();

private slots:
	void slotRunAtStartChecked(int state);

};

#endif // UOPTIONSDIALOG_H
