#include "loadinglabel.h"

LoadingLabel::LoadingLabel(QWidget *parent)
	: QLabel(parent), timer(this)
{
	QObject::connect(&timer, &QTimer::timeout, this, &LoadingLabel::updateDots);
	timer.start(500);
}

LoadingLabel::~LoadingLabel()
{}

void LoadingLabel::updateDots() {
	dots = (dots + 1) % 3;
	setText(QString("Loading") + QString(dots + 1, '.'));
}