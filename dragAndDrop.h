#ifndef SABOTEUR_GROUPE_AM_DRAGANDDROP_H
#define SABOTEUR_GROUPE_AM_DRAGANDDROP_H

#ifndef TESTALLEGRO1_RECTANGLE_H
#define TESTALLEGRO1_RECTANGLE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

typedef struct {
    int x, y, largeur, hauteur;
    ALLEGRO_COLOR couleur;
} Rect;

void dessinerCarte(Rect r, ALLEGRO_BITMAP *image);
unsigned char clicDansRectangle(Rect r, int x, int y);
void replacerSiDebordement(Rect* rectangle);
#endif

#endif //SABOTEUR_GROUPE_AM_DRAGANDDROP_H
