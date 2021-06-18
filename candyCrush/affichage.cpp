#include "affichage.h"
#include "matrice.h"
#include "queue.h"
#include <stdio.h>
#include <windows.h>



void afficher_matrice(struct matrice* stMatrice)
{
    /*affichage*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    //END affichage

    int x = -1, y = -1,   aid_a_lire_y =0;
    
    while (x < X_AXE)
    {
        if (x > -1)
        {
            SetConsoleTextAttribute(hConsole, VIDE_TEST);
            printf(" %d ", x);
        }
        while (y < Y_AXE)
        {
       
            if (x==-1 && y==-1)
            {
                SetConsoleTextAttribute(hConsole, VIDE_TEST);
                printf("   ");
                for (aid_a_lire_y = 0;aid_a_lire_y < 8;aid_a_lire_y++)
                {
                    printf(" %d ", aid_a_lire_y);
                }
                printf("\n");
            }
            if(y > -1)
            {
                switch (stMatrice->case_matrice[x][y].pion)
                {
                    // 2 = bleu, 3 = rouge et 4 = mauv
                case 0:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_JAUNE);
                    printf(" J ");
                    break;
                case 1:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_VERT);
                    printf(" V ");
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLEU);
                    printf(" B ");
                    break;
                case 3:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_ROUGE);
                    printf(" R ");
                    break;
                case 4:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_MAUVE);
                    printf(" M ");
                    break;

                }
            }

            y++;
        }
        printf("\n");
        y = 0;
        x++;
    }
//    END affichage pions

     x = -1, y = -1, aid_a_lire_y = 0;
    //gelatines
    while (x < X_AXE)
    {
        if (x > -1)
        {
            SetConsoleTextAttribute(hConsole, VIDE_TEST);
            printf(" %d ", x);
        }
        while (y < Y_AXE)
        {

            if (x == -1 && y == -1)
            {
                SetConsoleTextAttribute(hConsole, VIDE_TEST);
                printf("   ");
                for (aid_a_lire_y = 0;aid_a_lire_y < 8;aid_a_lire_y++)
                {
                    printf(" %d ", aid_a_lire_y);
                }
                printf("\n");
            }
            if (y > -1)
            {
                switch (stMatrice->case_matrice[x][y].gelatine)
                {
                    // 2 = bleu, 3 = rouge et 4 = mauv
                case 0:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_JAUNE);
                    printf(" 0 ");
                    break;
                case 1:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_VERT);
                    printf(" V ");
                    break;
       
                }
            }

            y++;
        }
        printf("\n");
        y = 0;
        x++;
    }
    //END affichage*/
}




void LirePionAChanger(struct matrice* st_matrice, struct queue* st_queue,struct action st_action)
{
    int pion_un_x , pion_un_y ,  pion_deux_x, pion_deux_y;
    printf("\nIntroduisez les cordonnees de la premiere pions à intervertir(séparer par une espace): \n");
    scanf_s( "%i %i",&pion_un_x,&pion_un_y);
    printf("\nIntroduisez les cordonnees de la premiere pions à intervertir(séparer par une espace): \n");
    scanf_s("%i %i", &pion_deux_x, &pion_deux_y);
    
    while (
        !(pion_un_x >= 0 && pion_un_x <= 7)
        ||
        !(pion_un_y >= 0 && pion_un_y <= 7)
        ||
        !(pion_deux_x >= 0 && pion_deux_x <= 7)
        ||
        !(pion_deux_y >= 0 && pion_deux_y <= 7)
        ||
        (pion_un_x == pion_deux_x && pion_un_y == pion_deux_y)
        ||
        !(
            (abs(pion_un_x - pion_deux_x) == 1 && pion_un_y == pion_deux_y)
            ||
            (abs(pion_un_y - pion_deux_y) == 1 && pion_un_x == pion_deux_x)

        )
        )
        {
            printf("Erreur  !,vieullez entrer les cordonnees des deux pions entre 0 et 7\n");
            printf("\nIntroduisez les cordonnees de la premiere pions à intervertir(séparer par une espace): \n");
            scanf_s("%i %i", &pion_un_x, &pion_un_y);
            printf("\nIntroduisez les cordonnees de la premiere pions à intervertir(séparer par une espace): \n");
            scanf_s("%i %i", &pion_deux_x, &pion_deux_y);
        }

    strcpy_s(st_action.nom_action, 20, "DEPLACEMENT");
    st_action.premiere_pion_x = pion_un_x;
    st_action.premiere_pion_y = pion_un_y;
    st_action.autre_pion_x = pion_deux_x;
    st_action.autre_pion_y = pion_deux_y;
    add_queue(st_queue, st_action);
}