#pragma once
#include <iostream>
#include "Student.h"


class DataBase {

public:
	DataBase(std::string _path){ path = _path; }

	Student find(int);            // поиск по id
	Student find(std::string);    // поиск по одному из данных

	int append(Student);          // добавление в конец БД студента
	int update(Student);          // обновить запись о студенте
	int remove(Student);          // удалить студента
	int printAll();               // вывести всю бд

private:
	std::string path;             // путь до нужной папки
	std::ifstream fin;
	std::ofstream fout;

	int writeInFile(Student);     // записать в файл студента
	int createRB(Student);        // создать файл зачётки
	int getLastID();              // получить последний ID


};