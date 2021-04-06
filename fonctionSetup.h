#ifndef SABOTEUR_GROUPE_AM_FONCTIONSETUP_H
#define SABOTEUR_GROUPE_AM_FONCTIONSETUP_H

#include "structure.h"
#include <allegro5/allegro.h>

int randomNumber(int min, int max);
void melangerPioche(Carte fausseCarte[]);
void attribuerCarteJoueur(DeckJoueurCase DeckJoueur1[], Carte fausseCarte[], int MAXPIOCHE);
void afficherCarteJoueurdeck(ALLEGRO_BITMAP *cards, char filename[], DeckJoueurCase deckJoueur[], float ratio_X,
                             float ratio_Y);
void placerCarteBaseGame(ALLEGRO_BITMAP *cards, char filename[], int a, int b, float ratio_X, float ratio_Y);

#endif //SABOTEUR_GROUPE_AM_FONCTIONSETUP_H
