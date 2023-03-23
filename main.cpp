#include <iostream>
const int NUM = 9;
int statusArr[NUM] = { 0 };
int winArr[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
void printStatus()
{
	int n = 1;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			switch (statusArr[n - 1])
			{
			case 0: std::cout << ' ' << n << ' '; break;
			case 1: std::cout << " O "; break;
			case 2: std::cout << " X "; break;
			default:
				break;
			}
			if (j == 2)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << '|';
			}
			n++;
		}
		if (i == 2)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << "---+---+---" << std::endl;
		}
	}
}
bool gameOver(int& status)
{
	for (size_t i = 0; i < 8; i++)
	{
		int n = statusArr[winArr[i][0]];
		if (n == 0)
		{
			continue;
		}
		bool same = true;
		for (size_t j = 1; j < 3; j++)
		{
			same = same && (n == statusArr[winArr[i][j]]);
		}
		if (same)
		{
			status = n;
			return true;
		}
	}
	bool fill = true;
	for (size_t i = 0; i < 9; i++)
	{
		if (statusArr[i] == 0)
		{
			fill = false;
			break;
		}
	}
	if (fill)
	{
		status = 0;
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	printStatus();
	int winner;
	int move;
	int current = 1;
	while (!gameOver(winner))
	{
		std::cout << "Enter your move: (1-9)";
		std::cin >> move;
		while (statusArr[move - 1] != 0)
		{
			std::cout << "Can't move " << move << ", Please re-enter:(1-9)";
			std::cin >> move;
		}
		statusArr[move - 1] = current;
		current = current == 1 ? 2 : 1;
		system("cls");
		printStatus();
	}
	switch (winner)
	{
	case 0: std::cout << "draw" << std::endl; break;
	case 1: std::cout << "O win" << std::endl; break;
	case 2: std::cout << "X win" << std::endl; break;
	default:
		break;
	}
}