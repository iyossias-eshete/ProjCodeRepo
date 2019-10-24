#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<iostream.h>
#include<fstream.h>

void moveBrick(int &,int &);
void drawWorld();
void drawPlayer();
void movePlayer(int &,int &,int &);
void gravity(int &,int &,int & );
void up(int &,int &,int &);
void check(int ); //checks if the player avoided the obstacle or not
void play(int &);
void displayScore(int );

int brick[4]={0,0,0,0};//Holds the position of the brick(moving obstacle)
int ball[2]={0,0};//Holds the coordinates of the circle

struct player{
int score;
char name[15];
};


int main()
{
int gd=DETECT,gm;

initgraph(&gd,&gm,"C:\\TurboC++\\Disk\\TurboC3\\BGI");
int score=1;
drawWorld();
drawPlayer();
play(score);

getch();
closegraph();
return 0;
}

void drawWorld()
{
	
int *b;
//bricks
setcolor(6);
setfillstyle(1,6);
rectangle(0,370,40,415);
rectangle(8,378,32,407);
line(0,370,8,378);
line(0,415,8,407);
line(32,378,40,370);
line(32,407,40,415);
floodfill(10,375,6);
floodfill(5,385,6);
floodfill(15,385,6);
setcolor(0);
rectangle(8,378,32,407);
line(0,370,8,378);

//bricks line 2nd
setcolor(6);
setfillstyle(1,6);
rectangle(0,415,40,460);
rectangle(8,423,32,452);
line(0,415,8,423);
line(0,460,8,452);
line(32,423,40,415);
line(32,452,40,460);
floodfill(10,420,6);
floodfill(5,430,6);
floodfill(15,430,6);
setcolor(0);
rectangle(8,423,32,452);
line(0,415,8,423);
setcolor(6);
rectangle(0,370,40,460);
getimage(0,370,40,460,b);
for(int i=40;i<=700;i=i+40)
{
putimage(i,370,b,COPY_PUT);
}
setcolor(4);
setfillstyle(1,9);
rectangle(0,0,600,370);
floodfill(150,100,4);

////////// break walls
setcolor(6);
setfillstyle(1,6);
rectangle(130,190,170,235);
floodfill(132,200,6);

//Small Bricks
//first line
setcolor(0);
setfillstyle(1,8);
rectangle(130,190,143,199);
floodfill(132,192,0);
setfillstyle(1,8);
rectangle(145,190,158,199);
floodfill(147,192,0);
setfillstyle(1,8);
rectangle(160,190,170,199);
floodfill(162,192,0);

//second line
setfillstyle(1,8);
rectangle(130,202,138,211);
floodfill(132,205,0);
setfillstyle(1,8);
rectangle(140,202,155,211);
floodfill(142,204,0);
setfillstyle(1,8);
rectangle(157,202,170,211);
floodfill(159,204,0);

//thrd line
setfillstyle(1,8);
rectangle(130,214,143,223);
floodfill(132,216,0);
setfillstyle(1,8);
rectangle(145,214,158,223);
floodfill(147,216,0);
setfillstyle(1,8);
rectangle(160,214,170,223);
floodfill(162,216,0);

//4th line

setfillstyle(1,8);
rectangle(130,226,138,235);
floodfill(132,228,0);
setfillstyle(1,8);
rectangle(140,226,155,235);
floodfill(142,228,0);
setfillstyle(1,8);
rectangle(157,226,170,235);
floodfill(159,228,0);

/////////////////////////////
///////////// clouds
setcolor(15);
setfillstyle(1,15);
arc(40,43,40,180,10);
arc(25,50,60,180,10);
arc(14,60,90,270,9);
arc(25,65,180,330,10);
arc(42,65,210,360,10);
arc(57,60,240,20,10);
arc(55,40,0,180,9);
arc(69,50,250,120,10);
floodfill(50,55,15);
ellipse(78,70,0,360,10,3);
floodfill(80,71,15);
ellipse(89,80,0,360,8,2);
floodfill(91,81,15);

//cloud 2
setfillstyle(1,15);
arc(450,43,40,180,10);
arc(435,50,60,180,10);
arc(424,60,90,270,9);
arc(435,65,180,330,10);
arc(452,65,210,360,10);
arc(467,60,240,20,10);
arc(465,40,0,180,9);
arc(479,50,250,120,10);
floodfill(455,55,15);
ellipse(488,70,0,360,10,3);
floodfill(490,71,15);
ellipse(499,80,0,360,8,2);
floodfill(500,81,15);

}


void moveBrick(int &score,int &speed)
{
  
  static int i=0;

  if( i < 555 )
{

  //moving obstacle
setcolor(6);
setfillstyle(1,6);
rectangle(555-i,320,595-i,365);
floodfill(557-i,330,6);

//First Line
setcolor(0);
setfillstyle(1,8);
rectangle(555-i,320,568-i,329);
floodfill(557-i,322,0);
setfillstyle(1,8);
rectangle(570-i,320,583-i,329);
floodfill(572-i,322,0);
setfillstyle(1,8);
rectangle(585-i,320,595-i,329);
floodfill(587-i,322,0);

//Second Line
setfillstyle(1,8);
rectangle(555-i,332,563-i,341);
floodfill(557-i,335,0);
setfillstyle(1,8);
rectangle(565-i,332,580-i,341);
floodfill(567-i,334,0);
setfillstyle(1,8);
rectangle(582-i,332,595-i,341);
floodfill(584-i,334,0);

//Third Line
setfillstyle(1,8);
rectangle(555-i,344,568-i,353);
floodfill(557-i,346,0);
setfillstyle(1,8);
rectangle(570-i,344,583-i,353);
floodfill(572-i,346,0);
setfillstyle(1,8);
rectangle(585-i,344,595-i,353);
floodfill(587-i,346,0);

//Fourth Line
setfillstyle(1,8);
rectangle(555-i,356,563-i,365);
floodfill(557-i,358,0);
setfillstyle(1,8);
rectangle(565-i,356,580-i,365);
floodfill(567-i,358,0);
setfillstyle(1,8);
rectangle(582-i,356,595-i,365);
floodfill(584-i,358,0);



if(i<555)
{
setcolor(9);
rectangle(555-i,320,595-i,365);
delay(0);
setcolor(2);
   }


    // The below Statement is used for storing the coordinates of the brick
    brick[0]=555-i;
    brick[1]=320;
    brick[2]=595-i;
    brick[3]=365;

    delay(speed);
    i++;
 }
if( i == 555)
{
  i=0;
  if(speed > 0)
  {
  speed --;
  }
  score ++;

}

}

void drawPlayer()
{
setcolor(2);
circle(300,345,20);
setfillstyle(SOLID_FILL,2);
floodfill(300,345,2);
ball[0]=300;
ball[1]=345;
}

void movePlayer(int &i,int &j,int &airball)
{

     int x=0,y=0,movem;//x and y are used for changing the coordinates during movement
      movem=getch();//Stores the key pressed by the player
      if(movem==72 && airball == 0) // For Moving up
	{
	   if(j == 345 )
	   {
	   airball=2;
	   }
	   if(j<=285)//used to avoid the ball from going too high
	    {
	    y=0;
	    }
	  else
	  {
	  x=0;
	  y=-1;
	  }
	  if(j<=255)
	  {
	  airball = 1;
	  }
	}

	if(movem == 27) //For using <ESC> key to exit
	{
	exit(0);
	}


      ball[0]=i;
      ball[1]=j;

  }

 
void gravity(int &i,int &j,int &airball)
{
      if( kbhit() )
      {
      char movem;
      movem=getch();
      if(movem == 27) //For using <ESC> key to exit
	{
	exit(0);
	}
      }
	// Used to draw a circle similar to the background
	// as a means of clearing the screen
      setcolor(9);
      circle(i,j,20);
      setfillstyle(SOLID_FILL,9);
      floodfill(i,j,9);

      //The new position is set below
      j=j+1;
      setcolor(2);
      circle(i,j,20);
      setfillstyle(SOLID_FILL,2);
      floodfill(i,j,2);

      ball[0]=i;
      ball[1]=j;

      if(j >= 345 )
      {
      airball=0;
      }
}

void up(int &i,int &j,int &airball)
{
 if( kbhit() )
      {
      char movem;
      movem=getch();
      if(movem == 27) //For using <ESC> key to exit
	{
	exit(0);
	}
      }
	// Used to draw a circle similar to the background
	// as a means of clearing the screen
      setcolor(9);
      circle(i,j,20);
      setfillstyle(SOLID_FILL,9);
      floodfill(i,j,9);

      //The new position is set below
      j=j-1;
      setcolor(2);
      circle(i,j,20);
      setfillstyle(SOLID_FILL,2);
      floodfill(i,j,2);

      ball[0]=i;
      ball[1]=j;

      if(j <= 255 )
      {
      airball=1;
      }
}

void check(int score)
{

// This function compares the coordinates of the ball and
// the brick so that the game can terminate when the ball
// touches the brick ie the coordinate of the ball is
// inbetween that of the bricks

  if(ball[0]>=brick[0] && ball[0]<=brick[2])  // Checks the x coordinates

    {
     if(ball[1]+20>=brick[1] && ball[1]-20<=brick[3]) // Checks the y coordinates
	    {
	     //the 20 in the if statement specifies the radius of the ball
	     setcolor(4);
	     cleardevice();
	     floodfill(40,40,7);
	     char displayscore[20];
	     player game;
	     game.score=score;

	     outtextxy(250,100,"GAME OVER !!!");
	     sprintf(displayscore,"SCORE %d",score);//used to store score variable
	     outtextxy(250,200,displayscore); //used to display score variable
	     outtextxy(250,250,"DONE BY:");
	     outtextxy(250,300,"IYOSSIAS GETACHEW");
	     outtextxy(250,350,"NESANET  GAMERO");
	     outtextxy(250,400,"TENSAE   NEGUSSIE");
	     outtextxy(250,450,"ENTER YOUR NAME:");
	     scanf("%d",&game.name);

	     fstream outScore("Score.bin",ios::binary|ios::in|ios::out|ios::app);
	     outScore.write((char *)& game,sizeof(player));
	     while(!outScore.eof() )
	     {
	     cleardevice();
	     static int x=50,y=50;
	     if(outScore.read((char *)& game,sizeof(player)) )
	     {
	     char scores[7];
	     sprintf(scores,"%d",game.score);
	     outtextxy(x,y,game.name);
	     outtextxy(x,y,scores);
	     x=x+20; y=y+20;
	     }
	     }
	     outScore.close();
	     getch();
	     exit(1);
	     getch();

	    }

    }

}

void displayScore(int score)
{
setcolor(7);
bar(0,0,100,7);
setfillstyle(SOLID_FILL,7);

 char displayscore[20];
 sprintf(displayscore,"  Score %d",score);//used to store score variable
 outtextxy(0,0,displayscore); //used to display score variable


}



void play(int &score)
{
  int go=1;//Used as a condition for the loop to keep on iterating
  static int pox=300,poy=345;//x and j are the initial coordinates of the ball
  int airball=0;//Specifies the location of the ball (air or not)
  int speed=15;//used to change delay time as the game goes on
  while( go ==1 )
  {
  moveBrick(score,speed);
    if ( kbhit () && airball==0 )
       {
	movePlayer(pox,poy,airball);
       }
    if (airball == 2)
    {
    up(pox,poy,airball);
    }
    if (airball == 1)
    {
    gravity(pox,poy,airball);
    }
   displayScore(score);
   check(score);

  }


}
