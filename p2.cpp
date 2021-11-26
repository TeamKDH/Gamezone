#include<bits/stdc++.h>
using namespace std;
    char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char turn ='X';
    int row,column;
    bool draw=false;
    string p1,p2;

 //to display board
void display_board()
{
    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\t\t---------------------------------------"<<endl;    
    cout<<"\t\t\t\t|| T I C K   T A C   T O E   G A M E ||"<<endl;
    cout<<"\t\t\t\t---------------------------------------"<<endl<<endl;

    cout<<p1<<" [X]"<<"\t\t\t\t\t\t\t\t\t\t\t"<<p2<<" [O]"<<endl<<endl<<endl;
    
    cout<<"\t\t      |        |         \n";
    cout<<"\t\t"<<board[0][0]<<"     |   "<<board[0][1]<<"    |    "<<board[0][2]<<"         \n";
    cout<<"\t\t______|________|________ \n";
    cout<<"\t\t      |        |         \n";
    cout<<"\t\t      |        |         \n";
    cout<<"\t\t"<<board[1][0]<<"     |   "<<board[1][1]<<"    |    "<<board[1][2]<<"         \n";
    cout<<"\t\t______|________|_________\n";
    cout<<"\t\t      |        |         \n";
    cout<<"\t\t      |        |         \n";
    cout<<"\t\t"<<board[2][0]<<"     |   "<<board[2][1]<<"    |    "<<board[2][2]<<"         \n";
    cout<<"\t\t      |        |         \n"; 
}

void player_turn()
{    
        int choice;
        if(turn=='X')
    cout<<endl<<p1<<" [X] Turn: ";
    else if(turn=='O')
    cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t\t"<<p2<<" [O] Turn: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        row=0; column=0;
        break;
        case 2:
        row=0; column=1;
        break;
        case 3:
        row=0; column=2;
        break;
        case 4:
        row=1; column=0;
        break;
        case 5:
        row=1; column=1;
        break;
        case 6:
        row=1; column=2;
        break;
        case 7:
        row=2; column=0;
        break;
        case 8:
        row=2; column=1;
        break;
        case 9:
        row=2; column=2;
        break;
    }
    if(turn=='X'&&board[row][column]!='X'&&board[row][column]!='O')
    {
        board[row][column]='X';
        turn='O';
    }
    else if(turn=='O'&&board[row][column]!='X'&&board[row][column]!='O')
    {
        board[row][column]='O';
        turn='X';
    }    
}

bool game_over()
{
    //checking winner
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
        return false;
        else if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
        return false;
       else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
        return false;
       else if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        return false;
    }

    //if there is any box not filled
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X'&&board[i][j]!='O')
            return true;
        }
    }

    //if match draw
    draw=true;
    return false;
}

int main()
{    
     system("cls");
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t\t||W E L C O M E  T O  T H E  G A M E||"<<endl;
    cout<<"\t\t\t\t---------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\tFIRST PLAYER NAME: ";
    getline(cin,p1);
    cout<<endl;
    cout<<"\t\t\t\tSECOND PLAYER NAME: ";
    getline(cin,p2);
    system("cls");
    cout<<endl<<endl<<endl;
    int oops;
    cout<<"\t\t\t\t A R E  Y O U  R E A D Y "<<endl<<endl<<endl; 
    cout<<"\t\t\t\tP L Z  C L I C K  A N Y  N U M B E R: "<<endl;
    cin>>oops;   
    while(game_over())
 {   
    display_board(); 
    player_turn();          
 }
 display_board();
 if(turn=='X'&&!draw)
 cout<<endl<<endl<<"\t\t\t******************"<<p2<<" [O] Wins!! Congratulations******************"<<endl;
 else if(turn=='O'&&!draw)
 cout<<endl<<endl<<"\t\t\t******************"<<p1<<" [X] Wins!! Congratulations******************"<<endl;
 else
 cout<<endl<<endl<<"\t\t\t:::::::::::::   M A T C H   D R A W    ::::::::::::::"<<endl<<endl<<endl<<endl<<endl<<endl;
 return 0;
}
