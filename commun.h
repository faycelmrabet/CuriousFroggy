/**
 * \file commun.h
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include <allegro.h>
#define np2 52
#define nbr_piece 34
#define nbr_serpent 2
#define nbr_reine 3

#ifndef COMMUN_H_INCLUDED
#define COMMUN_H_INCLUDED

/** *@brief x et y sont les coordonnées du fond. img contient le BITMAP du fond  */
typedef struct
{
	int x;
	int y;
	BITMAP *img;
	
}Background;

/** *@brief img contient le BITMAP du Calque qui est qui est l'image du fond dans lequel les obstacles sont coloriés par des couleurs spécifiques (les trous en blanc de coordonnées 16777215, le plancher en bleu ciel de coordonnées 65535, la zone d'arrivée en orange de coordonnées 16850088 dans tous les stages à l'exception du stage 3 où seulement les obstacles sont coloriés en blanc de coordonnées 16777215) 
 * x est inversement proportionelle à fond.x. Lorsque cette dernière augmente calque.x diminue et inversement */
typedef struct 
{
BITMAP *img;
int x,y;
}Calque;

/** *@brief Cette structure contient les positions x et y des messages GameOver et YouWin. Chacune d'eux contient deux etats mis dans 2 images dans le tableau BITMAP *img[]  */
typedef struct 
{
int x,y;
BITMAP *img[2];
}Game;


/** *@brief x et y sont les coordonnées des différentes pièces organisées dans les tableau int x[] et int y[]. img contient le BITMAP du fond  */
typedef struct
{ int x[100];
  int y[100];
  BITMAP *img;	
}Coins;	

/** *@brief x la position de Froggy en largeur et y en hauteur. Nous avons un seul sprite Froggy dans le jeu. img  est le BITMAP de ce pigeon  puisque il contient 7 frames donc nous avons 7 images. */
typedef struct 
{
int x;
int y;
BITMAP *img[7];
}Froggy;

/** *@brief Celle ci est la strucuture de la barre de vie. x est la position de la Barre en largeur et y en hauteur. Nous avons une seule Barre de vie dans le jeu. img  est le BITMAP de cette Barre  puisque nous avons dans le jeu 6 vies donc nous avons ici 7 frames. (un pour vie = 0) */
typedef struct
{int x;
 int y;
 BITMAP *img[7];
}Barre;

/** *@brief Celle-ci est la structure de la tête de Froggy qui s'affiche en haut et à gauche de l'écran dans les stages 1,2 et 4*/
typedef struct
{int x;
 int y;
 BITMAP *img;
}Tete;

/** *@brief Cette structure contient des images de chiffres utilisées pour afficher le score. Puisque les chiffres vont de 0 à 9 donc nous avons ici 10 images*/
typedef struct
{ BITMAP *img[10];
}Numero;

/** *@brief Cette structure est celle du menu de pause. Elle contient les coordonnées x et y du menu mais aussi les différents états (3 frames)*/
typedef struct
{int x;
 int y;
 BITMAP *img[3];
}Pause;

/** *@brief Cette structure contient la barre de chargement du jeu avec ses 4 états d'avancement*/
typedef struct
{BITMAP *img[4];
 int x;
 int y;
}Chargement;

/** *@brief Ceci est la déclaration du Buffer comme étant variable globale*/
BITMAP *Buffer;


/**
 * \fn void supprimer_piece(int pos,Coins *piece,int *nbr_p);
 * \brief Cette fonction permet de supprimer une pièce d'un tableau de Coins en prenant comme paramètre la position de la pièce à supprimer dans le tableau piece (Coins) et le nombre total de pièces
*/
void supprimer_piece(int pos,Coins *piece,int *nbr_p);

/**
 * \fn void update_pos_coins(Coins *piece, int nbr_p,int step);
 * \brief cette fonction permet de mettre à jour la position des pièces (Coins) au fur et à mesure que la posisition du fond est modifiée. On doit faire appel à cette fonction à chaque fois que fond.x augmente ou diminue
*/
void update_pos_coins(Coins *piece, int nbr_p,int step);

/**
 * \fn void init_Game_Over( Game *game);
 * \brief Cette fonction permet d'initialiser la variable game de type Game qui est le message Game Over
*/
void init_Game_Over( Game *game);

/**
 * \fn void init_You_Win(Game *win);
 * \brief Cette fonction permet d'initialiser la variable win de type Game qui est le message You Win
*/
void init_You_Win(Game *win);

/**
 * \fn void init_barre_vie(Barre *barre);
 * \brief Cette fonction permet d'initialiser la barre de vie (structure Barre)
*/
void init_barre_vie(Barre *barre);

/**
 * \fn void init_barre_vie(Barre *barre);
 * \brief Cette fonction permet d'initialiser la structure Tete
*/
void init_tete(Tete *tete);

/**
 * \fn void init_numero(Numero *numero);
 * \brief Cette fonction permet d'initialiser la structure Numero
*/
void init_numero(Numero *numero);

/**
 * \fn void destroy_numero(Numero *numero);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Numero
*/
void destroy_numero(Numero *numero);

/**
 * \fn void afficher_score(int score, Numero numero);
 * \brief Cette fonction permet d'afficher le score sur l'écran en utilisant les images de la structure Numero
*/
void afficher_score(int score, Numero numero);

/**
 * \fn void destroy_barre(Barre *barre);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Barre
*/
void destroy_barre(Barre *barre);

/**
 * \fn void destroy_frog(Froggy *frog);
 * \brief Cette fonction permet de libérer la mémoire allouée pour la structure Froggy
*/
void destroy_frog(Froggy *frog);

/**
 * \fn void init_pause(Pause *pause);
 * \brief Cette fonction permet d'initialiser la structure Pause (menu pause)
*/
void init_pause(Pause *pause);

/**
 * \fn int select_next();
 * \brief Cette fonction permet de vérifier si le curseur de la souris est pointé ou non sur le bouton next de la structure Game. Si c'est le cas elle retourne 1 sinon elle retourne 0
*/
int select_next();

/**
 * \fn int pause_curseur();
 * \brief Cette fonction permet de vérifier sur quel bouton du menu Pause le curseur de la souris est pointé. Si il est pointé sur le bouton "resume" elle retourne 1, si c'est sur le bouton "quit" elle retourne 2 sinon elle retourne 0
*/
int pause_curseur();

/**
 * \fn void saving(int stage_deverouille);
 * \brief Cette fonction permet une variable de type entier dans un fichier nommé "save.txt". Elle crée un nouveau fichier si celui ci n'existe pas et elle écrase son ancien contenu
*/
void saving(int stage_deverouille);

/**
 * \fn int loading();
 * \brief Cette fonction permet de charger un entier qui se trouve dans le fichier "save.txt" et le retourner
*/
int loading();

/**
 * \fn void conversion_stage_etat_s(int stage_deverouille,int *etat_s2,int *etat_s3,int *etat_s4);
 * \brief Cette fonction permet de convertir allant de 1 à 4 en une série d'entiers correspondant à l'état ouvert ou fermé de chaque stage
*/
void conversion_stage_etat_s(int stage_deverouille,int *etat_s2,int *etat_s3,int *etat_s4);

/**
 * \fn void init_chargement(Chargement *chargement);
 * \brief Cette fonction permet d'initialiser la structure Chargement
*/
void init_chargement(Chargement *chargement);

/**
 * \fn void fonction_chargement(int *loading_counter,int *page,int *turn_on_music,Chargement chargement,Background curious_froggy);
 * \brief Cette fonction permet d'afficher l'animation de chargement au début du jeu
*/
void fonction_chargement(int *loading_counter,int *page,int *turn_on_music,Chargement chargement,Background curious_froggy);

#endif
