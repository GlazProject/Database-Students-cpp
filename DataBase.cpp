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
			if (stud.getName().find(value)!=-1)
				goodUsers.push_back(stud);
			break;
		case(3):                                            // create return groop
			if (stud.getName().find(value) != -1)
				goodUsers.push_back(stud);
			break;
		case(4):                                             // create return cpec
			if (stud.getName().find(value) != -1)
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

std::pair<std::string, std::string> parse(std::string command) {
	std::string coll = "", value = "";
	bool collIsReady = false;
	for (int j = 0; j < command.size(); j++) {
		if (command[j] != '=') {
			if (!collIsReady) coll += command[j];
			else value += command[j];
			continue;
		}
		collIsReady = true;
	}
	return std::make_pair(coll, value);
}

std::list<Student> DataBase::find(std::string commandStr)
{
	std::list<std::pair<std::string, std::string>> queueOfSelect;
	std::string command ="";
	for (int i = 0; i < commandStr.size(); i++) {
		if (commandStr[i] != ' ') {
			command += commandStr[i];
			continue;
		}

		queueOfSelect.push_back(parse(command));
	}
	if(command!="") queueOfSelect.push_back(parse(command));
	

	auto selected = findAll();
	for (auto p : queueOfSelect) {
		selected = find(p.first, p.second, selected);
	}
	return selected;
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