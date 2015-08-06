#include "customdial.h"
#include <QPainter>
#include <QStyleOptionSlider>

CustomDial::CustomDial(QWidget* p) : QDial(p), color("#3d3"){

}

#include <iostream>
void CustomDial::setColor(const QColor& c){
	color = c;
}

void CustomDial::paintEvent(QPaintEvent*){
	QPainter p(this);

	QStyleOptionSlider tab;
	tab.init(this);

	bool hover = tab.state & QStyle::State_MouseOver;

	p.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
	QBrush brush("#333");
	if(hover) brush.setColor("#393939");

	p.setPen(Qt::NoPen);
	p.setBrush(brush);
	p.drawPie(20, 20, width()-20*2, height()-20*2, (220)*16, -(360-100)*16);

	if(hover) p.setPen(QPen(color.lighter(120), 15));
	else p.setPen(QPen(color, 15));

	p.drawArc(10, 10, width()-10*2, height()-10*2, 220*16, -(360-100)*16*value()/100);
}
