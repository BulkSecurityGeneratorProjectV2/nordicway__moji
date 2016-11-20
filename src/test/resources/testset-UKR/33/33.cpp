#include <conio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class graph
{
private:
	int n;						// ʳ������ ������
	int m;						// ʳ������ �����
	vector<int> start;			// �����
	vector<int> end;			//
	vector<vector<int>> V;		// �������
	multimap<int, int> lines;	// ������� �����
	string path;				// ����
	ifstream fin;				// ����� ������ � �����
	ofstream fout;				// ����� ����� � ����
public:

	void setInputFile(string file)	// ���� �����
	{
		fin.open(file + ".txt");	
	}

	void setOutputFile(string file)
	{
		fout.open(file + ".txt");
	}

	void InMatrix()
	{
		int cv, cu;								// ������� ����
		fin >> n >> m;							// ��� ����� � �����
		
		V.resize(n);							// ���������� ���'�� ��� �������
		for (int i = 0; i < n; i++)		
			V[i].resize(m);
		for (int i(0); i < n; i++)				// ����������� ������
			for (int j(0); j < m; j++)			
				V[i][j] = 0;					
	
		for (int i = 0; i < m; i++)				// ���������� � ����� �����
		{
			fin >> cv >> cu;
			start.push_back(cv);
			end.push_back(cu);
		}

		int i = 0;								
		for (auto it = start.begin(), it1 = end.begin(); it != start.end(); it++, it1++)	// ���������� ������� �������������
		{
			if (*it - 1 != *it1- 1)
			{
				V[*it - 1][i] = -1;
				V[*it1 - 1][i++] = 1;
			}
			else V[*it1 - 1][i++] = 2;
		}

		for (int j(0); j < n; j++)								// ���� �������
		{
			for (int k(0); k < m; k++)
			{
				if (V[j][k] != -1)
				{
					cout << ' ' << V[j][k] << ' ';
					fout << ' ' << V[j][k] << ' ';
				}
				else
				{
					cout << V[j][k] << ' ';
					fout << V[j][k] << ' ';
				}
			}
			cout << endl;
			fout << endl;
		}
	}

	void AdMatrix()
	{
		int cv, cu;								// ������� ����
		fin >> n >> m;							// ��� ����� � �����

		V.resize(n);							// ���������� ���'�� ��� �������
		for (int i = 0; i < n; i++)
			V[i].resize(n);
		for (int i(0); i < n; i++)				// ����������� ������
			for (int j(0); j < n; j++)
				V[i][j] = 0;

		for (int i = 0; i < m; i++)				// ���������� � ����� �����
		{
			fin >> cv >> cu;
			lines.insert(pair<int, int>(cv, cu));
		}

		for (auto it : lines)					// ����������� �������
			V[it.first-1][it.second-1]++;

		for (int j(0); j < n; j++)				// ���� �������
		{
			for (int k(0); k < n; k++)
			{
				cout << ' ' << V[j][k] << ' ';
				fout << ' ' << V[j][k] << ' ';
			}
			cout << endl;
			fout << endl;
		}
	}

	void clear()
	{
		fin.close();											// ������� ����
		fout.close();
		V.clear();												// ������� ���
		start.clear();											//
		end.clear();											//
		lines.clear();
	}
};

int main()
{
	string filename; // ���� �����
	string filename1;// ���� ������
	graph G;		 // ���� 
	bool end(false); //
	char answer;	 //
	
	while (!end)
	{
		cout << "Enter input file name: ";
		getline(cin, filename);
		cout << "Enter output file name: ";
		getline(cin, filename1);

		G.setInputFile(filename); 
		G.setOutputFile(filename1);

		cout << "Incendental Matrix: " << endl;
		G.InMatrix();
		G.clear();
		G.setInputFile(filename);
		G.setOutputFile(filename1+"2");
		cout << "Adjacency Matrix: " << endl;
		G.AdMatrix();
		G.clear();

		cout << "Another file? (y\\n)";
		answer = _getch();
		(answer == 'y' || answer == 'Y') ? end = false: end = true;
		cout << endl;
	}
	return 0;
}