// CubeRoller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <cstdlib>
#include <time.h>
#include <string>
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>
using namespace std;

class Player
{
private:
	int wintotal;
	int score; // ���� ������
	string name; // ��� ������
public:
	// ����������� 
	Player()
	{}
	Player(string m_name)
	{
		name = m_name;
		score = 0;
		wintotal = 0;
	}
	int getScore() { return score; }
	void setScore(int inc_score) { score = score + inc_score; }
	void dropScore() { score = 0; }
	int getWins() { return wintotal; }
	void setWin() { wintotal++; }
	string getName() { return name; }

};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//setlocale(LC_ALL, "Russian");
	cout << "����� ���������� � ����!" << endl;
	cout << "����� ����� ����������� 100 ������ ��� � \"������\" ��� ��������� ���������� ������� (�� 1 �� 10��)." << endl;
	cout << "������� ���������� �������: ";
	int massLength = 666;
	while (massLength < 1 || massLength > 10)
	{
		cin >> massLength;
		if (massLength < 1 || massLength >10)
		{ 
			cout << "�������� ���������� �������. ������� ����� �� 1 �� 10" << endl; 
		}
	} 

	Player *players = new Player[massLength];
	for (int i = 0; i < massLength; i++)
	{
		cout << "������� ��� ������ �" << i + 1 << " :";
		string name;
		cin >> name;
		players[i] = Player(name);
	}

	bool win;
	int summ;
	int points;
	int noOfMoves;
	srand(time(NULL));

	fstream inOut;
	inOut.open("Result.txt", ios::out); // ��������� ���� ��� ������

	for (int game = 0; game < 100; game++)
	{
		win = false;

		while (win != true)
		{
			for (int i = 0; i < massLength; i++)
			{
				inOut << "��� ������ �" << i + 1 << ", " << players[i].getName() <<":" << endl;
				summ = 0;
				noOfMoves = 1 + rand() % 5;
				int realMoves = noOfMoves;
				for (int j = 0; j < noOfMoves; j++)
				{
					points = 1 + rand() % 6;
					if (points == 1) {
						summ = 0;
						realMoves = j;
						break;
					}
					summ = summ + points;
				}
				inOut << "�� ���� ��� �������� �������: " << realMoves << " , ��������� " << summ << " �����." << endl;
				players[i].setScore(summ);

				inOut << "�������� � ���� ���� � ���� " << players[i].getScore() << "�����." << endl;

				if (players[i].getScore() > 100)
				{
					win = true;
					players[i].setWin();
					inOut << "-------------------------------------------------" << endl;
					inOut << "����� " << players[i].getName() << " ���������!" << endl;
					inOut << "-------------------------------------------------" << endl << endl;
					for (int i = 0; i < massLength; i++)
					{
						players[i].dropScore();
					}

					break;
				}
			}
		}
	}

	inOut << "-------------------------------------------------" << endl;
	inOut << "-------------------------------------------------" << endl;
	inOut << "              ���������� 100 ���                 " << endl;
	inOut << "-------------------------------------------------" << endl;
	inOut << "-------------------------------------------------" << endl;
	inOut << "  ���                          |      �����     |" << endl;
	inOut << "-------------------------------------------------" << endl;
	// �������  � ����
	char s[] = "                             |                |";
	for (int j = 0; j < massLength; j++)
	{
		inOut << "  " + players[j].getName() + "                             " + to_string(players[j].getWins()) << endl;
		inOut << "-------------------------------------------------" << endl;
	}
	inOut.close();

	list <Player> lst;
	list<Player>::iterator it;

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file