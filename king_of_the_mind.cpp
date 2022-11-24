#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "KingOfTheMind.h"

using namespace std;

//zadania
//-dodac reszte pytan

//The function responsible for greeting the player
void hello_word()
{
    cout << "    King of the mind\n\n";
    cout << "It is a simple game for two players,\nyou have question and two answers Yes/True(Y, yes, YES) or No/False(N, no, No)\nIf your answer is not like example is recognized as not.\n\n\n";
}

//The function responsible for get the player's answer
bool check_answer(string answer)
{
    if (answer == "Y")
    {
        return true;
    }
    else if(answer == "yes")
    {
        return true;
    }
    else if(answer == "YES")
    {
        return true;
    }
    else
    {
        return false;
    }
}

//The function responsible for get the player's answer, about saving the best player nick
bool show_position()
{
    string chose;
    cout << "If you want to show position -> press T, evrything else is no: ";
    cin >> chose;
    if (chose == "T")
    {
        return true;
    }
    else
    {
        return false;
    }
}

//The function responsible for saving the best player nick
void save_game()
{
    string chose;
    cout << "If you want to save your nick -> press T, evrything else is no: ";
    cin >> chose;
    if (chose == "T")
    {
        cout << "Your nick: ";
        cin >> chose;

        fstream save;

        save.open("save.txt", ios::app);
        if (save.is_open() == true)
        {
            cout << "Last winer is " << chose;
        }
        else
        {
            cout << "Error" << endl;
        }
        save.close();

    }
}

//The main function responsible for creating objects, handling of the game and its events
int main()
{
    string answer;
    vector<vector <char>> field;

    hello_word();

    Player Player_1(1);
    Player Player_2(2);
    Field Field;

    King* pointer_1;
    King* pointer_2;

    pointer_1 = &Player_1;
    pointer_2 = &Player_2;

    do
    {
        cout << "Question for first player: " << pointer_1->lottery_machine() << endl;
        cout << "Answer: ";
        cin >> answer;
        pointer_1->plus_point(pointer_1->answer_method(check_answer(answer)));

        cout << "Question for second player: " << pointer_2->lottery_machine() << endl;
        cout << "Answer: ";
        cin >> answer;
        pointer_2->plus_point(pointer_2->answer_method(check_answer(answer)));

        bool chose = show_position();
        if (chose)
        {
        Field.draw_field(pointer_1->return_position(), pointer_2->return_position());
        }

    } while (pointer_1->check_points() == false || pointer_2->check_points() == false);

    pointer_1->end(1);
    pointer_2->end(2);

    save_game();
    return 0;
}

