
#include <stdlib.h> 
#include <iostream> 
#include <fstream> 
#include <iomanip> 
using namespace std;
int n, m, A[20], B[20], check;
typedef int Matrix[20][20];
Matrix I, S;
char answer;

void gr_input(int*l, int*k) //�������� ����� �� ���������� ����� 
{
	ifstream fin;
	fin.open("input.txt");
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		fin >> *l >> *k;
		l++;
		k++;
	}
	fin.close();
}
void gr_check(int*l, int*k) //�������� ��������� ����� �� ����������� 
{
	if ((m>0) && (n > 0) && (m < 30) && (n < 30)) check = 1; else check = 0;
	for (int i = 0; i < m; i++)
	{
		if ((*l>0) && (*k > 0) && (*l <= n) && (*k <= n)) check = 1;
		else
		{
			check = 0;
			break;
		}
		l++;
		k++;
	}
}
void gr_output(int*l, int*k) //��������� ����� �� ����� 
{
	cout << "������� ����." << endl;
	cout << "�i���i��� ������: " << n << endl;
	cout << "�i���i��� �����: " << m << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "����� " << i + 1 << ": " << *l << " " << *k << endl;
		l++;
		k++;
	}
}
void matr_ints(Matrix matr, int*l, int*k) //������� ������������ 
{
	for (int i = 0; i < m; i++)
	{
		matr[*l - 1][i] = -1;
		matr[*k - 1][i] = 1;
		if (*l == *k) matr[*l - 1][i] = 2;
		l++;
		k++;
	}
}
void matr_sum(Matrix matr, int*l, int*k) //������� �������� 
{
	for (int i = 0; i < m; i++)
	{
		matr[*l - 1][*k - 1] = 1;
		l++;
		k++;
	}
}
void out_screen(Matrix m1, Matrix m2) //��������� �� ����� 
{
	cout << "������� i�����������i:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << m1[i][j];
		cout << endl;
	}
	cout << "������� ���i�����i:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << m2[i][j];
		cout << endl;
	}
}
void out_file(Matrix m1, Matrix m2) //��������� � ���� 
{
	ofstream fout;
	fout.open("output.txt");
	fout << "������� i�����������i:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fout << setw(3) << m1[i][j];
		fout << endl;
	}
	fout << "������� ���i�����i:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << setw(3) << m2[i][j];
		fout << endl;
	}
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	gr_input(A, B); //�������� ����� �� ���������� ����� 
	gr_check(A, B); //�������� ��������� ����� �� ����������� 
	if (check == 1)
	{
		gr_output(A, B); //��������� ����� �� ����� 
		matr_sum(S, A, B); //������� �������� 
		matr_ints(I, A, B); //������� ������������ 
		cout << "������� ��������� �� �����? (Y\\N): "; //����� �� ��������� ������� �� ����� 
		cin >> answer;
		if ((answer == 'Y') || (answer == 'y')) out_screen(I, S); //��������� �� ����� 
		cout << "�������� ��������� � ����? (output.txt) (Y\\N): "; //����� �� ��������� ������� � ���� 
		cin >> answer;
		if ((answer == 'Y') || (answer == 'y')) out_file(I, S); //��������� � ���� 
	}
	else cout << "�������. ���� ������� ���i���" << endl; //��������� ����������� ��� ������� 
	system("pause");
	return 0;
}