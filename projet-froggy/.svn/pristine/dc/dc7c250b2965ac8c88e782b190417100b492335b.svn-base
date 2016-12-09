#include "menu.h"
#include <allegro.h>
#include <alpng.h>


void init_menu1(bouton_exit *exit, bouton_help *help, bouton_play *play, bouton_son *son)
{
	play->x=800/2-60;
	play->y=600/2-60;
	play->img[0] = load_bitmap("./Boutons/play_jaune.bmp",NULL);
	play->img[1] = load_bitmap("./Boutons/play_vert.bmp",NULL);
	play->img[2] = load_bitmap("./Boutons/play_enfonce.bmp",NULL);
	
	if(play->img[0]==NULL)
	{allegro_message("Erreur lors du chargement des images!\n%s\n", allegro_error);
	
	}
	
	exit->x=800-110;
	exit->y=40;
	exit->img[0] = load_bitmap("./Boutons/exit_jaune.bmp",NULL);
	exit->img[1] = load_bitmap("./Boutons/exit_vert.bmp",NULL);
	exit->img[2] = load_bitmap("./Boutons/exit_enfonce.bmp",NULL);
	
	help->x=800-110;
	help->y=600-110;
	help->img[0] = load_bitmap("./Boutons/help_jaune.bmp",NULL);
	help->img[1] = load_bitmap("./Boutons/help_vert.bmp",NULL);
	help->img[2] = load_bitmap("./Boutons/help_enfonce.bmp",NULL);
	
	son->x=40;
	son->y=600-110;
	son->img[0] = load_bitmap("./Boutons/son_jaune.bmp",NULL);
	son->img[1] = load_bitmap("./Boutons/son_vert.bmp",NULL);
	son->img[2] = load_bitmap("./Boutons/son_enfonce.bmp",NULL);
	
	
	
}

void init_menu2(icone_stage1 *s1, icone_stage2 *s2, icone_stage3 *s3, icone_stage4 *s4)
{
	
	s1->x=150;
	s1->y=75;
	s1->img = load_bitmap("./icones/stage1_ouvert.bmp",NULL);
	
	s2->x=450;
	s2->y=75;
	s2->img[0] = load_bitmap("./icones/stage2_ouvert.bmp",NULL);
	s2->img[1] = load_bitmap("./icones/stage2_ferme.bmp",NULL);
	
	s3->x=150;
	s3->y=325;
	s3->img[0] = load_bitmap("./icones/stage3_ouvert.bmp",NULL);
	s3->img[1] = load_bitmap("./icones/stage3_ferme.bmp",NULL);
	
	s4->x=325;
	s4->y=325;
	s4->img[0] = load_bitmap("./icones/stage4_ouvert.bmp",NULL);
	s4->img[1] = load_bitmap("./icones/stage4_ferme.bmp",NULL);
	
}

void etat_bouton(int *b_play,int *b_exit,int *b_help,int *b_son)
{ if(mouse_b & 1 && mouse_x<(SCREEN_W/2+60) && (mouse_x>SCREEN_W/2-60) &&(mouse_y>SCREEN_H/2-60) && (mouse_y<SCREEN_H/2+60))
{ play_b=1;
}
}


int main() {
BITMAP *Buffer;
BITMAP *Background;
BITMAP *Cursor;
bouton_exit exit; bouton_help help; bouton_play play; bouton_son son;
//icone_stage1 s1; icone_stage2 s2; icone_stage3 s3; icone_stage4 s4;
int continuer = 1;
int play_b =0; int b_exit=0; int b_help=0; int b_son = 0;

allegro_init();
if (install_keyboard() == -1) {
allegro_message("Error while keyboard initialization! %s", allegro_error);
return -1;
}

if (install_mouse() == -1) {
allegro_message("Error while mouse initialization! %s", allegro_error);
return -1;
}
set_color_depth(16);
if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); 
allegro_message("Unable to initialize video mode!\n%s\n", allegro_error);
return 1;
}
init_menu1(&exit,&help,&play,&son);
Background = load_bitmap("menu1.bmp",NULL);
Cursor = load_bitmap("cursor.bmp",NULL);
Buffer = create_bitmap(800, 600);

while(continuer)
{

clear_bitmap(Buffer);	
blit(Background,Buffer,0,0,0,0,SCREEN_W,SCREEN_H);

draw_sprite(Buffer,help.img[0],help.x,help.y);
draw_sprite(Buffer,exit.img[0],exit.x,exit.y);
draw_sprite(Buffer,son.img[0],son.x,son.y);




if(key[KEY_ESC])
{continuer = 0;}


if(play_b==0)
{draw_sprite(Buffer,play.img[0],play.x,play.y);}
else
{draw_sprite(Buffer,play.img[1],play.x,play.y);}

draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}
return 0;
}

END_OF_MAIN();
