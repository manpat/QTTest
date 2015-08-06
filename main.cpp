#include <QApplication>
#include <fstream>
#include <string>
#include "moc_thing.h"

int main(int argc, char** argv){
	QApplication a(argc, argv);

	std::ifstream f("stylesheet.css");

	f.seekg(0, f.end);
	std::string css(f.tellg(), ' ');
	f.seekg(0, f.beg);

	f.read(&css[0], css.size());
	f.close();

	a.setStyleSheet(css.data());

	Thing window;

	window.resize(800, 600);
	window.setWindowOpacity(1.0);
	window.setWindowTitle("Fuck");
	window.show();

	return a.exec();
}