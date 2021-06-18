#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
2-correcting calcul function if he doesnt find any match so ?verification
3-change ecase name & stMatrice
4-add settings of jeu
5-afficher gelatine
6-ajouter niveau / gelatine generate max limit
7-change loop setting in main that update with new settings
8-correcting getQueue and tailleMatrice /top/next
9-delete functions comments
/*Les entetes */
#include "queue.h"
#include "matrice.h"
#include "affichage.h"

int main()
{ 
	srand(time(NULL));
	//niveau de jeau
	//nombre de tours
	int nombre_tours = 0;

	struct action st_action; 
	struct queue st_queue ;
	struct matrice st_matrice ;

	init_action(&st_action);
	init_queue(&st_queue);

//normalment on lance l'action pour que le top depasse le next et qu'il soit aussi plus grand que 0 comme ça on accede dans le while
	init_matrice(&st_matrice, &st_queue);
	afficher_matrice(&st_matrice);//à deplacer apres dans le while

	while (get_queue(&st_queue, &st_action))
	{
				
		if (strcmp(st_action.nom_action, "CALCUL") == 0)
		{
			printf("inside if CALCUL\n");
			calcul(&st_matrice, &st_queue);
		}	
		if (strcmp(st_action.nom_action, "INITIALISATION") == 0)
		{
			printf("inside if INITIALISATION\n");
			init_matrice(&st_matrice, &st_queue);
		}
		
		if (strcmp(st_action.nom_action, "SUPPRESSION_V") == 0)
		{
			printf("inside if SUPPRESSION_V\n");
			suppression_v(&st_matrice, &st_queue, st_action);
			afficher_matrice(&st_matrice);
		}
		
		if (strcmp(st_action.nom_action, "SUPPRESSION_H") == 0)
		{

			printf("inside if SUPPRESSION_H\n");
			suppression_h(&st_matrice, &st_queue, st_action);
			afficher_matrice(&st_matrice);
		}
		
		if (strcmp(st_action.nom_action, "AFFICHAGE") == 0)
		{
			printf("inside if AFFICHAGE\n");
			afficher_matrice(&st_matrice);
		}
		// à continuer
		if (strcmp(st_action.nom_action, "LECTURE") == 0)
		{
			printf("\ninside if LECTURE\n");
			LirePionAChanger(&st_matrice, &st_queue, st_action);
		}
		if (strcmp(st_action.nom_action, "VERIFICATION") == 0)
		{

			printf("\ninside if VERIFICATION\n");
			verification(&st_matrice, &st_queue, st_action);
			afficher_matrice(&st_matrice);
		}
		if (strcmp(st_action.nom_action, "DEPLACEMENT") == 0)
		{

			printf("\ninside if DEPLACEMENT\n");
			deplacment(&st_matrice,&st_queue, st_action);
			afficher_matrice(&st_matrice);
		}
	}
	return 0;
}
