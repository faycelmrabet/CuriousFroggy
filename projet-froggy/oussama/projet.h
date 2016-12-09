#include <allegro.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define NB_IMAGE 8
#define NB_IMAGES 7
typedef struct
{
	int x;
	int y;
	BITMAP *img[NB_IMAGE];
}froggy;
typedef struct
{
	int x;
	int y;
	BITMAP *img[NB_IMAGES];
}rats;	
typedef struct
{
	int x;
	int y;
	BITMAP *img;
}fond_ecran;
#endif
