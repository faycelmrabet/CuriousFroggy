/**
 * \file stage1.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/

#include <allegro.h>
#include "commun.h"
#define nbr_rat 4
#define nbr_coins11 15
#ifndef STAGE1_H_INCLUDED
#define STAGE1_H_INCLUDED

/** *@brief x la position du rat en largeur et y en hauteur. Nous avons 4 voitures dans le jeu donc nous avons besoin de 4 x et de 4 y différents. img est le BITMAP de cette voiture puisque elle contient 3 frames donc nous avons 3 images.*/
typedef struct
{BITMAP *img[3];
 int x[4];
 int y[4];
	
}Rat;

/**
 * \fn void init_fond11(Background *fond);
 * \brief cette fonction permet d'initialiser le fond du stage 1
*/
void init_fond11(Background *fond);

/**
 * \fn void init_frog11(Froggy *frog);
 * \brief cette fonction permet d'initialiser Froggy dans le stage 1
*/
void init_frog11(Froggy *frog);

/**
 * \fn void init_rat(Rat *rat);
 * \brief cette fonction permet d'initialiser le rat dans le stage 1 (img,x,y)
*/
void init_rat(Rat *rat);

/**
 * \fn void update_rat(Rat *rat,int step);
 * \brief cette fonction permet de mettre à jour la position du Rat au fur et à mesure que la posisition du fond se modifie. On doit faire appel à cette fonction à chaque fois que fond11.x augmente ou diminue
*/
void update_rat(Rat *rat,int step);

/**
 * \fn int collision_rat(Rat rat, Froggy frog);
 * \brief Cette fonction détecte s'il y a ou non un contact entre le rat et Froggy. Si celui-ci existe elle retourne 1 sinon elle retourne 0
*/
int collision_rat(Rat rat, Froggy frog);

/**
 * \fn void init_calque11(Calque *calque,Froggy frog);
 * \brief Cette fonction permet d'initialiser le calque du stage 1 qui est l'image du fond dans lequel les obstacles sont coloriés par des couleurs spécifiques (les trous en blanc de coordonnées 16777215, le plancher en bleu ciel de coordonnées 65535, la zone d'arrivée en orange de coordonnées 16850088)
*/
void init_calque11(Calque *calque,Froggy frog);

/**
 * \fn int collision_rat(Rat rat, Froggy frog);
 * \brief Cette fonction permet de détecter la nature de la surface au dessous de la grenouille lorsque celle ci se déplace vers la droite ou vers la gauche(plancher, trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide
*/
int collision_blanc11(Calque calque,int posx_blanc,int y);

/**
 * \fn void chute11(int test,Froggy *frog,int direction);
 * \brief lorsque test est égale à 1, toutes les touches seront bloquées et Froggy sera absorbée vers le bas
*/
void chute11(int test,Froggy *frog,int direction);

/**
 * \fn int collision_bleu11(Calque calque,int posx_bleu,int y);
 * \brief Cette fonction permet de détecter la nature de la surface au dessous de la grenouille lorsque celle ci saute(plancher, trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide
*/
int collision_bleu11(Calque calque,int posx_bleu,int y);

/**
 * \fn void init_coins11(Coins *piece);
 * \brief cette fonction permet d'initialiser les positions des pièces dans le stage 1
*/
void init_coins11(Coins *piece);

/**
 * \fn int collision_piece11(int x,int y,int *test,Coins piece,int nbr_p);
 * \brief Cette fonction permet de tester si Froggy entre en collision avec une piece (Coins) ou non. test prend 1 si la collision existe et 0 si celle-ci n'existe pas.
 * elle retourne la position de la pièce avec laquelle il y a eu collision.
*/
int collision_piece11(int x,int y,int *test,Coins piece,int nbr_p);

/**
 * \fn void destroy_rat(Rat *rat);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Rat
*/
void destroy_rat(Rat *rat);

/**
 * \fn void aspiration(int test,Froggy *frog,int direction,int *aspiration_terminee);
 * \brief lorsque test est égale à 1, toutes les touches seront bloquées et Froggy sera absorbée vers le haut
*/
void aspiration(int test,Froggy *frog,int direction,int *aspiration_terminee);

/**
 * \fn void fonction_stage1(int *stage1_termine,int *direction11,int *key_pressed11,int *frame_counter11,int *test_chute11,int *saut_horizontal11,int *rat_counter,
int *vie11,int *bloquer_collision_rat,int *compteur_collision_rat,int *nbr_piece11,int *score11,int *test_aspiration,int *aspiration_terminee,Background *fond11,Froggy *frog11,
Calque *calque11,Rat *rat,Coins *piece11,Pause pause,BITMAP *Cursor,int *saut_vertical11,int *top11);
 * \brief Cette fonction permet de faire appel aux fonctions du stage 1.
*/
void fonction_stage1(int *stage1_termine,int *direction11,int *key_pressed11,int *frame_counter11,int *test_chute11,int *saut_horizontal11,int *rat_counter,
int *vie11,int *bloquer_collision_rat,int *compteur_collision_rat,int *nbr_piece11,int *score11,int *test_aspiration,int *aspiration_terminee,Background *fond11,Froggy *frog11,
Calque *calque11,Rat *rat,Coins *piece11,Pause pause,BITMAP *Cursor,int *saut_vertical11,int *top11);






#endif
