#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char **argv) 
{
	ALLEGRO_FONT* fnt = NULL; 
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_create_display(640, 480);
	fnt = al_load_font("../../fonts/Roboto-Black.ttf", 30, 0);
	if(fnt == NULL)
	{
		printf("Failboat\n");
	 	exit(-1);
	}
	
	al_clear_to_color(al_map_rgb_f(1, 1, 0));
	al_draw_textf(fnt, al_map_rgb(210, 15, 0), 25, 345, ALLEGRO_ALIGN_LEFT, "Dead On Survival");
	
	al_flip_display();
	al_rest(5.0);
	return 0;
}
