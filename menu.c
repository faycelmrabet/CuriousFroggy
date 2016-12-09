/**
 * \file menu.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include "menu.h"
#include "commun.h"
#include "stage2.h"

extern BITMAP *Buffer;

void init_fond_menu(Background *fond)
{fond->img = load_bitmap("./Menu/menu1.bmp",NULL);
 fond->x = 0;
 fond->y=0;
}

void init_menu1(bouton *exit, bouton *help, bouton *play, bouton *son, bouton *son_coupe)
{
	play->x=800/2-60;
	play->y=600/2-60;
	play->img[0] = load_bitmap("./Menu/Boutons/play_jaune.bmp",NULL);
	play->img[1] = load_bitmap("./Menu/Boutons/play_vert.bmp",NULL);
	play->img[2] = load_bitmap("./Menu/Boutons/play_enfonce.bmp",NULL);
	
	if(play->img[0]==NULL)
	{allegro_message("Erreur lors du chargement des images!\n%s\n", allegro_error);
	
	}
	
	exit->x=800-110;
	exit->y=40;
	exit->img[0] = load_bitmap("./Menu/Boutons/exit_jaune.bmp",NULL);
	exit->img[1] = load_bitmap("./Menu/Boutons/exit_rouge.bmp",NULL);
	exit->img[2] = load_bitmap("./Menu/Boutons/exit_enfonce.bmp",NULL);
	
	help->x=800-110;
	help->y=600-110;
	help->img[0] = load_bitmap("./Menu/Boutons/help_jaune.bmp",NULL);
	help->img[1] = load_bitmap("./Menu/Boutons/help_vert.bmp",NULL);
	help->img[2] = load_bitmap("./Menu/Boutons/help_enfonce.bmp",NULL);
	
	son->x=40;
	son->y=600-110;
	son->img[0] = load_bitmap("./Menu/Boutons/son_jaune.bmp",NULL);
	son->img[1] = load_bitmap("./Menu/Boutons/son_vert.bmp",NULL);
	son->img[2] = load_bitmap("./Menu/Boutons/son_enfonce.bmp",NULL);
	
	son_coupe->x=40;
	son_coupe->y=600-110;
	son_coupe->img[0] = load_bitmap("./Menu/Boutons/son_jaune_coupe.bmp",NULL);
	son_coupe->img[1] = load_bitmap("./Menu/Boutons/son_vert_coupe.bmp",NULL);
	son_coupe->img[2] = load_bitmap("./Menu/Boutons/son_enfonce_coupe.bmp",NULL);
	
	
	
}

void init_menu2(icone_stage1 *s1, icone_stage2 *s2, icone_stage3 *s3, icone_stage4 *s4)
{
	
	s1->x=150;
	s1->y=75;
	s1->img = load_bitmap("./Menu/icones/stage11_ouvert.bmp",NULL);
	
	s2->x=450;
	s2->y=75;
	s2->img[0] = load_bitmap("./Menu/icones/stage1_ferme.bmp",NULL);
	s2->img[1] = load_bitmap("./Menu/icones/stage1_ouvert.bmp",NULL);
	
	s3->x=150;
	s3->y=325;
	s3->img[0] = load_bitmap("./Menu/icones/stage2_ferme.bmp",NULL);
	s3->img[1] = load_bitmap("./Menu/icones/stage2_ouvert.bmp",NULL);
	
	s4->x=450;
	s4->y=325;
	s4->img[0] = load_bitmap("./Menu/icones/stage4_ferme.bmp",NULL);
	s4->img[1] = load_bitmap("./Menu/icones/stage4_ouvert.bmp",NULL);
	
	
	
}

void init_bouton_prec(bouton *prec)
{prec->x=40;
	prec->y=600-110;
	prec->img[0] = load_bitmap("./Menu/Boutons/bouton prec_jaune.bmp",NULL);
	prec->img[1] = load_bitmap("./Menu/Boutons/bouton prec_rouge.bmp",NULL);
	prec->img[2] = load_bitmap("./Menu/Boutons/bouton prec_enfonce.bmp",NULL);
}

void etat_bouton_prec(int *b_prec)
{if (mouse_b & 1 && mouse_x<110 && mouse_x>40 && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_prec)=2;}
  else if (mouse_x<110 && mouse_x>40 && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_prec)=1;}
 else
 {(*b_prec)=0;}
}

void etat_bouton(int *b_play,int *b_exit,int *b_help,int *b_son)
{ if(mouse_b & 1 && mouse_x<(SCREEN_W/2+60) && (mouse_x>SCREEN_W/2-60) &&(mouse_y>SCREEN_H/2-60) && (mouse_y<SCREEN_H/2+60))
{ (*b_play)=2;
}
else if(mouse_x<(SCREEN_W/2+60) && (mouse_x>SCREEN_W/2-60) &&(mouse_y>SCREEN_H/2-60) && (mouse_y<SCREEN_H/2+60))
{ (*b_play)=1;
}
else
{(*b_play)=0;}

if(mouse_b & 1 && mouse_x<(SCREEN_W-40) && (mouse_x>SCREEN_W-110) && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_help)=2;
}
else if(mouse_x<(SCREEN_W-40) && (mouse_x>SCREEN_W-110) && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_help)=1;
}
else
{(*b_help)=0;}

 if (mouse_b & 1 && mouse_x<110 && mouse_x>40 && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_son)=2;}
  else if (mouse_x<110 && mouse_x>40 && (mouse_y>SCREEN_H-110) && (mouse_y<SCREEN_H-40))
 { (*b_son)=1;}
 else
 {(*b_son)=0;}
 
 if (mouse_b & 1 && mouse_x<(SCREEN_W-40) && (mouse_x>SCREEN_W-110) && (mouse_y>40) && (mouse_y<110))
 {(*b_exit)=2;}

else if (mouse_x<(SCREEN_W-40) && (mouse_x>SCREEN_W-110) && (mouse_y>40) && (mouse_y<110))
 {(*b_exit)=1;}
 else
 {(*b_exit)=0;}
}


void blit_boutons(int b_play,int b_exit,int b_help,int b_son,bouton exit,bouton help,bouton play,bouton son,bouton son_coupe,int sound_off)
{ 
	//bouton exit; bouton help; bouton play; bouton son;
	//init_menu1(&exit,&help,&play,&son);
	
	draw_sprite(Buffer,play.img[b_play],play.x,play.y);
	draw_sprite(Buffer,exit.img[b_exit],exit.x,exit.y);
	if(sound_off == 0)
	{draw_sprite(Buffer,son.img[b_son],son.x,son.y);}
	else if(sound_off == 1)
	{draw_sprite(Buffer,son_coupe.img[b_son],son_coupe.x,son_coupe.y);}
	
	draw_sprite(Buffer,help.img[b_help],help.x,help.y);
	
}

void destroy_boutons(bouton *exit, bouton *help, bouton *play, bouton *son)
{int i;
 for(i=0;i<3;i++)
 { destroy_bitmap(play->img[i]);
   destroy_bitmap(exit->img[i]);
   destroy_bitmap(help->img[i]);
   destroy_bitmap(son->img[i]);
}
}

void destroy_icones(icone_stage1 *s1,icone_stage2 *s2,icone_stage3 *s3,icone_stage4 *s4)
{int i;
 destroy_bitmap(s1->img);
 for(i=0;i<2;i++)
 {destroy_bitmap(s2->img[i]);
 destroy_bitmap(s3->img[i]);
 destroy_bitmap(s4->img[i]);
}
}

void blit_icones(int etat_s2,int etat_s3,int etat_s4,icone_stage1 s1, icone_stage2 s2,icone_stage3 s3,icone_stage4 s4)
{ //icone_stage1 s1; icone_stage2 s2;icone_stage3 s3;icone_stage4 s4;
//init_menu2(&s1, &s2, &s3, &s4);
draw_sprite(Buffer,s1.img,s1.x,s1.y);
	  draw_sprite(Buffer,s2.img[etat_s2],s2.x,s2.y);
	  draw_sprite(Buffer,s3.img[etat_s3],s3.x,s3.y);
	  draw_sprite(Buffer,s4.img[etat_s4],s4.x,s4.y);
	  
}

int select_stage()
{int selection = 0;
 if (mouse_b & 1 && mouse_x<350 && mouse_x>150 && (mouse_y>75) && (mouse_y<275))
 { selection = 1;}
 else if (mouse_b & 1 && mouse_x<650 && mouse_x>450 && (mouse_y>75) && (mouse_y<275))
 { selection = 2;}
 else if (mouse_b & 1 && mouse_x<350 && mouse_x>150 && (mouse_y>325) && (mouse_y<525))
 { selection = 3;}
 else if (mouse_b & 1 && mouse_x<650 && mouse_x>450 && (mouse_y>325) && (mouse_y<575))
 { selection = 4;}
 
 return selection;

}

void init_menu_help(Background *menu_help)
{ menu_help->x = 0;
  menu_help->y = 0;
  menu_help->img = load_bitmap("./Menu/menu_help.bmp",NULL);
}

void fonction_menu(int *continuer,Background fond_menu,Background menu_help,int *page,bouton exit,bouton help,bouton play,bouton son,bouton prec,icone_stage1 s1,
icone_stage2 s2,icone_stage3 s3,icone_stage4 s4,BITMAP *Cursor,int *b_play,int *b_exit,int *b_help,int *b_son,int *menu,int *etat_s2,int *etat_s3,int *etat_s4,int *b_prec,int stage_deverouille,int *turn_on_music,bouton son_coupe,int *sound_off,int *bloquer_click,int *click_counter)
{blit(fond_menu.img,Buffer,0,0,0,0,SCREEN_W,SCREEN_H);



if(*menu == 1)
   {

	
	
	etat_bouton(b_play,b_exit,b_help,b_son);
	
	blit_boutons(*b_play,*b_exit,*b_help,*b_son,exit,help,play,son,son_coupe,*sound_off);

	
	if(*b_play == 2)
	{ *menu = 2;
	//son_music = play_sample(music,128,128,1000,0);
	}
	else if(*b_exit == 2)
	{//son_music = play_sample(music,128,128,1000,0);
		(*continuer )= 0;
	
	}
	else if(*b_help == 2)
	{ *menu = 3;}
	else if(*b_son == 2 && *sound_off == 0 && *bloquer_click == 0)
	{*sound_off = 1;
	 *bloquer_click = 1;
	}
	else if(*b_son == 2 && *sound_off == 1 && *bloquer_click == 0)
	{*sound_off = 0;
	 *turn_on_music = 0;
	 *bloquer_click = 1;
	}
	
	if(*bloquer_click == 1 && *click_counter<200)
	{ (*click_counter)++;
	  if(*click_counter == 200)
	  { *bloquer_click = 0;
	    *click_counter = 0;
	  }
	}
	
	}
	
	
else if(*menu== 2)
	{ clear_bitmap(Buffer);	
	  etat_bouton_prec(b_prec);
	  blit(fond_menu.img,Buffer,0,0,0,0,SCREEN_W,SCREEN_H);
	  blit_icones(*etat_s2,*etat_s3,*etat_s4,s1,s2,s3,s4);
	  draw_sprite(Buffer,prec.img[*b_prec],prec.x,prec.y);
	  
	  if(*b_prec == 2)
	{ *menu = 1;
	  *bloquer_click = 1;
	}
	if(select_stage()==1)
	{*page=1;
	*turn_on_music=1;
	
	}
	else if(select_stage()==2 && stage_deverouille >= 2)
	{*page=12;
	*turn_on_music=2;
	}
	else if(select_stage()==3 && stage_deverouille >= 3)
	{*page=2;
	 *turn_on_music=3;
	 init_speed_counter();
	
	}
	else if(select_stage()==4 && stage_deverouille == 4)
	{*page=4;
	 
	 *turn_on_music=4;
	}
	 
	}
	

else if(*menu == 3)
{clear_bitmap(Buffer);	
 etat_bouton_prec(b_prec);
 blit(menu_help.img,Buffer,0,0,menu_help.x,menu_help.y,SCREEN_W,SCREEN_H);
 draw_sprite(Buffer,prec.img[*b_prec],prec.x,prec.y);
 if(*b_prec == 2)
	{ *menu = 1;
	  *bloquer_click = 1;
	}
}
	
draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}

