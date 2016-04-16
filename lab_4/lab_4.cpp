// lab_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class numeric {
public:
	int number;
	numeric() {
		number = 0;
	}
	~numeric() {}
	numeric(int k) {
		number = k;
		//cout << "Creating numeric" << endl;
	}
	numeric operator+(const numeric& op2) const
	{
		numeric temp;
		temp.number = number + op2.number;
		return temp;
	}

	numeric operator*(const numeric& op2) const
	{
		numeric temp;
		temp.number = number * op2.number;
		return temp;
	}

	void show() {
		cout << number;
	}
};

class matrix {
	numeric **p;
	int rows, cols;
public:
	matrix() {
		rows = 1;
		cols = 1;
		p = new numeric*[rows];
		p[0] = new numeric[cols];
	}

	matrix(int n, int m, int i) {
		rows = n;
		cols = m;
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
	
	matrix(int n, int m) {
		rows = n;
		cols = m;
		p = new numeric*[n];
		for (int i = 0; i < n; i++)
			p[i] = new numeric[m];
	}

	~matrix()
	{
		/*{
			for (int z = 0; z < rows; ++z)
				delete[] p[z];
			delete[] p;
		}*/
	}

	matrix operator *(matrix& sch) const
	{
		matrix temp(rows, rows);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < rows; j++) {
				temp.p[i][j].number = 0;
				for (int k = 0; k < rows; k++)
				{
					numeric dop = p[i][k] * sch(k, j);
					temp(i, j) = temp(i, j) + dop;
				}
			}
		return temp;
	}

	matrix operator *(const int num) const
	{
		matrix temp(cols, rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < cols; j++) {
				temp(i, j) = p[i][j].number * num;
			}
		return temp;
	}

	matrix operator +(matrix& sch) const {
		matrix matr(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matr(i, j) = sch(i, j) + p[i][j];
			}
		}
		return matr;
	}

	numeric& operator() (unsigned int i,unsigned int j){
		return p[i][j];
	}


	matrix transp(matrix& matr) {
		matrix matr1(cols, rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < rows; j++)
				matr1.p[i][j].number = matr.p[j][i].number;
		return matr1;
	}

	void show(int, int);
};

void matrix::show(int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << p[i][j].number << " ";
		cout << "\n" << endl;
	}
}

void Xhandler(matrix& matr, int n, int m, int limit) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			try {
				if (matr(i, j).number > limit)
					throw runtime_error("Bad index");
			}
			catch (runtime_error& e) {
				cout << "\nBAD INDEX:" << i << " " << j << endl;
			}
		}
	}
}

int _tmain()
{
	int i = 0; int j = 0;
	int num, lim = 10;
	int N, M; //строки, столбцы
	
    cout << "n*m : ROWS = ";
	cin >> N;
	cout << "      COLS = ";
	cin >> M;
	matrix m1(N, M, i);
	cout << "Your FIRST matrix" << endl;
	m1.show(N, M);
	Xhandler(m1, N, M, lim);

	cout << "\nNext matrix"<<endl;
	matrix m2(N, M, i);
	cout<< "\nYour SECOND matrix" << endl;
	m2.show(N, M);
	Xhandler(m2, N, M, lim);
	
	matrix mt(M, N);
	cout << "\nYour SECOND trans matrix" << endl;
	mt=m2.transp(m2);
	mt.show(M, N);
	Xhandler(mt, M, N, lim);
	
	matrix m3(N, N);
	m3 = m1 * mt;
	cout << "\nMatrix MULTIPLICATION" << endl;
	m3.show(N, N);
	Xhandler(m3, N, N, lim);

	matrix m4(N, N);
	cout << "\nMatrix MULTIPLICATION * NUMBER" << endl;
	cout << "NUMBER = ";
	cin >> i;
	m4 = m3 * i;
	m4.show(N, N);
	Xhandler(m4, N, N, lim);

	system("pause");
	return 0;
}

