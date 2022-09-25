#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

void box(int,int ,int,int);
void gotoxy(short , short );



struct pos
{
	int x;int y;int sts;
} a[1400];

//1.BOX INITIATION FUN
void box_ini()
{
	int i,m,n,ct=0;
	for(m=2;m<=22;m++)
	{
		for(n=5;n<=55;n++)
		{
			++ct;
			a[ct].x=n;
			a[ct].y=m;
			if((n==5||n==55||m==2||m==22))
			a[ct].sts=1;
			else
			a[ct].sts=0;
		}
	}
}


// 3. function to draw box
void box(int l,int b,int x,int y) //l,b,x,y
{
	int i , j;
	gotoxy(x,y);
	for(j=y;j<=b+y;j++)
	if(j==y||j==(y+b))
	for(i=x;i<=(l+x);i++)
	{   
		if(j==y){gotoxy(i,j);printf("%c",220);}
		else    {gotoxy(i,j);printf("%c",223);}
	}
	else
	{ 
		gotoxy(x,j);     printf("%c",221);
		gotoxy(x+l,j);   printf("%c",222);
	}
}


// 4. function to change cursor pos
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 