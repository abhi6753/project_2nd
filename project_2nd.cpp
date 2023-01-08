//Program a two-person game of Tic -Tac- Toe. 
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
char player1[50],player2[50];
int withPlayer();
void firstPlayer(char x,int*,int*);
void secondPlayer(char x,int*,int*);
int winner(char,char,int,int);
void print();
inline int menu();
void smartComputer();
int symbol(char,int,int,int*,int*);
void submenu(int);
int winnercomputer(char,int,int);
void draw();
void evilComputer();
void Evil_symbol(int,int);
void smartComputer()
{
    system("cls");
   // cout<<"########################### Tic Tac Toe ###########################"<<endl;
    char x;
    int row,col,r,c;
    int p1=0,p2=0;
    char X = 'X';
    char O = 'O';
    int z=0,count;
    cin.ignore();
    cout<<"Enter your name: ";
    cin.getline(player1,50);
    strcpy(player2,"Computer");
    print();
    for(short i=0;i<9;i++)
    {
        if(i%2==0)
        {
           in:cout<<"Player 1, Enter Marking Place: "; 
           cin>>x;
            for(short int j=0;j<3;j++)
            {
                for(short int k =0;k<3;k++)
                {
                    if(arr[j][k]==x)
                    {
                       z=1; // agr player 1 pe chl diya hai to uspe fir agr dusra player 1 ko hi select kre\
                       to uska moves n mana jaaye
                       break;
                    }
                }
                if(z==1)
                  break;
            }
            if(z==0)
            {
                print();
                goto in;
            }
            firstPlayer(x,&row,&col);
            z=0;
            print();
           
            p1 = winner(X,x,row,col); 
            if(p1==3)
            {
                if(player1[0]==10||player1[0]==9||player1[0]==32||player1[0]==13)
                    cout<<"Player 1 winner\n\n";
                else
                {
                   cout<<"Congratulations "<<player1<<", You're Winner\n\n";
                } 
                submenu(1);  
            }
        }
        else
        {
            count = symbol(x,row,col,&r,&c);
            if(count==2) // player 1 symbol value
            {
                arr[r][c]=O;
                print();
            }   
            else
            {
               for(int i =0;i<3;i++)
               {
                 for(int j = 0;j<3;j++)
                 {
                   if(arr[i][j]>48&&arr[i][j]<=57)
                   {
                     arr[i][j] = O;
                     r=i;
                     c=j;
                     z=1;
                     break;
                   }    
                 }
                 if(z==1)
                  break;
               } 
               z=0;
               print();
            }
            p2=winnercomputer(O,r,c);
            if(p2==3)
            {
              cout<<"You loose\n\n";
              submenu(1);
            }
        }
    }
    if(p1!=3&&p2!=3)
    {
        draw(); 
        submenu(1);
    }
}
int symbol(char x,int row,int col,int *r,int *c)
{
    int count=0;
    char X = 'X';
    bool z=0;
    //check by row
    for(int i=row;i<row+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==X)
            {
                ++count;
            }
        }
        if(count==2)
        {
           for(int i=row;i<row+1;i++)
           {
              for(int j=0;j<3;j++)
              {
                  if(arr[i][j]>48&&arr[i][j]<=57)
                  {
                    *r=i;
                    *c=j;
                    z=1;
                    break;
                  }
              }
              break;
           }
           if(z==1)
            return count;
        }
        else
         count=0;
    }
    //check by coloumn
    for(int i=col;i<col+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[j][i]==X)
            {
                ++count;
            }   
        }
        if(count==2)
        {
            z=0;
           for(int i=col;i<col+1;i++)
           {
              for(int j=0;j<3;j++)
              {
                if(arr[j][i]>48&&arr[j][i]<=57)
                {
                    *r=j;
                    *c=i;
                   z=1;
                   break;
                }
              }
              break;
           }
           if(z==1)
           return count;
        }
        else
         count =0;       
    }
    // check by diagonaly start from col = 0
    if(x=='1'||x=='5'||x=='9')
    {
      for(int i =0;i<3;i++)
      {
        if(arr[i][i]==X)
        {
            ++count;
        }
        if(count==2)
        {   z=0;
            for(i=0;i<3;i++)
            {
                if(arr[i][i]>48&&arr[i][i]<=57)
                {
                    *r=i;
                    *c=i;
                     z=1;
                     break;
                }
            }
           if(z==1)
            return count;
        }

      }
        count =0;
    }
     // check by diagonaly start from col = 2
    if(x=='3'||x=='5'||x=='7')
    {
        for(int i = 0;i<3;i++)
        {   
          for(int j = 2;j>=0;j--)
          {
            if(arr[i][j]==X)
            {
              ++count;
            }
            i++;
            if(count == 2)
            {
                for(i=0;i<3;i++)
                {
                    for(int j=2;j>=0;j--)
                    {
                        if(arr[i][j]>48&&arr[i][j]<=57)
                        {
                            *r=i;
                            *c=j;
                            z=1;
                            break;
                        }
                        i++;
                    }
                    if(z==1)
                     return count;
                }  
            } 
           }
        }
    }
    return count=0;
}
void submenu(int menunum)
{
    int ch;
    cout<<"\n\nDo you want to play again ??\n";
    cout<<"Press 1 for YES\tPress 0 for MENU\n";
    cin>>ch;
    char value='1'; //1 se 9 tk fir revalue krne k liye
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                arr[i][j]=value++;
            }
        }
    if(ch==1)
    {
        if(menunum==1)
         smartComputer();
        else if(menunum==2)
          evilComputer();
        else
         withPlayer();
    }   
    else
      menu();
}
void draw()
{
    cout<<"Ohhh!!! Match Draw";
}
int winnercomputer(char O,int row,int col)
{
    int count =0;
    //by row
    for(int i=row;i<row+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==O)
            {
               ++count;
            }
        }
        if(count==3)
          return count;
        else
         count =0;
    }
   // by col
    for(int i=col;i<col+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[j][i]==O)
            {
               ++count;
            }
        }
        if(count==3)
          return count;
        else
         count =0;
    }   
  // diagonally
  if(arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')
  {
     count =3;
     return count;
  }
  count =0;
  if(arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O')
  {
     count =3;
     return count;
  }
  count =0;
  return count;

}
void print()
{
    system("cls");
    cout<<"########################### Tic Tac Toe ###########################"<<endl;
    cout<<"Player 1: "<<player1<<" X"<<endl;
    cout<<"Player 2: "<<player2<<" O"<<endl<<endl<<endl;
    for(int i=0;i<3;i++)
    {
      cout<<"    |     |     "<<endl;
      for(int j=0;j<3;j++)
      {
        if(j!=2)
        printf("  %c | ",arr[i][j]);
        else 
        printf("  %c  ",arr[i][j]);
       }
       printf("\n");
       cout<<"____|_____|_____"<<endl;
    }
    cout<<"\n###################################################################"<<endl<<endl;
}
int menu()
{ 
    system("cls");
    short int ch;
   cho: cout<<"Enter your choice"<<endl;
    cout<<"1. Want to play with Smart Computer"<<endl;
    cout<<"2. Want to play with Evil Computer"<<endl;  
    cout<<"3. Want to play with player"<<endl;
    cout<<"4. Exit"<<endl; 
    cin>>ch;
    switch (ch)
    {
    case 1:
        smartComputer();
        break;
    case 2:
        evilComputer();
        break;
    case 3:
      withPlayer();
        break;
    case 4:
        return 0;
    default:
         cout<<"Error!! Enter valid choice"<<endl;
        goto cho;
    }
    cin.get();
    return 0;
}
int main()
{
    menu();
    return 0;
}
void evilComputer()
{
    system("cls");
    char x;
    int row,col,r,c;
    int p1=0,p2=0;
    char X = 'X';
    char O = 'O';
    int z=0,count;
    cout<<"Enter Your name: ";
    cin.ignore();
    cin.getline(player1,50);
    strcpy(player2,"Computer");
    print();
    for(short i=0;i<9;i++)
    {
        if(i%2==0)
        {
           in:cout<<"Player 1, Enter Marking Place: "; 
           cin>>x;
            for(short int j=0;j<3;j++)
            {
                for(short int k =0;k<3;k++)
                {
                    if(arr[j][k]==x)
                    {
                       z=1; // agr player 1 pe chl diya hai to uspe fir agr dusra player 1 ko hi select kre\
                       to uska moves n mana jaaye
                       break;
                    }
                }
                if(z==1)
                  break;
            }
            if(z==0)
            {
                print();
                goto in;
            }
              firstPlayer(x,&row,&col);
            z=0;
            print();
           
            p1 = winner(X,x,row,col); 
            if(p1==3)
            {
                if(player1[0]==10||player1[0]==9||player1[0]==32||player1[0]==13)
                    cout<<"Player 1 winner\n\n";
                else
                {
                   cout<<"Congratulations "<<player1<<", You're Winner\n\n";
                } 
                submenu(1);  
            }
        }
        else
        {
            count = symbol(x,row,col,&r,&c);
            if(count==2) // player 1 symbol value
            {
                arr[r][c]=O;
                print();
                p2=winnercomputer(O,r,c);
                if(p2==3)
                {
                    goto ch;
                }
                Evil_symbol(row,col);
                print();
            }   
            else
            {
               for(int i =0;i<3;i++)
               {
                 for(int j = 0;j<3;j++)
                 {
                   if(arr[i][j]>48&&arr[i][j]<=57)
                   {
                     arr[i][j] = O;
                     r=i;
                     c=j;
                     z=1;
                     break;
                   }    
                 }
                 if(z==1)
                  break;
               } 
               z=0;
               print();
            }
            p2=winnercomputer(O,r,c);
            ch:if(p2==3)
            {
              cout<<"You loose\n\n";
              submenu(2);
            }
        }
        z=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[i][j]>48&&arr[i][j]<=57)
                {
                    z=0;
                    break;
                }
            }
            if(z==0)
            {
                break;
            }
        }
        if(z==1)
        {    
            goto draw;
        }
    }
draw:if(p1!=3&&p2!=3)
    {
        draw(); 
        submenu(2);
    }
}
void Evil_symbol(int row,int col)
{
    int count =0;
    char X = 'X';
    bool z=0;
    for(int i=row;i<row+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==X)
            {
                ++count;
            }
        }
    }
    if(count==2)
    {
        for(int i=row;i<row+1;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[i][j]>48&&arr[i][j]<=57)
                {
                    arr[i][j]='O';
                    break;
                }
            }
            break;
        }
    }
    //for col
    for(int i=col;i<col+1;i++)
    {
        count =0;
        for(int j=0;j<3;j++)
        {
            if(arr[j][i]==X)
            {
                ++count;
            }   
        }
    }
    if(count==2)
    {
        for(int i=col;i<col+1;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[j][i]>48&&arr[j][i]<=57)
                {
                   arr[j][i]='O';
                   break;
                }
            }
            break;
        }
    }  
    count =0;
    for(int i =0;i<3;i++)
    {
        
        if(arr[i][i]==X)
        {
            ++count;
        }
    }
    if(count==2)
    {   
        for(int i=0;i<3;i++)
        {
            if(arr[i][i]>48&&arr[i][i]<=57)
            {
                arr[i][i]='O';
                break;
            }
        }
    }
    count =0;
    for(int i = 0;i<3;)
    {   
        for(int j = 2;j>=0;j--)
        {
            if(arr[i][j]==X)
            {
              ++count;
            }
            i++;
        }     
    }
    if(count==2)
    {
        for(int i = 0;i<3;)
       {   
          for(int j = 2;j>=0;j--)
          {
            if(arr[i][j]>48&&arr[i][j]<=57)
            {
                arr[i][j]='O';
                break;
            }
            i++;
          }     
       }
    }
}
int withPlayer()
{
    system("cls");
    cin.ignore();
    cout<<"Enter name of player 1 : ";
    cin.getline(player1,50);
    cout<<"Enter name of player 2 : ";
    cin.getline(player2,50);
    if(player1[0]>=97&&player1[0]<=122)
    {
        player1[0]=player1[0]-32;
    }
    if(player2[0]>=97&&player2[0]<=122)
    {
        player2[0]=player2[0]-32;
    }
    print();
    char x;// to input location to put player symbol
    int row,col;
    short p1=0,p2=0;
    char X = 'X';
    char O = 'O';
    bool ch,z=0;//choice
    //int limt =3;// agr 3 baar z ka value wrong ho to game exit ho jaaye
    for ( short int i = 0; i < 9; i++)
    {  
        if(i%2==0)//even
        {
           in: cout<<"player 1, Enter Marking Place: ";
            cin>>x;
            for(short int j=0;j<3;j++)
            {
                for(short int k =0;k<3;k++)
                {
                    if(arr[j][k]==x)
                    {
                       z=1; // agr player 1 pe chl diya hai to uspe fir agr dusra player 1 ko hi select kre\
                       to uska moves n mana jaaye
                       break;
                    }
                }
                if(z==1)
                  break;
            }
            if(z==0)
            {
                print();
                goto in;
            }
            firstPlayer(x,&row,&col);
            z=0;
            print();
           
            p1 = winner(X,x,row,col); 
            if(p1==3)
            {
                if(player1[0]==10||player1[0]==9||player1[0]==32||player1[0]==13)
                    cout<<"Player 1 winner\n\n";
                else
                 cout<<"Congratulations "<<player1<<", You're Winner\n\n";
                submenu(3);
              
            }
        }
        else//odd
        {
           in2: cout<<"player 2, Enter Marking Place: ";
            cin>>x;
            for(short int j =0;j<3;j++)
            {
                for(short int k =0;k<3;k++)
                {
                    if(arr[j][k]==x)
                    {
                       z=1;
                       break;
                    }
                }
                if(z==1)
                 break;
            }
            if(z==0)
            {
                print();
                goto in2;
            }
           secondPlayer(x,&row,&col);
           z=0;
           print();
           p2= winner(O,x,row,col);
            if(p2==3)
            {
              
                if(player2[0]==10||player2[0]==9||player2[0]==32||player1[0]==13)
                    cout<<"Player 1 winner\n\n";
                else
                    cout<<"Congratulations "<<player2<<", You're Winner\n\n";
               submenu(3);
            }
        }      
    }
    if(p1!=3&&p2!=3)
    {
        cout<<"Ohhh!!! Match Draw";
        submenu(3);
    } 
}
void firstPlayer(char x,int* row,int *col)
{
    for(short int i=0;i<3;i++)
    {
        for(short int j=0;j<3;j++)
        {
            if(arr[i][j]==x)
            {
                arr[i][j] = 'X';//X
                *row = i;
                *col = j;
                break;
            }
        }
    }
}
void secondPlayer(char x,int* row,int *col)
{
    for(short int i=0;i<3;i++)
    {
        for(short int j=0;j<3;j++)
        {
            if(arr[i][j]==x)
            {
                arr[i][j] = 'O';//O
                *row = i;
                *col = j;
                break;
            }
        }
    }
}          
int winner(char X,char x,int row,int col)
{
    short int count=0; // count player symbol

    // check by row
    for(int i=row;i<row+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==X)
            {
                ++count;
            }
        }
        if(count!=3)
        {
            count =0;
            break;
        }    
        else
          return count; //
    }
    //check by coloumn
    for(int i=col;i<col+1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[j][i]==X)
            {
                ++count;
            }
             
        }
        if(count!=3)
        {
            count =0;
            break;
        }
        else
        {
            return count;
        }
         
    }
    // check by diagonaly start from col = 0
    if(x=='1'||x=='5'||x=='9')
    {
      for(int i = 0;i<3;i++)
      {
        if(arr[i][i]==X)
        {
            ++count;
        }
        if(count==3)
        {
            return count;
        }
      }
    }
    // check by diagonaly start from col = 2
    if(x=='3'||x=='5'||x=='7')
    {
        count =0;
        for(int i = 0;i<3;i++)
        {   
          for(int j = 2;j>=0;j--)
          {
            if(arr[i][j]==X)
            {
              ++count;
            }
            i++;
           }
          if(count == 3)
           return count;
        }
    }
    return count=0;
}