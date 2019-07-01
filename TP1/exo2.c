#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLONNE 16
#define LIGNE 5

void affichage(char m[LIGNE][COLONNE]);
void animation(char a[LIGNE][COLONNE],char m[LIGNE][COLONNE]);

int	main(int argc, char const *argv[])
{
	char m[LIGNE][COLONNE]={{0},{0}};
	m[0][0]=' ';
	m[0][1]='+';
	m[0][2]='+';
	m[0][3]='+';
	m[0][4]=' ';
	m[0][5]='+';
	m[0][6]='+';
	m[0][7]='+';
	m[0][8]=' ';
	m[0][9]=' ';
	m[0][10]='+';
	m[0][11]=' ';
	m[0][12]=' ';
	m[0][13]=' ';
	m[0][14]='+';
	m[0][15]=' ';

	m[1][0]=' ';
	m[1][1]='+';
	m[1][2]=' ';
	m[1][3]=' ';
	m[1][4]=' ';
	m[1][5]='+';
	m[1][6]=' ';
	m[1][7]='+';
	m[1][8]=' ';
	m[1][9]='+';
	m[1][10]=' ';
	m[1][11]='+';
	m[1][12]=' ';
	m[1][13]='+';
	m[1][14]='+';
	m[1][15]=' ';

	m[2][0]=' ';
	m[2][1]='+';
	m[2][2]='+';
	m[2][3]='+';
	m[2][4]=' ';
	m[2][5]='+';
	m[2][6]='+';
	m[2][7]='+';
	m[2][8]=' ';
	m[2][9]='+';
	m[2][10]=' ';
	m[2][11]='+';
	m[2][12]=' ';
	m[2][13]=' ';
	m[2][14]='+';
	m[2][15]=' ';

	m[3][0]=' ';
	m[3][1]=' ';
	m[3][2]=' ';
	m[3][3]='+';
	m[3][4]=' ';
	m[3][5]='+';
	m[3][6]='+';
	m[3][7]=' ';
	m[3][8]=' ';
	m[3][9]='+';
	m[3][10]=' ';
	m[3][11]='+';
	m[3][12]=' ';
	m[3][13]=' ';
	m[3][14]='+';
	m[3][15]=' ';

	m[4][0]=' ';
	m[4][1]='+';
	m[4][2]='+';
	m[4][3]='+';
	m[4][4]=' ';
	m[4][5]='+';
	m[4][6]=' ';
	m[4][7]='+';
	m[4][8]=' ';
	m[4][9]=' ';
	m[4][10]='+';
	m[4][11]=' ';
	m[4][12]=' ';
	m[4][13]=' ';
	m[4][14]='+';
	m[4][15]=' ';
	char a[LIGNE][COLONNE];
		
	int run=1;
	while (run==1)
	{
		animation(a,m);
		affichage(a);
		usleep(500000);
  		system("clear");
		animation(m,a);
		affichage(m);
		usleep(500000);
  		system("clear");
	}	
}

void affichage(char m[LIGNE][COLONNE])
{
	for (int i = 0; i < LIGNE; ++i)
		{
			for (int j = 0; j < COLONNE; ++j)
				printf("%c ",m[i][j]);
			printf("\n");	
		}
}

void animation(char a[LIGNE][COLONNE],char m[LIGNE][COLONNE])
{
	for (int i = 0; i < LIGNE; ++i)
		{
			for (int j = 0; j < COLONNE; ++j)
				if (j-1<0)
					a[i][j]=m[i][15];
				else 
					a[i][j]=m[i][j-1];	
		}
}
