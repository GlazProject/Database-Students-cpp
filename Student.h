#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Student {
public:
	Student(int id = 0, std::string name = "") {
		this->id = id;
		this->name = name;
	}

	Student(std::string name) {
		this->id = 0;
		this->name = name;
	}

	void print();                                                                       // ������ � ������� �������
	int getId() { return id; }                                                          // ������� ID
	std::string getName() { return name; }                                              // ������� ���

	friend std::istream& operator>>(std::istream& os, Student& student);     // ���������� �� �������
	friend std::ostream& operator<<(std::ostream& os, Student& student);     // ������ � �������
	friend std::ifstream& operator>>(std::ifstream& os, Student& student);   // считывание из файла
	friend std::ofstream& operator<<(std::ofstream& os, Student& student);   // запись в файл

private:
	int id;
	int groopId;
	std::string spec;
	std::string name;

};