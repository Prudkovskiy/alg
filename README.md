# alg

// lab_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class numeric {
	int number, limit;
public:
	numeric() {
		number = 0;
		limit = 0;
	}
	~numeric() {}
	numeric(int k, int l) {
		number = k;
		limit = l;
		//cout << "Creating numeric" << endl;
	}
	numeric& operator+(numeric& op2)
	{
		numeric temp;
		temp.number = number + op2.number;
		return temp;
	}

	numeric& operator*(numeric& op2)
	{
		numeric temp;
		temp.number = number * op2.number;
		return temp;
	}

	void show();
};

class matrix {
	numeric ** p;
	int n,m;
public:
	matrix() {
		n = 1;
		m = 1;
		*p = new numeric[n,m];
	}

	matrix(int rows, int cols) {
		n = rows;
		m = cols;
		for (int i = 0; i < rows - 1; i++)
		{
			for (int j = 0; j < cols - 1; j++) {
				p[n,m] = p[rows, cols]
			}
	}

	~matrix()
	{
		//cout << "vector dtor" << endl;
	}

	/*Vector& operator +(numeric& sch)
	{
		n++;
		numeric *save;
		save = p;
		p = new numeric[n];
		for (int i = 0; i < n - 1; i++)
			p[i] = save[i];
		p[n - 2] = sch;
		return *this;
	} */

	numeric& operator[](int index)
	{
		return p[index];
	}

	matrix& operator *(matrix& sch)
	{
		matrix temp; numeric comp;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < sch.n - 1; j++) {
				comp = p[i] * sch.p[j];
			    temp.p[i] = temp.p[i] + comp;
			}
		}
		return temp;
	}

	void show();
};

void Vector::show() {
	for (int i = 0; i < n - 1; i++)
		p[i].show();
	cout << "\n" << endl;
}

void numeric::show() {
	cout << number << endl;
}

int _tmain()
{
	int num, lim = 0;
	int N; //строки, столбцы
	matrix m1, m2, m3;

	cout << "n*n : N = ";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cout << i << " string" << endl;
		for (int j = 0; j < N; j++)
		{
			cin >> m1.
		}
	}
			cout << "Number mat1 = "; cin >> num;
			numeric a(num, lim);
			v1 = v1 + a;

			cout << "Number mat2 = "; cin >> num;
			numeric b(num, lim);
			v2 = v2 + b;
		
		cout << "if you want to continue, enter 'ok' " << endl;
		cin >> c;
	}

	//v3 = v1 * v2;
	v1.show();
	v2.show();
	v3.show();

	//v[0].show();
	//v2[0].show();

	system("pause");
	return 0;
}
