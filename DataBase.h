#pragma once
#include <iostream>
#include "Student.h"


class DataBase {

public:
	DataBase(std::string _path){ path = _path; }

	Student find(int);            // ����� �� id
	Student find(std::string);    // ����� �� ������ �� ������

	int append(Student);          // ���������� � ����� �� ��������
	int update(Student);          // �������� ������ � ��������
	int remove(Student);          // ������� ��������
	int printAll();               // ������� ��� ��

private:
	std::string path;             // ���� �� ������ �����
	std::ifstream fin;
	std::ofstream fout;

	int writeInFile(Student);     // �������� � ���� ��������
	int createRB(Student);        // ������� ���� �������
	int getLastID();              // �������� ��������� ID


};