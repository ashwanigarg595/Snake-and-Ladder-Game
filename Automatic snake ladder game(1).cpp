// When the turn of any player comes...Dice rolls automatically and it gives all the details of all the moves

#include <bits/stdc++.h>
using namespace std;
#define blocks 100

class snake_ladder
{
    public:
       unordered_map<int,int> board;  // snake-ladder board
       int n;            // number of players
       int players[2];   // array storing positions of all the players
       int active_ply;   // stores which player's turn is this
       int dice;         // number on dice 
       
       snake_ladder();       //constructor  
       void fill_ladders();  // fill the ladders in board
       void fill_snakes();   // fill the snakes in board
       void roll_dice();     // roll the dice
       void make_move(int &ladder);  //move the player who threw the dice
};

snake_ladder :: snake_ladder()
{
    n=2;
    active_ply=0;
    dice=-1;  

    for(int i=1;i<=100;i++)
      board[i]=-1;           
           
    for(int i=0;i<n;i++)
      players[i]=1;
}

void snake_ladder :: fill_ladders()
{
    //ladders
    board[4]=14;
    board[9]=31;
    board[20]=38;
    board[28]=84;
    board[40]=59;
    board[51]=87;
    board[63]=81;
    board[71]=91;          
}

void snake_ladder :: fill_snakes()
{
    //snakes
    board[99]=78;
    board[95]=75;
    board[93]=73;
    board[87]=24;
    board[64]=60;
    board[62]=19;
    board[54]=34;
    board[17]=7;             
}

void snake_ladder :: roll_dice()
{
    dice= rand()%6 +1;
    cout<<"You got "<<dice<<" on dice!!"<<endl;
}

void snake_ladder :: make_move(int &ladder)
{
    int pos=players[active_ply];
    
    if(pos+dice<=100)
    {
        pos+=dice;
        cout<<"Moved to "<<pos<<" after this throw"<<endl;
        
        if(board[pos]!=-1)
        {
            if(board[pos]>pos)
            {
                ladder=1;
                cout<<"Wow...there is a ladder at "<<pos<<"!"<<endl;
                cout<<"Moving you forward to the postion "<<board[pos]<<endl;
            }
            else if(board[pos]<pos)
            {
                cout<<"ohh...there is a sanke at "<<pos<<"!"<<endl;
                cout<<"Moving you backards to the postion "<<board[pos]<<endl;                
            }
            
            pos=board[pos];
        }
        
        players[active_ply]=pos;
    }
    else
    {
        cout<<"Can't move forward with "<<dice<<" on dice..."<<endl;
    }
    
    cout<<endl;
}

int main()
{
    srand(time(0));
    snake_ladder game;
    game.fill_ladders();
    game.fill_snakes();
    
//    char c;
    
    while(1)
    {
        cout<<"Player "<<game.active_ply+1<<" Turn......"<<endl;
/*        cin>>c;
        
        if(c=='R' || c=='r')
        {*/
          int ladder=0;
          game.roll_dice();
          game.make_move(ladder);
        
          if(game.players[game.active_ply]==100)
          {
            cout<<"Congrats....Player "<<game.active_ply+1<<" Won the game!!!"<<endl;
            cout<<endl;
            break;
          }
        
          if(game.dice==6 || ladder==1)
          {
            cout<<"It's Again your Turn!!"<<endl;  
            cout<<endl;
          }
          else
            game.active_ply=1-game.active_ply;
            
/*        }
        else
        {
          cout<<"Please Enter correct key to roll the dice..."<<endl;
          cout<<endl;
        }  */
    }
    
    return 0;    
}


