#include "student.h"
#include "classify.h"
#include <string>

using std::string;
using navigate::Point;
using classify::Type;
using classify::Level;

Student::Student(Point position, Level level)
	: Character(position, level, classify::Student) {}

GrandStudent::GrandStudent(Point position)
	: Student(position, classify::Grand) {}

MasterStudent::MasterStudent(Point position)
	: Student(position, classify::Master) {}

LightStudent::LightStudent(Point position)
	: Student(position, classify::Light) {}

DarkStudent::DarkStudent(Point position)
	: Student(position, classify::Dark) {}

string GrandStudent::toString() {
	return "./pic/sa.png";
}

string MasterStudent::toString() {
	return "./pic/sb.png";
}

string LightStudent::toString() {
	return "./pic/sc.png";
}

string DarkStudent::toString() {
	return "./pic/sd.png";
}
