#pragma once

#define taille_tab_caractere 20
#define taille_queue 10


/*
*Les pions : J V B R M 
*/

struct action {
	char nom_action[taille_tab_caractere];

	int premiere_pion_x, premiere_pion_y;
	int autre_pion_x   , autre_pion_y   ; 
};

/*
//Top: Index du premier élément dans la Queue
//next : Index du prochain élément libre dans la Queue
//size : Index Maximal de la Queue
*/
struct queue {
	struct action toutes_actions[taille_queue];
	int top , next , size ;
};


void init_action(struct action* st_action);//qui initialise l'action meme.
void init_queue(struct queue *st_queue); //qui initialise la Queue

void add_queue(struct queue *st_queue , struct action st_action );  
int get_queue(struct queue* st_queue , struct action *st_action);   //qui retourne une action. Le Get doit aussi indiquer si une action a pu être retournée