#ifndef SABOTEUR_GROUPE_AM_DRAGANDDROP_H
#define SABOTEUR_GROUPE_AM_DRAGANDDROP_H

#ifndef TESTALLEGRO1_RECTANGLE_H
#define TESTALLEGRO1_RECTANGLE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "structure.h"

typedef struct {
    int x, y, width, height;
    ALLEGRO_COLOR couleur;
} Rect;

void dessinerCarte(Rect r, ALLEGRO_BITMAP *image, DeckJoueurCase deckJoueur1[]);
unsigned char clicDansRectangle(Rect r, int x, int y);
void replacerSiDebordement(Rect* rectangle);
void drapAndDrop(ALLEGRO_BITMAP *cards, ALLEGRO_DISPLAY *display, char filename[], ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event,
                 ALLEGRO_TIMER *timer, DeckJoueurCase deckJoueur1[], ALLEGRO_BITMAP *bcg, int a, int b);
void repeindre(Rect rectangle, ALLEGRO_BITMAP *image, DeckJoueurCase deckJoueur1[], ALLEGRO_BITMAP *bcg,
               char filename[], int a, int b);
#endif

#endif //SABOTEUR_GROUPE_AM_DRAGANDDROP_H
