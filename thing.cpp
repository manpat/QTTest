#include "moc_thing.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QSlider>
#include <QTabBar>
#include "customdial.h"
#include "customtabbar.h"
#include "customslider.h"

#include <iostream>

// http://zetcode.com/gui/qt4/layoutmanagement/

Thing::Thing(QWidget* parent) : QTabWidget(parent) {
	setTabBar(new CustomTabBar);
	tabBar()->setExpanding(true);
	tabBar()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

	auto tab1 = new QWidget();
	auto tab2 = new QWidget();
	auto tab3 = new QWidget();
	addTab(tab1, QIcon("icon1.png"), "");
	addTab(tab2, QIcon("icon3.png"), "");
	addTab(tab3, QIcon("icon2.png"), "");
	setTabPosition(South);

	auto hbox = new QHBoxLayout(tab1);
	auto rvbox = new QVBoxLayout();
	auto buttbox = new QHBoxLayout();
	auto dialbox = new QHBoxLayout();
	auto sliderbox = new QHBoxLayout();
	auto hsliderbox = new QVBoxLayout();

	hbox->setSpacing(1);
	rvbox->setSpacing(1);
	buttbox->setSpacing(1);
	sliderbox->setSpacing(1);
	hsliderbox->setSpacing(20);

	hbox->addStretch(1);
	hbox->addLayout(rvbox);

	auto dial1 = new CustomDial(this);
	auto dial2 = new CustomDial(this);
	auto dial3 = new CustomDial(this);
	dial1->setColor(QColor("#d33"));
	dial2->setColor(QColor("#3d3"));
	dial3->setColor(QColor("#33d"));
	dial1->setNotchesVisible(true);
	dial2->setNotchesVisible(true);
	dial3->setNotchesVisible(true);
	dial1->setNotchTarget(30.0);
	dial2->setNotchTarget(20.0);
	dial3->setNotchTarget(10.0);
	dial3->setValue(50);
	
	dialbox->addWidget(dial1);
	dialbox->addWidget(dial2);
	dialbox->addWidget(dial3);

	auto sl1 = new CustomSlider(this);
	auto sl2 = new CustomSlider(this);
	auto sl3 = new CustomSlider(this);
	auto sl4 = new CustomSlider(this);
	auto sl5 = new CustomSlider(this);
	auto sl6 = new CustomSlider(this);
	sl1->setMinimumHeight(200);
	sl2->setMinimumHeight(200);
	sl3->setMinimumHeight(200);
	sl4->setMinimumHeight(200);
	sl5->setOrientation(Qt::Horizontal);
	sl6->setOrientation(Qt::Horizontal);
	sl1->setValue(10);
	sl2->setValue(30);
	sl3->setValue(50);
	sl4->setValue(80);
	sl5->setValue(50);
	sl6->setValue(20);
	sl1->setColor("#3d3");
	sl5->setColor("#d33");
	sl6->setColor("#33d");

	sliderbox->addWidget(sl1);
	sliderbox->addWidget(sl2);
	sliderbox->addWidget(sl3);
	sliderbox->addWidget(sl4);
	hsliderbox->addWidget(sl5);
	hsliderbox->addWidget(sl6);

	auto butt1 = new QPushButton("Butt", this);
	auto butt2 = new QPushButton("Butt2", this);
	auto quitb = new QPushButton("FuckOff", this);

	butt1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	butt2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	quitb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	rvbox->addLayout(dialbox);
	rvbox->addLayout(sliderbox);
	rvbox->addStretch(1);
	rvbox->addLayout(hsliderbox);
	rvbox->addStretch(1);
	rvbox->addLayout(buttbox);

	buttbox->addWidget(butt1, 1, Qt::AlignRight);
	buttbox->addWidget(butt2, 0, Qt::AlignRight);
	buttbox->addWidget(quitb, 0, Qt::AlignRight);

	connect(butt1, SIGNAL(clicked()), this, SLOT(Blah1()));
	connect(butt1, SIGNAL(clicked()), this, SLOT(Blah2()));
	connect(butt2, SIGNAL(clicked()), this, SLOT(Blah2()));
	connect(quitb, SIGNAL(clicked()), qApp, SLOT(quit()));

	connect(dial1, SIGNAL(dialMoved(int)), this, SLOT(DialMoved(int)));
	connect(dial2, SIGNAL(dialMoved(int)), this, SLOT(DialMoved(int)));
}

void Thing::Blah1(){
	// std::cout << "Blah1" << std::endl;
}
void Thing::Blah2(){
	// std::cout << "Blah2" << std::endl;
}

void Thing::DialMoved(int v){
	// std::cout << "DialMoved " << v << std::endl;
}