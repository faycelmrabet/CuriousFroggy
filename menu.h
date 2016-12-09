/**
 * \file menu.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include <allegro.h>
#include "commun.h"
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/** *@brief Ceci est la structure d'un bouton qui doit apparaitre dans le menu. Elle contient les coordonnées du bouton et ses différents états (3 images) */
typedef struct 
{
int x,y;
BITMAP *img[3];		
}bouton;

/** *@brief Ceci est la structure d'une icône du stage 1 qui doit apparaitre dans le menu. Elle contient les coordonnées de l'icône */
typedef struct
{ int x;
  int y;
  BITMAP *img;
} icone_stage1;

/** *@brief Ceci est la structure d'une icône du stage 2 qui doit apparaitre dans le menu. Elle contient les coordonnées de l'icône et ses différents états (2 images) verouillé ou ouvert*/
typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage2;

/** *@brief Ceci est la structure d'une icône du stage 3 qui doit apparaitre dans le menu. Elle contient les coordonnées de l'icône et ses différents états (2 images) verouillé ou ouvert*/
typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage3;

/** *@brief Ceci est la structure d'une icône du stage 4 qui doit apparaitre dans le menu. Elle contient les coordonnées de l'icône et ses différents états (2 images) verouillé ou ouvert*/
typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage4;


/**
 * \fn void init_fond_menu(Background *fond);
 * \brief cette fonction permet d'initialiser le fond du menu
*/
void init_fond_menu(Background *fond);

/**
 * \fn void init_menu1(bouton *exit, bouton *help, bouton *play, bouton *son, bouton *son_coupe);
 * \brief Cette fonction permet d'initialiser les boutons du menu 1
*/
void init_menu1(bouton *exit, bouton *help, bouton *play, bouton *son, bouton *son_coupe);

/**
 * \fn void init_menu2(icone_stage1 *s1, icone_stage2 *s2, icone_stage3 *s3, icone_stage4 *s4);
 * \brief Cette fonction permet d'initialiser les icônes du menu 2
*/
void init_menu2(icone_stage1 *s1, icone_stage2 *s2, icone_stage3 *s3, icone_stage4 *s4);

/**
 * \fn void init_bouton_prec(bouton *prec);
 * \brief Cette fonction permet d'initialiser le bouton précédent (prec) qui apparait dans chacun des menus 1, 2 et help
*/
void init_bouton_prec(bouton *prec);

/**
 * \fn void etat_bouton_prec(int *b_prec);
 * \brief Cette fonction permet de vérifier si le curseur est pointé ou non sur le bouton précédent (prec) Elle retourne 1 si le curseur est pointé sur le bouton, 2 si en plus la touche gauche de la souris sinon elle retourne 0
*/
void etat_bouton_prec(int *b_prec);

/**
 * \fn void etat_bouton(int *b_play,int *b_exit,int *b_help,int *b_son);
 * \brief Cette fonction permet de vérifier si le curseur est pointé ou non sur l'un des boutons du menu 1. Chaque paramètre reçoit  1 si le curseur est pointé sur le bouton, 2 si en plus la touche gauche de la souris sinon il prend la valeur de 0.
*/
void etat_bouton(int *b_play,int *b_exit,int *b_help,int *b_son);

/**
 * \fn void blit_boutons(int b_play,int b_exit,int b_help,int b_son,bouton exit,bouton help,bouton play,bouton son,bouton son_coupe,int sound_off);
 * \brief Cette fonction permet les boutons du menu 1 en fonction de leur état.
*/
void blit_boutons(int b_play,int b_exit,int b_help,int b_son,bouton exit,bouton help,bouton play,bouton son,bouton son_coupe,int sound_off);

/**
 * \fn void destroy_boutons(bouton *exit, bouton *help, bouton *play, bouton *son);
 * \brief Cette fonction permet de libérer la mémoire allouée pour les boutons du menu 1 qui sont de type Bouton
*/
void destroy_boutons(bouton *exit, bouton *help, bouton *play, bouton *son);

/**
 * \fn void destroy_icones(icone_stage1 *s1,icone_stage2 *s2,icone_stage3 *s3,icone_stage4 *s4);
 * \brief Cette fonction permet de libérer la mémoire allouée pour les icônes du menu 2 qui sont de type icone_stage2
*/
void destroy_icones(icone_stage1 *s1,icone_stage2 *s2,icone_stage3 *s3,icone_stage4 *s4);

/**
 * \fn void blit_icones(int etat_s2,int etat_s3,int etat_s4,icone_stage1 s1, icone_stage2 s2,icone_stage3 s3,icone_stage4 s4);
 * \brief Cette fonction permet les icônes du menu 2 en fonction de leur état.
*/
void blit_icones(int etat_s2,int etat_s3,int etat_s4,icone_stage1 s1, icone_stage2 s2,icone_stage3 s3,icone_stage4 s4);

/**
 * \fn int select_stage();
 * \brief Cette fonction permet de vérifier si le curseur est pointé ou non sur l'une des icônes du menu 2. Elle retourne 1 si le curseur est pointé sur l'icône du stage 1, 2 pour le stage 2, 3 pour le stage 3 et 4 pour le stage 4.
*/
int select_stage();

/**
 * \fn void init_menu_help(Background *menu_help);
 * \brief Cette fonction permet d'initialiser le menu help.
*/
void init_menu_help(Background *menu_help);

/**
 * \fn void fonction_menu(int *continuer,Background fond_menu,Background menu_help,int *page,bouton exit,bouton help,bouton play,bouton son,bouton prec,icone_stage1 s1,icone_stage2 s2,icone_stage3 s3,icone_stage4 s4,BITMAP *Cursor,int *b_play,int *b_exit,int *b_help,int *b_son,int *menu,int *etat_s2,int *etat_s3,int *etat_s4,int *b_prec,int stage_deverouille,int *turn_on_music,bouton son_coupe,int *sound_off,int *bloquer_click,int *click_counter);
 * \brief Cette fonction permet de faire appel aux fonctions du menu.
*/
void fonction_menu(int *continuer,Background fond_menu,Background menu_help,int *page,bouton exit,bouton help,bouton play,bouton son,bouton prec,icone_stage1 s1,icone_stage2 s2,icone_stage3 s3,icone_stage4 s4,BITMAP *Cursor,int *b_play,int *b_exit,int *b_help,int *b_son,int *menu,int *etat_s2,int *etat_s3,int *etat_s4,int *b_prec,int stage_deverouille,int *turn_on_music,bouton son_coupe,int *sound_off,int *bloquer_click,int *click_counter);


#endif
