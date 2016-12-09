#include <allegro.h>
#include "projet.h"
#include <stdio.h>
#define NB_IMAGE 8
#define NB_IMAGES 7


volatile long speed_counter=0;
void increment_speed_counter()
{
	speed_counter ++;
} 
END_OF_FUNCTION(increment_speed_counter);
void init_froggy(froggy *frog)
{
frog->img[0]=load_bitmap("1_bmp.bmp",NULL);
frog->img[1]=load_bitmap("2_bmp.bmp",NULL);
frog->img[2]=load_bitmap("3_bmp.bmp",NULL);
frog->img[3]=load_bitmap("4_bmp.bmp",NULL);
frog->img[4]=load_bitmap("5_bmp.bmp",NULL);
frog->img[5]=load_bitmap("6_bmp.bmp",NULL);
frog->img[6]=load_bitmap("7_bmp.bmp",NULL);
frog->x=0;
frog->y=325;
				
}
void init_rat(rats *rat)
{
rat->x=400;
rat->y=SCREEN_H -155;
rat->img[0]=load_bitmap("position11.bmp",NULL);	
rat->img[1]=load_bitmap("position22.bmp",NULL);
rat->img[2]=load_bitmap("position33.bmp",NULL);	
rat->img[3]=load_bitmap("position44.bmp",NULL);	
rat->img[4]=load_bitmap("position55.bmp",NULL);
rat->img[5]=load_bitmap("position66.bmp",NULL);			
}
void init_fond(fond_ecran *fond)
{  fond->x=-150;
 fond->y=-100;
 fond->img = load_bitmap("image1.bmp",NULL);
 
}
void destroy_frog(froggy *frog)
{ int i;
  for(i=0;i<7;i++)
  {destroy_bitmap(frog->img[i]);}
}
void destroy_rat(rats *rat)
{ int i;
  for(i=0;i<7;i++)
  {destroy_bitmap(rat->img[i]);}
}
int main()
{
	froggy frog;
	fond_ecran fond;
	rats rat;
	allegro_init();
	install_timer();
	if(install_keyboard()==-1)
	{
		allegro_message("Error! %s", allegro_error);
		return -1;
	}
	set_color_depth(32);
if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)
{
set_gfx_mode(GFX_TEXT,0,0,0,0);
allegro_message("Unable to initialize video mode! \n%s\n",allegro_error);
return 1;
}
if(frog.img[7] == NULL)
{      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); 
       allegro_message("Impossible de charger l'image de Froggy\n%s\n", allegro_error);
return 1;
}
   LOCK_VARIABLE(speed_counter);
   LOCK_FUNCTION(increment_speed_counter);
   install_int_ex(increment_speed_counter,BPS_TO_TIMER(60));
   int frame_counter=0;

   init_froggy(&frog);
   init_rat(&rat);	
   init_fond(&fond); 
   BITMAP *Buffer;
   Buffer=create_bitmap(640,480);
blit(fond.img,Buffer,0,0,fond.x,fond.y,fond.img->w,fond.img->h);
draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

while(!key[KEY_ESC])
	{   clear_bitmap(Buffer);
	   if(rat.x>=0)
				  {
					  rat.x --;
				  }
		while(speed_counter>0 && key[KEY_RIGHT]&1)
	    {  
			
		if(key[KEY_RIGHT] && frog.x <= SCREEN_W)
	              {
					  frog.x ++;
				  }		  
		
	else  if(key[KEY_LEFT] && frog.x>=0)
				  {
					  frog.x --;
				  }
				else if(key[KEY_UP] && frog.y>0)
				  {
					 frog.y --;
				  }
				else if(key[KEY_DOWN] && frog.y<=SCREEN_H -155)
				 {
					 frog.y ++;
    			 }  
	 
          speed_counter --;
          frame_counter ++;
      }     
      
   
      	  
     if(frame_counter > 540) 
{
  frame_counter = 0;
}

	  
	 blit(fond.img,Buffer,0,0,fond.x,fond.y,fond.img->w,fond.img->h);
 	
	  	        
	        
	  if(frame_counter<60)
	  {    
		draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
		draw_sprite(Buffer, rat.img[0],rat.x,rat.y); 
		  
	 }	 
	else if(frame_counter >= 60 && frame_counter<120) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[1], frog.x, frog.y);
  draw_sprite(Buffer, rat.img[1],rat.x,rat.y);
}
else if(frame_counter >= 120 && frame_counter<180) 
{
  //fond.x--;
  draw_sprite(Buffer, frog.img[2], frog.x, frog.y);
  draw_sprite(Buffer, rat.img[2], rat.x, rat.y);
}
else if(frame_counter >= 180 && frame_counter<240) 
{
 fond.x--;
  draw_sprite(Buffer, frog.img[3], frog.x, frog.y);
   draw_sprite(Buffer, rat.img[3], rat.x, rat.y);
}
else if(frame_counter >= 240 && frame_counter<300) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[4], frog.x, frog.y);
  draw_sprite(Buffer, rat.img[4], rat.x, rat.y);
}
else if(frame_counter >= 360 && frame_counter<420) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[5], frog.x, frog.y);
    draw_sprite(Buffer, rat.img[4], rat.x, rat.y);
}
else if(frame_counter >= 420 && frame_counter<480) 
{
  //fond.x--;
  draw_sprite(Buffer, frog.img[6], frog.x, frog.y);
  draw_sprite(Buffer, rat.img[1],rat.x,rat.y);  
}
else if (frame_counter>=480 && frame_counter<540)
{draw_sprite(Buffer, frog.img[7], frog.x, frog.y);
 draw_sprite(Buffer, rat.img[1],rat.x,rat.y);
}

  
    blit(Buffer,screen,0,0,0,0,640,480);


}
 
	 

         		  	   			
destroy_frog(&frog);
destroy_rat(&rat);
destroy_bitmap(fond.img);
destroy_bitmap(Buffer);
return 0;
}		 	          
END_OF_MAIN()
