#pragma once
#include <iostream>
#include <fstream>

class Student {
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

	void print();                                                           // ������ � ������� �������
	int _id() { return id; }                                                // ������� ID
	int const _size() { return q; }                                         // ������� �������� ����� ���������
	std::string _name() { return name; }                                    // ������� ���
	
	friend std::istream& operator>>(std::istream& os, Student& student);     // ���������� �� �������
	friend std::ostream& operator<<(std::ostream& os, Student& student);     // ������ � �������
	friend std::ifstream& operator>>(std::ifstream& os, Student& student);   // ���������� �� �����
	friend std::ofstream& operator<<(std::ofstream& os, Student& student);   // ������ � ����

private:
	int id;
	int const q = 2;
	std::string name;
};