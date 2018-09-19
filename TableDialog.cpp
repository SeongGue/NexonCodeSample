#include "TableDialog.h"

#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qgroupbox.h>
#include <qcolordialog.h>

//#include "System\styleManager.h"

TableDialog::TableDialog(QWidget* parent, Qt::WindowFlags f)
	: QDialog(parent, f), m_tableFormat(), m_rowSpin(nullptr), m_colSpin(nullptr), m_borderColorBtn(nullptr), m_defaultTable()
{
	setFixedSize(250, 150);
	//setStyleSheet(STYLE_MANAGER->mainFrame);
	setWindowTitle("Table Property");

	m_tableFormat.setCellSpacing(0);
	m_tableFormat.setCellPadding(nPadding);
	m_tableFormat.setBorderBrush(QBrush(nBorderColor));

	createUI();
}

TableDialog::~TableDialog()
{

}

void TableDialog::createUI()
{
	QVBoxLayout* vMainLayout = new QVBoxLayout;
	setLayout(vMainLayout);

	vMainLayout->addWidget(createTableProperty(), 1);
	vMainLayout->addWidget(createBtnGroup(), 0);
}

QWidget* TableDialog::createTableProperty()
{
	QGroupBox* group = new QGroupBox("Table Property", this);
	//group->setStyleSheet(STYLE_MANAGER->imgDialogGroupBox);
	QVBoxLayout* vGroupLayout = new QVBoxLayout;
	group->setLayout(vGroupLayout);

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->setSpacing(5);

	QLabel* rowLabel = new QLabel("Row", group);
	hLayout->addWidget(rowLabel, 0);
	m_rowSpin = new QSpinBox(group);
	//m_rowSpin->setStyleSheet(STYLE_MANAGER->spinbox);
	m_rowSpin->setValue(2);
	hLayout->addWidget(m_rowSpin, 1);

	QLabel* colLabel = new QLabel("Col", group);
	hLayout->addWidget(colLabel, 0);
	m_colSpin = new QSpinBox(group);
	//m_colSpin->setStyleSheet(STYLE_MANAGER->spinbox);
	m_colSpin->setValue(2);
	hLayout->addWidget(m_colSpin, 1);
	vGroupLayout->addItem(hLayout);

	hLayout = new QHBoxLayout;
	hLayout->setSpacing(5);

	QLabel* paddingLabel = new QLabel("Padding", group);
	hLayout->addWidget(paddingLabel, 0);
	QSpinBox* paddingSpin = new QSpinBox(group);
	//paddingSpin->setStyleSheet(STYLE_MANAGER->spinbox);
	paddingSpin->setValue(nPadding);
	hLayout->addWidget(paddingSpin, 1);

	connect(paddingSpin, SIGNAL(valueChanged(int)), this, SLOT(OnPaddingChange(int)));

	QPixmap pix(16, 16);
	pix.fill(nBorderColor);
	m_borderColorBtn = new QPushButton(QIcon(pix), "Border Color", group);
	//m_borderColorBtn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	hLayout->addWidget(m_borderColorBtn, 2);

	connect(m_borderColorBtn, &QPushButton::clicked, this, &TableDialog::OnColorChange);

	vGroupLayout->addItem(hLayout);
	
	return group;
}

QWidget* TableDialog::createMEDIPDefaultTableButton()
{
	QGroupBox* group = new QGroupBox("Default Table", this);
	//group->setStyleSheet(STYLE_MANAGER->imgDialogGroupBox);
	QVBoxLayout* vGroupLayout = new QVBoxLayout;
	group->setLayout(vGroupLayout);

	QPushButton* btn = new QPushButton("Auto Patient Data", group);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	vGroupLayout->addWidget(btn);

	btn = new QPushButton("Texture Feature Table", group);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	vGroupLayout->addWidget(btn);

	return group;
}

QWidget* TableDialog::createBtnGroup()
{
	QWidget* btnArea = new QWidget(this);

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->setMargin(0);
	btnArea->setLayout(hLayout);

	QPushButton* btn = new QPushButton("OK", btnArea);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	hLayout->addWidget(btn);

	connect(btn, &QPushButton::clicked, this, &TableDialog::OnFinished);

	btn = new QPushButton("Cancel", btnArea);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	hLayout->addWidget(btn);

	connect(btn, &QPushButton::clicked, this, &TableDialog::OnCancel);

	return btnArea;
}

int TableDialog::getColumn()
{
	if (m_colSpin)
		return m_colSpin->value();
	return 0;
};

int TableDialog::getRow()
{
	if (m_rowSpin)
		return m_rowSpin->value();
	return 0;
};

void TableDialog::OnFinished()
{
	emit accept();
}

void TableDialog::OnCancel()
{
	this->close();
}

void TableDialog::OnPaddingChange(int val)
{
	m_tableFormat.setCellPadding(val);
}

void TableDialog::OnColorChange()
{
	QColorDialog dlg(this);
	dlg.setStyleSheet("color : white");
	if (dlg.exec() == QDialog::Accepted)
	{
		QColor color = dlg.selectedColor();
		m_tableFormat.setBorderBrush(QBrush(color));
		QPixmap pix(16, 16);
		pix.fill(color);
		m_borderColorBtn->setIcon(pix);
	}
}

//========================================================================

TableCellSplitDialog::TableCellSplitDialog(QWidget* parent, Qt::WindowFlags f)
	: QDialog(parent, f), m_columEditBox(nullptr), m_rowEditBox(nullptr)
{
	setFixedSize(200, 150);
	//setStyleSheet(STYLE_MANAGER->mainFrame);
	setWindowTitle("Split Cell");

	QWidget* widget = new QWidget(this);
	widget->setFixedSize(this->size());

	QVBoxLayout* vMainLayout = new QVBoxLayout;
	widget->setLayout(vMainLayout);

	QGroupBox* group = new QGroupBox("Number", this);
	//group->setStyleSheet(STYLE_MANAGER->imgDialogGroupBox);

	QVBoxLayout* vLayout = new QVBoxLayout;
	group->setLayout(vLayout);

	vLayout->addWidget(createRowNumberGroup(group));
	vLayout->addWidget(createColumNumberGroup(group));

	vMainLayout->addWidget(group, 1);
	vMainLayout->addWidget(createBtnGroup(), 0);
}


TableCellSplitDialog::~TableCellSplitDialog()
{
}

QWidget* TableCellSplitDialog::createRowNumberGroup(QWidget* parent)
{
	QWidget* group = new QWidget(parent);

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->setSpacing(0);
	hLayout->setMargin(0);
	group->setLayout(hLayout);

	QLabel* label = new QLabel("Column", group);
	hLayout->addWidget(label, 1);

	m_columEditBox = new QSpinBox(group);
	m_columEditBox->setFixedWidth(this->size().width() / 2);
	//m_columEditBox->setStyleSheet(STYLE_MANAGER->spinbox);
	m_columEditBox->setMaximum(50);
	m_columEditBox->setValue(2);
	hLayout->addWidget(m_columEditBox, 1, Qt::AlignRight);

	return group;
}

QWidget* TableCellSplitDialog::createColumNumberGroup(QWidget* parent)
{
	QWidget* group = new QWidget(parent);

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->setSpacing(0);
	hLayout->setMargin(0);
	group->setLayout(hLayout);

	QLabel* label = new QLabel("Row", group);
	hLayout->addWidget(label, 1);

	m_rowEditBox = new QSpinBox(group);
	m_rowEditBox->setFixedWidth(this->size().width() / 2);
	//m_rowEditBox->setStyleSheet(STYLE_MANAGER->spinbox);
	m_rowEditBox->setMaximum(50);
	m_rowEditBox->setValue(2);
	hLayout->addWidget(m_rowEditBox, 1, Qt::AlignRight);

	return group;
}

QWidget* TableCellSplitDialog::createBtnGroup()
{
	QWidget* btnArea = new QWidget(this);

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->setMargin(0);
	btnArea->setLayout(hLayout);

	QPushButton* btn = new QPushButton("OK", btnArea);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	hLayout->addWidget(btn);

	connect(btn, &QPushButton::clicked, this, &TableCellSplitDialog::OnFinished);

	btn = new QPushButton("Cancel", btnArea);
	//btn->setStyleSheet(STYLE_MANAGER->buttonBehind);
	hLayout->addWidget(btn);

	connect(btn, &QPushButton::clicked, this, &TableCellSplitDialog::OnCancel);

	return btnArea;
}

std::pair<int, int> TableCellSplitDialog::getSplitNumber()
{
	std::pair<int, int> res(m_columEditBox->value(), m_rowEditBox->value());
	return res;
}

void TableCellSplitDialog::OnFinished()
{
	emit accept();
}

void TableCellSplitDialog::OnCancel()
{
	this->close();
}