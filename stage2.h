/**
 * \file stage2.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include<allegro.h>
#include "commun.h"
#ifndef STAGE2_H_INCLUDED
#define STAGE2_H_INCLUDED


/** *@brief x la position du Pigeon en largeur et y en hauteur. Nous avons un Pigeon dans le jeu. img  est le BITMAP de ce Pigeon  puisque il contient 5 frames donc nous avons 5 images. */
typedef struct 
{
	BITMAP *img[5];
	int x,y ;
}Pigeon;
 
 /**
 * \fn void init_coins2(Coins *piece,int xfond);
 * \brief cette fonction permet d'initialiser la position des pièces
*/
 void init_coins2(Coins *piece,int xfond);
 
 /**
 * \fn void increment_speed_counter();
 * \brief cette fonction permet d'incrementer le compteur speed_counter 
*/
 void increment_speed_counter();
 
 /**
 * \fn void init_speed_counter();
 * \brief cette fonction permet d'initialiser le compteur speed_counter 
*/
 void init_speed_counter();
 
 /**
 * \fn void init_pigeon (Pigeon *pigeon );
 * \brief cette fonction permet d'initialiser la position du Pigeon
*/
  void init_pigeon (Pigeon *pigeon );
  
  /**
 * \fn void init_background2(Background *background );
 * \brief cette fonction permet d'initialiser le fond du stage3.
*/
 void init_background2(Background *background );
 
  /**
 * \fn void init_calque2(Calque *calque, Pigeon pigeon); 
 * \brief cette fonction permet d'initialiser le calque qui est l'image du fond dans lequel les obstacles sont coloriés par des couleurs 
 * spécifiques(les immeubles en blanc de cordonnées 16777215)
*/
 void init_calque2(Calque *calque, Pigeon pigeon); 
 
 /**
 * \fn  void chute2 (int test ,Pigeon *pigeon);
 * \brief lorsque test est égale à 1 toutes les touches sont bloquées et le Pigeon sera absorbé vers le bas 
*/
 void chute2 (int test ,Pigeon *pigeon);
 /**
 * \fn  int collision2 (Calque calque);
 * \brief Cette fonction détecte s'il y a ou non un contact entre les immeubles qui sont en blanc sur le Calque et Pigeon.si celle ci existe elle retourne 1 sinon elle retourne 0.
*/
 int collision2 (Calque calque);
 
 /**
 * \fn int collision_piece2(int x,int y,int *test,Coins piece,int nbr_p);
 * \brief Cette fonction permet de tester si le Pigeon entre en collision avec une piece (Coins) ou non.test prend 1 si la collision existe et 0 si celle-ci n'existe pas
 * elle retourne la position de la pièce avec laquelle il ya eu collision.
*/
 int collision_piece2(int x,int y,int *test,Coins piece,int nbr_p);
 
 /**
 * \fn  void  destroy_pigeon(Pigeon *pigeon);
 * \brief Cette fonction permet de libérer la mémoire allouer pour la structure Pigeon.
*/
 void destroy_pigeon(Pigeon *pigeon);
 
 /**
 * \fn  void  fonction_stage2(Pigeon *pigeon,Background *fond2,Game game_over,Calque *calque2,Coins *piece2,int *nbr2,int *test2,
 int *frame_counter,int *key_pressed2,Pause pause,BITMAP *Cursor,int *block_speed_counter,int *stage2_termine,int *win_stage2,int *score2); 
 * \brief Cette fonction permet de faire appel aux fonctions du stage3.
*/
 void fonction_stage2(Pigeon *pigeon,Background *fond2,Game game_over,Calque *calque2,Coins *piece2,int *nbr2,int *test2,
 int *frame_counter,int *key_pressed2,Pause pause,BITMAP *Cursor,int *block_speed_counter,int *stage2_termine,int *win_stage2,int *score2); 





#endif
