#pragma once
#include <qdialog.h>
#include <qtextformat.h>
#include <qspinbox.h>


class TableDialog : public QDialog
{
	Q_OBJECT

private:
	TableDialog(const TableDialog& copy) {}
	const TableDialog& operator=(const TableDialog& rhs) {}

	void createUI();
	QWidget* createTableProperty();
	QWidget* createMEDIPDefaultTableButton();
	QWidget* createBtnGroup();

public:
	explicit TableDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~TableDialog();

	int getColumn();
	int getRow();

	inline const QTextTableFormat& getTableFormat() { return m_tableFormat; };
	static int getTablePadding() { return nPadding; }

public slots:
	void OnFinished();
	void OnCancel();
	void OnPaddingChange(int val);
	void OnColorChange();

private:
	QTextTableFormat m_tableFormat;
	QSpinBox* m_rowSpin;
	QSpinBox* m_colSpin;
	QPushButton* m_borderColorBtn;
	QString m_defaultTable;

	static const int nPadding = 5;
	const QColor nBorderColor = Qt::black;
};

class TableCellSplitDialog : public QDialog
{
	Q_OBJECT

private:
	TableCellSplitDialog(const TableCellSplitDialog& copy) {}
	const TableCellSplitDialog& operator=(const TableCellSplitDialog& rhs) {}

	QWidget* createRowNumberGroup(QWidget* parent);
	QWidget* createColumNumberGroup(QWidget* parent);
	QWidget* createBtnGroup();

public:
	explicit TableCellSplitDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~TableCellSplitDialog();

	std::pair<int, int> getSplitNumber();

public slots:
	void OnFinished();
	void OnCancel();

private:
	QSpinBox* m_columEditBox;
	QSpinBox* m_rowEditBox;
};