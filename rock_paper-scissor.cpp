#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
    string player_name;
    cout<<"Enter Player Name:"<<endl;
    cin>>player_name;
    system("cls");
    int rounds=0;
    cout<<player_name<<" please select no of rounds you want to play."<<endl;
    cin>>rounds;
    system("cls");
    int player_score=0, computer_score=0;
    for(int i = 1;i<=rounds;i++)
    {
        system("cls");
        int player_choice, computer_choice;
        cout<<player_name<<"'s score: "<<player_score<<endl;
        cout<<"Computer's score:"<<computer_score<<endl;
        cout<< "Press 1 for Rock"<<endl;
        cout<< "Press 2 for Paper"<<endl;
        cout<< "Press 3 for Scissor"<<endl;
        cin>>player_choice;
        system("cls");
        srand(time(0));
        computer_choice = (rand()%3+1);
        if(player_choice == 1 && computer_choice == 1 || player_choice == 2 && computer_choice == 2 || player_choice == 3 && computer_choice == 3)
        {
            cout<<"Match Draw."<<endl;
        }
        else if(player_choice == 1 && computer_choice == 2 || player_choice == 2 && computer_choice == 3 || player_choice == 3 && computer_choice == 1 )
        {
            cout<<"Computer wins."<<endl;
            computer_score++;
        }
        else
        cout<<"Player wins."<<endl;
        player_score++;
    }
    system("cls");
    if(computer_score>player_score)
    {
        cout<<"computer wins with ratio of"<<computer_score<<":"<<player_score<<endl;
    }
    else if(player_score>computer_score)
    cout<<player_name<<" wins with ratio of"<<player_score<<":"<<computer_score<<endl;
    return 0;
}
