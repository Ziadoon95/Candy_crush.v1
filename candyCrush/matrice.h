#pragma once

#define X_AXE 8
#define Y_AXE 8

#define N_GELATINE_MAX 64






struct Case
{
    int pion;
    int gelatine;
};

struct matrice
{
    struct Case case_matrice[X_AXE][Y_AXE];
};


void init_matrice(struct matrice* stMatrice, struct queue* stQueue);
void calcul(struct matrice* stMatrice, struct queue* stQueue);

void suppression_v(struct matrice* st_matrice, struct queue* st_queue, struct action st_action);
void suppression_h(struct matrice* st_matrice, struct queue* st_queue, struct action st_action);

int parcourir_lignes(struct matrice* st_matrice,int* pion_x_trouve,int* pion_y_trouve);
int parcourir_colonnes(struct matrice* st_matrice,int* pion_x_trouve, int* pion_y_trouve);

void verification(struct matrice* st_matrice, struct queue* st_queue, struct action st_action);
void deplacment  (struct matrice* st_matrice, struct queue* st_queue, struct action st_action);