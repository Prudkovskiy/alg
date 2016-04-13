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
		{
			for (int z = 0; z < rows; ++z)
				delete[] p[z];
			delete[] p;
		}
	}

	matrix operator *(matrix& sch)
	{
		matrix temp(cols, rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < cols; j++) {
				temp.p[i][j].number = 0;
				for (int k = 0; k < rows; k++)
				{
					numeric dop = p[i][k] * sch.p[k][j];
					temp.p[i][j] = temp.p[i][j] + dop;
				}
			}
		return temp;
	}

	matrix operator *(const int& num) const
	{
		matrix temp(cols, rows);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < cols; j++) {
				temp.p[i][j].number = p[i][j].number * num;
			}
		return temp;
	}

	matrix operator +(const matrix& sch) const {
		matrix matr(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matr.p[i][j] =  sch.p[i][j] + p[i][j];//matr(i,j) =  sch.p[i][j] + p[i][j];
			}
		}
		return matr;
	}

	numeric operator() (unsigned int i,unsigned int j){
		return p[i][j];
	}


	matrix& transp(matrix& matr) {
		matrix matr1(cols, rows);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matr1.p[i][j].number = matr.p[j][i].number;
		return matr1;
	}

	void show();
};

void matrix::show() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << p[i][j].number << " ";
		cout << "\n" << endl;
	}
}


int _tmain()
{
	int i = 0; int j = 0;
	int num, lim = 0;
	int N, M; //строки, столбцы
	
    cout << "n*m : ROWS = ";
	cin >> N;
	cout << "      COLS = ";
	cin >> M;
	matrix m1(N, M, i);
	cout << "Your FIRST matrix" << endl;
	m1.show();

	cout << "\nNext matrix"<<endl;
	matrix m2(N, M, i);
	cout<< "\nYour SECOND matrix" << endl;
	m2.show();
	
	matrix mt(M, N);
	cout << "\nYour SECOND trans matrix" << endl;
	mt=m2.transp(m2);
	mt.show();
	
	matrix m3(N, N);
	m3 = m1 * mt;
	cout << "\nMatrix MULTIPLICATION" << endl;
	m3.show();

	matrix m4(N, N);
	cout << "\nMatrix MULTIPLICATION * NUMBER" << endl;
	cout << "NUMBER = ";
	cin >> i;
	m4 = m3 * i;
	m4.show();

	m4.p[i][j].show();

	system("pause");
	return 0;
}

