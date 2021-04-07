#ifndef SABOTEUR_GROUPE_AM_FONCTIONSETUP_H
#define SABOTEUR_GROUPE_AM_FONCTIONSETUP_H

#include "structure.h"
#include <allegro5/allegro.h>

int randomNumber(int min, int max);
void melangerPioche(Carte fausseCarte[]);
void attribuerCarteJoueur(DeckJoueurCase DeckJoueur1[], Carte fausseCarte[], int MAXPIOCHE);
void afficherCarteJoueurDeck(ALLEGRO_BITMAP *cards, char filename[], DeckJoueurCase deckJoueur[]);
void placerCarteBaseGame(ALLEGRO_BITMAP *cards, char filename[], int a, int b);
void cliquezDeposerCarte(ALLEGRO_BITMAP *cards, char filename[], DeckJoueurCase DeckJoueur1[],
                         CasePlateau casePlateau, int mouse_X, int mouse_Y);
void remplirDeckJoueur(DeckJoueurCase DeckJoueur1[], Carte fausseCarte[], int MAXPIOCHE, int toReplace);

#endif //SABOTEUR_GROUPE_AM_FONCTIONSETUP_H
