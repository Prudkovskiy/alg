#pragma once

#include "file.h"
#include "simlink.h"


using namespace std;


class directory : public parent {
public:
	vector <file*> fil;
	vector <directory*> dir;
	vector <simlink*> sim;

	directory(string, string, vector<user*>, directory*);
	~directory();

	void add_file(user, file*);
	void add_directory(user, directory*);
	void add_simlink(user, simlink*);
	
	void show();
	
	void delete_fil(string);
	void delete_dir(string);
	void delete_sim(string);

	file* findfile(string);
	directory operator=(directory);//перегрузка

	directory(const directory&);
};

directory::directory(string dname = "default", string adr = "default", vector<user*> user, directory* dir = NULL) :
	parent(dname, adr, user, dir) 
{
}

directory::~directory() {
	sim.~vector();
	fil.~vector();
	for (int i = 0; i < dir.size(); i++)
		if (dir.size() == 0) {
			dir.~vector;
		}	
		else {
			dir[i]->~directory;
			dir.erase(dir.begin() + i);
		}
	cout << "dctor directory";
}

void directory::add_file(user us, file* f)
{
	int k = 0;
	while ((k < f->users.size()) && (us.name != f->users[k]->name))
		k++;
	if ((k != f->users.size()) || (us.get_adm == true))
		fil.push_back(f);
	else
		throw "that user can't create new file";
}

void directory::add_simlink(user us, simlink* siml) 
{
	int k = 0;
	while ((k < siml->users.size()) && (us.name != siml->users[k]->name))
		k++;
	if ((k != siml->users.size()) || (us.get_adm == true)) 
	{
		sim.push_back(siml);
	}	
	else
		throw "that user can't create new simlink";
}

void directory::add_directory(user us, directory* d)
{
	int k = 0;
	while ((k < d->users.size()) && (us.name != d->users[k]->name))
		k++;
	if ((k != d->users.size()) || (us.get_adm == true))
	{
		dir.push_back(d);
	}
	else
		throw "that user can't create new directory";
}


/*
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
*/

void directory::show() {
	cout << "files: " << endl;
	if (fil.size() == 0)
		cout << "EMPTY" << endl;
	else
		for (int i = 0; i < fil.size(); i++) {
			cout << fil[i]->name << endl;
		}

	cout << "simlinks: " << endl;
	if (sim.size() == 0)
		cout << "EMPTY" << endl;
	else
		for (int i = 0; i < sim.size(); i++) {
			cout << sim[i]->name << endl;
			cout << "файл, на который указывает ссылка" << endl;
			cout << sim[i]->link->name << endl;
		}

	cout << "directories: " << endl;
	if (dir.size() == 0)
		cout << "EMPTY" << endl;
	else
		for (int i = 0; i < dir.size(); i++) {
			cout << dir[i]->name << endl;
		}
}

void directory::delete_fil(string fname) {
	int k = 1;
	for (int i = 0; i < fil.size(); i++)
		if (fil[i]->name == fname) {
			fil[i]->~file;
			fil.erase(fil.begin() + i);
		}
		else k++;

	if (k == fil.size())
		throw "this file can't be found";
}

void directory::delete_sim(string sname) {
	int k = 1;
	for (int i = 0; i < sim.size(); i++)
		if (sim[i]->name == sname) {
			sim[i]->~simlink;
			sim.erase(sim.begin() + i);
		}
		else k++;

	if (k == sim.size())
		throw "this simlink can't be found";
}

void directory::delete_dir(string dname) {
	int k = 1;
	for (int i = 0; i < dir.size(); i++)
		if (dir[i]->name == dname) {
			dir[i]->~directory;
			dir.erase(dir.begin() + i);
		}
		else k++;

	if (k == dir.size())
		throw "this directory can't be found";
}

file* directory::findfile(string name) {  //поиск файла в папке рекурсией
	int k = 1;
	for (int i = 0; i < fil.size(); i++) {
		if (fil[i]->name == name)
			return fil[i];
		else k++;
	}

	int l = 1;
	if (k == fil.size)
		for (int i = 0; i < dir.size(); i++)
			if (dir[i]->findfile(name))
				return dir[i]->findfile(name);
			else l++;
	
			if (l == dir.size)
				throw "this file can't be found in that directory";
}

directory::directory(const directory& previous_directory) : parent((parent&)previous_directory)
{
	name = previous_directory.name;
	address = previous_directory.address;

	for (int i = 0; i < users.size(); i++)
		users[i] = previous_directory.users[i];
	for (int i = 0; i < dir.size(); i++) 
		dir[i] = previous_directory.dir[i];
	for (int i = 0; i < sim.size(); i++) 
		sim[i] = previous_directory.sim[i];
	for (int i = 0; i < fil.size(); i++) 
		fil[i] = previous_directory.fil[i];
}

directory directory::operator=(directory d)
{
	name = d.name;
	address = d.address;
	for (int i = 0; i < users.size(); i++)
		users[i] = d.users[i];
	for (int i = 0; i < dir.size(); i++)
		dir[i] = d.dir[i];
	for (int i = 0; i < sim.size(); i++)
		sim[i] = d.sim[i];
	for (int i = 0; i < fil.size(); i++)
		fil[i] = d.fil[i];

	return *this;
}