#pragma once
#include <iostream>
#include <fstream>

class Student {

private:
	int id;
	int const q = 2;
	std::string name;

public:
	Student(int _id, std::string _name) {
		id = _id;
		name = _name;
	}

	Student(std::string _name) {
		id = 0;
		name = _name;
	}

	Student() {
		id = 0;
		name = "";
	}

	void print();                                                                        // печать в консоль красиво
	int _id() { return id; }                                                             // вернуть ID
	int const _size() { return q; }                                                      // вернуть кличесво полей структуры
	std::string _name() { return name; }                                                 // вернуть ФИО
	
	friend std::istream& operator>>(const std::istream& os, const Student& student);     // считывание из консоли
	friend std::ostream& operator<<(const std::ostream& os, const Student& student);     // запись в консоль
	friend std::ifstream& operator>>(const std::ifstream& os, const Student& student);   // считывание из файла
	friend std::ofstream& operator<<(const std::ofstream& os, const Student& student);   // запись в файл
};