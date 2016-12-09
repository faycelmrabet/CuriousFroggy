/**
 * \file main.c
 * \author Las Vegas
 * \date 22 Mai 2013
*/
#include <allegro.h>
#include <apeg.h>
#include "menu.h"
#include "commun.h"
#include "stage2.h"
#include "stage1.h"
#include "stage1_2.h"
#include "stage4.h"



extern BITMAP *Buffer;

int main() 
{
//Commun
BITMAP *Cursor;
int continuer = 1;

Background curious_froggy;
Chargement chargement;
int loading_counter = 0;

int page = -1;
int stage_deverouille;
stage_deverouille = loading();
Game game_over; ////
Game you_win;
Pause pause;
int etat_next = 0;
int turn_on_music = 666;

SAMPLE *music1; 
SAMPLE *music2;
SAMPLE *music3;
SAMPLE *music4;
SAMPLE *music_menu;

//MENU

bouton exit; 
bouton help; 
bouton play;
bouton son;
bouton son_coupe;
bouton prec;
icone_stage1 s1; 
icone_stage2 s2;
icone_stage3 s3;
icone_stage4 s4;


int bloquer_click = 0;
int click_counter = 0;
int sound_off = 0;
int b_play =0; int b_exit=0; int b_help=0; int b_son = 0;
int etat_s2;int etat_s3;int etat_s4;
conversion_stage_etat_s(stage_deverouille,&etat_s2,&etat_s3,&etat_s4);
int b_prec = 0;
int menu = 1;
Background fond_menu;
Background menu_help;
//Stage 1
    int direction11 = 0;
    int key_pressed11 = 0;
    int frame_counter11 = 0;
    int test_chute11 = 0;
    int test_aspiration = 0;
    int aspiration_terminee = 0;
    int saut_horizontal11 = 0;
    int rat_counter = 0;
    int vie11 = 6;
    int bloquer_collision_rat = 0;
    int compteur_collision_rat = 0;
    int nbr_piece11 = nbr_coins11;
    int score11 = 0;
    int stage1_termine = 0;
    int saut_vertical11=0;
    int top11=0;
    
    
    Background fond11;
	Froggy frog11;
	Calque calque11;
	Rat rat;
	Coins piece11;
	
	

//Stage 1_2

    int direction12 = 0;
    int key_pressed12 = 0;
    int frame_counter12 = 0;
    int test_chute12 = 0;
    int saut_horizontal12 = 0;
    //int vie12 = 6;
    int nbr_piece12 = nbr_coins12;
    int score12 = 0;
    int saut_vertical12 = 0;
    int top12 = 0;
    int car_counter = 0;
    int stage12_termine = 0;
    int vie12=6;
    int win_stage12 = 0;
    int bloquer_voiture = 0;
    
    Background fond12;
	Froggy frog12;
	Calque calque12;
	Coins piece12;
	Voiture voiture;

////


//Stage 2
Pigeon pigeon;
Background fond2;
Coins piece2;
Calque calque2;

int test2 = 0;
int nbr2 = np2;
int block_speed_counter = 1;
int stage2_termine = 0;
int key_pressed2 = 0;
int win_stage2 = 0;
int score2 = 0;





//

//Stage 4
int direction = 0;
int key_pressed = 0;
int frog_counter = 0;
int serpent_counter = 0;
int reine_counter = 0;
int saut_horizontal = 0;
int test_chute = 0;
int top = 0;
int saut_vertical = 0;
int nbr_p = nbr_piece;
int score4 = 0;
int vie4 = 6;
int compteur_collision_reine = 0;
int bloquer_collision_reine = 0;
int stage_termine = 0;
int win_stage = 0;
int bloquer_animation = 0;



Background fond;
Froggy frog;
Barre barre;////
Tete tete;////
Calque calque;
Coins piece;
Numero numero;////
Serpent serpent;
Reine reine;
//



////




allegro_init();
install_timer();
if (install_keyboard() == -1) {
allegro_message("Error! %s", allegro_error);
return -1;
}
if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL))
{
	allegro_message("Unable to initialize sound! %s",allegro_error);
	return -1;
}
if (install_mouse() == -1) {
allegro_message("Error while mouse initialization! %s", allegro_error);
return -1;
}
show_mouse(screen);
set_color_depth(32);
if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); 
allegro_message("Unable to initialize video mode!\n%s\n", allegro_error);
return 1;
}



clear_to_color(screen,makecol(0,0,0));
 apeg_play_mpg("./Loading/final.ogv",screen,FALSE,NULL);

Buffer = create_bitmap(800, 600);
music1 = load_wav("./Commun/Music/music1.wav");
music2 = load_wav("./Commun/Music/music2.wav");
music3 = load_wav("./Commun/Music/music3.wav");
music4 = load_wav("./Commun/Music/music4.wav");
music_menu = load_wav("./Commun/Music/music_menu.wav");
set_volume(255,255);
//#Commun
Cursor = load_bitmap("./Commun/cursor.bmp",NULL);
init_Game_Over(&game_over);
init_You_Win(&you_win);
init_pause(&pause);
init_chargement(&chargement);
curious_froggy.img = load_bitmap("./Loading/titre3.bmp",NULL);


//#Menu

init_fond_menu(&fond_menu);
init_menu1(&exit,&help,&play, &son,&son_coupe);
init_menu2(&s1, &s2, &s3, &s4);
init_bouton_prec(&prec);
init_menu_help(&menu_help);

//#Stage1
init_fond11(&fond11);
init_frog11(&frog11);
init_calque11(&calque11,frog11);
init_rat(&rat);
init_coins11(&piece11);

//#Stage1_2
init_fond12(&fond12);
init_frog12(&frog12);
init_calque12(&calque12,frog12);
init_coins12(&piece12);
init_voiture(&voiture);


//#Stage2


  LOCK_VARIABLE(speed_counter);                
  LOCK_FUNCTION(increment_speed_counter);
  //install_int_ex(increment_speed_counter, BPS_TO_TIMER(80));
  init_pigeon (&pigeon );
 init_background2(&fond2 );
 init_calque2(&calque2,pigeon);
 init_coins2(&piece2,fond2.x);
 int frame_counter = 0; 


//# Stage 4
init_background(&fond);
init_frog(&frog);
init_barre_vie(&barre);
init_tete(&tete);
init_calque(&calque,frog);
init_coins(&piece,fond.x);
init_numero(&numero);
init_serpent(&serpent);
init_reine(&reine);

//#


while(continuer)
{ 
	if(key[KEY_ESC]){
		continuer = 0;
	}
 
 clear_bitmap(Buffer);
 
 if(page == -1)
 {fonction_chargement(&loading_counter,&page,&turn_on_music,chargement,curious_froggy);}
	
  if(page == 0)
      {
	   if(turn_on_music==0)
	  {play_sample(music_menu,128,128,1000,1);
	   turn_on_music=666;
	  }
	  
	  if(sound_off == 1 && turn_on_music == 666)
	  { stop_sample(music_menu);
	    turn_on_music = 555;
	  }
	  
	  
	  
	  
	  fonction_menu(&continuer,fond_menu,menu_help,&page,exit,help,play,son,prec,s1,s2,s3,s4,Cursor,&b_play,&b_exit,&b_help,&b_son,&menu,&etat_s2,&etat_s3,&etat_s4,&b_prec,stage_deverouille,&turn_on_music,son_coupe,&sound_off,&bloquer_click,&click_counter);
	  } 
	  
else if (page==1){
		  if(turn_on_music==1 )
	  {
		  stop_sample(music_menu);
		  if(sound_off == 0)
		  {play_sample(music1,128,128,1000,1);}
	   turn_on_music=666;
	  }
		  
		  fonction_stage1(&stage1_termine,&direction11,&key_pressed11,&frame_counter11,&test_chute11,&saut_horizontal11,&rat_counter,
&vie11,&bloquer_collision_rat,&compteur_collision_rat,&nbr_piece11,&score11,&test_aspiration,&aspiration_terminee,&fond11,&frog11,
&calque11,&rat,&piece11,pause,Cursor,&saut_vertical11,&top11);

      if(test_chute11)
      {//chute(test_chute,&frog,direction);
       etat_next = select_next();
       if(etat_next == 0 || etat_next ==1)
       {draw_sprite(Buffer,game_over.img[etat_next],game_over.x,game_over.y);
       draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
       }
       if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage1_termine = 1;}
       
       //textprintf_centre_ex(Buffer, font, 400, 50,makecol(0, 100, 243), -1,"Mouse.x: %d Mouse.y: %d",mouse_x,mouse_y);
      }
      else if(aspiration_terminee)
      { etat_next = select_next();
        
		draw_sprite(Buffer,you_win.img[etat_next],you_win.x,you_win.y);
        draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
        if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage1_termine = 1;}
	  }
	  if(test_chute11!=1)
      {draw_sprite(Buffer,barre.img[vie11],barre.x,barre.y);}
      else
      {draw_sprite(Buffer,barre.img[0],barre.x,barre.y);}
      draw_sprite(Buffer,tete.img,tete.x,tete.y);
      afficher_score(score11,numero);
      
      if(stage1_termine)
      {
		 page = 0;
		 if(score11>=3 && aspiration_terminee)
		 {etat_s2=1;
		  stage_deverouille = 2;
		 }
		 menu = 2; 
		 stop_sample(music1); 
		 turn_on_music = 0;
		 direction11 = 0;
		 saut_vertical11 = 0;
		 top11=0;
         key_pressed11 = 0;
         frame_counter11 = 0;
         test_chute11 = 0;
         test_aspiration = 0;
         aspiration_terminee = 0;
         saut_horizontal11 = 0;
         rat_counter = 0;
         vie11 = 6;
         bloquer_collision_rat = 0;
         compteur_collision_rat = 0;
         nbr_piece11 = nbr_coins11;
         score11 = 0;
         stage1_termine = 0;
         
         init_fond11(&fond11);
         init_frog11(&frog11);
         init_calque11(&calque11,frog11);
         init_rat(&rat);
         init_coins11(&piece11);
       
	  }
      

}

else if(page==12)
{
	if(turn_on_music==2)
	  {
		  stop_sample(music_menu);
		  if(sound_off == 0)
		  {play_sample(music2,128,128,1000,1);}
	   turn_on_music=666;
	  }
	
	fonctions_stage1_2(&direction12,&key_pressed12,&frame_counter12,&test_chute12,&saut_horizontal12,&nbr_piece12,
&score12,&saut_vertical12,&top12,&car_counter,&stage12_termine,&win_stage12,&bloquer_voiture,&fond12,&frog12,&calque12,&piece12,&voiture,pause,Cursor);

if(test_chute12 != 1)
{
draw_sprite(Buffer,barre.img[vie12],barre.x,barre.y);
}
else
{draw_sprite(Buffer,barre.img[0],barre.x,barre.y);}
      draw_sprite(Buffer,tete.img,tete.x,tete.y);
      afficher_score(score12,numero);



if(test_chute12)
      {
       etat_next = select_next();
       if(etat_next == 0 || etat_next ==1)
       {draw_sprite(Buffer,game_over.img[etat_next],game_over.x,game_over.y);
       draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
       }
       if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage12_termine = 1;}
       
      }
else if(win_stage12)
      { etat_next = select_next();
        
		draw_sprite(Buffer,you_win.img[etat_next],you_win.x,you_win.y);
        draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
        if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage12_termine = 1;}
	  }


if(stage12_termine)
{page = 0;
 menu = 2;
 if(score12>=3 && win_stage12)
		 {etat_s3=1;
		  stage_deverouille = 3;
		 }
		 stop_sample(music2); 
		 turn_on_music = 0;
 direction12 = 0;
 key_pressed12 = 0;
 frame_counter12 = 0;
 test_chute12 = 0;
 saut_horizontal12 = 0;
 win_stage12 = 0;
    
 nbr_piece12 = nbr_coins12;
 score12 = 0;
 saut_vertical12 = 0;
 top12 = 0;
 vie12=6;
 car_counter = 0;
 init_fond12(&fond12);
  init_frog12(&frog12);
  init_calque12(&calque12,frog12);
  init_coins12(&piece12);
 init_voiture(&voiture);
 stage12_termine = 0;
 
 
}


}

  else if(page == 2)
  {
	  if(block_speed_counter==1)
	  { init_speed_counter();
	  install_int_ex(increment_speed_counter, BPS_TO_TIMER(80));
	  
	   block_speed_counter = 0;
      }
	   
	   if(turn_on_music==3)
	  {stop_sample(music_menu);
		  if(sound_off == 0)
		  {play_sample(music3,128,128,1000,1);}
	   turn_on_music=666;
	  }
	  
	  
	  fonction_stage2(&pigeon,&fond2,game_over,&calque2,&piece2,&nbr2,&test2,&frame_counter,&key_pressed2,pause,Cursor,&block_speed_counter,&stage2_termine,&win_stage2,&score2);
	  
	  afficher_score(score2,numero);
	  if(test2)
	   {etat_next = select_next();
        if(etat_next == 0 || etat_next ==1)
        {draw_sprite(Buffer,game_over.img[etat_next],game_over.x,game_over.y);
        draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
        }
        if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage2_termine = 1;}
		   
	   }
	   else if(win_stage2)
      { etat_next = select_next();
        
		draw_sprite(Buffer,you_win.img[etat_next],you_win.x,you_win.y);
        draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
        if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage2_termine = 1;}
	  }
	  
	  
	   if(stage2_termine)
		{page = 0;
		menu = 2;
		if(score2>=27 && win_stage2)
		 {etat_s4=1;
		  stage_deverouille = 4;
		 }
		 stop_sample(music3);
		 turn_on_music = 0;
		score2=0;
		test2 = 0;
        nbr2 = np2;
		block_speed_counter = 1;
		key_pressed2 = 0;
		win_stage2 = 0;
		init_pigeon (&pigeon );
		init_background2(&fond2 );
		init_calque2(&calque2,pigeon);
		init_coins2(&piece2,fond2.x);
		frame_counter = 0; 
		stage2_termine = 0;
		}
  }
  else if(page == 4)
  {   
	  if(turn_on_music==4)
	  {
		  stop_sample(music_menu);
		  if(sound_off == 0)
		  {play_sample(music4,128,128,1000,1);}
	   turn_on_music=666;
	  }
	  
	  fonction_stage4(&direction,&key_pressed,&frog_counter,&serpent_counter,&reine_counter,
      &saut_horizontal,&test_chute,&top,&saut_vertical,&nbr_p,&score4,&vie4,
      &compteur_collision_reine,&bloquer_collision_reine,&fond,&frog,&calque,
       &piece,&serpent,&reine,pause,Cursor,&stage_termine,&win_stage,&bloquer_animation);
	  
	  
	  
	  if(test_chute)
      {chute(test_chute,&frog,direction);
       //draw_sprite(Buffer,game_over.img[0],game_over.x,game_over.y);
       etat_next = select_next();
       if(etat_next == 0 || etat_next ==1)
       {draw_sprite(Buffer,game_over.img[etat_next],game_over.x,game_over.y);
       draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
       }
       if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage_termine = 1;}
      }
      else if(win_stage)
      { etat_next = select_next();
        
		draw_sprite(Buffer,you_win.img[etat_next],you_win.x,you_win.y);
        draw_sprite(Buffer,Cursor,mouse_x,mouse_y);
        if (mouse_b & 1 && mouse_x<490 && mouse_x>320 && (mouse_y>470) && (mouse_y<540))
       {stage_termine = 1;}
	  }
	  if(test_chute != 1)
      {draw_sprite(Buffer,barre.img[vie4],barre.x,barre.y);}
      else
      {draw_sprite(Buffer,barre.img[0],barre.x,barre.y);}
      draw_sprite(Buffer,tete.img,tete.x,tete.y);
      afficher_score(score4,numero);
      
      if(stage_termine)
		{page = 0;
		 menu = 2;
		 stop_sample(music4);
		 turn_on_music = 0;
		 direction = 0;
		 key_pressed = 0;
		 frog_counter = 0;
		 serpent_counter = 0;
		 reine_counter = 0;
		 saut_horizontal = 0;
		 test_chute = 0;
		 top = 0;
		 saut_vertical = 0;
		 nbr_p = nbr_piece;
		 score4 = 0;
		 vie4 = 6;
		 compteur_collision_reine = 0;
		 bloquer_collision_reine = 0;
		 
		 win_stage = 0;
		 init_background(&fond);
		 init_frog(&frog);
		 init_barre_vie(&barre);
		 init_tete(&tete);
		 init_calque(&calque,frog);
		 init_coins(&piece,fond.x);
		 init_numero(&numero);
		 init_serpent(&serpent);
		 init_reine(&reine);
		 stage_termine = 0;
		
	    }
  }

	
	
blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

}

saving(stage_deverouille);

destroy_barre(&barre);
destroy_boutons(&exit,&help,&play,&son);
destroy_icones(&s1,&s2,&s3,&s4);
destroy_bitmap(Cursor);
destroy_bitmap(fond_menu.img);
destroy_bitmap(fond11.img);
destroy_bitmap(calque11.img);
destroy_bitmap(piece11.img);
destroy_rat(&rat);
destroy_frog(&frog11);
destroy_bitmap(fond2.img);
destroy_bitmap(calque2.img);
destroy_bitmap(piece2.img);
destroy_pigeon(&pigeon);
destroy_frog(&frog12);
destroy_bitmap(fond12.img);
destroy_bitmap(calque12.img);

destroy_bitmap(piece12.img);
destroy_voiture(&voiture);
destroy_frog(&frog);
destroy_bitmap(fond.img);
destroy_bitmap(calque.img);
destroy_bitmap(piece.img);

destroy_reine(&reine);
destroy_serpent(&serpent);

destroy_bitmap(tete.img);
//destroy_numero(&numero);
return 0;
}
