/**
 * \file stage1.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/

#include "stage1.h"
extern BITMAP *Buffer;



void init_fond11(Background *fond)
{fond->x=0;
 fond->y=0;
 fond->img = load_bitmap("./Stage1/fonds/stage1_1_test8.bmp",NULL);
 
}

void init_frog11(Froggy *frog)
{
frog->img[0]=load_bitmap("./Stage1/frames/1_bmp_110.bmp",NULL);
frog->img[1]=load_bitmap("./Stage1/frames/2_bmp_110.bmp",NULL);
frog->img[2]=load_bitmap("./Stage1/frames/3_bmp_110.bmp",NULL);
frog->img[3]=load_bitmap("./Stage1/frames/4_bmp_110.bmp",NULL);
frog->img[4]=load_bitmap("./Stage1/frames/5_bmp_110.bmp",NULL);
frog->img[5]=load_bitmap("./Stage1/frames/6_bmp_110.bmp",NULL);
frog->img[6]=load_bitmap("./Stage1/frames/1_bmp_110.bmp",NULL);
frog->x=300;
frog->y=435;
	
}

void init_rat(Rat *rat)
{rat->img[0] =load_bitmap("./Stage1/Rat/position11.bmp",NULL);
rat->img[1] = load_bitmap("./Stage1/Rat/position22.bmp",NULL);
rat->img[2] = load_bitmap("./Stage1/Rat/position33.bmp",NULL);

rat->x[0] = 2500;
rat->y[0] = 455;

rat->x[1] = 5300;
rat->y[1] = 455;

rat->x[2] = 6300;
rat->y[2] = 455;

rat->x[3] = 8200;
rat->y[3] = 455;


	
}

void update_rat(Rat *rat,int step)
{ int i;

  for(i=0;i<nbr_rat;i++)
  { rat->x[i]+=step;
  }
}

int collision_rat(Rat rat, Froggy frog)
{ int i;
  int test = 0;
for(i=0;i<nbr_rat;i++)
  {if(rat.x[i]<330 && rat.x[i]>250 && frog.y>425 && frog.y<455)
  {test = 1;}
  }
  return test;
}

void init_calque11(Calque *calque,Froggy frog)
{calque->img = load_bitmap("./Stage1/fonds/calque1_1_test8.bmp",NULL);
 calque->x = frog.x;
}

int collision_blanc11(Calque calque,int posx_blanc,int y)
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

void chute11(int test,Froggy *frog,int direction)
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

int collision_bleu11(Calque calque,int posx_bleu,int y)
{ if(getpixel(calque.img,posx_bleu+55,y+108)== 65535 /*&& getpixel(calque.img,posx_bleu+100,y+108)== 65535*/)
   {return 2;}
  else if(getpixel(calque.img,posx_bleu+55,y+108) == 16777215)
  {return 1;}
  else
  {return 0;}
}

void init_coins11(Coins *piece)
{ piece->img = load_bitmap("./Stage1/fonds/piece_froggy_petite_gimp_photoshop_16.bmp",NULL);
  piece->x[0] = 700;
  piece->y[0] = 300;
  
  piece->x[1] = 1200;
  piece->y[1] = 400;
  
  piece->x[2] =1400;
  piece->y[2] = 350;
  
  piece->x[3] = 1800;
  piece->y[3] = 350;
  
  piece->x[4] = 2800;
  piece->y[4] = 350;
  
  piece->x[5] = 3000;
  piece->y[5] = 250;
  
  piece->x[6] = 3600;
  piece->y[6] = 350;
  
  piece->x[7] = 4800;
  piece->y[7] = 350;
  
  piece->x[8] = 5000;
  piece->y[8] = 300;
  
  piece->x[9] =5190;
  piece->y[9] =210;
  
  piece->x[10] =5460;
  piece->y[10] =200;
  
  piece->x[11] = 5780;
  piece->y[11] = 199;
  
  piece->x[12] = 6500;
  piece->y[12] = 400; 
  
  piece->x[13] = 7800;
  piece->y[13] = 350;
  
  piece->x[14] = 8400;
  piece->y[14] = 360;
  
}

int collision_piece11(int x,int y,int *test,Coins piece,int nbr_p)//?
{int pos = 666,i;
 for(i=0;i<nbr_p;i++)
 { if(370>= piece.x[i] && 340<=piece.x[i] && y+30>=piece.y[i] && y+30<=piece.y[i]+45)
   {(*test)=1;
    pos = i;
   }

 }
 return pos;
 
}

void destroy_rat(Rat *rat)
{int i;
 for(i=0;i<3;i++)
 {destroy_bitmap(rat->img[i]);}
}

void aspiration(int test,Froggy *frog,int direction,int *aspiration_terminee)
{ 
 if (frog->y>300 && direction == 0 && test == 1)
 {frog->y--;
  draw_sprite(Buffer,frog->img[5],frog->x,frog->y);
  
 }
 else if (frog->y>300 && direction == 1 && test == 1)
 {frog->y--;
  draw_sprite_h_flip(Buffer,frog->img[5],frog->x,frog->y);
  
 }
 else if(frog->y==300 && test==1)
 { *aspiration_terminee = 1;
 }
}





void fonction_stage1(int *stage1_termine,int *direction11,int *key_pressed11,int *frame_counter11,int *test_chute11,int *saut_horizontal11,int *rat_counter,
int *vie11,int *bloquer_collision_rat,int *compteur_collision_rat,int *nbr_piece11,int *score11,int *test_aspiration,int *aspiration_terminee,Background *fond11,Froggy *frog11,
Calque *calque11,Rat *rat,Coins *piece11,Pause pause,BITMAP *Cursor,int *saut_vertical11,int *top11)
{int test_blanc;//
    int posx_blanc;//
    int test_bleu;//
    int posx_bleu;//
    int i;//
    int test_piece=0; //
    int pos = 666;//
    int bouton_curseur = 0;//
    
    
    if(key[KEY_RIGHT] && *key_pressed11 == 0 && fond11->x>= -8700)
  {*key_pressed11 = 1;
   *direction11 = 0;
  }
  else if(key[KEY_SPACE] && *key_pressed11 == 0 && fond11->x>=-8700)
  {*key_pressed11 = 5;
  }
  else if(key[KEY_LEFT] && *key_pressed11 == 0 && fond11->x<= -100)
  {*key_pressed11 = 2;
   *direction11 = 1;
  }
  else if(key[KEY_P] && *key_pressed11 == 0)
  { *key_pressed11=11;
  }
  else if(key[KEY_UP] && *key_pressed11 == 0)
  { *key_pressed11=4;
  }
  /*else if(key[KEY_P] && *key_pressed11 == 11)
  { *key_pressed11= 0;
  }*/
  
  blit(fond11->img,Buffer,0,0,fond11->x,fond11->y,fond11->img->w,fond11->img->h);
  
  pos = collision_piece11(calque11->x,frog11->y,&test_piece,*piece11,*nbr_piece11);
  if(test_piece==1)
  {supprimer_piece(pos,piece11,nbr_piece11);
   (*score11)++;
 
   test_piece = 0;
  }
  for(i=0;i<(*nbr_piece11);i++)
{
draw_sprite(Buffer,piece11->img,piece11->x[i],piece11->y[i]);
}
  
  
  if(*vie11>0 && collision_rat(*rat,*frog11) == 1 && *bloquer_collision_rat == 0)
  { (*vie11)--;
    *bloquer_collision_rat = 1;
  }
  if(*bloquer_collision_rat == 1 && *compteur_collision_rat<2000)
  {
	  (*compteur_collision_rat)++;
	  if(*compteur_collision_rat == 2000)
	  { *compteur_collision_rat = 0;
	    *bloquer_collision_rat = 0;
	  }
  }
  
  if(*rat_counter < 200)
{ draw_sprite(Buffer,rat->img[0],rat->x[0],rat->y[0]);
  draw_sprite(Buffer,rat->img[0],rat->x[1],rat->y[1]);
  draw_sprite(Buffer,rat->img[0],rat->x[2],rat->y[2]);
  draw_sprite(Buffer,rat->img[0],rat->x[3],rat->y[3]);
 
  (*rat_counter)++;
}
else if(*rat_counter >= 200 && *rat_counter < 400)
{ draw_sprite(Buffer,rat->img[1],rat->x[0],rat->y[0]);
  draw_sprite(Buffer,rat->img[1],rat->x[1],rat->y[1]);
  draw_sprite(Buffer,rat->img[1],rat->x[2],rat->y[2]);
  draw_sprite(Buffer,rat->img[1],rat->x[3],rat->y[3]);
 
  if((*rat_counter)%5 == 0)
  {for(i=0;i<nbr_rat;i++)
    {rat->x[i]--;}
  }
  (*rat_counter)++;
}
else if(*rat_counter >= 400 && *rat_counter < 601)
{ draw_sprite(Buffer,rat->img[2],rat->x[0],rat->y[0]);
  draw_sprite(Buffer,rat->img[2],rat->x[1],rat->y[1]);
  draw_sprite(Buffer,rat->img[2],rat->x[2],rat->y[2]);
  draw_sprite(Buffer,rat->img[2],rat->x[3],rat->y[3]);
 
  //reine.x[0]--;
  (*rat_counter)++;
}
else if(*rat_counter >= 601 && *rat_counter < 800)
{ draw_sprite_h_flip(Buffer,rat->img[2],rat->x[0],rat->y[0]);
  draw_sprite_h_flip(Buffer,rat->img[2],rat->x[1],rat->y[1]);
  draw_sprite_h_flip(Buffer,rat->img[2],rat->x[2],rat->y[2]);
  draw_sprite_h_flip(Buffer,rat->img[2],rat->x[3],rat->y[3]);
  //reine.x[0]++;
  (*rat_counter)++;
}
else if(*rat_counter >= 800 && *rat_counter < 1000)
{ draw_sprite_h_flip(Buffer,rat->img[1],rat->x[0],rat->y[0]);
  draw_sprite_h_flip(Buffer,rat->img[1],rat->x[1],rat->y[1]);
  draw_sprite_h_flip(Buffer,rat->img[1],rat->x[2],rat->y[2]);
  draw_sprite_h_flip(Buffer,rat->img[1],rat->x[3],rat->y[3]);
if((*rat_counter)%5 == 0)
  {for(i=0;i<nbr_rat;i++)
    {rat->x[i]++;}
  }
  (*rat_counter)++;
}
else if(*rat_counter >= 1000 && *rat_counter < 1201)
{ draw_sprite_h_flip(Buffer,rat->img[0],rat->x[0],rat->y[0]);
  draw_sprite_h_flip(Buffer,rat->img[0],rat->x[1],rat->y[1]);
  draw_sprite_h_flip(Buffer,rat->img[0],rat->x[2],rat->y[2]);
  draw_sprite_h_flip(Buffer,rat->img[0],rat->x[3],rat->y[3]);
  //reine.x[0]++;
  (*rat_counter)++;
  if(*rat_counter == 1201)
  {*rat_counter=0;}
}

  
  
  
  if(*frame_counter11 < 60 && *key_pressed11 == 1) 
{
  (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[0], frog11->x, frog11->y);
}

else if(*frame_counter11 >= 60 && *frame_counter11<120 && *key_pressed11 ==1) 
{
  fond11->x--;
  update_rat(rat,-1);
  
  update_pos_coins(piece11,*nbr_piece11,-1);
  
  calque11->x++;
  (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[1], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 120 && *frame_counter11<180 && *key_pressed11==1) 
{
  
  (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[2], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 180 && *frame_counter11<240 && *key_pressed11 ==1) 
{
 fond11->x--;
 update_rat(rat,-1);
 update_pos_coins(piece11,*nbr_piece11,-1);
 calque11->x++;
 (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[3], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 240 && *frame_counter11<300 && *key_pressed11 == 1) 
{
  fond11->x--;
  update_rat(rat,-1);
  update_pos_coins(piece11,*nbr_piece11,-1);
  calque11->x++;
  (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[4], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 300 && *frame_counter11<360 && *key_pressed11 ==1) 
{
  
  (*frame_counter11)++;
  draw_sprite(Buffer, frog11->img[5], frog11->x, frog11->y);
}
else if(*frame_counter11 >=360  && *key_pressed11 == 1) 
{ posx_blanc=calque11->x;
  test_blanc = collision_blanc11(*calque11,posx_blanc,frog11->y);
  if(test_blanc == 1)
  { 
  *key_pressed11 = 666;
  *test_chute11 = 1;
  }
  else if(test_blanc == 2)
  { *key_pressed11 = 0;
    *frame_counter11 = 0;
    draw_sprite(Buffer, frog11->img[0], frog11->x, frog11->y);
    
  }
  else
  { frog11->y++;
  (*frame_counter11)++;
    draw_sprite(Buffer, frog11->img[5], frog11->x, frog11->y);
  }
  
}




//

if(*frame_counter11 < 60 && *key_pressed11 == 2) 
{
  
  (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[0], frog11->x, frog11->y);
}

else if(*frame_counter11 >= 60 && *frame_counter11<120 && *key_pressed11 ==2) 
{
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[1], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 120 && *frame_counter11<180 && *key_pressed11==2) 
{
  
  (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[2], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 180 && *frame_counter11<240 && *key_pressed11 ==2) 
{
 fond11->x++;
 update_rat(rat,1);
 update_pos_coins(piece11,*nbr_piece11,1);
 calque11->x--;
 (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[3], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 240 && *frame_counter11<300 && *key_pressed11 == 2) 
{
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[4], frog11->x, frog11->y);
}
else if(*frame_counter11 >= 300 && *frame_counter11<360 && *key_pressed11 ==2) 
{
  
  (*frame_counter11)++;
  draw_sprite_h_flip(Buffer, frog11->img[5], frog11->x, frog11->y);
}
else if(*frame_counter11 >=360  && *key_pressed11 == 2) 
{ posx_blanc=calque11->x;
  test_blanc = collision_blanc11(*calque11,posx_blanc,frog11->y);
  if(test_blanc == 1)
  { 
  *key_pressed11 = 666;
  *test_chute11 = 1;
  }
  else if(test_blanc == 2)
  { *key_pressed11 = 0;
    *frame_counter11 = 0;
    draw_sprite_h_flip(Buffer, frog11->img[0], frog11->x, frog11->y);
    
  }
  else
  { frog11->y++;
  (*frame_counter11)++;
    draw_sprite_h_flip(Buffer, frog11->img[5], frog11->x, frog11->y);
  }
  
}
//

if(*key_pressed11 == 4 && *saut_vertical11<150 && *top11==0)
{
	(*saut_vertical11)++;
	frog11->y--;
	if(*direction11 ==0)	
	{draw_sprite(Buffer,frog11->img[5],frog11->x,frog11->y);}
	else
	{draw_sprite_h_flip(Buffer,frog11->img[5],frog11->x,frog11->y);}
}
else if(*key_pressed11 == 4 && *saut_vertical11 == 150 && *top11==0)
{ *top11=1;
if(*direction11 == 0)
{draw_sprite(Buffer,frog11->img[5],frog11->x,frog11->y);}
else
{draw_sprite_h_flip(Buffer,frog11->img[5],frog11->x,frog11->y);}

}
else if(*key_pressed11 ==4 && *top11 ==1 && getpixel(calque11->img,calque11->x+45,frog11->y+108)!=65535)
{ //saut_vertical--;
  
  if(*direction11==0)
  {draw_sprite(Buffer,frog11->img[5],frog11->x,frog11->y);}
  else
  {draw_sprite_h_flip(Buffer,frog11->img[5],frog11->x,frog11->y);}
  frog11->y++;
}
else if(*key_pressed11 ==4 && *top11==1 && getpixel(calque11->img,calque11->x+45,frog11->y+108)==65535)
{*top11=0;
 *key_pressed11=0;
 *saut_vertical11 = 0;
 if(*direction11 == 0)
 {draw_sprite(Buffer,frog11->img[0],frog11->x,frog11->y);}
 else
 {draw_sprite_h_flip(Buffer,frog11->img[0],frog11->x,frog11->y);}
}


////
if(*key_pressed11 == 5 && *saut_horizontal11<40 && *direction11 == 0)
{
  frog11->y--;
  fond11->x--;
  update_rat(rat,-1);
  update_pos_coins(piece11,*nbr_piece11,-1);
  calque11->x++;
  (*saut_horizontal11)++;
  draw_sprite(Buffer,frog11->img[1],frog11->x,frog11->y);
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=40 && *saut_horizontal11<80 && *direction11 == 0)
{ frog11->y--;
  fond11->x--;
  update_rat(rat,-1);
  update_pos_coins(piece11,*nbr_piece11,-1);
  calque11->x++;
  (*saut_horizontal11)++;
  draw_sprite(Buffer,frog11->img[2],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=80 && *saut_horizontal11<120 && *direction11 == 0)
{ frog11->y--;
  fond11->x--;
  update_rat(rat,-1);
  update_pos_coins(piece11,*nbr_piece11,-1);
  calque11->x++;
  (*saut_horizontal11)++;
  draw_sprite(Buffer,frog11->img[3],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=120 && *saut_horizontal11<160 && *direction11 == 0)
{ 
  fond11->x--;
  update_rat(rat,-1);
  update_pos_coins(piece11,*nbr_piece11,-1);
  calque11->x++;
  (*saut_horizontal11)++;
  draw_sprite(Buffer,frog11->img[4],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=160  && *direction11 == 0)
{ 
  posx_bleu = calque11->x;
  test_bleu = collision_bleu11(*calque11,posx_bleu,frog11->y);
	if(test_bleu == 2 && *key_pressed11 == 5 && *direction11 == 0)
	{ 	draw_sprite(Buffer,frog11->img[0],frog11->x,frog11->y);
	    *saut_horizontal11 = 0;
		*key_pressed11 = 0;
	}
	else if (test_bleu == 1 && *key_pressed11 == 5 && *direction11 == 0)
	{   
		*key_pressed11 = 666;
		*saut_horizontal11 = 0;
		*test_chute11 = 1;
	}
	else
	{	frog11->y++;
		fond11->x--;
		update_rat(rat,-1);
		update_pos_coins(piece11,*nbr_piece11,-1);
		calque11->x++;
		(*saut_horizontal11)++;
		draw_sprite(Buffer,frog11->img[5],frog11->x,frog11->y);
	}
  
}
if(*key_pressed11 == 5 && *saut_horizontal11<40 && *direction11 == 1)
{
  frog11->y--;
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*saut_horizontal11)++;
  draw_sprite_h_flip(Buffer,frog11->img[1],frog11->x,frog11->y);
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=40 && *saut_horizontal11<80 && *direction11 == 1)
{ frog11->y--;
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*saut_horizontal11)++;
  draw_sprite_h_flip(Buffer,frog11->img[2],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=80 && *saut_horizontal11<120 && *direction11 == 1)
{ frog11->y--;
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*saut_horizontal11)++;
  draw_sprite_h_flip(Buffer,frog11->img[3],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=120 && *saut_horizontal11<160 && *direction11 == 1)
{ 
  fond11->x++;
  update_rat(rat,1);
  update_pos_coins(piece11,*nbr_piece11,1);
  calque11->x--;
  (*saut_horizontal11)++;
  draw_sprite_h_flip(Buffer,frog11->img[4],frog11->x,frog11->y);
  
}
else if(*key_pressed11 == 5 && *saut_horizontal11>=160  && *direction11 == 1)
{ 
  posx_bleu = calque11->x;
  test_bleu = collision_bleu11(*calque11,posx_bleu,frog11->y);
	if(test_bleu == 2 && *key_pressed11 == 5 && *direction11 == 1)
	{ 	draw_sprite_h_flip(Buffer,frog11->img[0],frog11->x,frog11->y);
	    *saut_horizontal11 = 0;
		*key_pressed11 = 0;
	}
	else if (test_bleu == 1 && *key_pressed11 == 5 && *direction11 == 1)
	{   
		*key_pressed11 = 666;
		*saut_horizontal11 = 0;
		//chute(test_bleu,&frog,direction);
		*test_chute11 = 1;
	}
	else
	{	frog11->y++;
		fond11->x++;
		update_rat(rat,1);
		update_pos_coins(piece11,*nbr_piece11,1);
		calque11->x--;
		(*saut_horizontal11)++;
		draw_sprite_h_flip(Buffer,frog11->img[5],frog11->x,frog11->y);
	}
  
}

if(*key_pressed11==11)
{ 
  bouton_curseur = pause_curseur();
  draw_sprite(Buffer,pause.img[bouton_curseur],pause.x,pause.y);
  draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
  
  if(bouton_curseur==1 && mouse_b & 1)
  { *key_pressed11 = 0;
  }
  else if(bouton_curseur==2 && mouse_b & 1)
  { *stage1_termine = 1;
  }
  
  //textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Mouse.x: %d Mouse.y: %d",mouse_x,mouse_y);
}

if(getpixel(calque11->img,calque11->x,frog11->y+55)==16750088 && *key_pressed11==0 && *score11>=3)
{ *test_aspiration=1;
  *key_pressed11=666;
 /* if(*aspiration_terminee)
  {*stage1_termine = 1;}*/
}

if(*test_aspiration)
{aspiration(*test_aspiration,frog11,*direction11,aspiration_terminee);
}

if(*vie11 == 0)
{*test_chute11 = 1;
*key_pressed11=666;
}


if(*test_chute11)
{chute11(*test_chute11,frog11,*direction11);
 //draw_sprite(Buffer,game_over.img,game_over.x,game_over.y);
}


if(*key_pressed11 == 0 && *direction11 == 0)
{draw_sprite(Buffer,frog11->img[0],frog11->x,frog11->y);}
else if(*key_pressed11 == 0 && *direction11 == 1)
{draw_sprite_h_flip(Buffer,frog11->img[0],frog11->x,frog11->y);}

}



