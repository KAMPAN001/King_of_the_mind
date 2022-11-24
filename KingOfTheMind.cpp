#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "KingOfTheMind.h"

using namespace std;

//I decided to put two classes in one cpp file

//PLAYER
/*!
*\brief Class Player is responsible for creating the player
* 
* Operations supported:
* For question: draw, download question, download answer
* Load player position
* Scoring support
*/

/*!
*\brief Player class constructor
* 
* Creating object for Player. He has one argument(const), it is player position
*/
Player::Player(const int position)
{
	position_x = 0;
	position_y = position;
}

/*!
*\brief Method (string), is responsible for download question for player
*/
string Player::lottery_machine()
{
	int x =1, number_of_question = (rand() % 21) + 1;//Actualy is 21 question, should be 100
	fstream questions;
	string line, question_for_player;

	number_question = number_of_question;

	questions.open("text.txt", ios::in);
	if (questions.is_open() == true)
	{
		while (!questions.eof())
		{
			getline(questions, line);
			if (x == number_of_question)
			{
				question_for_player = line;
			}
			x++;
		}
	}
	else
	{
		cout << "Error" << endl;
	}
	questions.close();
	return question_for_player;
}

/*!
*\brief Method (bool), is responsible for download answer for question
*/
bool Player::answer_method(bool player_answer)
{
	fstream answers;
	int x = 1;
	string answer;

	answers.open("text_answer.txt", ios::in);
	if (answers.is_open() == true)
	{
		while (!answers.eof())
		{
			getline(answers, answer);
			if (x == number_question)
			{
				if (answer == "1")
				{
					if (player_answer == true)
					{
						return true;
					}
					else if (player_answer == false)
					{
						return false;
					}
				}
				else if (answer == "0")
				{
					if (player_answer == false)
					{
						return true;
					}
					else if (player_answer == true)
					{
						return false;
					}
				}
				break;
			}
			x++;
		}
	}
	else
	{
		cout << "Error" << endl;

	}
	answers.close();
}

/*!
*\brief Method (bool), is responsible for checking when game will end
*/
bool Player::check_points()
{
	if (points == 10)
	{
		Player::end_game = true;
		return true;
	}
	else
	{
		return false;
	}
}

/*!
*\brief Method (void), is responsible for plus point for player when his answer is good
*/
void Player::plus_point(bool answer)
{
	if (answer == true)
	{
		points += 1;
		position_x += 1;
	}
}

/*!
*\brief Method (void), is responsible for shoving winner on screen
*/
void Player::end(int player)
{
	if (end_game == true)
	{
		cout << "The game is over, The winer is player: " << player;
	}
}

/*!
*\brief Method (void), returning x position
*/
int Player::return_position()
{
	return Player::position_x;
}



//FIELD

/*!
*\brief Class Field is responsible for creating field
*
* Operations supported:
* Creating needed vector
* Drawing field on screen
*/

/*!
*\brief Field class constructor
*
* Creating object for Field = vector. 
*/
Field::Field()
{
	vector <char> first_vector;

	for (int i = 0; i < 10; i++)
	{
		first_vector.clear();
		for (int k = 0; k < 2; k++)
		{
			first_vector.push_back('#');
		}
		field.push_back(first_vector);
	}
}

/*!
*\brief Method (void), drawing field on screen
*/
void Field::draw_field(int Player_1, int Player_2)
{
	field[Player_1 ][0] = '1';
	field[Player_2 ][1] = '2';
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << field[i][k];
		}
		cout << endl;
	}
	field[Player_1][0] = '#';
	field[Player_2][1] = '#';

}

