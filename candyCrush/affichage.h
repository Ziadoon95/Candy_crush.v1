#pragma once
/*numero 4 pour donner un fond de couleurs dans chaque case selon son couleur*/
#define FOREGROUND_MAUVE 0x4005
#define FOREGROUND_JAUNE 0x4006
#define FOREGROUND_VERT 0x4002
#define FOREGROUND_ROUGE 0x4004
#define FOREGROUND_BLEU 0x4001
#define VIDE_TEST 0x4008
#define NB_TOURS_MAX 30

void afficher_matrice(struct matrice* st_matrice);
void LirePionAChanger(struct matrice* stMatrice ,struct queue *st_queue, struct action st_action);
