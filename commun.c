/**
 * \file commun.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include "commun.h"
#include <stdio.h>
extern BITMAP *Buffer;

void supprimer_piece(int pos,Coins *piece,int *nbr_p)
{int i;
 
 for(i=pos;i<(*nbr_p-1);i++)
 { piece->x[i]=piece->x[i+1];
   piece->y[i]=piece->y[i+1];
 }
 (*nbr_p)--;
}

void update_pos_coins(Coins *piece, int nbr_p,int step)
{
	int i;
	for(i=0;i<nbr_p;i++)
	{ piece->x[i]+=step;
	}
		
}

void init_Game_Over( Game *game)
{
	game->x=0;
	game->y=0;
	 game->img[0]=load_bitmap("./Commun/gameover_jaune.bmp",NULL);
	 game->img[1]=load_bitmap("./Commun/gameover_vert.bmp",NULL);
}

void init_You_Win(Game *win)
{ win->x = 0;
  win->y=0;
  win->img[0] = load_bitmap("./Commun/youwin_jaune.bmp",NULL);
  win->img[1] = load_bitmap("./Commun/youwin_vert.bmp",NULL);
}

void init_barre_vie(Barre *barre)
{ barre->x=100;
  barre->y = 25;
  barre->img[0] = load_bitmap("./Commun/barre_vie/barre_0.bmp",NULL);
  barre->img[1] = load_bitmap("./Commun/barre_vie/barre_1.bmp",NULL);
  barre->img[2] = load_bitmap("./Commun/barre_vie/barre_2.bmp",NULL);
  barre->img[3] = load_bitmap("./Commun/barre_vie/barre_3.bmp",NULL);
  barre->img[4] = load_bitmap("./Commun/barre_vie/barre_4_gimp.bmp",NULL);
  barre->img[5] = load_bitmap("./Commun/barre_vie/barre_5_gimp.bmp",NULL);
  barre->img[6] = load_bitmap("./Commun/barre_vie/barre_6_gimp.bmp",NULL);
}

void init_tete(Tete *tete)
{tete->x=-3;
 tete->y=-6;
 tete->img = load_bitmap("./Commun/barre_vie/tete_froggy.bmp",NULL);
 
}

void init_numero(Numero *numero)
{ numero->img[0] = load_bitmap("./Commun/numero/0.bmp",NULL);
  numero->img[1] = load_bitmap("./Commun/numero/1.bmp",NULL);
  numero->img[2] = load_bitmap("./Commun/numero/2.bmp",NULL);
  numero->img[3] = load_bitmap("./Commun/numero/3.bmp",NULL);
  numero->img[4] = load_bitmap("./Commun/numero/4.bmp",NULL);
  numero->img[5] = load_bitmap("./Commun/numero/5.bmp",NULL);
  numero->img[6] = load_bitmap("./Commun/numero/6.bmp",NULL);
  numero->img[7] = load_bitmap("./Commun/numero/7.bmp",NULL);
  numero->img[8] = load_bitmap("./Commun/numero/8.bmp",NULL);
  numero->img[9] = load_bitmap("./Commun/numero/9.bmp",NULL);
}

void destroy_numero(Numero *numero)
{ int i;
  for(i=0;i<10;i++)
  {destroy_bitmap(numero->img[i]);}
}

void afficher_score(int score, Numero numero)
{int u,d;
 
 
 d = score/10;
 u = score % 10;
 
 //draw_sprite(Buffer,numero.img[m],660,10);
 //draw_sprite(Buffer,numero.img[c],690,10);
 draw_sprite(Buffer,numero.img[d],720,10);
 draw_sprite(Buffer,numero.img[u],750,10);
 
 
}


void destroy_barre(Barre *barre)
{int i;
 for(i=0;i<7;i++)
 {destroy_bitmap(barre->img[i]);}
}

void destroy_frog(Froggy *frog)
{int i;
 for(i=0;i<7;i++)
 {destroy_bitmap(frog->img[i]);}
}

void init_pause(Pause *pause)
{ pause->x = 250;
  pause->y = 50;
  pause->img[0] = load_bitmap("./Pause/pause_jaune.bmp",NULL);
  pause->img[1] = load_bitmap("./Pause/pause_vert.bmp",NULL);
  pause->img[2] = load_bitmap("./Pause/pause_rouge.bmp",NULL);
  
}

int select_next()
{int selection = 0;
 if (mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
 { selection = 1;}
 /*else if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
 { selection = 2;}*/
 
 
 return selection;

}

int pause_curseur()
{ int bouton_curseur;
  if(mouse_x>=310 && mouse_x<=470 && mouse_y>=230 && mouse_y<=300)
  {bouton_curseur = 1;}
  else if (mouse_x>=310 && mouse_x<=470 && mouse_y>=390 && mouse_y<=430)
  {bouton_curseur = 2;}
  else
  {bouton_curseur = 0;}
  
  return bouton_curseur;
}

void saving(int stage_deverouille)
{ FILE *fichier;
  fichier = fopen("./Commun/save.txt","w");
  fprintf(fichier,"%d",stage_deverouille);
  fclose(fichier);
}

int loading()
{int stage_deverouille;
 FILE *fichier;
 fichier = fopen("./Commun/save.txt","r");
 fscanf(fichier,"%d",&stage_deverouille);
 fclose(fichier);
 return stage_deverouille;
}

void conversion_stage_etat_s(int stage_deverouille,int *etat_s2,int *etat_s3,int *etat_s4)
{ if(stage_deverouille == 1)
  {*etat_s2 = 0;
   *etat_s3 = 0;
   *etat_s4 = 0;
  }
  else if(stage_deverouille == 2)
  {*etat_s2 = 1;
   *etat_s3 = 0;
   *etat_s4 = 0;
  }
  else if(stage_deverouille == 3)
  {*etat_s2 = 1;
   *etat_s3 = 1;
   *etat_s4 = 0;
  }
  else if(stage_deverouille == 4)
  {*etat_s2 = 1;
   *etat_s3 = 1;
   *etat_s4 = 1;
  }
}

void init_chargement(Chargement *chargement)
{ chargement->img[0] = load_bitmap("./Loading/barre00.bmp",NULL);
chargement->img[1] = load_bitmap("./Loading/barre11.bmp",NULL);
chargement->img[2] = load_bitmap("./Loading/barre22.bmp",NULL);
chargement->img[3] = load_bitmap("./Loading/barre33.bmp",NULL);

chargement->x = 0;
chargement->y = 0;
}

void fonction_chargement(int *loading_counter,int *page,int *turn_on_music,Chargement chargement,Background curious_froggy)
{
	if(*loading_counter<1200)
	{blit(curious_froggy.img,Buffer,0,0,0,0,SCREEN_W,SCREEN_H);
	 (*loading_counter)++;
    }
    else if(*loading_counter>=1200 && *loading_counter<2000)
    {blit(chargement.img[0],Buffer,0,0,chargement.x,chargement.y,SCREEN_W,SCREEN_H);
     (*loading_counter)++;
	}
	else if(*loading_counter>=2000 && *loading_counter<2800)
    {blit(chargement.img[1],Buffer,0,0,chargement.x,chargement.y,SCREEN_W,SCREEN_H);
     (*loading_counter)++;
	}
	else if(*loading_counter>=2800 && *loading_counter<3600)
    {blit(chargement.img[2],Buffer,0,0,chargement.x,chargement.y,SCREEN_W,SCREEN_H);
     (*loading_counter)++;
	}
	else if(*loading_counter>=3600 && *loading_counter<4400)
    {blit(chargement.img[3],Buffer,0,0,chargement.x,chargement.y,SCREEN_W,SCREEN_H);
     (*loading_counter)++;
     if(*loading_counter == 4400)
     {*page=0;
      *turn_on_music = 0;
     }
	}
}
