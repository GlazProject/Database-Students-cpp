#include <iostream>
#include "DataBase.h"

int main() {
	DataBase DB("students.cppDB");
	DB.printAll();
	Student st("tmp");

	std::list<Student> selected = DB.find("name=Nikita");
	std::cout << "Selected students by \"name=Nikita\"" << std::endl;
	for (auto st : selected) {
		std::cout << st << std::endl;
	}
	std::cout << "The end" << std::endl;

}