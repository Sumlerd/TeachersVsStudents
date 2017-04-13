#ifndef STUDENT_H
#define STUDENT_H

#include "character.h"
#include "classify.h"
#include "navigate.h"
#include <string>

class Student : public Character {
public:
	Student(navigate::Point, classify::Level);
};

class GrandStudent : public Student {
public:
	GrandStudent(navigate::Point);

	std::string toString();
};

class MasterStudent : public Student {
public:

	MasterStudent(navigate::Point);

	std::string toString();
};

class LightStudent : public Student {
public:

	LightStudent(navigate::Point);

	std::string toString();
};


class DarkStudent : public Student {
public:
	DarkStudent(navigate::Point);

	std::string toString();
};

#endif
