#include <iostream>

using namespace std;

const int SIZE = 3;
const int PLAYERS = 2;

struct SPlayers
{
	int playerID;
	std::string name;
};

class CNought
{
private:
	int mGrid[SIZE][SIZE];
	SPlayers players[PLAYERS];
	bool mIsRunning = true;
public:
	void CreateGrid();
	void CreatePlayers();
	bool CellEmpty(int x, int y);
	bool CellNotEmpty(int x, int y);
	void GamePlay();
	void PlayerInput(int& i, int& x, int& y);
	void Grid();
	void HasWon();
	void GameOver();
	void Stop();
};

// Set up the grid - filling it with 0's
void CNought::CreateGrid()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			mGrid[i][j] = 0;
		}
	}
}

void CNought::CreatePlayers()
{
	std::string pieces[]{ "nought", "cross" };
	for (int i = 0; i < PLAYERS; ++i)
	{
		players[i].name = pieces[i];
		players[i].playerID = (i + 1);
	}
}

// Checks to see if the cell is empty
bool CNought::CellEmpty(int x, int y)
{
	return mGrid[x][y] == 0;
}

bool CNought::CellNotEmpty(int x, int y)
{
	return mGrid[x][y] != 0;
}

void CNought::PlayerInput(int& i, int& x, int& y)
{
	cout << "Player " << players[i].name << endl;
	cout << "Please enter x coordinate: ";
	cin >> x;
	cout << "Please enter y coordinate: ";
	cin >> y;
}

void CNought::GamePlay()
{
	cout << "Welcome all" << endl << endl;

	while (mIsRunning)
	{
		for (int i = 0; i < PLAYERS; ++i)
		{
			int x, y;
			PlayerInput(i, x, y);

			if (mGrid[x][y] == 0)
			{
				mGrid[x][y] = players[i].playerID;
			}
			else
			{
				cout << endl << "Incorrect! Square is taken!" << endl;
				while (!CellEmpty(x, y))
				{
					PlayerInput(i, x, y);

					if (CellEmpty(x, y))
					{
						mGrid[x][y] = players[i].playerID;
						break;
					}
				}
			}

			Grid();
			HasWon();
		}
	}
}

void CNought::Grid()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			std::cout << mGrid[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

// Check for wins
void CNought::HasWon()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (mGrid[i][j] == 1 && mGrid[i + 1][j] == 1 && mGrid[i + 2][j] == 1)
			{
				cout << "player 1 has won" << endl;
				GameOver();
			}
			if (mGrid[i][j] == 1 && mGrid[i][j + 1] == 1 && mGrid[i][j + 2] == 1)
			{
				cout << "player 1 has won" << endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i + 1][j] == 2 && mGrid[i + 2][j] == 2)
			{
				cout << "player 2 has won" << endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i][j + 1] == 2 && mGrid[i][j + 2] == 2)
			{
				cout << "player 2 has won" << endl;
				GameOver();
			}
			if (mGrid[i][j] == 1 && mGrid[i + 1][j + 1] == 1 && mGrid[i + 2][j + 2] == 1)
			{
				cout << "player 1 has won" << endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i + 1][j + 1] == 2 && mGrid[i + 2][j + 2] == 2)
			{
				cout << "player 2 has won" << endl;
				GameOver();
			}
		}
	}
}

// Calling this will end the game
void CNought::Stop()
{
	mIsRunning = false;
}

void CNought::GameOver()
{
	Stop();
	cout << "GAME OVER!" << endl;
}

int main()
{
	CNought* game = new CNought;
	game->CreateGrid();
	game->CreatePlayers();
	game->GamePlay();

	system("pause");
	return 0;
}