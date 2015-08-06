#ifndef THING_H
#define THING_H

#include <QTabWidget>

class Thing : public QTabWidget {
	Q_OBJECT

public:
	Thing(QWidget* parent = nullptr);

private slots:
	void Blah1();
	void Blah2();

	void DialMoved(int);
};


#endif