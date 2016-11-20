#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>
#include <string.h>

int v = 0,e;							//������� � ����
FILE * fin, *fout, *f;					//������� � �������� �����
char filenameIN[20], filenameOUT[20];   //����� ������� �� �������� �����  
int j = 0;							   	//������� ����� � �������� ����
int column[60][2];						//������� � �����
int matrix[50][150] = { 0 };			//������� ��� ������������ � �������� �� ������������(0)


//===���������� �� �����
void file(int li, int lj)
{
	char str[10];						       //����� ��� ������ �� �����
	char name[20];								//��*� ������ �����
	cout << "Input name of new file:" << endl;
	cin >> name;
	fout = fopen(name, "w+");

	for (int l = 1; l <= li; l++)
	{
		for (int i = 1; i <= lj; i++)
		{
			if (matrix[l][i] == -1) 	fputs("-1", fout);   //�������� � �������.
			else{
				_itoa(matrix[l][i], str, 100);
				fputc(' ', fout);
				fputs(str, fout);
			}
			fputc(' ',fout);
		}
		fputc('\n',fout);
	}
}
//===���� ���������� �� �����
void screen(int li, int lj)
{
	for (int l = 1; l <= li; l++)
	{
		for (int i = 1; i <= lj; i++)
			cout <<setw(3)<< matrix[l][i]<< " ";
		cout << endl;
	}
}

//==���� ������ ���������
void output(int li,int lj)
{
	int answ;					//���� ������ ����
	fflush(stdin);
	cout << "Choose kind of output:" << endl;
	cout << "== 1 - data in file  ==" << endl;
	cout << "== 2 - data on screen== " << endl;
	cin >> answ;
	switch (answ)
	{
	case 2:{ screen(li,lj);  break; }
	case 1:{ file(li,lj); break; }
	}
}

//===��������� ������� ��������
void sum()
{
	for (int li = 1; li < j; li++)
	{
		matrix[column[li][0]][column[li][1]] = 1;   //
	}
	cout << "Adjacency matrix" << endl;
	output(v,v);
}

//==��������� ������� ������������
void intz()
{
	for (int li = 0; li <= e; li++)
	{
		if (column[li][0] == column[li][1])  matrix[column[li][0]][li] = 2;   //����
		else 
		{
			matrix[column[li][0]][li] = -1;    //������� 
			matrix[column[li][1]][li] = 1;     //�����
		}
	}

	cout << "Incidence matrix" << endl;
	output(v,e);           //�������� ������� ������ � ��� ��� ���������
}

//=== ����
void menu()
{
	int key;					//���� ����
	cout << "Press:" << endl;
	cout << "== 1 - incidence matrix ==" << endl;
	cout << "== 2 - adjacency matrix ==" << endl;
	cin>>key;
	v=column[0][0];                 //���������� ������� ������
	e = column[0][1];				//���������� ������� ���

	switch (key)
	{
	case 1:{ intz();  break; }
	case 2:{ sum(); break; }
	}
}
int main()
{
	fflush(stdin);
	
	cout << "Author Anastasia Dubine column-51 " << endl;
	cout << "Laba #1" << endl;
	cout << "Input name of input file: " << endl;
	gets(filenameIN);
	
	cout << "Information from file:" << endl;
	fin = fopen(filenameIN, "r");
	while (!feof(fin))
	{					//���������� � ����� � ������ �� �������������� ����
		for (int i = 0; i < 2; i++)
		{
			fscanf(fin, "%d", &column[j][i]);
			cout << column[j][i] << " ";
		}
		cout << endl;
		j++;
	}
	fclose(fin);
	menu();
	system("pause");
}