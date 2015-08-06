#ifndef CUSTOMDIAL_H
#define CUSTOMDIAL_H

#include <QDial>

class CustomDial : public QDial {
	// Q_OBJECT
public:
	CustomDial(QWidget* parent);

	void setColor(const QColor&);

protected:
	void paintEvent(QPaintEvent*) override;

	QColor color;
};

#endif