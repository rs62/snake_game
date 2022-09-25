void level(int lev);
int lev_ch();


//2.Level CREATOR
void level(int lev)
{
	int i,j,t,x=7,y=125,c=219;
    if(lev==2)
    {       
		for(y=162+2*51;y<900;y+=10*51)
		for(i=0;i<50;i++)
		{ 
			if((i>1&&i<5)||(i>11&&i<15)||i>21&&i<25||i>31&&i<35) 
			{
				gotoxy(a[y+i].x,a[y+i].y);
				printf("%c",c);
				a[y+i].sts=1;
			}                                    
		}      
    }
    else if(lev==3)
    {
		for(y=162+2*51;y<900;y+=10*51)
		for(i=0;i<50;i++)
		{ 
			if((i>1&&i<5)||(i>11&&i<15)||i>21&&i<25||i>31&&i<35)
			{
				gotoxy(a[y+i].x,a[y+i].y);
				printf("%c",c);
				a[y+i].sts=1; 
			}
			if(i==3||i==13||i==23||i==33)
			{
				for(j=y;j<900-2*51;j+=51)
				{
					gotoxy(a[j+i].x,a[j+i].y);
					printf("%c",c);
					a[j+i].sts=1;
				} 
			}                                    
		}
    }
	else if(lev==4)
	{
		for(y=162+2*51;y<900;y+=10*51)
		for(i=0;i<36;i+=3)
		{ 
			if((i>=0&&i<15)||i>18&&i<35)
			{
				gotoxy(a[y+i].x,a[y+i].y);
				printf("%c",c);a[y+i].sts=1;
			}                                    
			if(i==18)
			{
				for(t=417;t<645;t+=51)
				{
					gotoxy(a[t+i-1].x,a[t+i-1].y);
					printf("%c",c);a[t+i-1].sts=1;
				} 
			}
			if(i==0||i==33)
			{
				for(j=y;j<900-2*51;j+=2*51)
				{
					gotoxy(a[j+i].x,a[j+i].y);
					printf("%c",c);a[j+i].sts=1;
				}
			}                                    
		}          
	}
     else  ;  
}


//10.LEVEL CHANGE FUN
int lev_ch()
{
	int lev,i=6,j=6;

	system("cls");
	box(77,24,1,0); 
 
	gotoxy(25,i);
	printf("1.\tLevel 1");
	gotoxy(25,i+4);
	printf("2.\tLevel 2");
	gotoxy(25,i+8);
	printf("3.\tLevel 3");
	gotoxy(25,i+12);
	printf("4.\tLevel 4");
	j=opt(4);

	switch(j)
	{
		case 6:lev=1; return lev;
		case 10:lev=2; return lev;
		case 14:lev=3; return lev;
		case 18:lev=4; return lev;         
	}		   
}
