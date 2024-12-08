#ifndef FRMPROGRESSROUND_H
#define FRMPROGRESSROUND_H

#include <QWidget>
#include <QPainterPath>

class ProgressRound;

namespace Ui
{
class frmProgressRound;
}

class frmProgressRound : public QWidget
{
	Q_OBJECT

public:
	explicit frmProgressRound(QWidget *parent = 0);
	~frmProgressRound();

private:
	Ui::frmProgressRound *ui;

private slots:
    void initForm();
	void connectToSlider(ProgressRound *bar);
    void on_progressRound5_customContextMenuRequested(const QPoint &pos);
};

#endif // FRMPROGRESSROUND_H
