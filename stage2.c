/**
 * \file stage2.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include "stage2.h"
#include "commun.h"

extern BITMAP *Buffer;

void init_coins2(Coins *piece,int xfond)
{ piece->img = load_bitmap("./Commun/piece.bmp",NULL);

    piece->x[0] = xfond + 1400;
	piece->y[0] = 180;
	
	piece->x[1] = xfond +1500;
	piece->y[1] = 200;
	
	piece->x[2] = xfond + 1600;
	piece->y[2] = 220;
	
	piece->x[3] = xfond + 1700;
	piece->y[3] = 240;
	
	piece->x[4] = xfond +1800;
	piece->y[4] = 260;
	
	piece->x[5] = xfond + 2700;
	piece->y[5] = 100;
	
	piece->x[6] = xfond +2900;
	piece->y[6] = 320;
	
	piece->x[7] = xfond+3100;
	piece->y[7] = 100;
	
	piece->x[8] = xfond + 3300;
	piece->y[8] = 320;
	
	piece->x[9] = xfond + 3800;
	piece->y[9] = 50;
	
	piece->x[10] = xfond + 3900;
	piece->y[10] = 100;
	
	piece->x[11] = xfond + 4000;
	piece->y[11] = 50;
	
	piece->x[12] = xfond + 4100;
	piece->y[12] = 100;
	
	piece->x[13] = xfond + 4200;
	piece->y[13] = 50;
	
	piece->x[14] = xfond + 4500;
	piece->y[14] = 400;
	
	piece->x[15] = xfond + 4600;
	piece->y[15] = 500;
	
	piece->x[16] = xfond + 4700;
	piece->y[16] = 400;
	
	piece->x[17] = xfond + 4800;
	piece->y[17] = 500;
	
	piece->x[18] = xfond + 4900;
	piece->y[18] = 400;
	
	piece->x[19] = xfond + 5000;
	piece->y[19] = 500;
	
	piece->x[20] = xfond + 6500;
	piece->y[20] = 180;
	
	piece->x[21] = xfond + 6700;
	piece->y[21] = 180;
	
	piece->x[22] = xfond + 6900;
	piece->y[22] = 300;
	
	piece->x[23] = xfond +7100;
	piece->y[23] = 300;
	
	piece->x[24] = xfond+7300;
	piece->y[24] = 180;
	
	piece->x[25] = xfond + 7500;
	piece->y[25] = 180;
	
	piece->x[26] = xfond + 8100;
	piece->y[26] = 80;
	
	piece->x[27] = xfond + 8300;
	piece->y[27] = 400;
	
	piece->x[28] = xfond + 8500;
	piece->y[28] = 80;
	
	piece->x[29] = xfond + 8700;
	piece->y[29] = 400;
	
	piece->x[30] = xfond + 9500;
	piece->y[30] = 180;
	
	piece->x[31] = xfond + 9600;
	piece->y[31] = 220;
	
	piece->x[32] = xfond + 9700;
	piece->y[32] = 260;
	
	piece->x[33] = xfond + 9800;
	piece->y[33] = 300;

    piece->x[34] = xfond + 10500;
	piece->y[34] = 40;
	
	piece->x[35] = xfond + 10800;
	piece->y[35] = 200;
	
	piece->x[36] = xfond + 10900;
	piece->y[36] = 200;
	
	piece->x[37] = xfond + 11200;
	piece->y[37] = 40;
	
	piece->x[38] = xfond + 12000;
	piece->y[38] = 500;

    piece->x[39] = xfond + 12300;
	piece->y[39] = 200;
	
	piece->x[40] = xfond + 12600;
	piece->y[40] = 500;
	
	piece->x[41] = xfond + 12900;
	piece->y[41] = 200;

   piece->x[42] = xfond + 14000;
	piece->y[42] = 100;

    piece->x[43] = xfond + 14200;
	piece->y[43] = 100;
	
	piece->x[44] = xfond + 14400;
	piece->y[44] = 100;
	
	piece->x[45] = xfond + 14600;
	piece->y[45] = 100;

    piece->x[46] = xfond + 15600;
	piece->y[46] = 500;
	
	piece->x[47] = xfond + 15800;
	piece->y[47] = 300;

   piece->x[48] = xfond + 16000;
	piece->y[48] = 100;

    piece->x[49] = xfond + 17000;
	piece->y[49] = 500;
	
	piece->x[50] = xfond + 17200;
	piece->y[50] = 80;
	
	piece->x[51] = xfond + 17400;
	piece->y[51] = 100;

}

BITMAP *Buffer;
volatile long speed_counter = 0;
void increment_speed_counter()
{
  speed_counter++; 
}
END_OF_FUNCTION(increment_speed_counter); 

void init_speed_counter()
{ speed_counter = 0;
}


 void init_pigeon (Pigeon *pigeon )
 {
	 pigeon->img[0] = load_bitmap("./Stage2/pos_pigeon/pigeon1_1.bmp",NULL);
	 pigeon->img[1]=load_bitmap("./Stage2/pos_pigeon/pigeon2_2.bmp",NULL);
	 pigeon->img[2]=load_bitmap("./Stage2/pos_pigeon/pigeon3_3.bmp",NULL);
	 pigeon->img[3] = load_bitmap("./Stage2/pos_pigeon/pigeon2_2.bmp",NULL);
	 pigeon->img[4]=load_bitmap("./Stage2/pos_pigeon/pigeon1_1.bmp",NULL);
	 
	pigeon->x=800/5-100;
	pigeon->y=600/2-60;
	
}

void init_background2(Background *background )
{
	background->img = load_bitmap("./Stage2/fond_nuages.bmp",NULL);
	background->x=0;
	background->y=0;
	
}
 
void init_calque2(Calque *calque, Pigeon pigeon)
{
	
	calque->img=load_bitmap("./Stage2/calque.bmp",NULL);
	calque->x=pigeon.x;
	calque->y=pigeon.y;
}
 
 
 
 
 
void chute2 (int test ,Pigeon *pigeon)
{
	if (pigeon->y<800)
	{pigeon->y++;}
	draw_sprite(Buffer,pigeon->img[0],pigeon->x,pigeon->y);
}

	  
int collision2 (Calque calque)
{
	if (getpixel(calque.img,calque.x+10,calque.y+110)==16777215)
	{return 1; }
	else if (getpixel(calque.img,calque.x+110,calque.y+110)==16777215)
	{return 1; }  
	else {return 0;}
}

int collision_piece2(int x,int y,int *test,Coins piece,int nbr_p)
{int pos = 666,i;
 for(i=0;i<nbr_p;i++)
 { if(0<= piece.x[i] && 150>=piece.x[i] && y+60>=piece.y[i]-20 && y+60<=piece.y[i]+200)
   {(*test)=1;
    pos = i;
   }

 }
 return pos;
 
}

void destroy_pigeon(Pigeon *pigeon)
{int i;
 for(i=0;i<5;i++)
 {destroy_bitmap(pigeon->img[i]);}
}

void fonction_stage2(Pigeon *pigeon,Background *fond2,Game game_over,Calque *calque2,Coins *piece2,int *nbr2,int *test2,
int *frame_counter,int *key_pressed2,Pause pause,BITMAP *Cursor,int *block_speed_counter,int *stage2_termine,int *win_stage2,int *score2)
{int i;
 int pos_piece2;
 int test_piece2 = 0;
 int pause_bouton;
 
 *test2=collision2 (*calque2);

	
	blit(fond2->img,Buffer,0,0,fond2->x,fond2->y,fond2->img->w,fond2->img->h);
	for(i=0;i<(*nbr2);i++)
	{ draw_sprite(Buffer,piece2->img,piece2->x[i],piece2->y[i]);
        }
	
 if(key[KEY_P] && *key_pressed2 == 0)
  { *key_pressed2 =22;
  }
	
	if((*test2)==0  && (*key_pressed2 == 0 || *key_pressed2 == 33))
	{while(speed_counter > 0)
	{if(fond2->x > -23*800)
	{
	fond2->x--;
	 calque2->x++;
	 
	 update_pos_coins(piece2,*nbr2,-1);
    }
    
    else if(fond2->x<= -23*800)
    {pigeon->x++;
     calque2->x++;
	}
   if(key[KEY_UP]&&pigeon->y>-50 && *key_pressed2 == 0)
   { pigeon->y--;
     calque2->y--;
   }
   else if(key[KEY_DOWN]&& pigeon->y+120<600 && *key_pressed2 == 0)
   {pigeon->y++;
    calque2->y++;
   }
   
   speed_counter --;
   (*frame_counter)++;
   if(*frame_counter > 400) 
	{
	*frame_counter = 0;
	}
   }
   
   if(*frame_counter<40)
   { draw_sprite(Buffer,pigeon->img[0],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=40 && *frame_counter<80)
   { draw_sprite(Buffer,pigeon->img[1],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=80 && *frame_counter<120)
   { draw_sprite(Buffer,pigeon->img[2],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=120&& *frame_counter<160)
   { draw_sprite(Buffer,pigeon->img[3],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=160 && *frame_counter<200)
   { draw_sprite(Buffer,pigeon->img[4],pigeon->x,pigeon->y);
   }
    else if(*frame_counter>=200 && *frame_counter<240)
   { draw_sprite(Buffer,pigeon->img[0],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=240 && *frame_counter<280)
   { draw_sprite(Buffer,pigeon->img[1],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=280 && *frame_counter<320)
   { draw_sprite(Buffer,pigeon->img[2],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=320 && *frame_counter<360)
   { draw_sprite(Buffer,pigeon->img[3],pigeon->x,pigeon->y);
   }
   else if(*frame_counter>=360 && *frame_counter<400)
   { draw_sprite(Buffer,pigeon->img[4],pigeon->x,pigeon->y);
   }
}
else if(*test2)
{ 
	chute2(*test2,pigeon);
	
}


if(*key_pressed2==22)
{ 
  pause_bouton = pause_curseur();
  draw_sprite(Buffer,pause.img[pause_bouton],pause.x,pause.y);
  draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
  
  if(pause_bouton ==1 && mouse_b & 1)
  { *key_pressed2 = 0;
    *block_speed_counter = 1;
    speed_counter = 0;
  }
  else if(pause_bouton==2 && mouse_b & 1)
  { *stage2_termine = 1;
    //*block_speed_counter = 1;
    speed_counter = 0;
  }
}

if(*score2>=27 && fond2->x<= -23*800)
{*win_stage2=1;
 *key_pressed2 = 33;
 
}



pos_piece2 = collision_piece2(calque2->x,pigeon->y,&test_piece2,*piece2,*nbr2);

if(test_piece2 == 1)
{supprimer_piece(pos_piece2,piece2,nbr2);
 test_piece2 = 0;
 (*score2)++;
}

//textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Fond.x: %d Score: %d",fond2->x,*score2);


}
