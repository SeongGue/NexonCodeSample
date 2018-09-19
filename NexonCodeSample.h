#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NexonCodeSample.h"

class ReportWidget;

class NexonCodeSample : public QMainWindow
{
	Q_OBJECT

public:
	explicit NexonCodeSample(QWidget *parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent *event) override;

private:
	Ui::NexonCodeSampleClass ui;
	ReportWidget* m_report;
};
