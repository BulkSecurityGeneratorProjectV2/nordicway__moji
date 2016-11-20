//lab1_DM.cpp ��������� ������� �������� � ������� ������������
#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int read(int m, int n, int** graf)
{
	
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cin >> graf[i][j];
			if (graf[i][j]>n)
			{
				cout << "����� ������� ������� " << graf[i][j] << " �������� �i���i��� ������ ( " << n << " �������)" << endl;
				_getch();
				system("cls");
				return 1;
			}
		}
	}
	return 0;
}

void sumij(int m, int**graf, int** m_sum)
{
	int i;
	for (i = 0; i < m; i++)
	{
		m_sum[graf[i][0] - 1][graf[i][1] - 1] = 1;
	}
}

void out(int n, int m, char f, int**matr)
{
	int i, j, k;
	cout << "    ";
	if (f == 's')
	{
		for (i = 0; i < n; i++)
			cout << "v" << i + 1 << "  ";
		k = n;
	}
	else
	{
		for (i = 0; i < m; i++)
			cout << "e" << i + 1 << "  ";
		k = m;
	}
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << "v" << i + 1;
		for (j = 0; j < k; j++)
			cout << setw(4) << matr[i][j];
		cout << endl;
	}

}

void incedent(int m, int**graf, int** matr)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		if (graf[i][0] == graf[i][1])
			matr[graf[i][0] - 1][i] = 2;
		else
		{
			matr[graf[i][0] - 1][i] = -1;
			matr[graf[i][1] - 1][i] = 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	int n, m, i, j, min, max, kil, flag1 = 0, c;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "����i�� �i���i��� ������ i �����" << endl;
		cin >> n >> m;
		cout << "����i�� ������� �����" << endl;
		int** graf = new int*[m];
		for (i = 0; i < m; i++)
		{
			graf[i] = new int[2];
		}
		flag1 = read(m, n, graf);
		if (flag1 == 0)
		{
			cout << "������� ���i�����i" << endl;
			int** m_sum = new int*[n];
			for (i = 0; i < n; i++)
			{
				m_sum[i] = new int[n];
				for (j = 0; j < n; j++)
					m_sum[i][j] = 0;
			}
			sumij(m, graf, m_sum);
			out(n, m, 's', m_sum);
			int** m_inc = new int*[n];
			for (i = 0; i < n; i++)
			{
				m_inc[i] = new int[n];
				for (j = 0; j < m; j++)
					m_inc[i][j] = 0;
			}
			incedent(m, graf, m_inc);
			cout << "������� i�����������i" << endl;
			out(n, m, 'i', m_inc);

		}
		cout << endl;
		cout << "������i�� 'Esc' ��� ������." << endl;
		cout << "������i�� ����-��� ����i��, ��� ���������..." << endl;
		c = _getch();
		if (c == 27) exit(1);
	}
	system("pause");
	return 0;
}

