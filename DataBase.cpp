#include <iostream>
#include <string>
#include "DataBase.h"

int DataBase::printAll() {
	fin.open(path);
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
	return 0;
}

int DataBase::writeInFile(Student student)
{
	fin.open(path);
	char a; fin >> a;
	bool isNewDB = false;
	if (a == NULL || !fin.is_open()) isNewDB = true;
	fin.close();

	fout.open(path, std::ios_base::app);
	if (!isNewDB) { fout << std::endl; }
	fout << student;
	fout.close();
	return 0;
}

int DataBase::createRB(Student student)
{
	std::string filename = "RecordBooks\\RB_";
	filename += std::to_string(student._id())+".txt";
	fout.open(filename);
	fout << student._id() << "	" << student._name();
	fout.close();
}

int DataBase::getLastID()
{
	fin.open(path);
	if (!fin.is_open()) return 0;
	
}
