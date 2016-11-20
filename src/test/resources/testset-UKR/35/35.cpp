/* ������ ������ ��-51 Բ��, ����������� �1 */
#include<iostream>
#include<stdio.h>
using namespace std;

FILE *fin, *fout; //������� � �������� ����
char str[255];	//�������� �����
int incMatrix[255][255], sumMatrix[255][255];	//������� ������������, ������� ��������
int vectors[255][2];	//����� ��� ���������� ��������� ������
char n[255], m[255];	//�-��� ������, �-��� �������
char tempv[255];		//�������� ������

int main()
{
	//³������� �����
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	//���������� �-�� ������ � �-�� ������� 
	fgets(str, 100, fin);
	strcpy(n, strtok(str, " "));
	strcpy(m, strtok(NULL, " "));

	//���������� ��������� ��� �������
	for (int i = 0; i < atoi(m); i++)
	{
		fgets(str, 100, fin);
		strcpy(tempv, strtok(str, " "));
		vectors[i][0] = atoi(tempv);
		strcpy(tempv, strtok(NULL, " "));
		vectors[i][1] = atoi(tempv);
	}

	//����������� ������� ��������
	for (int i = 0; i < atoi(m); i++)
	{
		sumMatrix[vectors[i][0]-1][vectors[i][1]-1] = 1;
	}

	//����������� ������� �������� � �������� ����
	fputs("������� ��������:\n", fout);
	for (int i = 0; i < atoi(n); i++)
	{
		for (int j = 0; j < atoi(n); j++)
		{
			fprintf(fout, "%d ", sumMatrix[i][j]);
		}
		fputs("\n",fout);
	}

	//����������� ������� ������������
	for (int i = 0; i < atoi(m); i++)
	{
		incMatrix[vectors[i][0] - 1][i] = -1;
		incMatrix[vectors[i][1] - 1][i] = 1;
		if (vectors[i][0] == vectors[i][1]) incMatrix[vectors[i][0] - 1][i] = 2;
	}

	//����������� ������� ������������ � �������� ����
	fputs("\n������� ������������:\n", fout);
	for (int i = 0; i < atoi(n); i++)
	{
		for (int j = 0; j < atoi(m); j++)
		{
			if (incMatrix[i][j] == -1) {
				fprintf(fout, "%d ", incMatrix[i][j]);
			}
			else {
				fprintf(fout, " %d ", incMatrix[i][j]);
			}
		}
		fputs("\n", fout);
	}

	//�������� �����
	fclose(fin);
	fclose(fout);
}