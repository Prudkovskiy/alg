// lab_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class numeric {
public:
	int number, limit;
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
};

class matrix {
	numeric ** p;
	int n,m;
public:
	matrix() {
		n = 1;
		m = 1;
		p = new numeric*[n];
		p[0] = new numeric[m];
	}

	matrix(int rows, int cols, int i) {
		n = rows;
		m = cols;
		p = new numeric*[n];
		for (int i = 0; i < n; i++)
			p[i] = new numeric[m];
		for (int i = 0; i < n; i++)
		{
			cout << i+1 << " raws" << endl;
			for (int j = 0; j < m; j++)
			{
				cin >> p[i][j].number;
			}
		}
	}
	
	matrix(int rows, int cols) {
		n = rows;
		m = cols;
		p = new numeric*[n];
		for (int i = 0; i < n; i++)
			p[i] = new numeric[m];
	}

	~matrix()
	{
		//cout << "vector dtor" << endl;
	}

	/*matrix& operator *(matrix& sch)
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
	}*/

	matrix& operator +(matrix& sch) {
		matrix matr(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matr.p[i][j].number =  sch.p[i][j].number + p[i][j].number;
			}
		}
		return matr;
	}
	void show();
};

void matrix::show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << p[i][j].number << " ";
		cout << "\n" << endl;
	}
}


int _tmain()
{
	int i = 0;
	int num, lim = 0;
	int N; //строки, столбцы
	
    cout << "n*n : N = ";
	cin >> N;
	matrix m1(N, N, i);
	cout << "your first matrix" << endl;
	m1.show();
	cout << "Next matrix"<<endl;
	matrix m2(N, N, i);
	cout<< "your second matrix" << endl;
	m2.show();
	matrix m3(N, N);
	m3 = m1 + m2;
	cout << "your third matrix" << endl;
	m3.show();

	
		

	system("pause");
	return 0;
}

