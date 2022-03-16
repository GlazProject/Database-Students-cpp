#include "DataBase.h"

short DataBase::printAll() {
	fin.open(this->path);
	if (!fin.is_open()) {
		std::cerr << "Cannot open DB" << std::endl;
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

int DataBase::getLastID() {
	fin.open(this->path);
	if (!fin.is_open()) {
		std::cerr << "Cannot open DB" << std::endl;
		return -1;
	}

	int id;
	char ch = ' ';
	fin.seekg(-(sizeOfId + sizeOfName + 2), std::ios_base::end);

	std::string buff;
	std::getline(fin, buff);
	id = buff.substr(0, sizeOfId).empty() ? 1 : std::stoi(buff.substr(0, sizeOfId));


	fin.close();
	return id;
}

int convert(std::string coll) {
	if (coll == "id") return 1;
	if (coll == "name") return 2;
	if (coll == "groop") return 3;
	if (coll == "specialization") return 4;
	return 0;
}

std::list<Student> DataBase::find(std::string coll, std::string value, std::list<Student> listToFind)
{
	std::list<Student> goodUsers;
	int collID = convert(coll);
	if(collID == 0){}

	for (Student stud : listToFind) {
		switch (collID)
		{
		case (1):
			if (stud.getId() == std::stoi(value))
				goodUsers.push_back(stud);
			break;
		case(2):
			if (stud.getName() == value)
				goodUsers.push_back(stud);
			break;
		case(3):                                            // create return groop
			if (stud.getName() == value)
				goodUsers.push_back(stud);
			break;
		case(4):                                             // create return cpec
			if (stud.getName() == value)
				goodUsers.push_back(stud);
			break;
		}
	}

	return goodUsers;
}

std::list<Student> DataBase::findAll()
{
	std::list<Student> allUsers;
	Student tmpStudent;

	fin.open(this->path);
	if (!fin.is_open()) {
		std::cerr << "Cannot open DB" << std::endl;
		return allUsers;
	}

	while (!fin.eof()) {
		fin >> tmpStudent;
		allUsers.push_back(tmpStudent);
	}

	fin.close();
	return allUsers;
}

short DataBase::append(Student student) {
	fout.open(this->path, std::ios::app);
	if (!fout.is_open()) {
		std::cerr << "Cannot open DB" << std::endl;
		return 1;
	}

	std::string id = std::to_string(getLastID() + 1);
	std::string name = student.getName();
	for (int i = id.length(); i < sizeOfId; i++) {
		id += ' ';
	}
	for (int i = name.length(); i < sizeOfName; i++) {
		name += ' ';
	}

	fout << id << name << '\n';

	fout.close();
	return 0;
}