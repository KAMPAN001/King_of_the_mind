#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//A template for the classes needed for the program

//Main class, responsible for virtual methods
//I wanted to show the usage of virtual methods
//if you need to create another player (class) you can use virtual methods
class King
{
public:
	virtual bool answer_method(bool player_answer) = 0;
	virtual string lottery_machine() = 0;
	virtual bool check_points() = 0;
	virtual void plus_point(bool answer) = 0;
	virtual void end(int player) = 0;
	virtual int return_position() = 0;
};

//Class using virtual methods
class Player :public King
{
public:
	Player(){};
	Player(const int position);
	~Player(){};
	virtual string lottery_machine();
	virtual bool answer_method(bool player_answer);
	virtual bool check_points();
	virtual void plus_point(bool answer);
	virtual void end(int player);
	virtual int return_position();

private:
	int position_x = 0, position_y = 0, points = 0;
	int number_question = 0;
	bool end_game = false;
};

//Result class
class Field :public Player
{
public:
	Field();
	~Field() {};
	void draw_field(int Player_1, int Player_2);
private:
	vector<vector<char>> field;
};

