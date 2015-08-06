#ifndef CUSTOMTABBAR_H
#define CUSTOMTABBAR_H

#include <QTabBar>
#include <QPainter>
#include <QIcon>
#include <QStyleOptionTabV2>

class CustomTabBar : public QTabBar {
public:
	CustomTabBar(QWidget* p = nullptr) : QTabBar(p){
		setExpanding(true);
	}

protected:
	void paintEvent(QPaintEvent*) override{
		QPainter p(this);
		p.setRenderHint(QPainter::Antialiasing);
		p.setPen(Qt::NoPen);
		p.setBrush(Qt::NoBrush);

		for(int i = 0; i < count(); i++){
			QStyleOptionTabV2 tab;
			initStyleOption(&tab, i);
			bool selected = tab.state & QStyle::State_Selected;
			bool hover = tab.state & QStyle::State_MouseOver;

			auto r = tab.rect;

			QLinearGradient grad(r.topLeft(), r.bottomLeft());
			grad.setColorAt(0, "#222");
			if(selected){
				grad.setColorAt(0.9, "#222");
				grad.setColorAt(0.901, "#555");
			}else if(hover){
				grad.setColorAt(0.899, "#222");
				grad.setColorAt(0.9, "#454545");
			}else{
				grad.setColorAt(0.949, "#222");
				grad.setColorAt(0.95, "#444");				
			}

			p.fillRect(r, grad);

			r.adjust(6, 6, -6, -6); // scale

			tabIcon(i).paint(&p, r, Qt::AlignTop | Qt::AlignHCenter);
		}
	}
};

#endif