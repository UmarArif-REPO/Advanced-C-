#include <iostream>

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
	bool CellEmpty(int& x, int& y);
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
bool CNought::CellEmpty(int& x, int& y)
{
	return mGrid[x][y] == 0;
}

// Repeat code thus has been separated out into it's own method
void CNought::PlayerInput(int& i, int& x, int& y)
{
	std::cout << "Player " << players[i].name << std::endl;
	std::cout << "Please enter x coordinate: ";
	std::cin >> x;
	std::cout << "Please enter y coordinate: ";
	std::cin >> y;
}

// COntains the while loop
void CNought::GamePlay()
{
	std::cout << "Welcome all" << std::endl << std::endl;

	while (mIsRunning)
	{
		for (int i = 0; i < PLAYERS; ++i)
		{
			int x, y;
			PlayerInput(i, x, y);

			if (CellEmpty(x, y))
			{
				mGrid[x][y] = players[i].playerID;
			}
			else
			{
				std::cout << std::endl << "Incorrect! Square is taken!" << std::endl;
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

// Prints the grid onto the screen
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
				std::cout << "player 1 has won" << std::endl;
				GameOver();
			}
			if (mGrid[i][j] == 1 && mGrid[i][j + 1] == 1 && mGrid[i][j + 2] == 1)
			{
				std::cout << "player 1 has won" << std::endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i + 1][j] == 2 && mGrid[i + 2][j] == 2)
			{
				std::cout << "player 2 has won" << std::endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i][j + 1] == 2 && mGrid[i][j + 2] == 2)
			{
				std::cout << "player 2 has won" << std::endl;
				GameOver();
			}
			if (mGrid[i][j] == 1 && mGrid[i + 1][j + 1] == 1 && mGrid[i + 2][j + 2] == 1)
			{
				std::cout << "player 1 has won" << std::endl;
				GameOver();
			}
			if (mGrid[i][j] == 2 && mGrid[i + 1][j + 1] == 2 && mGrid[i + 2][j + 2] == 2)
			{
				std::cout << "player 2 has won" << std::endl;
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

// Changes isRunning to false
void CNought::GameOver()
{
	Stop();
	std::cout << "GAME OVER!" << std::endl;
}

int main()
{
	CNought* game = new CNought;
	game->CreateGrid();
	game->CreatePlayers();
	game->GamePlay();

	delete(game); // Release memory

	system("pause");
	return 0;
}