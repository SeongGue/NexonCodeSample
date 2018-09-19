#include "NexonCodeSample.h"

#include <qlayout.h>

#include "ReportWidget.h"

NexonCodeSample::NexonCodeSample(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_report = new ReportWidget(this);
}

void NexonCodeSample::resizeEvent(QResizeEvent *event)
{
	m_report->resize(size());
}
