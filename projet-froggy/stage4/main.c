#include <allegro.h>
#include "stage4.h"

volatile long speed_counter = 0; 

void increment_speed_counter() 
{
  speed_counter++; 
}
END_OF_FUNCTION(increment_speed_counter);

void init_frog(Froggy *frog)
{
frog->img[0]=load_bitmap("./frog_2d/1_bmp_2d.bmp",NULL);
frog->img[1]=load_bitmap("./frog_2d/2_bmp_2d.bmp",NULL);
frog->img[2]=load_bitmap("./frog_2d/3_bmp_2d.bmp",NULL);
frog->img[3]=load_bitmap("./frog_2d/4_bmp_2d.bmp",NULL);
frog->img[4]=load_bitmap("./frog_2d/5_bmp_2d.bmp",NULL);
frog->img[5]=load_bitmap("./frog_2d/6_bmp_2d.bmp",NULL);
frog->img[6]=load_bitmap("./frog_2d/7_bmp_2d.bmp",NULL);
frog->x=300;
frog->y=387;
	
}	

void init_background(Background *fond)
{fond->x=0;
 fond->y=0;
 fond->img = load_bitmap("9600_plate.bmp",NULL);
 
}


void destroy_frog(Froggy *frog)
{ int i;
  for(i=0;i<7;i++)
  {destroy_bitmap(frog->img[i]);}
}


int main() {
BITMAP *Buffer;
int continuer = 1;
//int compteur=0;
int key_pressed=0;
int key_pressed_left =0;
int direction = 0;
//int i=0;
Froggy frog;
Background fond;
allegro_init();
install_timer();

LOCK_VARIABLE(speed_counter);               
  LOCK_FUNCTION(increment_speed_counter); 
  install_int_ex(increment_speed_counter, BPS_TO_TIMER(60)); 
  
  
if (install_keyboard() == -1) {
allegro_message("Error! %s", allegro_error);
return -1;
}
 LOCK_VARIABLE(speed_counter);                 
  LOCK_FUNCTION(increment_speed_counter); 
  install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));
set_color_depth(32);
if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); 
allegro_message("Unable to initialize video mode!\n%s\n", allegro_error);
return 1;
}

init_background(&fond);
init_frog(&frog);
Buffer = create_bitmap(800, 600);
blit(fond.img,Buffer,0,0,fond.x,fond.y,fond.img->w,fond.img->h);
draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

int frame_counter = 0;

while(continuer)
{ 

	
	if(key[KEY_ESC])
	{continuer = 0;}
	
	//while(speed_counter > 0)
	if(key[KEY_RIGHT] && fond.x > -8800)
		{direction = 0;
		key_pressed =1;}
	else if(key[KEY_LEFT] && fond.x<0)
	    {key_pressed_left =1;
	     direction = 1;
	     }
	//}
	 speed_counter --;
	 frame_counter ++;
	 
	 if(frame_counter > 540) 
{
  frame_counter = 0;
}

blit(fond.img,Buffer,0,0,fond.x,fond.y,fond.img->w,fond.img->h);

if(frame_counter < 60 && key_pressed == 1) 
{
  //fond.x--;
  draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
}

else if(frame_counter >= 60 && frame_counter<120 && key_pressed ==1) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[1], frog.x, frog.y);
}
else if(frame_counter >= 120 && frame_counter<180 && key_pressed==1) 
{
  //fond.x--;
  draw_sprite(Buffer, frog.img[2], frog.x, frog.y);
}
else if(frame_counter >= 180 && frame_counter<240 && key_pressed ==1) 
{
 fond.x--;
  draw_sprite(Buffer, frog.img[3], frog.x, frog.y);
}
else if(frame_counter >= 240 && frame_counter<300 && key_pressed == 1) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[4], frog.x, frog.y);
}
else if(frame_counter >= 360 && frame_counter<420 && key_pressed ==1) 
{
  fond.x--;
  draw_sprite(Buffer, frog.img[5], frog.x, frog.y);
}
else if(frame_counter >= 420 && frame_counter<480 && key_pressed == 1) 
{
  //fond.x--;
  draw_sprite(Buffer, frog.img[6], frog.x, frog.y);
  
}

else if(key_pressed == 1 && frame_counter>=480 && frame_counter<540)
{draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
key_pressed = 0;
}


if(frame_counter < 60 && key_pressed_left == 1) 
{
  //fond.x--;
  draw_sprite_h_flip(Buffer, frog.img[0], frog.x, frog.y);
}

else if(frame_counter >= 60 && frame_counter<120 && key_pressed_left ==1) 
{
  fond.x++;
  draw_sprite_h_flip(Buffer, frog.img[1], frog.x, frog.y);
}
else if(frame_counter >= 120 && frame_counter<180 && key_pressed_left==1) 
{
  //fond.x--;
  draw_sprite_h_flip(Buffer, frog.img[2], frog.x, frog.y);
}
else if(frame_counter >= 180 && frame_counter<240 && key_pressed_left ==1) 
{
 fond.x++;
  draw_sprite_h_flip(Buffer, frog.img[3], frog.x, frog.y);
}
else if(frame_counter >= 240 && frame_counter<300 && key_pressed_left == 1) 
{
  fond.x++;
  draw_sprite_h_flip(Buffer, frog.img[4], frog.x, frog.y);
}
else if(frame_counter >= 360 && frame_counter<420 && key_pressed_left ==1) 
{
  fond.x++;
  draw_sprite_h_flip(Buffer, frog.img[5], frog.x, frog.y);
}
else if(frame_counter >= 420 && frame_counter<480 && key_pressed_left == 1) 
{
  //fond.x--;
  draw_sprite_h_flip(Buffer, frog.img[6], frog.x, frog.y);
  
}

else if(key_pressed_left == 1 && frame_counter>=480 && frame_counter<540)
{draw_sprite_h_flip(Buffer, frog.img[0], frog.x, frog.y);
key_pressed_left = 0;
}

else if(key_pressed == 0 && direction == 0)
{draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
}

if(key_pressed == 0 && direction == 0)
{draw_sprite(Buffer, frog.img[0], frog.x, frog.y);
}
else if(key_pressed_left == 0 && direction == 1)
{draw_sprite_h_flip(Buffer,frog.img[0],frog.x,frog.y);
}

blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	


//draw_sprite(Buffer,frog.img[0],frog.x,frog.y);

}

destroy_bitmap(fond.img);
destroy_frog(&frog);
destroy_bitmap(Buffer);

return 0;
}
END_OF_MAIN();
