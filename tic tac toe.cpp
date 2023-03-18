// a tic tac toe game made in C
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
char XO[3][3];
void reset()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			XO[i][j] = ' ';
		}
	}
}
void printPole()
{
	printf(" %c | %c | %c \n",XO[0][0],XO[0][1],XO[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n",XO[1][0],XO[1][1],XO[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n",XO[2][0],XO[2][1],XO[2][2]);
	printf("\n");
}
int slobodniMesta()
{
	int i,j,slobodni=9;
	for(i=2;i>=0;i--)
	{
		for(j=2;j>=0;j--)
		{
			if(XO[i][j]!=' ')
			slobodni--;
		}
	}
	return slobodni;
}
void igrac(char i)
{
	int x,y;
	if(slobodniMesta()>0)
	{
	do
	{
	printf("Odberi red i kolona: ");
	scanf("%i %i",&x,&y);
	x--;
	y--;
    if(XO[x][y]!=' ')
	{
		printf("Poleto e popolneto ili ne postoi.\n");
	} 
	else
	{
		XO[x][y]=i;
		break;
	}
    }
    while(XO[x][y]!=' ');
    }
}
void komp(char i)
{
	int x,y;
	x=rand()%3;
	y=rand()%3;
	if(XO[x][y]==' ')
	{
		XO[x][y]=i;
		return;
	}
	return komp(i);
}
char pobednik()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		if(XO[i][0]==XO[i][1]&&XO[i][0]==XO[i][2])
		return XO[i][0];
	}
	for(j=0;j<3;j++)
	{
		if(XO[0][j]==XO[1][j]&&XO[0][j]==XO[2][j])
		return XO[0][j];
	}
	if(XO[0][0]==XO[1][1]&&XO[0][0]==XO[2][2])
	return XO[0][0];
	if(XO[0][2]==XO[1][1]&&XO[0][2]==XO[2][0])
	return XO[0][2];
	return ' ';
}
int main()
{
	char IGRAC,KOMP,kraj;
	char izbor='y';
	int k;
	while(toupper(izbor)=='Y')
	{
	reset();
	srand(time(NULL));
	k=rand()%2+1;
	if(k==1)
	{
		IGRAC='X';
		KOMP='O';
		printf("Ovaa runda ti ides prv.\n");
	}
	else
	{
		IGRAC='O';
		KOMP='X';
	}
	printPole();
	do
	{
	if(k==1)
	{
		igrac(IGRAC);
		system("cls");
		printPole();
		komp(KOMP);
		system("cls");
		printPole();
	}
	else
	{
		komp(KOMP);
		system("cls");
		printPole();
		igrac(IGRAC);
		system("cls");
		printPole();
	}
	kraj=pobednik();
	}
	while(slobodniMesta()!=0 && pobednik()==' ');
	if(k==1)
	{
	if(kraj=='X')
	printf("Bravo pobedi!\n");
	else if(kraj=='O')
	printf("Izgubi od kompjuter...\n");
	else
	printf("Nereseno e!\n");
	}
	else
	{	
	if(kraj=='X')
	printf("Izgubi od kompjuter...\n");
	else if(kraj=='O')
	printf("Bravo pobedi!\n");
	else
	printf("Nereseno e!\n");
	}
	printf("Dali sakas da igras pak?\nnapisi ''Y'' za da ili ''N'' za ne: ");
	scanf("\n%c",&izbor);
	system("cls");
    }
    printf("Prijatno bakson!");
	return 0;
}
