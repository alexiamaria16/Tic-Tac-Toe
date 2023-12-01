#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

char Board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool draw = false;



void display_board()
{
      cout<<"\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[0][0]<<"  |  "<<Board[0][1]<<"  |  "<<Board[0][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[1][0]<<"  |  "<<Board[1][1]<<"  |  "<<Board[1][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<Board[2][0]<<"  |  "<<Board[2][1]<<"  |  "<<Board[2][2]<<" \n";
    cout<<"\t\t\t\t     |     |     \n";
}

void player_turn()
{
    if(turn == 'X')
    {
        cout<<"\nRandul Jucatorului - 1 [X]  : ";
    }
    else if(turn == 'O')
    {
        cout<<"\nRandul Jucatorului - 2 [O]  : ";
    }

    cin>> choice;



    switch(choice)
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;
    default:
        cout<<"Miscare invalida";
    }

    if(turn == 'X' && Board[row][column] != 'X' && Board[row][column] != 'O')
    {

        Board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && Board[row][column] != 'X' && Board[row][column] != 'O')
    {

        Board[row][column] = 'O';
        turn = 'X';
    }
    else
    {

        cout<<"Este deja o valoare!\n Selecteaza alta boxa!!\n\n";
        player_turn();
    }

    display_board();
}


bool gameover()
{

    for(int i=0; i<3; i++)
        if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] || Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
            return false;



    if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] || Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
        return false;


    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(Board[i][j] != 'X' && Board[i][j] != 'O')
                return true;


    draw = true;
    return false;
}



int main()
{
    cout<<"\t\t\t\t     -Inceput- \n";
    cout<<"\t\t\t\t    'X' si 'O' \t\t\t\t\t";
    cout<<"\n\t\t\t\t     Jucatori: \n\t\t\t";
    display_board();
    while(gameover())
    {

        player_turn();

    }

    if(turn == 'O' && draw == false)
    {
        cout<<"\n\nFelicitari!Jucatorul cu 'X' a castigat jocul!";
    }
    else if(turn == 'X' && draw == false)
    {
        cout<<"\n\nFelicitari!Jucatorul cu 'O' a castigat jocul!";
    }
    else
        cout<<"\n\nEgalitate!\n\n";
}

