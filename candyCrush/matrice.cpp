#include "matrice.h"
#include "queue.h"
#include "affichage.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/*
    La fonction intiMatrice
    Grace à la fonctin rand() un nombre entre 0 et 4 est généré aléatoirement dans dPion :
    si 0 = jaune, 1 = vert, 2 = bleu, 3 = rouge et 4 = mauve
    Ainsi qu'un nombre aléatoire entre 0 et 1 dans dGelatine :
    si 1 alors il y a de la gélatine dans la case, si 0 il n'y en a pas
    Puis fait appel à addQueue (calcul) pour lancer le jeu
*/
void init_matrice(struct matrice *st_matrice, struct queue* st_queue)
{    
    struct action st_action;
    strcpy_s(st_action.nom_action,20, "CALCUL");

    int x = 0 , y = 0, Gel_cpt = 0;
    while (x < X_AXE)
    {
        while (y < Y_AXE)
        {
            int pion = rand() % 5, gelatine = rand() % 2;
            if(Gel_cpt <= N_GELATINE_MAX)
            {
                st_matrice->case_matrice[x][y].gelatine = gelatine;
                Gel_cpt++;
            }
            st_matrice->case_matrice[x][y].pion = pion ;
            y++;
        }
        printf("\n");
        y = 0;
        x++;
    }

    /*lancer la fonction calcul*/
    add_queue(st_queue, st_action);
    /*END lancer la fonction calcul*/
}

void calcul(struct matrice* stMatrice, struct queue* st_queue)
{
    struct action st_action;
    bool trouver = false;
    int y = 0, x = 0;
    int pion_x_trouve = 0;
    int pion_y_trouve = 0;

    if (parcourir_lignes(stMatrice, &pion_x_trouve, &pion_y_trouve))
    {
        printf("\n CALCUL LIGNES match has been detected on (x : %d, y : %d)", pion_x_trouve , pion_y_trouve);
        strcpy_s(st_action.nom_action, 20, "SUPPRESSION_H");
        st_action.premiere_pion_x = pion_x_trouve;
        st_action.premiere_pion_y = pion_y_trouve;
        st_action.autre_pion_x = pion_x_trouve + 2;
        st_action.autre_pion_y = pion_y_trouve + 2;
    }
    
    else if (parcourir_colonnes(stMatrice, &pion_x_trouve, &pion_y_trouve))
    {
        printf("\n CALCUL COLONNES match has been detected on (x : %d, y : %d)", pion_x_trouve, pion_y_trouve);
        strcpy_s(st_action.nom_action,20,"SUPPRESSION_V");
        st_action.premiere_pion_x = pion_x_trouve;
        st_action.premiere_pion_y = pion_y_trouve;
        st_action.autre_pion_x = pion_x_trouve + 2;
        st_action.autre_pion_y = pion_y_trouve + 2;
    }
    else {
        printf("\n CALCUL No action has been detected !!");

        strcpy_s(st_action.nom_action, 20, "VERIFICATION");
        st_action.premiere_pion_x = 0;
        st_action.premiere_pion_y = 0;
        st_action.autre_pion_x = 0 ;
        st_action.autre_pion_y = 0;
    }
   //remplir l'action à enovoyer à la queue
 
    printf("le nom d'action : %s\n",st_action.nom_action);

    add_queue(st_queue, st_action);

}
int parcourir_lignes(struct matrice* st_matrice,int *pion_x_trouve ,int *pion_y_trouve)
{
    int x = 0, y = 0;
    bool trouver = false;
    while(x < X_AXE && trouver == false)
    {
       // printf("is Y(%d) < Y_AXE(%d) \n", y , Y_AXE);
        while (y < Y_AXE && trouver == false)
        {
           if (
                st_matrice->case_matrice[x][y].pion == st_matrice->case_matrice[x][y + 1].pion
                &&
                st_matrice->case_matrice[x][y].pion == st_matrice->case_matrice[x][y + 2].pion
               )
               {
                    *pion_x_trouve = x; 
                    *pion_y_trouve = y; 
                    trouver = true;
                    printf("\ninside parcourir lignes match has been detected on (x: %d,y: %d)", x, y);

               }
           y++;
        }
        y = 0;
        x++;
    }

    if (trouver) return 1; else return 0;
    
}
int parcourir_colonnes(struct matrice* st_matrice, int* pion_x_trouve, int* pion_y_trouve)
{    int x = 0, y = 0;

    bool trouver = false;

    while (y < Y_AXE && trouver == false)
    {
        while(x < X_AXE && trouver == false)
        {
            //printf("\nCOLONNES [%d,%d](%d) == [%d,%d](%d) == [%d,%d](%d)", x, y, st_matrice->case_matrice[x][y].pion, x, y, st_matrice->case_matrice[x + 1][y].pion, x, y, st_matrice->case_matrice[x][y].pion == st_matrice->case_matrice[x + 2][y].pion);

            if (
                st_matrice->case_matrice[x][y].pion == st_matrice->case_matrice[x+1][y].pion
                &&
                st_matrice->case_matrice[x][y].pion == st_matrice->case_matrice[x+2][y].pion
                )
            {
                printf("\ninside parcourir colonnes match has been detected on (x: %d,y: %d)", x, y);
                *pion_x_trouve = x;
                *pion_y_trouve = y;
                 trouver = true;
            }
            x++;
        }
        x = 0;

        y++;
    }
    if (trouver) return 1; else return 0;

}

void suppression_v(struct matrice* st_matrice, struct queue* st_queue, struct action st_action)
{
    /* la direction de supression :
        y1   y2  
      ----------
    x1|   | ! |
      ----------
    x2|   | ! |
      ----------
    x3|   | v | 
      ----------
    */
    int const PIONS_Y = st_action.premiere_pion_y;


    //new code
     //si le ligne est plus grand que 0 alors 

   // if (PIONS_Y > 0)
    //{
        //1)eliminer les gelatines 
        st_matrice->case_matrice[st_action.premiere_pion_x][PIONS_Y].gelatine = 0;
        st_matrice->case_matrice[st_action.premiere_pion_x+1][PIONS_Y].gelatine = 0;
        st_matrice->case_matrice[st_action.premiere_pion_x+2][PIONS_Y].gelatine = 0;

        //2)faire desencdre les pions
        int autre_pion_x = st_action.autre_pion_x;
     
            while (autre_pion_x > 2)
            {
                st_matrice->case_matrice[autre_pion_x][PIONS_Y].pion = st_matrice->case_matrice[autre_pion_x-3][PIONS_Y].pion;
                autre_pion_x--;
            }
            //3)generer des pios aleatoires
          //  printf("\nl'index de  autre pion x est : %d autre_pion_x\n", autre_pion_x);
            int remplir_nouveaux_pions = autre_pion_x;
            while (remplir_nouveaux_pions >= 0)
            {
                st_matrice->case_matrice[remplir_nouveaux_pions][PIONS_Y].pion = rand() % 5;
                remplir_nouveaux_pions--;
            }
    
    strcpy_s(st_action.nom_action, 20, "CALCUL");
    add_queue(st_queue, st_action);

}

/*
    La fonction suppression_h
    Elle reçoit les coordonnées dFirstX, dFirstY, dLastX et dLastY d'une séquence de pions de la même couleur.
    Elle doit décaler tous les pions au-dessus pour simuler la gravité et générer 3 pions aléatoire tout en haut.
    Si il y a de la gélatine sur les pions éliminés, elle doit s'éliminer également (voir système de points ?).
    Fait appel à la fonction addQueue (calcul) pour recommencer à chercher une autre séquence de pions allignés.
*/
void suppression_h(struct matrice* st_matrice, struct queue* st_queue, struct action st_action)
{
    /* la direction de supression :  
       y1   y2   y3   y4
      ----------------------------------
    x1|   | -- | -- | --> |   |   |   |
      ----------------------------------
    */
    int const PIONS_X = st_action.premiere_pion_x;

    printf("\n inside supression_h function \n");

    //si le ligne est plus grand que 0 alors 
    
    if (PIONS_X > 0)
    {
        //1)eliminer les gelatines 
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y].gelatine = 0;
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y + 1].gelatine = 0;
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y + 2].gelatine = 0;
        //2)faire desencdre les pions
        int ligne_n_x = PIONS_X;
        while (ligne_n_x > 0)
        {
            st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y].pion = st_matrice->case_matrice[ligne_n_x - 1][st_action.premiere_pion_y].pion;
            st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y + 1].pion = st_matrice->case_matrice[ligne_n_x - 1][st_action.premiere_pion_y+1].pion;
            st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y + 2].pion = st_matrice->case_matrice[ligne_n_x - 1][st_action.premiere_pion_y+2].pion;
            ligne_n_x--;
        }
       //3)generer des pios aleatoires
        st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y].pion = rand() % 5;
        st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y+1].pion = rand() % 5;
        st_matrice->case_matrice[ligne_n_x][st_action.premiere_pion_y+2].pion = rand() % 5;
  
    }
    else {
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y].pion = rand() % 5;
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y + 1].pion = rand() % 5;
        st_matrice->case_matrice[PIONS_X][st_action.premiere_pion_y + 2].pion = rand() % 5;
    }

    strcpy_s(st_action.nom_action, 20, "CALCUL");
    add_queue(st_queue, st_action);

}


void verification(struct matrice* st_matrice, struct queue* st_queue, struct action st_action)
{
    bool gel_trouver = false;
    int gelatine_cpt = 0;
    int x = 0, y = 0;
    while (x < X_AXE && gel_trouver == false)
    {
        while (y < Y_AXE && gel_trouver == false)
        {
            if (st_matrice->case_matrice[x][y].gelatine == 1 )
            {
                gel_trouver = true;
            }
            y++;
        }
        y = 0;
        x++;
    }
    if (gel_trouver)
    {
        strcpy_s(st_action.nom_action, 20, "LECTURE");
        add_queue(st_queue, st_action);
    }
    if (!gel_trouver) {
        printf("VOuS AVeZ GaGNé !!");
    }
}

void deplacment(struct matrice* st_matrice, struct queue* st_queue, struct action st_action)
{
    printf("\nfrom inside deplacement %d", st_action.autre_pion_x);
    /*pas important */
    int premier_pion_x = st_action.premiere_pion_x;
    int premier_pion_y = st_action.premiere_pion_y;
    int autre_pion_x = st_action.autre_pion_x;
    int autre_pion_y = st_action.autre_pion_y;
    /*pas important */

    int temp_pion = st_matrice->case_matrice[autre_pion_x][autre_pion_y].pion;

    //intervertir dans la matrice
    st_matrice->case_matrice[autre_pion_x][autre_pion_y].pion = st_matrice->case_matrice[premier_pion_x][premier_pion_y].pion;
    st_matrice->case_matrice[premier_pion_x][premier_pion_y].pion = temp_pion;

    strcpy_s(st_action.nom_action, 20, "CALCUL");
    add_queue(st_queue, st_action);

}