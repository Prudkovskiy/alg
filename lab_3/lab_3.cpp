#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class school {
protected:
	string name;
	int number;
public:
	school() {
		name = "default";
		number = 0;
	}
	~school(){}
	school(string s, int k) {
		name = s;
		number = k;
		//cout << "Creating School" << endl;
	}
	virtual void show() = 0;
};

class director : public school {
protected:
	string direct;
public:
	director() : school() {
		direct = "default";
	}
	virtual ~director() {
		//cout << "director dtor" << endl;
	}
	director(string s, int count, string dir) : school(s, count) {
		direct = dir;
		//cout << "Creating Public School" << endl;
	}
	void show();
};

class specialschool : public director {
protected:
	string speciality;
public:
	specialschool() : director() {
		speciality = "default";
	}
	~specialschool() {
		//cout << "specialschool dtor" << endl;
	}
	specialschool(string s, int count, string dir) : director(s, count, dir) {
		//cout << "Creating Special School" << endl;
	}
	void show();

	specialschool& operator=(string s) {
		speciality = s;
		return *this;
	}

	string getname() {
		return name;
	}
};

class Vector {
	specialschool *p;
	int n;
public:
	Vector() {
		n = 1;
		p = new specialschool[n];
	}

	~Vector()
	{
		//cout << "vector dtor" << endl;
	}

	int getcount() {
		return n;
	}

	specialschool& operator[](int index)
	{
		return p[index];
	}

	Vector& operator +(specialschool& sch)
	{
		n++;
		specialschool *save;
		save = p;
		p = new specialschool[n];
		for (int i = 0; i < n - 1; i++)
			p[i] = save[i];
		p[n - 2] = sch;
		return *this;
	}

	Vector& operator -(specialschool& sch)
	{
		int k = -1;
		for (int i = 0; i < n - 1; i++)
			if (p[i].getname() == sch.getname()) {
				k = i;
			}

		if (k != -1) {
			n--;
			specialschool *save;
			save = p;
			p = new specialschool[n];
			for (int i = 0; i < n - 1; i++)
				if (i < k) p[i] = save[i];
				else p[i] = save[i + 1];
		}
		return *this;
	}

	Vector& operator &(Vector& sch)
	{
		Vector temp;
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < sch.n - 1; j++)
				if (p[i].getname() == sch.p[j].getname())
					temp + p[i];
		return temp;
	}

	Vector& operator |(Vector& sch)
	{
		Vector temp, peresech;
		for (int i = 0; i < n - 1; i++)
			temp + p[i];
		for (int j = 0; j < sch.n - 1; j++)
			temp + sch.p[j];

		peresech = *this & sch;
		for (int k = 0; k < peresech.n - 1; k++)
			temp - peresech.p[k];
		return temp;
	}

	void show();
};

class functor {
	Vector temp;
public:
	void operator()(Vector a, Vector b) {
		temp = a & b;
		cout << "\nI'm functor!!!" << endl;
		cout << "number of schools Vector1 & Vector2 = " << temp.getcount()-1 << endl;
	}
};

void director::show() {
	cout << "\nSchool " << name << endl;
	cout << "Director " << direct << endl;
	cout << "number of students = " << number << endl;
}

void specialschool::show() {
	cout << "\nSchool " << name << endl;
	cout << "Director " << direct << endl;
	cout << "number of students = " << number << endl;
	cout << "Speciality: " << speciality << endl;
}

void Vector::show() {
	for (int i = 0; i < n - 1; i++)
		p[i].show();
}

int _tmain()
{
	string name, speciality, direct, c = "ok";
	int num;
	Vector v, v1, v2, v3;

	specialschool* b = new specialschool;
	director* a = b;
	delete a;

	
	while (c == "ok")
	{
		cout << "add object -> '+' or clean object -> '-' " << endl;
		cin >> c;

		if (c == "+") {
			cout << "\nSchool             "; cin >> name;
			cout << "Director             "; cin >> direct;
			cout << "Count of students    "; cin >> num;
			cout << "Speciality           "; cin >> speciality;
			specialschool g(name, num, direct);
			g = speciality;
			v = v + g;

			cout << "\nSchool             "; cin >> name;
			cout << "Director             "; cin >> direct;
			cout << "Count of students    "; cin >> num;
			cout << "Speciality           "; cin >> speciality;
			specialschool l(name, num, direct);
			g = speciality;
			v1 = v1 + l;
		}
		if (c == "-") {
			cout << "\nSchool               "; cin >> name;
			specialschool g(name, num, direct);
			g = speciality;
			v = v - g;

			cout << "\nSchool               "; cin >> name;
			specialschool l(name, num, direct);
			g = speciality;
			v1 = v1 - l;
		}
		cout << "if you want to continue, enter 'ok' " << endl;
		cin >> c;
	}

	v2 = v & v1;
	v3 = v | v1;
	functor f;
	f(v, v1);

	//v[0].show();
	//v2[0].show();

	cout << "\nVECTOR1" << endl;
	v.show();
	cout << "\nVECTOR2" << endl;
	v1.show();
	cout << "\nVECTOR1 & VECTOR2" << endl;
	v2.show();
	cout << "\nVECTOR1 | VECTOR2" << endl;
	v3.show(); 
	system("pause");
	return 0;
}