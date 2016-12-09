/**
 * \file stage4.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include <allegro.h>
#include "commun.h"
#ifndef STAGE4_H_INCLUDED
#define STAGE4_H_INCLUDED



/** *@brief x la position du serpent en largeur et y en hauteur. Nous avons 3 serpents dans le jeu donc nous avons besoin de 3 x et de 3 y différents. img est le BITMAP de ce serpent  puisque il contient 5 positions donc nous avons 5 images. */
typedef struct
{ int x[3];
  int y[3];
  BITMAP *img[5];
	
}Serpent;

 /** *@brief x la position de reine en largeur et y en hauteur. Nous avons 3 reines dans le jeu donc nous avons besoin de 3 x et de 3 y différents. img est le BITMAP de cette voiture puisque elle contient 5 positions donc nous avons 5 images. */

typedef struct
{ int x[3];
  int y[3];
  BITMAP *img[3];
}Reine;

/**
 * \fn void init_frog(Froggy *frog);
 * \brief cette fonction permet d'initialiser la position du froggy
*/
void init_frog(Froggy *frog);

/**
 * \fn void init_background(Background *fond);
 * \brief cette fonction permet d'initialiser le fond du stage 4
*/
void init_background(Background *fond);

/**
 * \fn void init_calque(Calque *calque,Froggy frog);
 * \brief cette fonction permet d'initialiser le calque qui est l'image du fond dont le quel les obstacles sont coloriés par des couleurs 
 * spécifiques(les trous en blanc de cordonnées 16777215, le plancher en bleu-ciel de cordonnées 65535, la zone d'arrivée en orange de cordonnées 16750088)
*/
void init_calque(Calque *calque,Froggy frog);
//void destroy_frog(Froggy *frog);


/**
 * \fn int collision blanc(Calque calque,int posx_blanc,int y);
 * \brief cette fonction permet de detecter la nature de la surface au dessous de la grenouille lorsque celle ci se déplace à gauche ou à droite (plancher,trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide. 
*/
int collision_blanc(Calque calque,int posx_blanc,int y);


/**
 * \fn int collision bleu(Calque calque,int posx_bleu,int y);
 * \brief cette fonction permet de detecter la nature de la surface au dessous de la grenouille lorsqu'il celle ci saute (plancher,trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide. 
*/
int collision_bleu(Calque calque,int posx_bleu,int y);


/**
 * \fn void chute(int test,Froggy *frog,int direction);
 * \brief Lorsque test est égale 1 toutes les touches sont bloquées et la grenouille sera apsorbé vers le bas. 
*/
void chute(int test,Froggy *frog,int direction);

/**
 * \fn void init_coins(Coins *piece,int xfond);
 * \brief Cette fonction permet d'initialiser les piéces selon x et y.
*/
void init_coins(Coins *piece,int xfond);

/**
 * \fn void init_serpent(Serpent *serpent);
 * \brief Cette fonction permet d'initialiser le serpent dans le stage4.
*/
void init_serpent(Serpent *serpent);

/**
 * \fn void update_serpent(Serpent *serpent,int step);
 * \brief Cette fonction permet de mettre à jour la position du Serpent au fur et à mesure que la position du fond est modifiée.On doit faire appel à cette fonction lorsque font.x augmente ou dimminue.
*/
void update_serpent(Serpent *serpent,int step);

/**
 * \fn void destroy_serpent(Serpent *serpent);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Serpent.
*/
void destroy_serpent(Serpent *serpent);

/**
 * \fn void init_reine(Reine *reine);
 * \brief Cette fonction permet d'initialiser la reine selon x et y.
*/
void init_reine(Reine *reine);

/**
 * \fn void update_reine(Reine *reine,int step);
 * \brief Cette fonction permet de mettre à jour la position de la Reine au fur et à mesure que la position du fond est modifiée.On doit faire appel à cette fonction lorsque font.x augmente ou dimminue.
*/
void update_reine(Reine *reine,int step);


/**
 * \fn int collision_serpent(Serpent *serpent,Froggy frog);
 * \brief Cette fonction détecte s'il y a ou non un contact avec Froggy.Elle retourne 1 si elle existe sinon elle retourne 0.
*/
int collision_serpent(Serpent serpent,Froggy frog);


/**
 * \fn int collision_reine(Reine *reine,Froggy frog);
 * \brief Cette fonction détecte s'il y a ou non un contact avec Froggy.Elle retourne 1 si elle existe sinon elle retourne 0.
*/
int collision_reine(Reine reine, Froggy frog);

/**
 * \fn void destroy_reine(Reine *reine);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Reine.
*/
void destroy_reine(Reine *reine);

/**
 * \fn void fonction_stage4(int *direction,int *key_pressed,int *frame_counter,int *serpent_counter,int *reine_counter,
int *saut_horizontal,int *test_chute,int *top,int *saut_vertical,int *nbr_p,int *score4,int *vie4,
int *compteur_collision_reine,int *bloquer_collision_reine,Background *fond,Froggy *frog,Calque *calque,
Coins *piece,Serpent *serpent,Reine *reine,Pause pause,BITMAP *Cursor,int *stage_termine,int *win_stage,int *bloquer_animation);
 * \brief Cette fonction permet de faire l'appel aux fonctions du stage4.
*/
void fonction_stage4(int *direction,int *key_pressed,int *frame_counter,int *serpent_counter,int *reine_counter,
int *saut_horizontal,int *test_chute,int *top,int *saut_vertical,int *nbr_p,int *score4,int *vie4,
int *compteur_collision_reine,int *bloquer_collision_reine,Background *fond,Froggy *frog,Calque *calque,
Coins *piece,Serpent *serpent,Reine *reine,Pause pause,BITMAP *Cursor,int *stage_termine,int *win_stage,int *bloquer_animation);

#endif
