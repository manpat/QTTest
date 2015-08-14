#ifndef THING_H
#define THING_H

#include <QTabWidget>

class CustomSlider;

class Thing : public QTabWidget {
	Q_OBJECT

public:
	Thing(QWidget* parent = nullptr);

protected:
	CustomSlider* sl1;

private slots:
	void Blah1();
	void Blah2();

	void DialMoved(int);
};


#endif