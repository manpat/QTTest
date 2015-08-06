INCLUDES=-I/usr/include/qt4 $(foreach d,$(wildcard /usr/include/qt4/*),-I$(d))
LIBS=-lQtGui -lQtCore 
FLAGS=-std=c++11 -Wall

MOC := $(shell find . -name "moc_*")
SRC := $(shell find . -name "*.cpp") $(MOC:%.h=%.cpp)
OBJ := $(SRC:%.cpp=%.o)

build: $(OBJ)
	@g++ $^ -obuild $(LIBS)

moc_%.cpp: moc_%.h
	@echo "-- Generating $@ --"
	@moc-qt4 $(INCLUDES) $^ -o$@

moc_%.cpp: moc_%.h %.cpp
	@echo "-- Generating $@ --"
	@moc-qt4 $(INCLUDES) $^ -o$@

%.o: %.cpp
	@echo "-- Building $@ --"
	@g++ $(FLAGS) -c $< $(INCLUDES)

run: build
	@echo "-- Running --"
	@./build