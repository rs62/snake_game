#include<conio.h>
#include<time.h>

void delay(int );

int opt(int n_op);


// 5.delay time

void delay(int number_of_milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + number_of_milli_seconds)
        ;
}

//11.OPTION CONTROL FUN
int opt(int n_op)
{
	int j=6,ch=0,k;
	do
	{  
		gotoxy(24,j);
		if(kbhit())
		{
			ch=getch();
			if(ch==13)
			{
				return j;
			}

			else if(ch==224||ch==0)
			{
				k=getch();
				fflush(stdin);
						 
				if(k==72)    
				{  	
					if(j!=6) j-=4;   
					else j=6+(n_op-1)*4;
				}
				else if(k==80)  
				{  	
					if(j!=(6+(n_op-1)*4)) 
						j+=4;         
					else 
						j=6;
				}
			}
			else if(ch==49)//1
			j=6;
			else if(ch==50&&n_op>1)//2
			j=10;
			else if(ch==51&&n_op>2)//3
			j=14;
			else if(ch==52&&n_op>3)//4 
			j=18;  						
		}
	}while(ch!=13);				   
}
