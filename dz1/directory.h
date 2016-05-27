#pragma once

#include <vector>

#include "file.h"
#include "simlink.h"

using namespace std;


class directory : public parent {
	vector <string> inf;
public:
	vector <file*> fil;
	vector <directory*> dir;
	vector <simlink*> sim;

	directory(string, string);
	~directory();
	string getname() { return name; };
	void del() { (*this).~directory(); }
	void add(string user);
	void show();
	void deletedir(string);
	file* findfile(string);
	directory copy(string user);
};

directory::directory(string user, string fname = "default") : parent(user, fname) {}

directory::~directory() { fil.clear(); dir.clear(); sim.clear(); cout << "dctor directory"; }

void directory::add(string user) {
	char command[10];
	string name;
	string dat;

	cout << "добавить файл - fil" << endl;
	cout << "добавить символическую ссылку - sim" << endl;
	cout << "добавить папку - dir" << endl;

	scanf("%s", &command);
	switch (command[0]) {
	case 'f':
	{
		cout << "name of file: ";
		cin >> name;
		cout << "text: ";
		cin >> dat;
		file* f = new file(user, name, dat);
		fil.push_back(f);
	}
	break;

	case 's':
	{
		cout << "name of simlink: ";
		cin >> name;
		cout << "введите имя файла на который хотите указывать" << endl;
		string fname;
		cin >> fname;
		file* f = findfile(fname);
		simlink* s = new simlink(user, f, name);
		sim.push_back(s);
	}
	break;

	case 'd':
	{
		cout << "name of directory: ";
		cin >> name;
		directory* d = new directory(user, name);
		dir.push_back(d);
	}
	break;

	default:
		break;
	}
}

void directory::show() {
	cout << "files: " << endl;
	if (fil.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < fil.size(); i++) {
			cout << fil[i]->getname() << endl;
		}

	cout << "simlinks: " << endl;
	if (sim.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < sim.size(); i++) {
			cout << sim[i]->getname() << endl;
			cout << "файл, на который указывает ссылка" << endl;
			cout << sim[i]->link->name << endl;
		}

	cout << "directories: " << endl;
	if (dir.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < dir.size(); i++) {
			cout << dir[i]->getname() << endl;
		}
}

void directory::deletedir(string name) { //удаление директории 

	for (int i = 0; i < fil.size(); i++)
		fil[i]->del();

	for (int i = 0; i < sim.size(); i++)
		sim[i]->del();

	for (int i = 0; i < dir.size(); i++)
		if (dir.size() == 0)
			del();
		else
			deletedir(dir[i]->getname());
}

file* directory::findfile(string name) {  //поиск файла в папке рекурсией
		for (int i = 0; i < fil.size(); i++)
			if (fil[i]->name == name) {
				return fil[i];
			}
		for (int i = 0; i < dir.size(); i++)
			if (dir[i]->findfile(name))
				return dir[i]->findfile(name);
		return 0;
}

directory directory::copy(string user) { //копия директорий
	directory d(user);
	for (int i = 0; i < dir.size(); i++) {
		d.dir[i] = dir[i];
	}
	for (int i = 0; i < sim.size(); i++) {
		d.sim[i] = sim[i];
	}
	for (int i = 0; i < fil.size(); i++) {
		d.fil[i] = fil[i];
	}
	return d;
}