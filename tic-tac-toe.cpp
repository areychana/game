#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int currentPlayer;
char currentmarker;

void drawBoard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" |  "<<board[0][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" |  "<<board[1][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" |  "<<board[2][2]<<endl;
}

void placeMarker(int slot)
{
    int row;
    if(slot % 3 == 0)
    {
        row = (slot / 3 ) - 1;
    }
    else
    row = slot/3;

    int col;
    if(slot % 3 == 0)
    {
        col = 2;
    }
    else 
    col = (slot % 3) - 1;

    board[row][col] = currentmarker;
}

char winner()
{
    for(int i = 0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return currentPlayer;
        }
        else if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return currentPlayer;
        }
        else if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][1])
        {
            return currentPlayer;
        }
        
    }
    
}

void swap_player_marker()
{
    if(currentPlayer == 1) currentPlayer = 2;
    else if(currentPlayer == 2) currentPlayer = 1;
    if(currentmarker == 'x') currentmarker = 'o';
     else if(currentmarker == 'o') currentmarker = 'x';

}

void game()
{
    cout<<"Player1 please choose your marker."<<endl;
    char marker_1;
    cin>>marker_1;

    currentPlayer = 1;
    currentmarker = marker_1;

    drawBoard();
    cout<<""<<endl;
    for (int i = 0 ; i < 10; i++)
    {
        cout<<"Its player"<<currentPlayer<<"'s turn choose your slot:"<<endl;
        int slot;
        int playerlost;
        playerlost = winner();
        if (playerlost == 1)
        {
            cout<<"Player2 is winner."<<endl;
            break;
        }
        if (playerlost == 2)
        {
            cout<<"Player1 is winner."<<endl;
            break;
        }
        cin>>slot;
        placeMarker(slot);
        swap_player_marker();
        drawBoard();
    }
    
    
}

int main()
{
    game();
    return 0;
}
