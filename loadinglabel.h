#pragma once

#include <QLabel>
#include <QTimer>

class LoadingLabel  : public QLabel
{
	Q_OBJECT

private:
	QTimer timer;
	int dots = 0;

private slots:
	void updateDots();

public:
	LoadingLabel(QWidget *parent);
	~LoadingLabel();
};
