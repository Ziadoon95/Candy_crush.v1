#include "queue.h"
#include "string.h"
#include <stdio.h>

//initialiser l'action meme.
void init_action(struct action *st_action)
{
	strcpy_s(st_action->nom_action,20,"");
	st_action->premiere_pion_x = 0 , st_action->premiere_pion_y = 0;
	st_action->autre_pion_x = 0 , st_action->autre_pion_y = 0;
}

//qui initialise la Queue
void init_queue(struct queue *st_queue)
{
	st_queue->next = 0, st_queue->top = 0, st_queue->size = taille_queue;
}

//permet d’ajouter une action que l’on passe en paramètre. La fonction Add doit aussi indiquer si l’insertion a pu se faire
void add_queue(struct queue *st_queue, struct action st_action)
{
	//reitialiser l'index next pour qu'il ne depasse pas la taille de queue
	if (st_queue->next == taille_queue)
	{
		st_queue->next = 0;
	}
	/*
	next = 3; top = 0 ;
	--------------------------------
	|act|act|act| - | - | - | - |
	--------------------------------
	*/
	if (st_queue->next <= taille_queue)
	{
		st_queue->toutes_actions[st_queue->next] = st_action;
		st_queue->next++ ;
	}
}



int get_queue(struct queue *st_queue, struct action *st_action)
{
	printf("\n VALEUR next EST %d", st_queue->next);
	printf("\n VALEUR top %d", st_queue->top);

	//reitialiser l'index top pour qu'il ne depasse pas la taille de queue ou le prchain element à lire
	if(st_queue->top == taille_queue)st_queue->top = 0;
	if (st_queue->top == st_queue->next)
	{
		st_queue->top = 0;
		return  0;
	}
	else
	{
		st_action->premiere_pion_x = st_queue->toutes_actions[st_queue->top].premiere_pion_x;
		st_action->premiere_pion_y = st_queue->toutes_actions[st_queue->top].premiere_pion_y;
		st_action->autre_pion_x = st_queue->toutes_actions[st_queue->top].autre_pion_x;
		st_action->autre_pion_y = st_queue->toutes_actions[st_queue->top].autre_pion_y;
		strcpy_s(st_action->nom_action,20 ,st_queue->toutes_actions[st_queue->top].nom_action);

		st_queue->top++;
		return  1;
	}
}