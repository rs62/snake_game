void read();

//8.INSTRUCTION DISP FUN
void read()
{
	system("cls");   
	box(77,24,1,0);
	gotoxy(15,6);
	printf("1. Use arrow keys to contol the direction of");
	gotoxy(15,7);
	printf("   motion of snake ");
	gotoxy(15,9);
	printf("2. Move to the eggs to collect them  ");
	gotoxy(15,11);
	printf("3. Collect 100 eggs to go to next level ");
	gotoxy(15,13);system("pause");
}