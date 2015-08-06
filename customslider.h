#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QPainter>
#include <QStyleOptionSlider>

class CustomSlider : public QSlider {
public:
	CustomSlider(QWidget* p = nullptr) : QSlider(p), color("#3d3") {}

	void setColor(const QColor& c) {
		color = c;
	}

protected:
	void mousePressEvent(QMouseEvent* e) override  {
		if (e->button() == Qt::LeftButton){
			bool vertical = orientation() == Qt::Vertical;
			setValue(QStyle::sliderValueFromPosition(minimum(), maximum(), vertical?e->y():e->x(), vertical?height():width(), vertical));

			e->accept();
		}
		QSlider::mousePressEvent(e);
	}

	void mouseMoveEvent(QMouseEvent* e) override {
		bool vertical = orientation() == Qt::Vertical;
		setValue(QStyle::sliderValueFromPosition(minimum(), maximum(), vertical?e->y():e->x(), vertical?height():width(), vertical));

		e->accept();

		QSlider::mouseMoveEvent(e);
	}

	void paintEvent(QPaintEvent*) override {
		QPainter p(this);
		p.setPen(Qt::NoPen);

		QStyleOptionSlider style;
		style.init(this);

		bool hover = style.state & QStyle::State_MouseOver;
		auto& r = style.rect;

		if(hover) p.setBrush(QColor("#393939"));
		else p.setBrush(QColor("#333"));

		p.drawRect(r);

		if(hover) p.setBrush(color.lighter(120));
		else p.setBrush(color);

		if(orientation() == Qt::Vertical){
			auto nh = height()*value()/100;
			r.setY(height()-nh);
			r.setHeight(nh);
		}else{
			auto nh = width()*value()/100;
			r.setWidth(nh);			
		}

		p.drawRect(r);
	}

protected:
	QColor color;
};

#endif