// When the turn of any player comes...Dice rolls automatically and it gives all the details of all the moves

#include <bits/stdc++.h>
using namespace std;
#define blocks 100

unordered_map<int,int> board;

int roll_dice()
{
    int dice= rand()%6 +1;
    cout<<"You got "<<dice<<" on dice!!"<<endl;
    return dice;
}

void make_move(int player[],int active_ply,int dice,int &ladder)
{
    int pos=player[active_ply];
    
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
                cout<<"Moving you up to the postion "<<board[pos]<<endl;
            }
            else if(board[pos]<pos)
            {
                cout<<"ohh...there is a sanke at "<<pos<<"!"<<endl;
                cout<<"Moving you down to the postion "<<board[pos]<<endl;                
            }
            
            pos=board[pos];
        }
        
        player[active_ply]=pos;
    }
    else
    {
        cout<<"Can't move forward with "<<dice<<" on dice..."<<endl;
    }
    
    cout<<endl;
    
}


int main()
{
    
    for(int i=1;i<=blocks;i++)
       board[i]=-1;
       
    //ladders
    board[4]=14;
    board[9]=31;
    board[20]=38;
    board[28]=84;
    board[40]=59;
    board[51]=87;
    board[63]=81;
    board[71]=91;
    
    //snakes
    board[99]=78;
    board[95]=75;
    board[93]=73;
    board[87]=24;
    board[64]=60;
    board[62]=19;
    board[54]=34;
    board[17]=7;    
    
    
    int player[2]={1,1};
    int active_ply=0;
    int dice=-1;
//    char c; 
    srand(time(0));
    
    while(1)
    {
        cout<<"Player "<<active_ply+1<<" Turn.........."<<endl;
/*        cin>>c;
        
        if(c=='R' || c=='r')
        {*/
          int ladder=0;
          dice=roll_dice();
          make_move(player,active_ply,dice,ladder);
        
          if(player[active_ply]==100)
          {
            cout<<"Congrats....Player "<<active_ply+1<<" Won the game!!!"<<endl;
            cout<<endl;
            break;
          }
        
          if(dice==6)
          {
            cout<<"You got 6 on dice...It's Again your Turn!!"<<endl;  
            cout<<endl;
          }
          else if(ladder==1)
          {
            cout<<"You climbed the ladder...It's Again your Turn!!"<<endl;  
            cout<<endl;
          }
          else
            active_ply=1-active_ply;
            
/*        }
        else
        {
          cout<<"Please Enter correct key to roll the dice..."<<endl;
          cout<<endl;
        }  */
    }
    
    return 0;
}
