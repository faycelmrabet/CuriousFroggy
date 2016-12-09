#include <allegro.h>
#ifndef STAGE4_H_INCLUDED
#define STAGE4_H_INCLUDED

typedef struct 
{
int x;
int y;
BITMAP *img[7];
}Froggy;

typedef struct
{
	int x;
	int y;
	BITMAP *img;
}Background;


#endif
