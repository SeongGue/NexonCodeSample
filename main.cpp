#include "NexonCodeSample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NexonCodeSample w;
	//w.show();
	w.showMaximized();
	return a.exec();
}
