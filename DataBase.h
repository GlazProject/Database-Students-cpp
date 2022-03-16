#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Student.h"

class DataBase {
public:
	DataBase(std::string path) { this->path = path; };
	std::list<Student> find(std::string coll, std::string value, std::list<Student> listToFind);
	std::list<Student> findAll();

	short append(Student student);    
	//short update(Student student);     
	//short remove(Student student);     
	short printAll();       

private:
	const int numberOfColumns = 3;
	const int sizeOfId = 10;
	const int sizeOfName = 50;

	std::string path;
	std::ifstream fin;
	std::ofstream fout;

	//int writeInFile(Student student); 
	//int createRB(Student);    
	int getLastID();             
};