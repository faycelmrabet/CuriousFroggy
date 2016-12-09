/**
 * \file stage1_2.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/


#include "stage1_2.h"
extern BITMAP *Buffer;


void init_fond12(Background *fond)
{fond->x=0;
 fond->y=0;
 fond->img = load_bitmap("./Stage1_2/fonds/stage1_2.bmp",NULL);
 
}

void init_frog12(Froggy *frog)
{
frog->img[0]=load_bitmap("./Stage1_2/frames/1_bmp_110.bmp",NULL);
frog->img[1]=load_bitmap("./Stage1_2/frames/2_bmp_110.bmp",NULL);
frog->img[2]=load_bitmap("./Stage1_2/frames/3_bmp_110.bmp",NULL);
frog->img[3]=load_bitmap("./Stage1_2/frames/4_bmp_110.bmp",NULL);
frog->img[4]=load_bitmap("./Stage1_2/frames/5_bmp_110.bmp",NULL);
frog->img[5]=load_bitmap("./Stage1_2/frames/6_bmp_110.bmp",NULL);
frog->img[6]=load_bitmap("./Stage1_2/frames/1_bmp_110.bmp",NULL);
frog->x=300;
frog->y=435;
	
}



void init_calque12(Calque *calque,Froggy frog)
{calque->img = load_bitmap("./Stage1_2/fonds/calque1_2_orange.bmp",NULL);
 calque->x = frog.x;
}

int collision_blanc12(Calque calque,int posx_blanc,int y)
{ 
  if( getpixel(calque.img,posx_blanc+40,y+113) == 16777215)
 {return 1;
 }
 else if(getpixel(calque.img,posx_blanc+80,y+113) == 16777215)
 {return 1;
 }
 else if(getpixel(calque.img,posx_blanc+40,y+106) == 65535)
 { return 2;
 }
 else
 {return 0;
 }
}

void chute12(int test,Froggy *frog,int direction)
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

int collision_bleu12(Calque calque,int posx_bleu,int y)
{ if(getpixel(calque.img,posx_bleu+55,y+108)== 65535 /*&& getpixel(calque.img,posx_bleu+100,y+108)== 65535*/)
   {return 2;}
  else if(getpixel(calque.img,posx_bleu+55,y+108) == 16777215)
  {return 1;}
  else
  {return 0;}
}

void init_coins12(Coins *piece)
{ piece->img = load_bitmap("./Stage1_2/fonds/piece_froggy_petite_gimp_photoshop_16.bmp",NULL);
  piece->x[0] = 1600;
  piece->y[0] = 400;
  
  piece->x[1] = 1650;
  piece->y[1] = 350;
  
  piece->x[2] = 1700;
  piece->y[2] = 400;
  
  piece->x[3] = 2800;
  piece->y[3] = 400;
  
  piece->x[4] = 3000;
  piece->y[4] = 400;
  
  piece->x[5] = 3200;
  piece->y[5] = 400;
  
  piece->x[6] = 5000;
  piece->y[6] = 400;
  
  piece->x[7] = 5100;
  piece->y[7] = 380;
  
  piece->x[8] = 5200;
  piece->y[8] = 400;
  piece->x[9] = 6500;
  piece->y[9] = 410;
  piece->x[10] = 6600;
  piece->y[10] = 400;
 piece->x[11] = 6700;
  piece->y[11] = 400;
  
}

int collision_piece12(int x,int y,int *test,Coins piece,int nbr_p)//?
{int pos = 666,i;
 for(i=0;i<nbr_p;i++)
 { if(370>= piece.x[i] && 340<=piece.x[i] && y+30>=piece.y[i] && y+30<=piece.y[i]+45)
   {(*test)=1;
    pos = i;
   }

 }
 return pos;
 
}

void init_voiture(Voiture *voiture)
{    voiture->img[0] = load_bitmap("./Stage1_2/Voiture/voiture_0.bmp",NULL);
     voiture->img[1] = load_bitmap("./Stage1_2/Voiture/voiture_1.bmp",NULL);
     voiture->img[2] = load_bitmap("./Stage1_2/Voiture/voiture_2.bmp",NULL);
     voiture->img[3] = load_bitmap("./Stage1_2/Voiture/voiture_3.bmp",NULL);
     voiture->img[4] = load_bitmap("./Stage1_2/Voiture/voiture_4_mo.bmp",NULL);
     
     
     voiture->pos = 0;
     
     voiture->x[0][0] = 1170;
     voiture->y[0][0] = 310;
     voiture->x[0][1] = 1150;
     voiture->y[0][1] = 310;
     voiture->x[0][2] = 1130;
     voiture->y[0][2] = 310;
     voiture->x[0][3] = 1080;
     voiture->y[0][3] = 310;
     voiture->x[0][4] = 1000;
     voiture->y[0][4] = 310;
     
     
     voiture->x[1][0] = 3570;
     voiture->y[1][0] = 310;
     voiture->x[1][1] = 3550;
     voiture->y[1][1] = 310;
     voiture->x[1][2] = 3530;
     voiture->y[1][2] = 310;
     voiture->x[1][3] = 3480;
     voiture->y[1][3] = 310;
     voiture->x[1][4] = 3400;
     voiture->y[1][4] = 310;
     
     voiture->x[2][0] = 5970;
     voiture->y[2][0] = 310;
     voiture->x[2][1] = 5950;
     voiture->y[2][1] = 310;
     voiture->x[2][2] = 5930;
     voiture->y[2][2] = 310;
     voiture->x[2][3] = 5880;
     voiture->y[2][3] = 310;
     voiture->x[2][4] = 5800;
     voiture->y[2][4] = 310;
     
     voiture->x[3][0] = 8370;
     voiture->y[3][0] = 310;
     voiture->x[3][1] = 8350;
     voiture->y[3][1] = 310;
     voiture->x[3][2] = 8330;
     voiture->y[3][2] = 310;
     voiture->x[3][3] = 8280;
     voiture->y[3][3] = 310;
     voiture->x[3][4] = 8200;
     voiture->y[3][4] = 310;
     
}

void update_voiture(Voiture *voiture,int step)
{int i;
 int j;
 for(i=0;i<nbr_voiture;i++)
 {for(j=0;j<5;j++)
  {voiture->x[i][j]+=step;}
}
 
}

void destroy_voiture(Voiture *voiture)
{int i;
 for(i=0;i<5;i++)
 {destroy_bitmap(voiture->img[i]);}
}

void fonctions_stage1_2(int *direction12,int *key_pressed12,int *frame_counter12,int *test_chute12,int *saut_horizontal12,int *nbr_piece12,
int *score12,int *saut_vertical12,int *top12,int *car_counter,int *stage12_termine,int *win_stage12,int *bloquer_voiture,Background *fond12,Froggy *frog12,Calque *calque12,Coins *piece12,
Voiture *voiture,Pause pause,BITMAP *Cursor)
{  int test_blanc;//
    int posx_blanc;//
    int test_bleu;//
    int posx_bleu;//
    int i;//
    int test_piece=0; //
    int pos = 666;//
    int pause_bouton;//
	
	
	if(key[KEY_RIGHT] && *key_pressed12 == 0 && fond12->x>= -8600 && getpixel(calque12->img,calque12->x+290,frog12->y+55)!= 65535)
  {*key_pressed12 = 1;
   *direction12 = 0;
  }
  else if(key[KEY_SPACE] && *key_pressed12 == 0 && fond12->x>= -8600 && getpixel(calque12->img,calque12->x-284,frog12->y+55)!= 65535)
  {*key_pressed12 = 5;
  }
  else if(key[KEY_LEFT] && *key_pressed12 == 0 && fond12->x<= -100 && getpixel(calque12->img,calque12->x-180,frog12->y+55)!= 65535)
  {*key_pressed12 = 2;
   *direction12 = 1;
  }
  else if(key[KEY_UP] && *key_pressed12 == 0)
  { *key_pressed12 = 4;
  }
  else if(key[KEY_P] && *key_pressed12 == 0)
  { *key_pressed12 =11;
    *bloquer_voiture = 1;
  }
  
  blit(fond12->img,Buffer,0,0,fond12->x,fond12->y,fond12->img->w,fond12->img->h);
  //test
  
  
  
  pos = collision_piece12(calque12->x,frog12->y,&test_piece,*piece12,*nbr_piece12);
  if(test_piece==1)
  {supprimer_piece(pos,piece12,nbr_piece12);
   (*score12)++;
 
   test_piece = 0;
  }
  for(i=0;i<*nbr_piece12;i++)
{
draw_sprite(Buffer,piece12->img,piece12->x[i],piece12->y[i]);
}

if(*car_counter<500)
{ for(i=0;i<nbr_voiture;i++)
  {draw_sprite(Buffer,voiture->img[0],voiture->x[i][0],voiture->y[i][0]);}
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
  voiture->pos=0;
	
}
else if(*car_counter>=500 && *car_counter<1000)
{for(i=0;i<nbr_voiture;i++)
  {draw_sprite(Buffer,voiture->img[1],voiture->x[i][1],voiture->y[i][1]);}
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
}
else if(*car_counter>=1000 && *car_counter<1500)
{for(i=0;i<nbr_voiture;i++)
  {draw_sprite(Buffer,voiture->img[2],voiture->x[i][2],voiture->y[i][2]);}
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
}
else if(*car_counter>=1500 && *car_counter<2000)
{for(i=0;i<nbr_voiture;i++)
  {draw_sprite(Buffer,voiture->img[3],voiture->x[i][3],voiture->y[i][3]);}
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
  
}
else if(*car_counter>=2000 && *car_counter<2500)
{for(i=0;i<nbr_voiture;i++)
  {draw_sprite(Buffer,voiture->img[4],voiture->x[i][4],voiture->y[i][4]);}
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
  voiture->pos = 1;
}
else if(*car_counter>=2500 && *car_counter<3000)
{
  if(*bloquer_voiture==0)
  {(*car_counter)++;}
  voiture->pos = 0;
  if(*car_counter==3000)
  {*car_counter=0;}
}
  
  
  
  if(*frame_counter12 < 60 && *key_pressed12 == 1) 
{
  (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[0], frog12->x, frog12->y);
}

else if(*frame_counter12 >= 60 && *frame_counter12<120 && *key_pressed12 ==1) 
{
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  
  calque12->x++;
  (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[1], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 120 && *frame_counter12<180 && *key_pressed12==1) 
{
  
  (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[2], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 180 && *frame_counter12<240 && *key_pressed12 ==1) 
{
 fond12->x--;
 update_voiture(voiture,-1);
 update_pos_coins(piece12,*nbr_piece12,-1);
 calque12->x++;
 (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[3], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 240 && *frame_counter12<300 && *key_pressed12 == 1) 
{
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  calque12->x++;
  (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[4], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 300 && *frame_counter12<360 && *key_pressed12 ==1) 
{
  
  (*frame_counter12)++;
  draw_sprite(Buffer, frog12->img[5], frog12->x, frog12->y);
}
else if(*frame_counter12 >=360  && *key_pressed12 == 1) 
{ posx_blanc=calque12->x;
  test_blanc = collision_blanc12(*calque12,posx_blanc,frog12->y);
  /*if(test_blanc == 1)
  { 
  key_pressed12 = 666;
  test_chute12 = 1;
  }*/
  if(test_blanc == 2)
  { *key_pressed12 = 0;
    *frame_counter12 = 0;
    draw_sprite(Buffer, frog12->img[0], frog12->x, frog12->y);
    
  }
  else
  { frog12->y++;
  (*frame_counter12)++;
    draw_sprite(Buffer, frog12->img[5], frog12->x, frog12->y);
  }
  
}




//

if(*frame_counter12 < 60 && *key_pressed12 == 2) 
{
  
  (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[0], frog12->x, frog12->y);
}

else if(*frame_counter12 >= 60 && *frame_counter12<120 && *key_pressed12 ==2) 
{
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[1], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 120 && *frame_counter12<180 && *key_pressed12==2) 
{
  
  (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[2], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 180 && *frame_counter12<240 && *key_pressed12 ==2) 
{
 fond12->x++;
 update_voiture(voiture,1);
 update_pos_coins(piece12,*nbr_piece12,1);
 calque12->x--;
 (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[3], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 240 && *frame_counter12<300 && *key_pressed12 == 2) 
{
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[4], frog12->x, frog12->y);
}
else if(*frame_counter12 >= 300 && *frame_counter12<360 && *key_pressed12 ==2) 
{
  
  (*frame_counter12)++;
  draw_sprite_h_flip(Buffer, frog12->img[5], frog12->x, frog12->y);
}
else if(*frame_counter12 >=360  && *key_pressed12 == 2) 
{ posx_blanc=calque12->x;
  test_blanc = collision_blanc12(*calque12,posx_blanc,frog12->y);
  /*if(test_blanc == 1)
  { 
  key_pressed12 = 666;
  test_chute12 = 1;
  }*/
 if(test_blanc == 2)
  { *key_pressed12 = 0;
    *frame_counter12 = 0;
    draw_sprite_h_flip(Buffer, frog12->img[0], frog12->x, frog12->y);
    
  }
  else
  { frog12->y++;
  (*frame_counter12)++;
    draw_sprite_h_flip(Buffer, frog12->img[5], frog12->x, frog12->y);
  }
  
}

//#//#
if(*key_pressed12 == 4 && *saut_vertical12<150 && *top12==0)
{
	(*saut_vertical12)++;
	frog12->y--;
	if(*direction12 ==0)	
	{draw_sprite(Buffer,frog12->img[5],frog12->x,frog12->y);}
	else
	{draw_sprite_h_flip(Buffer,frog12->img[5],frog12->x,frog12->y);}
}
else if(*key_pressed12 == 4 && *saut_vertical12 == 150 && *top12==0)
{ *top12=1;
if(*direction12 == 0)
{draw_sprite(Buffer,frog12->img[5],frog12->x,frog12->y);}
else
{draw_sprite_h_flip(Buffer,frog12->img[5],frog12->x,frog12->y);}

}
else if(*key_pressed12 ==4 && *top12 ==1 && getpixel(calque12->img,calque12->x+45,frog12->y+88)!=65535)
{ //saut_vertical--;
  
  if(*direction12==0)
  {draw_sprite(Buffer,frog12->img[5],frog12->x,frog12->y);}
  else
  {draw_sprite_h_flip(Buffer,frog12->img[5],frog12->x,frog12->y);}
  frog12->y++;
}
else if(*key_pressed12 ==4 && *top12==1 && getpixel(calque12->img,calque12->x+45,frog12->y+88)==65535)
{*top12=0;
 *key_pressed12=0;
 *saut_vertical12 = 0;
 if(*direction12 == 0)
 {draw_sprite(Buffer,frog12->img[0],frog12->x,frog12->y);}
 else
 {draw_sprite_h_flip(Buffer,frog12->img[0],frog12->x,frog12->y);}
}


////
if(*key_pressed12 == 5 && *saut_horizontal12<40 && *direction12 == 0)
{
  frog12->y--;
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  calque12->x++;
  (*saut_horizontal12)++;
  draw_sprite(Buffer,frog12->img[1],frog12->x,frog12->y);
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=40 && *saut_horizontal12<80 && *direction12 == 0)
{ frog12->y--;
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  calque12->x++;
  (*saut_horizontal12)++;
  draw_sprite(Buffer,frog12->img[2],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=80 && *saut_horizontal12<120 && *direction12 == 0)
{ frog12->y--;
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  calque12->x++;
  (*saut_horizontal12)++;
  draw_sprite(Buffer,frog12->img[3],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=120 && *saut_horizontal12<160 && *direction12 == 0)
{ 
  fond12->x--;
  update_voiture(voiture,-1);
  update_pos_coins(piece12,*nbr_piece12,-1);
  calque12->x++;
  (*saut_horizontal12)++;
  draw_sprite(Buffer,frog12->img[4],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=160  && *direction12 == 0)
{ 
  posx_bleu = calque12->x;
  test_bleu = collision_bleu12(*calque12,posx_bleu,frog12->y);
	if(test_bleu == 2 && *key_pressed12 == 5 && *direction12 == 0)
	{ 	draw_sprite(Buffer,frog12->img[0],frog12->x,frog12->y);
	    *saut_horizontal12 = 0;
		*key_pressed12 = 0;
	}
	/*else if (test_bleu == 1 && key_pressed12 == 5 && direction12 == 0)
	{   
		key_pressed12 = 666;
		saut_horizontal12 = 0;
		test_chute12 = 1;
	}*/
	else
	{	frog12->y++;
		fond12->x--;
		update_voiture(voiture,-1);
		update_pos_coins(piece12,*nbr_piece12,-1);
		calque12->x++;
		(*saut_horizontal12)++;
		draw_sprite(Buffer,frog12->img[5],frog12->x,frog12->y);
	}
  
}
if(*key_pressed12 == 5 && *saut_horizontal12<40 && *direction12 == 1)
{
  frog12->y--;
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*saut_horizontal12)++;
  draw_sprite_h_flip(Buffer,frog12->img[1],frog12->x,frog12->y);
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=40 && *saut_horizontal12<80 && *direction12 == 1)
{ frog12->y--;
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*saut_horizontal12)++;
  draw_sprite_h_flip(Buffer,frog12->img[2],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=80 && *saut_horizontal12<120 && *direction12 == 1)
{ frog12->y--;
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*saut_horizontal12)++;
  draw_sprite_h_flip(Buffer,frog12->img[3],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=120 && *saut_horizontal12<160 && *direction12 == 1)
{ 
  fond12->x++;
  update_voiture(voiture,1);
  update_pos_coins(piece12,*nbr_piece12,1);
  calque12->x--;
  (*saut_horizontal12)++;
  draw_sprite_h_flip(Buffer,frog12->img[4],frog12->x,frog12->y);
  
}
else if(*key_pressed12 == 5 && *saut_horizontal12>=160  && *direction12 == 1)
{ 
  posx_bleu = calque12->x;
  test_bleu = collision_bleu12(*calque12,posx_bleu,frog12->y);
	if(test_bleu == 2 && *key_pressed12 == 5 && *direction12 == 1)
	{ 	draw_sprite_h_flip(Buffer,frog12->img[0],frog12->x,frog12->y);
	    *saut_horizontal12 = 0;
		*key_pressed12 = 0;
	}
	/*else if (test_bleu == 1 && key_pressed12 == 5 && direction12 == 1)
	{   
		key_pressed12 = 666;
		saut_horizontal12 = 0;
		//chute(test_bleu,&frog,direction);
		test_chute12 = 1;
	}*/
	else
	{	frog12->y++;
		fond12->x++;
		update_voiture(voiture,1);
		update_pos_coins(piece12,*nbr_piece12,1);
		calque12->x--;
		(*saut_horizontal12)++;
		draw_sprite_h_flip(Buffer,frog12->img[5],frog12->x,frog12->y);
	}
  
}

if(*key_pressed12==11)
{ 
  pause_bouton = pause_curseur();
  draw_sprite(Buffer,pause.img[pause_bouton],pause.x,pause.y);
  draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
  
  if(pause_bouton ==1 && mouse_b & 1)
  { *key_pressed12 = 0;
    *bloquer_voiture = 0;
  }
  else if(pause_bouton==2 && mouse_b & 1)
  { *stage12_termine = 1;
  }
  
  //textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Mouse.x: %d Mouse.y: %d",mouse_x,mouse_y);
}
if(getpixel(calque12->img,calque12->x+40,frog12->y+55)==16750088 && *key_pressed12==0 && *score12>=3)
{ *win_stage12=1;
  *key_pressed12=1212;
 
}


if(*key_pressed12==0 && voiture->pos==1 && getpixel(calque12->img,calque12->x+55,frog12->y+55)== 575248)
{*key_pressed12 =666;
 *test_chute12 = 1;
}






if(*test_chute12)
{chute12(*test_chute12,frog12,*direction12);
 //draw_sprite(Buffer,game_over.img,game_over.x,game_over.y);
}


if((*key_pressed12 == 0 || *key_pressed12 == 1212) && (*direction12 == 0))
{draw_sprite(Buffer,frog12->img[0],frog12->x,frog12->y);}
else if((*key_pressed12 == 0 || *key_pressed12 == 1212) && (*direction12 == 1))
{draw_sprite_h_flip(Buffer,frog12->img[0],frog12->x,frog12->y);}
//textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Couleur %d",getpixel(calque12->img,calque12->x+40,frog12->y+55));
//textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Calque.x %d",calque12.x);
}




