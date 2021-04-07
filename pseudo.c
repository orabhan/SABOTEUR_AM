#include "pseudo.h"

#include "pseudo.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

void ecrirePseudo(int x, int y, int size){

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT_SOURCE *source = al_get_keyboard_event_source();

    ALLEGRO_BITMAP *bitmapBlanc = NULL;
    bitmapBlanc = al_load_bitmap("../text/fondblanc.jpg");

    ALLEGRO_BITMAP *bitmapNoir = NULL;
    bitmapNoir = al_load_bitmap("../text/fondnoir.jpg");

    al_register_event_source(queue, source);

    int isEnd = 0;
    char pseudo[20];
    int i = 0;

    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);

    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(1500, 1500);

    al_clear_to_color(white);
    al_set_window_title(display, "Projet Info");
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    assert(display);

    ALLEGRO_FONT *font = NULL;
    font = al_load_ttf_font("../text/StarWars.ttf", size, 0);

    al_clear_to_color(white);
    al_flip_display();

    while (!isEnd) {
        ALLEGRO_EVENT event = {0};
        //al_start_timer(timer);
        al_wait_for_event(queue, &event);
        switch (event.type) {
            //case ALLEGRO_EVENT_TIMER:
            al_flip_display();
            case ALLEGRO_EVENT_KEY_DOWN:
                x += 55;
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_Q:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "A");
                        pseudo[i] = 'A';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_B:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "B");
                        pseudo[i] = 'B';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_C:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "C");
                        pseudo[i] = 'C';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_D:
                        al_flip_display();
                        al_draw_textf(font, black, x,y, 0, "D");
                        pseudo[i] = 'D';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_E:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "E");
                        pseudo[i] = 'E';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_F:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "F");
                        pseudo[i] = 'F';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_G:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "G");
                        pseudo[i] = 'G';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_Q:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "A");
                        pseudo[i] = 'A';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_H:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "H");
                        pseudo[i] = 'H';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_I:
                        al_flip_display();
                        al_draw_textf(font, black, x+15, y, 0, "I");
                        pseudo[i] = 'I';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_J:
                        al_flip_display();
                        al_draw_textf(font, black, x+10, y, 0, "J");
                        pseudo[i] = 'J';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_K:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "K");
                        pseudo[i] = 'K';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_L:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "L");
                        pseudo[i] = 'L';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_M:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "M");
                        pseudo[i] = 'M';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_N:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "N");
                        pseudo[i] = 'N';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_O:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "O");
                        pseudo[i] = 'O';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_P:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "P");
                        pseudo[i] = 'P';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_A:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "Q");
                        pseudo[i] = 'Q';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_R:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "R");
                        pseudo[i] = 'R';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_S:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "S");
                        pseudo[i] = 'S';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_T:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "T");
                        pseudo[i] = 'T';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_U:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "U");
                        pseudo[i] = 'U';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_V:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "V");
                        pseudo[i] = 'V';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_Z:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "W");
                        pseudo[i] = 'W';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_X:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "X");
                        pseudo[i] = 'X';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_Y:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "Y");
                        pseudo[i] = 'Y';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_W:
                        al_flip_display();
                        al_draw_textf(font, black, x, y, 0, "Z");
                        pseudo[i] = 'Z';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        al_flip_display();
                        al_draw_tinted_scaled_rotated_bitmap_region(bitmapBlanc, 0, 0, 50, 50, white,
                                                                    0, 0, x-65, y,
                                                                    1, 1, 0, 0);
                        pseudo[i] = ' ';
                        i += 1;
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_DELETE:
                        al_flip_display();
                        al_draw_tinted_scaled_rotated_bitmap_region(bitmapNoir, 0, 0, 50, 50, black,
                                                                    0, 0, x-65, y,
                                                                    1, 1, 0, 0);
                        al_flip_display();
                }
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        isEnd = 1;
                }
        }
        printf("%s", pseudo);
    }
}