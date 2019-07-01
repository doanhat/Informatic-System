#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBR_ETU_MAX 100
#define NBR_UV_MAX 10
#define MAX 100 // taille max d'une chaine dans le fichier


typedef struct Etudiant
{
	int idEtu;
	char nom[30];
	char prenom[30];
	float moyenne;
}Etudiant;


int main(int argc, char *argv[])
{
    
    Etudiant etu[NBR_UV_MAX][NBR_ETU_MAX]; // les colonnes sont numérotées normalement (0,1,2,..)
    
    Etudiant etuNote[NBR_UV_MAX][NBR_ETU_MAX]; //les colonnes sont numérotées avec idEtu

	int type_fichier; // 0:LO21,1:NF16,2:SR01
	
	int ouvrir=1; // continuer à ouvrir des fichiers 
	
	char *nom_fichier=NULL;
	
	int nbre_etu=0,nbre_uv=0; 
	
	while (ouvrir==1)
	{

		printf("choissiez le fichier (0:LO21,1:NF16,2:SR01)\n");
		
		scanf("%d",&type_fichier);
		
		nbre_uv++; // calculer le nombre d'uv pour calculer la moyenne 
		
		switch (type_fichier )
		{
			case 0:nom_fichier="LO21.txt";
				   type_fichier=0;			
				   break;
			case 1:nom_fichier="NF16.txt";
				   type_fichier=1;
				   break;
			case 2:nom_fichier="SR01.txt";
			       type_fichier=2;			 
				   break;
		}
		
		FILE* fichier = NULL; 
		
		fichier = fopen(nom_fichier, "r"); // ouvrir du fichier
	    
	    char chaine[MAX] = ""; // chaîne vide de taille MAX
	    
	    int i=0;
	    
	    if (fichier != NULL) 
	    {
	        while (fgets(chaine, MAX, fichier)!=NULL)
	        {
	        	
	        	i++;
	        	
	        	int tmp=0;
	        	
	        	fscanf(fichier,"%d      %s                %s                           %f",&etu[type_fichier][i].idEtu,&etu[type_fichier][i].nom,&etu[type_fichier][i].prenom,&etu[type_fichier][i].moyenne); // récupérer des données
	        	
	        	printf("%d %s %s %.2f\n",etu[type_fichier][i].idEtu, etu[type_fichier][i].nom, etu[type_fichier][i].prenom, etu[type_fichier][i].moyenne );
	        	
	        	tmp = etu[type_fichier][i].idEtu;
	        	
	        	etuNote[type_fichier][tmp]=etu[type_fichier][i]; // on va traiter avec une matrice dans laquelle les colonnes sont numérotées selon idEtu

	        }
	        
	        nbre_etu=i; //nombre d'étudiants
	        
	        printf("vous avez choisi %d UV \n",nbre_uv);
	        
	        fclose(fichier);//fermer du fichier

	    }
	    else
	    {
	        // On affiche un message d'erreur sinon
	        printf("Impossible d'ouvrir le fichier\n");
	    }
		
		printf("ouvrir un autre fichier ?[0 = NON/1 = OUI]\n"); // on considère le cas dans lequel l'utilisateur ne veux ouvrir que deux fichier au lieu de 3 par example (LO21,NF16) ou (LO21,SR01)...
		
		scanf("%d",&ouvrir);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("tableau de la moyenne \n");
	printf("==============================\n");
	Etudiant moyEtu[NBR_ETU_MAX];
	int a=0;	
	for (int j = 0;j<NBR_ETU_MAX;j++)
	{
		
		float somme=0;
		
		for (int k = 0; k < 3; k++)
		
			if (etuNote[k][j].idEtu!=0) // dans l'intervalle  [0,NBR_ETU_MAX[ on ne récupère que des idEtu existants
			{
				a=k;
				somme+=etuNote[k][j].moyenne;
			}
			moyEtu[j]=etuNote[a][j];// quelque soit tel que l'étudiant existe dans la liste
			moyEtu[j].moyenne=somme/nbre_uv;
		
			if (moyEtu[j].moyenne!=0)
			{
				printf("idEtu: %d %s %s note: %f\n",j,moyEtu[j].nom,moyEtu[j].prenom,moyEtu[j].moyenne ); 
				printf("==============================\n");
			}
	}
	int ordre=0;
	while (ordre==0)
	{
		ordre =1;
		for (int l = 0; l < NBR_ETU_MAX; l++)
		{
			if (moyEtu[l+1].moyenne>moyEtu[l].moyenne)
			{
				Etudiant tmp;				//des instructions pour trier le tableau
				tmp = moyEtu[l+1];
				moyEtu[l+1]=moyEtu[l];
				moyEtu[l]=tmp;
				ordre=0;
				
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("TABLEAU TRIE \n");
	printf("==============================\n");
	for (int i = 0; i < NBR_ETU_MAX; ++i)
		if (moyEtu[i].idEtu!=0)
		{
			printf("idEtu: %d note: %f\n",moyEtu[i].idEtu,moyEtu[i].moyenne ); 
			printf("==============================\n");
		}
	FILE* fichier_final = NULL; 
		
	fichier_final = fopen("Fichier_final.txt", "w");

	if (fichier_final != NULL)
    { 
        // On l'écrit dans le fichier
        fprintf(fichier_final, "Nb_etudiant=%d\n", nbre_etu);
        
        fprintf(fichier_final, "\n");
        
        for (int i = 0; i < NBR_ETU_MAX; ++i)
	       
	        if (moyEtu[i].idEtu!=0)
	        	
	        	fprintf(fichier_final, "%d      %s                %s                           %.3f\n",moyEtu[i].idEtu,moyEtu[i].nom,moyEtu[i].prenom,moyEtu[i].moyenne);
        
        fclose(fichier_final);
    }

    return 0;
}