#include "snake.c"

int main()
{
	snake();
	system("cls");
	box(MAIN_BOX_LENGHT, MAIN_BOX_HEIGHT, MAIN_BOX_START_X, MAIN_BOX_START_Y);
	gotoxy(15,MAIN_BOX_HEIGHT/2 );
	printf("HOPE U ENJOYED PLAYING & U HAD A FUN TIME !!!!!");
	gotoxy(15,(MAIN_BOX_HEIGHT/2)+2);
	printf("                Thanx for PLAYING !!!!!");
	getch();
	return 0;
}
