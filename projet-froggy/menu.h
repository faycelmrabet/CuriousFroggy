#include <allegro.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct 
{
int x,y;
BITMAP *img[3];		
}bouton_play;

typedef struct 
{
int x,y;
BITMAP *img[3];			
}bouton_exit;

typedef struct 
{
int x,y;
BITMAP *img[3];			
}bouton_help;

typedef struct 
{
int x,y;
BITMAP *img[3];			
}bouton_son;

typedef struct
{ int x;
  int y;
  BITMAP *img;
} icone_stage1;

typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage2;

typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage3;

typedef struct
{ int x;
  int y;
  BITMAP *img[2];
} icone_stage4;

void init_menu1(bouton_exit *exit, bouton_help *help, bouton_play *play, bouton_son *son);
void init_menu2(icone_stage1 *s1, icone_stage2 *s2, icone_stage3 *s3, icone_stage4 *s4);


#endif
