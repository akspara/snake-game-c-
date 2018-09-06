//AKSHIT TIWARI
// VEY SIMPLE AND BASIC SNAKE GAME IN C++
//CREATED IN CODE::BLOCKS 13.12
//HEADER FILES
#include<ctime>
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<conio.h>
//GLOBAL VARIABLES

int main();
int play=0;
int c=0;
int gameover;
int print=0;
int arrow=0;
int x,y,fx,fy;
const int w=60;
const int h=20;
int score=0;
int tx[100],ty[100];
int nt;
int p,speed;

 void starting()
 {

	system("cls");
	cout<<"                    WELCOME"<<endl<<" "<<endl<<""<<endl;
	cout<<"                    TO"<<endl<<" "<<endl<<""<<endl;
	cout<<"                    SNAKE GAME"<<endl<<" "<<endl<<""<<endl;
   cout<<"                     press any key to continue";
   getch();
   system("cls");
    cout<<endl<<"                enter level no:"<<endl;
    cout<<"                      level no 1:(easy)"<<endl;
    cout<<"                      level no 2:(moderate)"<<endl;
    cout<<"                      level no 3:(hard)"<<endl;
    cout<<"                      (USE w,a,s,d not arrw keys)"<<endl;

    ppoy:

    cin>>p;

        switch(p)
    {
        case 1:
            speed=7000;
            break;
        case 2:
            speed=4000;
            break;
        case 3:
            speed=10;
            break;
        default:
            cout<<"enter right key"<<endl;
            goto ppoy;
    }

 }

void setup()
{

gameover=0;
  x=w/2;
  y=h/2;
  p:
  fx=rand()%60;
  fy=rand()%20;
  if(fx==0||fy==0||fx==w||fy==h)
    goto p;

}

//FOR MAP OF THE GAME
  void structure()
{  system("cls");
   for(int i=1;i<=h;i++)
   {    cout<<endl;
       for(int j=1;j<=w;j++)
       { if(j==1||j==w||i==1||i==h)
           cout<<"#";
           else if(j==x&&i==y)
           cout<<"O";//head
           else if(j==fx&&i==fy)
            cout<<"F";//fruit
            else
           { print=1;
                for(int k=0;k<nt;k++)
                {
                    if(tx[k]==j && ty[k]==i)
                    {cout<<"o";//o IS TAIL
                    print=0;}

                 }

                if(print)
                cout<<" ";}

        }

   }
   cout<<endl<<"score="<<score;
}

//funtion to detect the input W/A/S/D
void IN()
{
   if(kbhit())
 switch(getch())
    {  case 'w':
    arrow=1;
    if(c==3)
        arrow=3;
   break;
   case 'W':
    arrow=1;
    if(c==3)
        arrow=3;
   break;
   case 'A':
    arrow=2;
    if(c==4)
        arrow=4;
   break;
   case 'a':
   arrow=2;
   if(c==4)
    arrow=4;
   break;
   case 'S':
    arrow=3;
    if(c==1)
        arrow=1;
   break;
   case 's':
   arrow=3;
   if(c==1)
    arrow=1;
   break;
   case 'D':
    arrow=4;
    if(c==2)
        arrow=2;
   break;
   case 'd':
   arrow=4;
   if(c==2)
    arrow=2;
   break;
   default:
    break;

    } c=arrow;
}



  void logic()
 {      int prevx=tx[0];//logic for snake tail
         int prevy=ty[0];
         int prev2x,prev2y;
         tx[0]=x;ty[0]=y;
     for(int i=1;i<nt;i++)
     {
         prev2x=tx[i];
         prev2y=ty[i];
         tx[i]=prevx;
         ty[i]=prevy;
         prevx=prev2x;
         prevy=prev2y;

     }
     switch(arrow) //logic for  moving up and down
           { case 1: y--;
    break;
    case 2:  x--;
    break;
    case 3: y++;
    break;
    case 4: x++;
    break;
    default:
    break;
            }
  for(int k=0;k<nt;k++)
    {
        if(tx[k]==x&&ty[k]==y)
            {
                system("cls");
                cout<<"GAMEOVER";
                gameover=1;
                play=1;


            }
    }
    if(x>=w||x<=0||y>=h||y<=0)
    {


              system("cls");
              cout<<"GAMEOVER";
              gameover=1;
              play=1;

    }

       if(x==fx&&y==fy)
       {  score=score+10;
           level:
          fx=rand()%60;
          fy=rand()%20;
          if(fx==w||fx==0||fy==h||fy==0)
            goto level;
            nt++;
       }

 }

int main()
{    srand(time(NULL));

    starting();
    setup();
while(!gameover)
   {
    structure();
  for(int i=0;i<speed;i++)//to delay the spped can also use delay funtion but this was easy lol
  {
      for(int j=0;j<speed;j++)
      {

      }
  }
    IN();
    logic();

    }

return 1;
     }
