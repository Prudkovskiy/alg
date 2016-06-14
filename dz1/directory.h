#pragma once

#include "file.h"
#include "simlink.h"


using namespace std;


class directory : public parent {
public:
	vector <file*> fil;
	vector <directory*> dir;
	vector <simlink*> sim;

	directory(string, address*, vector<user*>);
	~directory();

	void add_file(file*);
	void add_directory(directory*);
	void add_simlink(simlink*);
	void add_user(user*);

	void show();
	void show_All(int);

	void delete_fil(user*, string);
	void delete_dir(user*, string);
	void delete_sim(user*, string);

	directory* get_in(user*, string);
	directory* get_out();
	directory* get_on_start();

	file* findfile(string);

	directory(const directory&);
	void del() { this->~directory(); }
	string show_address();
};

directory::directory(string dname = "default", address* adr = NULL, vector<user*> users_ = vector<user*>()) :
	parent(dname, adr, users_) 
{
}

directory::~directory() {
	for (int i = 0; i < dir.size(); i++)
		delete dir[i];
	for (int i = 0; i < fil.size(); i++)
		delete fil[i];
	for (int i = 0; i < sim.size(); i++)
		delete sim[i];
	cout << " dctor directory ";
}

void directory::add_file(file* f)
{
		fil.push_back(f);
}

void directory::add_simlink(simlink* siml) 
{
		sim.push_back(siml);
}

void directory::add_directory(directory* d)
{
		dir.push_back(d);
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
	cout << this->show_address() << endl;
		for (int i = 0; i < fil.size(); i++) {
			cout << fil[i]->name << ".fil" << endl;
		}

		for (int i = 0; i < sim.size(); i++) {
			directory* d = sim[i]->link->adr->way[sim[i]->link->adr->way.size() - 1];
			string adr = d->show_address() + d->name + "/";
			cout << sim[i]->name << ".sim" << "  pointed on  " << adr << sim[i]->link->name << ".fil" << endl;
		}

		for (int i = 0; i < dir.size(); i++) {
			cout << dir[i]->name << ".dir" << endl;
		}
}

void directory::show_All(int step) {
	for (int i = 0; i < fil.size(); i++) {
		for (int k = 0; k < step; k++)
			cout << "  ";
		cout << fil[i]->name << ".fil" << endl;
	}

	for (int i = 0; i < sim.size(); i++) {
		directory* d = sim[i]->link->adr->way[sim[i]->link->adr->way.size() - 1];
		string adr = d->show_address() + d->name + "/";
		for (int k = 0; k < step; k++)
			cout << "  ";
		cout << sim[i]->name << ".sim" << "  pointed on  " << adr << sim[i]->link->name << ".fil" << endl;
	}

	for (int i = 0; i < dir.size(); i++) {
		for (int k = 0; k < step; k++)
			cout << "  ";
		cout << dir[i]->name << ".dir" << endl;
		dir[i]->show_All(step + 1);
	}
}

void directory::delete_fil(user* us, string fname) {
	int m = 0;
	for (int i = 0; i < fil.size(); i++)
		if (fil[i]->name == fname)
		{
			int k = 0;
			for (int l = 0; l < fil[i]->users.size(); l++)
				if (us->name != fil[i]->users[l]->name)
					k++;
			if ((k != fil[i]->users.size()) || (us->get_adm() == true))
			{
				fil[i]->del();
				fil.erase(fil.begin() + i);
			}
			else
				throw "that user can't delete that file";
		}
		else m++;

		if (m == sim.size())
			throw "that file can't be found";
}

void directory::delete_sim(user* us, string sname) {
	int m = 0;
	for (int i = 0; i < sim.size(); i++)
		if (sim[i]->name == sname)
		{
			int k = 0;
			for (int l = 0; l < sim[i]->users.size(); l++)
				if (us->name != sim[i]->users[l]->name)
					k++;
			if ((k != sim[i]->users.size()) || (us->get_adm() == true))
			{
				sim[i]->del();
				sim.erase(sim.begin() + i);
			}
			else
				throw "that user can't delete that simlink";
		}
		else m++;

		if (m == sim.size())
			throw "that simlink can't be found";
}

void directory::delete_dir(user* us, string dname) {
	int m = 0;
	for (int i = 0; i < dir.size(); i++)
		if (dir[i]->name == dname)
		{
			int k = 0;
			for (int l = 0; l < dir[i]->users.size(); l++)
				if (us->name != dir[i]->users[l]->name)
					k++;
			if ((k != dir[i]->users.size()) || (us->get_adm() == true))
			{
				dir[i]->del();
				dir.erase(dir.begin() + i);
			}
			else
				throw "that user can't delete that directory";
		}
		else m++;

		if (m == dir.size())
			throw "that directory can't be found";
}

void directory::add_user(user* us) {
	users.push_back(us);
}

directory* directory::get_in(user* us, string dname) {
	int l = 0;
	for (int i = 0; i < dir.size(); i++)
		if (dir[i]->name == dname) {
			int k = 0;
			while ((k < dir[i]->users.size()) && (us->name != dir[i]->users[k]->name))
				k++;
			if ((k != dir[i]->users.size()) || (us->get_adm() == true))
			{
				return dir[i];
			}
			else
				throw "that user can't open that directory";
		}
		else l++;

		if (l == dir.size())
			throw "that directory can't be found";
}

directory* directory::get_out() {
	if (this->adr->way.size() >= 2)
		return this->adr->way[this->adr->way.size()-2];
	else {
		throw "you can't move out of that directory! It's start directory!";
		return this;
	}
}

directory* directory::get_on_start() {
	return this->adr->way[0];
}

file* directory::findfile(string name) {  //recursion find_file
	int k = 0;
	for (int i = 0; i < fil.size(); i++)
		if (fil[i]->name == name) {
			address* a = this->adr;
			a->way.push_back(this);
			fil[i]->adr = a;
			return fil[i];
		}
		else k++; 

	int l = 0;
	if (k == fil.size()) {
		for (int i = 0; i < dir.size(); i++)
			if (dir[i]->findfile(name))
				return dir[i]->findfile(name);
			else l++;
	}
		if (l == dir.size())
			throw "this file can't be found in that directory";
}

directory::directory(const directory& previous_directory) : parent((parent&)previous_directory)
{
	for (int i = 0; i < dir.size(); i++) 
		dir[i] = previous_directory.dir[i];
	for (int i = 0; i < sim.size(); i++) 
		sim[i] = previous_directory.sim[i];
	for (int i = 0; i < fil.size(); i++) 
		fil[i] = previous_directory.fil[i];
}

string directory::show_address() {
	string a;
	for (int i = 0; i < adr->way.size(); i++)
		a = a + adr->way[i]->name + "/";
	return a;
}

/*directory& directory::operator=(directory& d)
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
}*/