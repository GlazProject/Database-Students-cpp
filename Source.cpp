#include <iostream>
#include "DataBase.h"

int main() {
	DataBase DB("students.cppDB");
	DB.printAll();
	Student st("tmp");
	DB.find("name", "anton", DB.findAll());
}