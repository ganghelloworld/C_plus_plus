#include <iostream>

using namespace std;

class GameBoard
{
public:
	GameBoard(){ cout << "GameBoard()" << endl; }
	GameBoard(const GameBoard&)
	{
		cout << "GameBoard(const GameBoard&)" << endl;
	}
	GameBoard& operator=(const GameBoard&)
	{
		cout << "GameBoard& operator=(const GameBoard&)" << endl;
		return *this;
	}
	~GameBoard(){ cout << "~GameBoard()" << endl; }
};
class Game
{
	GameBoard gb;
public:
	Game(){ cout << "Game()" << endl; }
	Game(const Game& g): gb(g.gb)
	{
		cout << "Game(const Game& g)" << endl;
	}
	Game(int){ cout << "Game(int)" << endl; }
	Game& operator=(const Game& g)
	{
		gb = g.gb;
		cout << "Game& operator=(const Game& g)" << endl;
		return *this;
	}
	class Other{};
	operator Other() const
	{
		cout << "Game::operator Other()" << endl;
		return Other();
	}
	~Game(){ cout << "~Game()" << endl; }
};
class Chess : public Game {};

void f(Game::Other){}

class Checkers : public Game
{
public:
	Checkers()
	{
		cout << "Checkers()" << endl;
	}
	Checkers(int)
	{
		cout << "Checkers(int)" << endl;
	}
	Checkers(const Checkers& c) : Game(c)
	{
		cout << "Checkers(const Checkers& c)" << endl;
	}
	Checkers& operator=(const Checkers& c)
	{
		//Game::operator=(c);
		cout << "Checkers::operator=(const Checkers& c)" << endl;
		return *this;
	}
};

int main()
{
	Checkers c1, c2;
	c1 = c2;
}
