#include "Student.h"

void Student::print() {
	std::cout << "------------------------------------------------------------------------------------------\n";
	std::cout << "| Student id #" << this->getId() << "\n\t 		Student name: " << this->getName() << std::endl;
	std::cout << "|\n------------------------------------------------------------------------------------------\n\n";
}

std::istream& operator>>(std::istream& os, Student& student)
{
	int id; os >> id;
	std::string name = "", tmp;
	os >> tmp;
	name += tmp + " ";
	os >> tmp;
	name += tmp;
	student.id = id;
	student.name = name;
	return os;
}

std::ostream& operator<<(std::ostream& os, Student& student)
{
	os << student.id << "	" << student.name;
	return os;
}

std::ifstream& operator>>(std::ifstream& os, Student& student)
{
	int id; os >> id;
	std::string name = "", tmp;
	os >> tmp;
	name += tmp + " ";
	os >> tmp;
	name += tmp;
	student.id = id;
	student.name = name;
	return os;
}

std::ofstream& operator<<(std::ofstream& os, Student& student)
{
	os << student.id << "	" << student.name;
	return os;
}
