#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <class type>
class matrix {
	type **p;
	int rows, cols, limit;
public:
	matrix() {
		rows = 1;
		cols = 1;
		p = new type*[rows];
		p[0] = new type[cols];
	}

	matrix(int n, int m, int lim, int i) {
		rows = n;
		cols = m;
		limit = lim;
		p = new type*[n];
		for (int i = 0; i < n; i++)
			p[i] = new type[m];
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " raws" << endl;
			for (int j = 0; j < m; j++)
			{
				cin >> p[i][j];
			}
		}
	}

	matrix(int n, int m, int lim) {
		rows = n;
		cols = m;
		limit = lim;
		p = new type*[n];
		for (int i = 0; i < n; i++)
			p[i] = new type[m];
	}

	~matrix() {
		/*for (int i = 0; i < rows; i++)
			delete[] p[i];
		delete[] p;
		cout << "dctor" << endl;*/
	}

	matrix operator *(matrix& matr2) const
	{
		matrix temp(rows, matr2.cols, limit);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < matr2.cols; j++) {
				temp(i, j) = 0;
				for (int k = 0; k < cols; k++)
					temp(i, j) = temp(i, j) + p[i][k] * matr2(k, j);

				if (temp(i, j) > limit)
					throw "Bad index";
			}
		return temp;
	}

	matrix operator *(const int num) const
	{
		matrix temp(rows, cols, limit);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				temp(i, j) = p[i][j] * num;

				if (temp(i, j) > limit)
					throw "STOP PLEASE";
			}
		return temp;
	}

	matrix operator +(matrix& matr) const {
		matrix temp(rows, cols, limit);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				temp(i, j) = matr(i, j) + p[i][j];

				if (temp(i, j) > limit)
					throw "Bad index";
			}
		}
		return temp;
	}

	type& operator() (int i, int j) {
		return p[i][j];
	}

	matrix transp() const{
		matrix temp(cols, rows, limit);
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < rows; j++)
				temp(i, j) = p[j][i];
		return temp;
	}

	template<class type1>
	friend void show(int, int, matrix<type1>&);
};

template <class type1>
void show(int n, int m, matrix<type1>& matr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matr(i , j) << " ";
		cout << "\n" << endl;
	}
}
