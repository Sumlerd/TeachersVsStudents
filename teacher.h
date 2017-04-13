#ifndef TEACHER_H
#define TEACHER_H

#include "character.h"
#include "classify.h"
#include "navigate.h"
#include <string>

class Teacher : public Character {
public:
	Teacher(navigate::Point, classify::Level);
};

class GrandTeacher : public Teacher {
public:
	GrandTeacher(navigate::Point);

	std::string toString();
};

class MasterTeacher : public Teacher {
public:
	MasterTeacher(navigate::Point);

	std::string toString();
};

class LightTeacher : public Teacher {
public:
	LightTeacher(navigate::Point);

	std::string toString();
};

class DarkTeacher : public Teacher {
public:
	DarkTeacher(navigate::Point);

	std::string toString();
};

#endif

