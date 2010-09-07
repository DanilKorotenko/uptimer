#include <QtGui/QApplication>
#include "uapplication.h"

int main(int argc, char *argv[])
{
	UApplication app(argc, argv);

	return app.exec();
}
