#include "teacher.h"
#include "navigate.h"
#include "classify.h"
#include <string>

using std::string;
using navigate::Point;
using classify::Type;
using classify::Level;

Teacher::Teacher(Point position, Level level)
	: Character(position, level, classify::Teacher) {}

GrandTeacher::GrandTeacher(Point position)
	: Teacher(position, classify::Grand) {}

MasterTeacher::MasterTeacher(Point position)
	: Teacher(position, classify::Master) {}

LightTeacher::LightTeacher(Point position)
	: Teacher(position, classify::Light) {}

DarkTeacher::DarkTeacher(Point position)
	: Teacher(position, classify::Dark) {}

string GrandTeacher::toString() {
	return "./pic/ta.png";
}

string MasterTeacher::toString() {
	return "./pic/tb.png";
}

string LightTeacher::toString() {
	return "./pic/tc.png";
}

string DarkTeacher::toString() {
	return "./pic/td.png";
}
