#include <iostream>
#include <string>
#include "DataBase.h"

int DataBase::printAll() {
	fin.open("Students.cppDB");
	if (!fin.is_open()) {
		std::cout<<"Can not open DB"<<std::endl;
		return 1;
	}

	Student student;
	int count = 0;
	while (!fin.eof()) {
		fin >> student;
		count++;
		student.print();
	}

	fin.close();
	std::cout << "DB has got " << count << " positons" << std::endl;
}