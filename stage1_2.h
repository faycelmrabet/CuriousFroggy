/**
 * \file stage1_2.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include <allegro.h>
#include "commun.h"
#define nbr_coins12 12
#define nbr_voiture 4
#ifndef STAGE1_2_H_INCLUDED
#define STAGE1_2_H_INCLUDED

/**
 * \typedef struct
 * \brief x la position de la voiture en largeur et y en hauteur. Nous avons 4 voitures dans le jeu donc nous avons besoin de 4 x et de 4 y différents. img est le BITMAP de cette voiture puisque elle contient 5 positions donc nous avons 5 images.
*/
/** *@brief voici la structure Voiture */
typedef struct
{int x[4][5];
 int y[4][5];
 int pos;
 BITMAP *img[5];
}Voiture;

/**
 * \fn void init_fond12(Background *fond);
 * \brief cette fonction permet d'initialiser le fond du stage 2
*/
void init_fond12(Background *fond);

/**
 * \fn init_frog12(Froggy *frog);
 * \brief cette fonction permet d'initialiser la position froggy
*/
void init_frog12(Froggy *frog);

/**
 * \fn init_calque12(Calque *calque,Froggy frog);
 * \brief cette fonction permet d'initialiser le calque qui est l'image du fond dont le quel les obstacles sont coloriés par des couleurs 
 * spécifiques(les trous en blanc de cordonnées 16777215, le plancher en bleu-ciel de cordonnées 65535, la zone d'arrivée en orange de cordonnées 16750088)
*/
void init_calque12(Calque *calque,Froggy frog);

/**
 * \fn collision_blanc12(Calque calque,int posx_blanc,int y);
 * \brief cette fonction permet de detecter la nature de la surface au dessous de la grenouille lorsque celle ci se déplace à gauche ou à droite (plancher,trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide. 
*/
int collision_blanc12(Calque calque,int posx_blanc,int y);

/**
 * \fn chute12(int test,Froggy *frog,int direction);
 * \brief Lorsque test est égale 1 toutes les touches sont bloquées et la grenouille sera apsorbé vers le bas. 
*/
void chute12(int test,Froggy *frog,int direction);

/**
 * \fn collision_bleu12(Calque calque,int posx_bleu,int y);
 * \brief cette fonction permet de detecter la nature de la surface au dessous de la grenouille lorsqu'il celle ci saute (plancher,trou ou vide). Elle retourne 1 si c'est un plancher, 2 si c'est un trou et 0 si c'est du vide. 
*/
int collision_bleu12(Calque calque,int posx_bleu,int y);

/**
 * \fn init_coins12(Coins *piece);
 * \brief Cette fonction permet d'initialiser les piéces selon x et y.
*/
void init_coins12(Coins *piece);

/**
 * \fn  collision_piece12(int x,int y,int *test,Coins piece,int nbr_p);
 * \brief Cette fonction permet de tester si le Pigeon entre en collision avec une piece (Coins) ou non.test prend 1 si la collision existe et 0 si celle-ci n'existe pas
 * elle retourne la position de la pièce avec laquelle il ya eu collision.
*/
int collision_piece12(int x,int y,int *test,Coins piece,int nbr_p);

/**
 * \fn init_voiture(Voiture *voiture);
 * \brief cette fonction permet d'initialiser la position de la voiture
*/
void init_voiture(Voiture *voiture);

/**
 * \fn update_voiture(Voiture *voiture,int step);
 * \brief Cette fonction permet de mettre à jour la position de la voiture au fur et à mesure que la position du fond est modifiée.On doit faire appel à cette fonction lorsque font.x augmente ou dimminue.
*/
void update_voiture(Voiture *voiture,int step);

 /**
 * \fn  destroy_voiture(Voiture *voiture);
 * \brief Cette fonction permet de libérer la mémoire allouer pour la structure Voiture.
*/
void destroy_voiture(Voiture *voiture);

/**
 * \fn void fonctions_stage1_2(int *direction12,int *key_pressed12,int *frame_counter12,int *test_chute12,int *saut_horizontal12,int *nbr_piece12,
int *score12,int *saut_vertical12,int *top12,int *car_counter,int *stage12_termine,int *win_stage12,int *bloquer_voiture,Background *fond12,Froggy *frog12,Calque *calque12,Coins *piece12,
Voiture *voiture,Pause pause,BITMAP *Cursor);
 * \brief Cette fonction permet de faire appel aux fonctions du stage 2.
*/
void fonctions_stage1_2(int *direction12,int *key_pressed12,int *frame_counter12,int *test_chute12,int *saut_horizontal12,int *nbr_piece12,
int *score12,int *saut_vertical12,int *top12,int *car_counter,int *stage12_termine,int *win_stage12,int *bloquer_voiture,Background *fond12,Froggy *frog12,Calque *calque12,Coins *piece12,
Voiture *voiture,Pause pause,BITMAP *Cursor);




#endif
