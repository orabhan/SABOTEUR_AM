#include "fonctionSetup.h"
#include "time.h"
#include "stdlib.h"
#include "structure.h"

#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#define INDEX_MAX_PIOCHE 66

int randomNumber(int min, int max) {
    int nbrGen;
    nbrGen = (rand() % (max - min + 1) + min);
    return nbrGen;
}

void melangerPioche(Carte fausseCarte[]) {
    srand(time(NULL));
    int n1, n2;
    Carte temp;
    for(int i = 0 ; i < 70 ; i++) {
        n1 = randomNumber(0, INDEX_MAX_PIOCHE - 1);
        do {
            n2 = randomNumber(0, INDEX_MAX_PIOCHE - 1);
        } while (n2 == n1);
        temp.x = fausseCarte[n1].x;
        temp.y = fausseCarte[n1].y;
        temp.type = fausseCarte[n1].type;
        fausseCarte[n1].x = fausseCarte[n2].x;
        fausseCarte[n1].y = fausseCarte[n2].y;
        fausseCarte[n1].type = fausseCarte[n2].type;
        fausseCarte[n2].x = temp.x;
        fausseCarte[n2].y = temp.y;
        fausseCarte[n2].type = temp.type;
    }
}

void attribuerCarteJoueur(DeckJoueurCase DeckJoueur1[], Carte fausseCarte[], int MAXPIOCHE) {
    srand(time(NULL));
    Carte temp;
    for(int i = 0 ; i < 6 ; i++) {
        int indice = rand() % MAXPIOCHE;
        DeckJoueur1[i].x = fausseCarte[indice].x;
        DeckJoueur1[i].y = fausseCarte[indice].y;
        DeckJoueur1[i].type = fausseCarte[indice].type;

        temp.x = fausseCarte[indice].x;
        temp.y = fausseCarte[indice].y;
        temp.type = fausseCarte[indice].type;
        fausseCarte[indice].x = fausseCarte[MAXPIOCHE].x;
        fausseCarte[indice].y = fausseCarte[MAXPIOCHE].y;
        fausseCarte[indice].type = fausseCarte[MAXPIOCHE].type;
        fausseCarte[MAXPIOCHE].x = temp.x;
        fausseCarte[MAXPIOCHE].y = temp.y;
        fausseCarte[MAXPIOCHE].type = temp.type;

        MAXPIOCHE -= 1;
    }
}

void afficherCarteJoueurdeck(ALLEGRO_BITMAP *cards, char filename[], DeckJoueurCase deckJoueur[], float ratio_X,
                             float ratio_Y) {
    ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);
    cards = al_load_bitmap(filename);
    for (int i = 0 ; i < 6 ; i++) {
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    deckJoueur[i].x, deckJoueur[i].y,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    (101 + i * deckJoueur->width + (i * deckJoueur->bordTnW * 2)) / ratio_X, 136 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
    }
}

void placerCarteBaseGame(ALLEGRO_BITMAP *cards, char filename[], int a, int b, float ratio_X, float ratio_Y) {
    srand(time(NULL));
    ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);
    cards = al_load_bitmap(filename);
    al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                1280, 0,
                                                256, 162,
                                                color_white, 0, 0,
                                                75 / ratio_X, 921 / ratio_Y,
                                                (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                0, 0);
    if (a == 0) {
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 571 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 921 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        if (b == 0) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        768, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 1271 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 1) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1024, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 1271 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 2) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1280, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 1271 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
    }
    if (a == 1) {
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 921 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 1271 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        if (b == 0) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        768, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 571 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 1) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1024, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 571 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 2) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1280, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 571 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
    }
    if (a == 2) {
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 571 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                    512, 486,
                                                    256, 162,
                                                    color_white, 0, 0,
                                                    2227 / ratio_X, 1271 / ratio_Y,
                                                    (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                    0, 0);
        if (b == 0) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        768, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 921 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 1) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1024, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 921 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
        if (b == 2) {
            al_draw_tinted_scaled_rotated_bitmap_region(cards,
                                                        1280, 486,
                                                        256, 162,
                                                        color_white, 0, 0,
                                                        2227 / ratio_X, 921 / ratio_Y,
                                                        (1 / ratio_X) * 1.02, (1 / ratio_Y) * 1.02,
                                                        0, 0);
        }
    }
}