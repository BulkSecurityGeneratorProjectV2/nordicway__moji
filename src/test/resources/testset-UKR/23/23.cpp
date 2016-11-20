#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
	
#pragma warning(disable : 4996)

FILE * FileCreateOrOpen();
char * GetInput();
void PrintLine(FILE *file, char *input);
void SaveWordInFile(char *word);
void SaveFindCount(int count);


int main()
{
	setlocale(LC_ALL, "russian");
	cout << "����� ��-53 \n";
	cout << "������ �����\n";
	cout << "������������ ������ �1\n";

	FILE *fileTxt; // ���������� ��� ������ �����	

	fileTxt = FileCreateOrOpen(); // ��������� ���� ��� ���������
	PrintLine(fileTxt, GetInput()); // ������� �� ����� ���� ��������� ������ 

	fclose(fileTxt); // ��������� ����
	system("pause");
}

void SaveWordInFile(char *word)
{
	FILE* file = fopen("Lab11_save.txt", "a"); // ��������� ���� ��� ���������� ������
	fputs(word, file); // ��������� ������
	fclose(file); // ������� ����
}

void SaveFindCount(int count)
{
	FILE *file = fopen("Lab11_save.txt", "a"); // ��������� ����
	fputs("\n������� �����: ", file); // �������� ������

	char *findCount = new char[64]; // ��������������� ����� � ������
	itoa(count, findCount, 10); // 10 - ���������� �������� ���������
	fputs(findCount, file); // ���������� � ����� ���� �����

	fclose(file); // ��������� ����
}

FILE *FileCreateOrOpen()
{
	FILE * file; // ���������� ���� ������� ����
	file = fopen("Lab11.txt", "r"); // ��������� ���� � ������� "������"
	cout << "���� 'Lab11.txt' ����� � ������!" << endl;
	return file; // ���������� ����
}

char *GetInput()
{
	cout << "������� ���� ������: ";
	char *myString = new char[512]; // ������� ���������� ��� �������� ����� ������
	gets_s(myString, 512); // ���������� ������ � ����������
	return myString; // ���������� ������
}

void PrintLine(FILE *file, char *input)
{
	int findCount = 0; // ���������� ��� ���������� ����� � ������� ������ ���� ������
	while (!feof(file)) // ���������� ������ � �����
	{
		char *newString = new char[512]; // ���� ����� ���������� ������
		fgets(newString, 512, file); // ���������� ������
		if (strstr(newString, input)) // ���� ������ �������� ���� �����
		{
			findCount++; // ����������� ���������� ��������� ����� �� 1
			puts(newString); // ������� ������ �� �����
			SaveWordInFile(newString); // ��������� ������ � �������� ����
		}
	}
	SaveFindCount(findCount); // ����� ��������� ������ ����� ���������� ���������� ��������� ����� � ����
}