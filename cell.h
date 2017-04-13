#ifndef CELL_H
#define CELL_H

#include <string>
#include <stdint.h>
#include "navigate.h"
#include "object.h"

using navigate::Point;

class Cell {
private:
	bool vacancy;


	Object* occupant;

public:
	Cell();
	Cell(Point);
	Cell(Point, Object*);
    Point position;
	Point getPosition() const;
	Object* getOccupant();

	bool isVacant() const;
	bool occupy(Object*);
	void vacate();

	virtual bool isAnimate();
	std::string toString();

	virtual ~Cell();
};
#endif
