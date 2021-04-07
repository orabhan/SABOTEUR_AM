#ifndef SABOTEUR_GROUPE_AM_STRUCTURE_H
#define SABOTEUR_GROUPE_AM_STRUCTURE_H

typedef struct{
    int x1, y1;
    int x2, y2;
} Bouton;

typedef struct{
    float x;
    float y;
    int width;
    int height;
    int verifHaut, verifBas, verifGauche, verifDroite;
    int type; // 1 = chemin, 2 = réparer, 3 = casser, 4 = map, 5 = éboulement
} Carte;

typedef struct{
    float x, y;
    int width;
    int height;
    int bordTnW;
    int bordTnH;
    int type;
} DeckJoueurCase;

typedef struct{
    float x, y;
    int width;
    int height;
    int bordTnW;
    int bordTnH;
    int type;
    int isFilled;
} CasePlateau;

#endif //SABOTEUR_GROUPE_AM_STRUCTURE_H
