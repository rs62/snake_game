#include "box.c"
#include "utils.c"
#include "snake_instruction.c"
#include "snake_level.c"

//#include <time.h>

#define MAIN_BOX_LENGHT 77
#define MAIN_BOX_HEIGHT 24
#define MAIN_BOX_START_X 1
#define MAIN_BOX_START_Y 0

int egg_gn();
int sn(int lev);
int  snake();


void clearScr_renderMainBox()
{
	system("cls");
	box( MAIN_BOX_LENGHT, MAIN_BOX_HEIGHT, MAIN_BOX_START_X, MAIN_BOX_START_Y);
}


//6.EGG GENERATOR
int egg_gn()
{
    int flag=0,egg;
      
    while(!flag)
    {                   
		egg=rand()%1020+51;  //printf("egg = %d",egg);   
		if(a[egg].sts==0)
		{flag=1;break;}
    }   //  printf("egg = %d",egg);
    gotoxy(a[egg].x,a[egg].y);
    printf("%c",233);
	return egg;
}
//7.SNAKE CONTROL FUN
int sn(int lev)
{   
	clearScr_renderMainBox();
	box_ini();
	box(50,20,5,2);
	int size=5,i=54,k=77,k1,ch,egg,d,p[1200],score=0;
	level(lev);
	p[0]=54;p[1]=53;
    egg= egg_gn();
	do
	{   k1=k;
		
        if(kbhit())
        {
			ch=getch();

			if(ch==32)
			{
				gotoxy(15,23);system("pause");
						gotoxy(15,23);printf("\t\t\t\t\t");
			}
			else if(ch==27)
			{
				break;
			}
			if(ch==224||ch==0)
			{
				k=getch();
				if(k1==80&&k==72||k1==72&&k==80||k1==77&&k==75||k1==75&&k==77)
				k=k1;
				fflush(stdin); //printf("k1= %d",k1);
			}
        }

	    switch(k)
		{
			case 80:p[0]+=51;                break; //down
			case 77:p[0]++;                  break; // right
			case 72:p[0]-=51;                break; //up
			case 75:--p[0];                  break; //left
		}

		if(a[p[0]].sts==1)   //p[0]= start pos of snake 
		{
			gotoxy(15,23);
			printf("\t\tGAME OVER !!!!!\t\t");
			getch();
			fflush(stdin);
			break;
		}
        for(i=size;i>0;i--)
        {
		    p[i]=p[i-1];
        }
		gotoxy(a[p[0]].x,a[p[0]].y);printf("%c",291);a[p[0]].sts=1;
		gotoxy(a[p[size-1]].x,a[p[size-1]].y);printf(" ");a[p[size-1]].sts=0;
		delay(100);
            

		if(p[0]==egg)
		{ 
			egg=egg_gn(); size++; score+=10; 
			if(score%500==0&&score>0&&lev!=4)
			{     
				clearScr_renderMainBox();
				gotoxy(25,15);
				printf("  CONGRATS!!! U HAVE COMPLEATED LEVEL %d",lev);
				gotoxy(25,17);
				printf("  PRESS ANY KEY TO GO TO NEXT LEVEL !!! ");
				getch();                

				clearScr_renderMainBox();
				box_ini();
				box(50,20,5,2); lev++;size=5;i=54;k=77;
				level(lev);
				p[0]=54;p[1]=53;
				egg= egg_gn(); 
			}
			  
			else if(score%100==0&&score>0&&lev==4)
			{
				clearScr_renderMainBox();
				gotoxy(25,15);
				printf("  CONGRATS!!! U HAVE COMPLEATED LEVEL %d",lev);
				gotoxy(25,17);
				printf("  THANX FOR PLAYING !!!");
				gotoxy(25,19);
				printf("  PRESS ANY KEY TO  !!!  TO CONTINUE ");
				getch();  return 0;     
			}                             
		}
		gotoxy(64,10);printf("Score: %d",score);
		gotoxy(64,5);printf("LEVEL: %d",lev);
		gotoxy(60,15);printf("Press Space bar");
		gotoxy(60,16);printf("   to pause");
		gotoxy(60,19);printf("Press Escape");
		gotoxy(60,20);printf("   to quit");
	  
	}while(1);
     
	clearScr_renderMainBox();
	gotoxy(25,12);
	printf("HOPE U ENJOYED PLAYING Snake !!!!!");
	gotoxy(25,14);
	printf("      Thanx for PLAYING !!!!!");
	getch();

	return 0; 
}

//9.SNAKE OPTIONS FUN
int  snake()
{    
	srand (time(NULL));/* initialize random seed: */
    int lev=1,i,j,gc=1;
	do
	{
		i=6;j=6;
		clearScr_renderMainBox();
		   
		gotoxy(25,i);
		printf("1.\tPlay SNAKE");
		gotoxy(25,i+4);
		printf("2.\tRead Instructions");
		gotoxy(25,i+8);
		printf("3.\tChoose Level");
		gotoxy(25,i+12);
		printf("4.\tQuit Game");
		
		j=opt(4);
		switch(j)
		{
			case 6: sn(lev);break;
			case 10:read();break;
			case 14:lev=lev_ch(); break;
			case 18:gc=0; break;         
		}	   
	}while(gc==1);
	
	return 0;
}
