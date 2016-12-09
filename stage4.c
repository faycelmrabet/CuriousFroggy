/**
 * \file stage4.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include "stage4.h"
#include "commun.h"
extern BITMAP *Buffer;

void init_frog(Froggy *frog)
{
frog->img[0]=load_bitmap("./Stage4/frog_2d/1_bmp_2d_gimp.bmp",NULL);
frog->img[1]=load_bitmap("./Stage4/frog_2d/2_bmp_2d_gimp.bmp",NULL);
frog->img[2]=load_bitmap("./Stage4/frog_2d/3_bmp_2d_gimp.bmp",NULL);
frog->img[3]=load_bitmap("./Stage4/frog_2d/4_bmp_2d_gimp.bmp",NULL);
frog->img[4]=load_bitmap("./Stage4/frog_2d/5_bmp_2d_gimp.bmp",NULL);
frog->img[5]=load_bitmap("./Stage4/frog_2d/6_bmp_2d_gimp.bmp",NULL);
frog->img[6]=load_bitmap("./Stage4/frog_2d/1_bmp_2d_gimp.bmp",NULL);
frog->x=300;
frog->y=387;
	
}	

void init_background(Background *fond)
{fond->x=0;
 fond->y=0;
 fond->img = load_bitmap("./Stage4/fonds/9600_plate_2.bmp",NULL);
 
}

void init_calque(Calque *calque,Froggy frog)
{calque->img = load_bitmap("./Stage4/fonds/calque_4_orange.bmp",NULL);
 calque->x = frog.x;
 //calque->y = frog.y;
}
/*void destroy_frog(Froggy *frog)
{ int i;
  for(i=0;i<7;i++)
  {destroy_bitmap(frog->img[i]);}
}*/

int collision_blanc(Calque calque,int posx_blanc,int y)
{ 
  if( getpixel(calque.img,posx_blanc+20,y+93) == 16777215)
 {return 1;
 }
 else if(getpixel(calque.img,posx_blanc+70,y+93) == 16777215)
 {return 1;
 }
 else if(getpixel(calque.img,posx_blanc+45,y+88) == 65535)
 { return 2;
 }
 else
 {return 0;
 }
}

int collision_bleu(Calque calque,int posx_bleu,int y)
{ if(getpixel(calque.img,posx_bleu+20,y+88)== 65535 && getpixel(calque.img,posx_bleu+80,y+88)== 65535)
   {return 2;}
  else if(getpixel(calque.img,posx_bleu+20,y+88) == 16777215)
  {return 1;}
  else
  {return 0;}
}

void chute(int test,Froggy *frog,int direction)
{ 
 if (frog->y<1200 && direction == 0 && test == 1)
 {frog->y++;
  draw_sprite(Buffer,frog->img[5],frog->x,frog->y);
  
 }
 else if (frog->y<1200 && direction == 1 && test == 1)
 {frog->y++;
  draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);
  
 }
}

void init_coins(Coins *piece,int xfond)
{ piece->img = load_bitmap("./Stage4/fonds/piece_froggy_petite_gimp_photoshop_16.bmp",NULL);

piece->x[0] = xfond + 1400;
	piece->y[0] = 180;
	
	piece->x[1] = xfond +1500;
	piece->y[1] = 180;
	
	piece->x[2] = xfond + 1600;
	piece->y[2] = 180;
	
	piece->x[3] = xfond + 1700;
	piece->y[3] = 180;
	
	piece->x[4] = xfond +1800;
	piece->y[4] = 180;
	
	piece->x[5] = xfond + 2090;
	piece->y[5] = 280;
	
	piece->x[6] = xfond +2890;
	piece->y[6] = 320;
	
	piece->x[7] = xfond+3030;
	piece->y[7] = 230;
	
	piece->x[8] = xfond + 3220;
	piece->y[8] = 100;
	
	piece->x[9] = xfond + 3320;
	piece->y[9] = 100;
	
	piece->x[10] = xfond + 3420;
	piece->y[10] = 100;
	
	piece->x[11] = xfond + 3750;
	piece->y[11] = 180;
	
	piece->x[12] = xfond + 3850;
	piece->y[12] = 180;
	
	piece->x[13] = xfond + 3950;
	piece->y[13] = 180;
	
	piece->x[14] = xfond + 4050;
	piece->y[14] = 180;
	
	piece->x[15] = xfond + 4150;
	piece->y[15] = 180;
	
	piece->x[16] = xfond + 4250;
	piece->y[16] = 180;
	
	piece->x[17] = xfond + 6200;
	piece->y[17] = 180;
	
	piece->x[18] = xfond + 6300;
	piece->y[18] = 180;
	
	piece->x[19] = xfond + 6400;
	piece->y[19] = 180;
	
	piece->x[20] = xfond + 6500;
	piece->y[20] = 180;
	
	piece->x[21] = xfond + 6600;
	piece->y[21] = 180;
	
	piece->x[22] = xfond + 6890;
	piece->y[22] = 280;
	
	piece->x[23] = xfond +7690;
	piece->y[23] = 320;
	
	piece->x[24] = xfond+7830;
	piece->y[24] = 230;
	
	piece->x[25] = xfond + 8020;
	piece->y[25] = 100;
	
	piece->x[26] = xfond + 8120;
	piece->y[26] = 100;
	
	piece->x[27] = xfond + 8220;
	piece->y[27] = 100;
	
	piece->x[28] = xfond + 8550;
	piece->y[28] = 180;
	
	piece->x[29] = xfond + 8650;
	piece->y[29] = 180;
	
	piece->x[30] = xfond + 8750;
	piece->y[30] = 180;
	
	piece->x[31] = xfond + 8850;
	piece->y[31] = 180;
	
	piece->x[32] = xfond + 8950;
	piece->y[32] = 180;
	
	piece->x[33] = xfond + 4050;
	piece->y[33] = 180;
 
}

int collision_piece(int x,int y,int *test,Coins piece,int nbr_p)
{int pos = 666,i;
 for(i=0;i<nbr_p;i++)
 { if(370>= piece.x[i] && 340<=piece.x[i]+45 && y+20>=piece.y[i] && y+20<=piece.y[i]+45)
   {(*test)=1;
    pos = i;
   }

 }
 return pos;
 
}

void init_serpent(Serpent *serpent)
{ serpent->img[0] = load_bitmap("./Stage4/position_serpent/serpent1_ps.bmp",NULL);
  serpent->img[1] = load_bitmap("./Stage4/position_serpent/serpent2_ps.bmp",NULL);
  serpent->img[2] = load_bitmap("./Stage4/position_serpent/serpent3_ps.bmp",NULL);
  serpent->img[3] = load_bitmap("./Stage4/position_serpent/serpent4_ps.bmp",NULL);
  serpent->img[4] = load_bitmap("./Stage4/position_serpent/serpent5_ps.bmp",NULL);
  
  
  serpent->x[0] = 2550;
  serpent->y[0] = 400;
  
  serpent->x[1] = 4000;
  serpent->y[1] = 400;
}

void update_serpent(Serpent *serpent,int step)
{int i;
 for(i=0;i<nbr_serpent;i++)
 { serpent->x[i] += step;
 }
}

void destroy_serpent(Serpent *serpent)
{int i;
 for(i=0;i<6;i++)
 {destroy_bitmap(serpent->img[i]);}
}

void init_reine(Reine *reine)
{ reine->img[0]=  load_bitmap("./Stage4/Serpent/serpent_1_140_gimp.bmp",NULL);
  reine->img[1] = load_bitmap("./Stage4/Serpent/serpent_2_130_gimp.bmp",NULL);
  reine->img[2] = load_bitmap("./Stage4/Serpent/serpent_3_130_gimp.bmp",NULL);
  
  reine->x[0] = 5000;
  reine->y[0] = 385;
  
  reine->x[1] = 6500;
  reine->y[1] = 385;
  
  reine->x[2] = 7500;
  reine->y[2] = 385;
  
}

void update_reine(Reine *reine,int step)
{ int i;

  for(i=0;i<nbr_reine;i++)
  { reine->x[i]+=step;
  }
}
int collision_serpent(Serpent serpent,Froggy frog)
{int i,test = 0;
 for(i=0;i<nbr_serpent;i++)
 {if(serpent.x[i]<330 && serpent.x[i]>250 && frog.y == 387)
  {test = 1;}
 }
 return test;
}

int collision_reine(Reine reine, Froggy frog)
{ int i;
int test = 0;
for(i=0;i<nbr_reine;i++)
  {if(reine.x[i]<330 && reine.x[i]>250 && frog.y==387)
  {test = 1;}
  
  }
return test;
}

void destroy_reine(Reine *reine)
{ int i;
  for(i=0;i<nbr_reine;i++)
  {destroy_bitmap(reine->img[i]);
  }
}

void fonction_stage4(int *direction,int *key_pressed,int *frame_counter,int *serpent_counter,int *reine_counter,
int *saut_horizontal,int *test_chute,int *top,int *saut_vertical,int *nbr_p,int *score4,int *vie4,
int *compteur_collision_reine,int *bloquer_collision_reine,Background *fond,Froggy *frog,Calque *calque,
Coins *piece,Serpent *serpent,Reine *reine,Pause pause,BITMAP *Cursor,int *stage_termine,int *win_stage,int *bloquer_animation)
{int posx_blanc = 0;//
int test_blanc =0;//
int posx_bleu = 0;//
int test_bleu = 0;//
int i;//
int test_piece=0;//
int pos;//
int test_reine = 0;//
int test_serpent = 0;//
int pause_bouton;//

if(key[KEY_RIGHT] && *key_pressed == 0 && (fond->x)>= -8600)
  {*key_pressed = 1;
   *direction = 0;
  }
  else if(key[KEY_SPACE] && *key_pressed == 0 )
  {*key_pressed = 5;
  }
  else if(key[KEY_LEFT] && *key_pressed == 0 && (fond->x)<= -100)
  {*key_pressed = 2;
   *direction = 1;
  }
  else if(key[KEY_UP] && *key_pressed == 0)
  { *key_pressed = 4;
  }
  else if(key[KEY_P] && *key_pressed == 0)
  { *key_pressed=11;
    *bloquer_animation = 1;
  }
  
  blit(fond->img,Buffer,0,0,fond->x,fond->y,fond->img->w,fond->img->h);

//draw_sprite(Buffer,reine.img[0],reine.x[0],reine.y[0]);

pos = collision_piece(calque->x,frog->y,&test_piece,*piece,*nbr_p);
if(test_piece==1)
{supprimer_piece(pos,piece,nbr_p);
 (*score4)++;
 
 test_piece = 0;
}
test_reine=collision_reine(*reine,*frog);
if(test_reine==1 && *vie4>0 && *bloquer_collision_reine == 0)
{ (*vie4)--;
  *bloquer_collision_reine = 1;
  
}

test_serpent = collision_serpent(*serpent,*frog);
if(test_serpent == 1 && *vie4>0 && *bloquer_collision_reine == 0)
{(*vie4)--;
  *bloquer_collision_reine = 1;
}

if(*vie4==0)
{ *test_chute = 1;
  *key_pressed = 666;
}


if(*compteur_collision_reine <2000 && *bloquer_animation == 0)
{ (*compteur_collision_reine)++;

 if(*compteur_collision_reine==2000)
 {*compteur_collision_reine=0;
  *bloquer_collision_reine=0;
 }
}





for(i=0;i<(*nbr_p);i++)
{//update_pos_coins(&piece,fond.x);
draw_sprite(Buffer,piece->img,piece->x[i],piece->y[i]);
}

if((*frame_counter) < 60 && (*key_pressed) == 1) 
{
  //fond.x--;
  (*frame_counter)++;
  draw_sprite(Buffer, frog->img[0], frog->x, frog->y);
}

else if(*frame_counter >= 60 && *frame_counter<120 && *key_pressed ==1) 
{
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*frame_counter)++;
  draw_sprite(Buffer, frog->img[1], frog->x, frog->y);
}
else if(*frame_counter >= 120 && *frame_counter<180 && *key_pressed==1) 
{
  //fond.x--;
  (*frame_counter)++;
  draw_sprite(Buffer, frog->img[2], frog->x, frog->y);
}
else if(*frame_counter >= 180 && *frame_counter<240 && *key_pressed ==1) 
{
 fond->x--;
 update_serpent(serpent,-1);
 update_pos_coins(piece,*nbr_p,-1);
 update_reine(reine,-1);
 calque->x++;
 (*frame_counter)++;
  draw_sprite(Buffer, frog->img[3], frog->x, frog->y);
}
else if(*frame_counter >= 240 && *frame_counter<300 && *key_pressed == 1) 
{
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*frame_counter)++;
  draw_sprite(Buffer, frog->img[4], frog->x, frog->y);
}
else if(*frame_counter >= 300 && *frame_counter<360 && *key_pressed ==1) 
{
  //fond.x--;
  //calque.x++;
  (*frame_counter)++;
  draw_sprite(Buffer, frog->img[5], frog->x, frog->y);
}
else if(*frame_counter >=360  && *key_pressed == 1) 
{ posx_blanc=calque->x;
  test_blanc = collision_blanc(*calque,posx_blanc,frog->y);
  if(test_blanc == 1)
  { 
  *key_pressed = 666;
  *test_chute = 1;
  }
  else if(test_blanc == 2)
  { *key_pressed = 0;
    *frame_counter = 0;
    draw_sprite(Buffer, frog->img[0], frog->x, frog->y);
    
  }
  else
  { frog->y++;
  (*frame_counter)++;
    draw_sprite(Buffer, frog->img[5], frog->x, frog->y);
  }
  
}

//

if(*frame_counter < 60 && *key_pressed == 2) 
{
  //fond.x--;
  (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[0], frog->x, frog->y);
}

else if(*frame_counter >= 60 && *frame_counter<120 && *key_pressed ==2) 
{
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
  (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[1], frog->x, frog->y);
}
else if(*frame_counter >= 120 && *frame_counter<180 && *key_pressed==2) 
{
  //fond.x--;
  (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[2], frog->x, frog->y);
}
else if(*frame_counter >= 180 && *frame_counter<240 && *key_pressed ==2) 
{
 fond->x++;
 update_serpent(serpent,1);
 update_pos_coins(piece,*nbr_p,1);
 update_reine(reine,1);
 calque->x--;
 (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[3], frog->x, frog->y);
}
else if(*frame_counter >= 240 && *frame_counter<300 && *key_pressed == 2) 
{
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
  (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[4], frog->x, frog->y);
}
else if(*frame_counter >= 300 && *frame_counter<360 && *key_pressed ==2) 
{
  //fond.x--;
  //calque.x++;
  (*frame_counter)++;
  draw_sprite_h_flip(Buffer, frog->img[5], frog->x, frog->y);
}
else if(*frame_counter >=360  && *key_pressed == 2) 
{ posx_blanc=calque->x;
  test_blanc = collision_blanc(*calque,posx_blanc,frog->y);
  if(test_blanc == 1)
  { 
  *key_pressed = 666;
  *test_chute = 1;
  }
  else if(test_blanc == 2)
  { *key_pressed = 0;
    *frame_counter = 0;
    draw_sprite_h_flip(Buffer, frog->img[0], frog->x, frog->y);
    
  }
  else
  { frog->y++;
  (*frame_counter)++;
    draw_sprite_h_flip(Buffer, frog->img[5], frog->x, frog->y);
  }
  
}

if(*key_pressed == 4 && *saut_vertical<150 && *top==0)
{
	(*saut_vertical)++;
	frog->y--;
	if(*direction ==0)	
	{draw_sprite(Buffer,frog->img[5],frog->x,frog->y);}
	else
	{draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);}
}
else if(*key_pressed == 4 && *saut_vertical == 150 && *top==0)
{ *top=1;
if(*direction == 0)
{draw_sprite(Buffer,frog->img[5],frog->x,frog->y);}
else
{draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);}

}
else if(*key_pressed ==4 && *top ==1 && getpixel(calque->img,calque->x+45,frog->y+88)!=65535)
{ //saut_vertical--;
  
  if(*direction==0)
  {draw_sprite(Buffer,frog->img[5],frog->x,frog->y);}
  else
  {draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);}
  frog->y++;
}
else if(*key_pressed ==4 && *top==1 && getpixel(calque->img,calque->x+45,frog->y+88)==65535)
{*top=0;
 *key_pressed=0;
 *saut_vertical = 0;
 if(*direction == 0)
 {draw_sprite(Buffer,frog->img[0],frog->x,frog->y);}
 else
 {draw_sprite_h_flip(Buffer,frog->img[0],frog->x,frog->y);}
}

if (*serpent_counter < 200)
{ 
  draw_sprite(Buffer,serpent->img[0],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[0],serpent->x[1],serpent->y[1]);

if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
}

else if(*serpent_counter>=200 && *serpent_counter <400)
{ 
  draw_sprite(Buffer,serpent->img[1],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[1],serpent->x[1],serpent->y[1]);
  if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
}

else if(*serpent_counter>=400 && *serpent_counter <600)
{ 
  draw_sprite(Buffer,serpent->img[2],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[2],serpent->x[1],serpent->y[1]);
  
  if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
}

else if(*serpent_counter>=600 && *serpent_counter <800)
{ 
  draw_sprite(Buffer,serpent->img[1],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[1],serpent->x[1],serpent->y[1]);
  if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
}

else if(*serpent_counter>=800 && *serpent_counter <1000)
{ 
  draw_sprite(Buffer,serpent->img[0],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[0],serpent->x[1],serpent->y[1]);
  if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
}

else if(*serpent_counter>=1000 && *serpent_counter <1200)
{ 
  draw_sprite(Buffer,serpent->img[4],serpent->x[0],serpent->y[0]);
  draw_sprite(Buffer,serpent->img[4],serpent->x[1],serpent->y[1]);
  if(*bloquer_animation == 0)  
{(*serpent_counter)++;}
  if(*serpent_counter == 1200)
{ *serpent_counter = 0;
}
}


if(*reine_counter < 200)
{ draw_sprite(Buffer,reine->img[0],reine->x[0],reine->y[0]);
  draw_sprite(Buffer,reine->img[0],reine->x[1],reine->y[1]);
  draw_sprite(Buffer,reine->img[0],reine->x[2],reine->y[2]);
  //reine.x[0]--;
  if(*bloquer_animation==0)
  {(*reine_counter)++;}
}
else if(*reine_counter >= 200 && *reine_counter < 400)
{ draw_sprite(Buffer,reine->img[1],reine->x[0],reine->y[0]);
  draw_sprite(Buffer,reine->img[1],reine->x[1],reine->y[1]);
  draw_sprite(Buffer,reine->img[1],reine->x[2],reine->y[2]);
  if(*bloquer_animation==0)
  {reine->x[0]--;
  reine->x[1]--;
  reine->x[2]--;
  (*reine_counter)++;
  }
}
else if(*reine_counter >= 400 && *reine_counter < 600)
{ draw_sprite(Buffer,reine->img[2],reine->x[0],reine->y[0]);
  draw_sprite(Buffer,reine->img[2],reine->x[1],reine->y[1]);
  draw_sprite(Buffer,reine->img[2],reine->x[2],reine->y[2]);
  //reine.x[0]--;
  if(*bloquer_animation==0)
  {(*reine_counter)++;}
}
else if(*reine_counter >= 600 && *reine_counter < 800)
{ draw_sprite_h_flip(Buffer,reine->img[2],reine->x[0],reine->y[0]);
  draw_sprite_h_flip(Buffer,reine->img[2],reine->x[1],reine->y[1]);
  draw_sprite_h_flip(Buffer,reine->img[2],reine->x[2],reine->y[2]);
  //reine.x[0]++;
  if(*bloquer_animation==0)
  {(*reine_counter)++;}
}
else if(*reine_counter >= 800 && *reine_counter < 1000)
{ draw_sprite_h_flip(Buffer,reine->img[1],reine->x[0],reine->y[0]);
  draw_sprite_h_flip(Buffer,reine->img[1],reine->x[1],reine->y[1]);
  draw_sprite_h_flip(Buffer,reine->img[1],reine->x[2],reine->y[2]);
  if(*bloquer_animation==0)
  {reine->x[0]++;
  reine->x[1]++;
  reine->x[2]++;
  (*reine_counter)++;
  }
}
else if(*reine_counter >= 1000 && *reine_counter < 1200)
{ draw_sprite_h_flip(Buffer,reine->img[0],reine->x[0],reine->y[0]);
  draw_sprite_h_flip(Buffer,reine->img[0],reine->x[1],reine->y[1]);
  draw_sprite_h_flip(Buffer,reine->img[0],reine->x[2],reine->y[2]);
  //reine.x[0]++;
  if(*bloquer_animation==0)
  {(*reine_counter)++;}
 
 
  if(*reine_counter == 1200)
  {*reine_counter=0;}
}









if(*key_pressed == 5 && *saut_horizontal<40 && *direction == 0)
{
  frog->y--;
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*saut_horizontal)++;
  draw_sprite(Buffer,frog->img[1],frog->x,frog->y);
}
else if(*key_pressed == 5 && *saut_horizontal>=40 && *saut_horizontal<80 && *direction == 0)
{ frog->y--;
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*saut_horizontal)++;
  draw_sprite(Buffer,frog->img[2],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=80 && *saut_horizontal<120 && *direction == 0)
{ frog->y--;
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*saut_horizontal)++;
  draw_sprite(Buffer,frog->img[3],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=120 && *saut_horizontal<160 && *direction == 0)
{ 
  fond->x--;
  update_serpent(serpent,-1);
  update_pos_coins(piece,*nbr_p,-1);
  update_reine(reine,-1);
  calque->x++;
  (*saut_horizontal)++;
  draw_sprite(Buffer,frog->img[4],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=160  && *direction == 0)
{ 
  posx_bleu = calque->x;
  test_bleu = collision_bleu(*calque,posx_bleu,frog->y);
	if(test_bleu == 2 && *key_pressed == 5 && *direction == 0)
	{ 	draw_sprite(Buffer,frog->img[0],frog->x,frog->y);
	    *saut_horizontal = 0;
		*key_pressed = 0;
	}
	else if (test_bleu == 1 && *key_pressed == 5 && *direction == 0)
	{   
		*key_pressed = 666;
		*saut_horizontal = 0;
		//chute(test_bleu,&frog,direction);
		*test_chute = 1;
	}
	else
	{	frog->y++;
		fond->x--;
		update_serpent(serpent,-1);
		update_pos_coins(piece,*nbr_p,-1);
		update_reine(reine,-1);
		calque->x++;
		(*saut_horizontal)++;
		draw_sprite(Buffer,frog->img[5],frog->x,frog->y);
	}
  
}

////

if(*key_pressed == 5 && *saut_horizontal<40 && *direction == 1)
{
  frog->y--;
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
  (*saut_horizontal)++;
  draw_sprite_h_flip(Buffer,frog->img[1],frog->x,frog->y);
}
else if(*key_pressed == 5 && *saut_horizontal>=40 && *saut_horizontal<80 && *direction == 1)
{ frog->y--;
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
  (*saut_horizontal)++;
  draw_sprite_h_flip(Buffer,frog->img[2],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=80 && *saut_horizontal<120 && *direction == 1)
{ frog->y--;
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
 (*saut_horizontal)++;
  draw_sprite_h_flip(Buffer,frog->img[3],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=120 && *saut_horizontal<160 && *direction == 1)
{ 
  fond->x++;
  update_serpent(serpent,1);
  update_pos_coins(piece,*nbr_p,1);
  update_reine(reine,1);
  calque->x--;
  (*saut_horizontal)++;
  draw_sprite_h_flip(Buffer,frog->img[4],frog->x,frog->y);
  
}
else if(*key_pressed == 5 && *saut_horizontal>=160  && *direction == 1)
{ 
  posx_bleu = calque->x;
  test_bleu = collision_bleu(*calque,posx_bleu,frog->y);
	if(test_bleu == 2 && *key_pressed == 5 && *direction == 1)
	{ 	draw_sprite_h_flip(Buffer,frog->img[0],frog->x,frog->y);
	    *saut_horizontal = 0;
		*key_pressed = 0;
	}
	else if (test_bleu == 1 && *key_pressed == 5 && *direction == 1)
	{   
		*key_pressed = 666;
		*saut_horizontal = 0;
		//chute(test_bleu,&frog,direction);
		*test_chute = 1;
	}
	else
	{	frog->y++;
		fond->x++;
		update_serpent(serpent,1);
		update_pos_coins(piece,*nbr_p,1);
		update_reine(reine,1);
		calque->x--;
		(*saut_horizontal)++;
		draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);
	}
  
}

if(*key_pressed==11)
{ 
  pause_bouton = pause_curseur();
  draw_sprite(Buffer,pause.img[pause_bouton],pause.x,pause.y);
  draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
  
  if(pause_bouton==1 && mouse_b & 1)
  { *key_pressed = 0;
    *bloquer_animation = 0;
  }
  else if(pause_bouton==2 && mouse_b & 1)
  { *stage_termine = 1;
  }
  
  //textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Mouse.x: %d Mouse.y: %d",mouse_x,mouse_y);
}
if(getpixel(calque->img,calque->x+40,frog->y+55)==16750088 && *key_pressed==0 && *score4>=10)
{ *win_stage=1;
  *key_pressed= 44;
 
}


  
if((*key_pressed == 0 || *key_pressed == 44) && *direction == 0)
{draw_sprite(Buffer,frog->img[0],frog->x,frog->y);}
else if((*key_pressed == 0 || *key_pressed==44) && *direction == 1)
{draw_sprite_h_flip(Buffer,frog->img[0],frog->x,frog->y);}

//textprintf_centre_ex(Buffer, font, 400, 100,makecol(0, 100, 243), -1,"reine: %d   frog.x: %d fond.x: %d calque.x: %d",reine->x[1],frog->x,fond->x,calque->x);

}
