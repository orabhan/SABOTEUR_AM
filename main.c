// INCLUDE MODULES
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/events.h>
#include <assert.h>

#include "structure.h"
#include "fonctionSetup.h"
#include "pseudo.h"


// MACRO
#define FPS 60.0

// IMAGES BACKGROUND
#define BCG_MENU "../images/BCG_MENU.jpg"
#define BCG_RULES "../images/BCG_RULES.jpg"
#define BCG_CHOIX_JOUEURS "../images/BCG_CHOIX_JOUEURS.jpg"
#define BCG_NOM_2J "../images/BCG_NOM_2J.jpg"
#define BCG_NOM_3J "../images/BCG_NOM_3J.jpg"
#define BCG_NOM_4J "../images/BCG_NOM_4J.jpg"
#define BCG_PLT_2J "../images/BCG_PLT_2J.jpg"
#define BCG_PLT_3J "../images/BCG_PLT_3J.jpg"
#define BCG_PLT_4J "../images/BCG_PLT_4J.jpg"
#define BCG_REVEAL "../images/BCG_REVEAL_2J.jpg"

#define BITMAP_CARDS "../cards.jpg"


// MAIN
int main() {


    // INIT
    al_init();
    assert(al_install_mouse());
    assert(al_init_image_addon());
    assert(al_init_primitives_addon());


    // INIT VARIABLES ALLEGRO
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *loading = NULL;
    ALLEGRO_MONITOR_INFO userMonitorInfo;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);


    // INIT VARIABLES FONCT
    int userMonitorWidth, userMonitorHeight;
    int isEnd = 0;
    int selectionPseudo = 0;
    int menuActif; //1 = BCG_MENU, 2 = BCG_RULES, 3 = BCG_CHOIX_JOUEURS, 4 = BCG_NOM, 5 = PLT234J
    int choixNbrJ = 0;
    int MAXPIOCHE = 65;
    char filename[] = "../cards.jpg";
    srand(time(NULL));
    int a = randomNumber(0, 2);
    int b = randomNumber(0, 2);

    // INIT BOUTONS (les positions des boutons sont définis dans la résolution native de l'image faite sur photoshop (2560.1080) puis une formule qui calculer
    // le ratio permet de calculer en fonction de la taille de l'écran de l'utilisateur si le clique est sur un bouton ou non)

    // BOUTON DU MENU PRINCIPAL
    Bouton btnMenuQuitter, btnMenuRules, btnMenuLancer, btnMenuCharger;
    btnMenuQuitter.x1 = 899, btnMenuQuitter.x2 = 1660, btnMenuQuitter.y1 = 1155, btnMenuQuitter.y2 = 1346;
    btnMenuRules.x1 = 899, btnMenuRules.x2 = 1660, btnMenuRules.y1 = 890, btnMenuRules.y2 = 1081;
    btnMenuLancer.x1 = 418, btnMenuLancer.x2 = 1179, btnMenuLancer.y1 = 628, btnMenuLancer.y2 = 818;
    btnMenuCharger.x1 = 1380, btnMenuCharger.x2 = 2141, btnMenuCharger.y1 = 628, btnMenuCharger.y2 = 818;

    // BOUTON GENERAL AU JEU
    Bouton btnRetour, btnSuivant;
    btnRetour.x1 = 87, btnRetour.x2 = 692, btnRetour.y1 = 1200, btnRetour.y2 = 1352;
    btnSuivant.x1 = 1854, btnSuivant.x2 = 2459, btnSuivant.y1 = 1200, btnSuivant.y2 = 1352;

    // BOUTON ECRAN JOUEURS
    Bouton btnChoix2J, btnChoix3J, btnChoix4J;
    btnChoix2J.x1 = 439, btnChoix2J.x2 = 809, btnChoix2J.y1 = 560, btnChoix2J.y2 = 959;
    btnChoix3J.x1 = 1095, btnChoix3J.x2 = 1465, btnChoix3J.y1 = 560, btnChoix3J.y2 = 959;
    btnChoix4J.x1 = 1751, btnChoix4J.x2 = 2121, btnChoix4J.y1 = 560, btnChoix4J.y2 = 959;

    // BOUTON NOM JOUEURS
    Bouton btnNom1, btnNom2, btnNom3, btnNom4;
    btnNom1.x1 = 706, btnNom1.y1 = 410, btnNom1.x2 = 1853, btnNom1.y2 = 560;
    btnNom2.x1 = 706, btnNom2.y1 = 597, btnNom2.x2 = 1853, btnNom2.y2 = 747;
    btnNom3.x1 = 706, btnNom3.y1 = 784, btnNom3.x2 = 1853, btnNom3.y2 = 934;
    btnNom4.x1 = 706, btnNom4.y1 = 971, btnNom4.x2 = 1853, btnNom4.y2 = 1121;

    // PIOCHE DE BITMAP
    Carte fausseBmpOG;
    fausseBmpOG.x = 0.0, fausseBmpOG.y = 0.0, fausseBmpOG.width = 256, fausseBmpOG.height = 162;
    Carte fausseBmp[70];

    // DECK JOUEUR PUIS INIT DECK VIA FAUSSE
    DeckJoueurCase deckJoueur1[6];
    deckJoueur1->bordTnW = 6, deckJoueur1->bordTnH = 6;
    deckJoueur1->width = 256, deckJoueur1->height = 162;

    // CASE PLATEAU
    CasePlateau caseReference;
    caseReference.x = 101.0, caseReference.y = 136.0;
    caseReference.width = 256, caseReference.height = 162;
    caseReference.bordTnW = 6, caseReference.bordTnH = 6;
    CasePlateau casePlateau[5] [9];
    int i = 0, j = 0;
    for(i = 0 ; i < 5 ; i++) {
        for(j = 0 ; j < 9 ; j++) {
            casePlateau[i] [j].x = caseReference.x + (i * caseReference.width) + (2 * i * caseReference.bordTnW);
            casePlateau[i] [j].y = caseReference.y + (i * caseReference.height) + (2 * i * caseReference.bordTnH);
            casePlateau[i] [j].type = 0;
            casePlateau[i] [j].isFilled = 0;
        }
    }
    casePlateau[2] [0].isFilled = 1, casePlateau[0] [8].isFilled = 1;
    casePlateau[2] [8].isFilled = 1, casePlateau[4] [8].isFilled = 1;

    // INIT DES CARTES DANS LA PIOCHE
    for (i = 0 ; i < 8 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x;
        fausseBmp[i].y = fausseBmpOG.y;
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 1; // type chemin
        fausseBmp[i].verifDroite = 1;
        fausseBmp[i].verifGauche = 0;
        fausseBmp[i].verifHaut = 1;
        fausseBmp[i].verifBas = 1;
    }
    for (i = 8 ; i < 17; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 1);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 0);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 1; // type chemin
        fausseBmp[i].verifDroite = 1;
        fausseBmp[i].verifGauche = 1;
        fausseBmp[i].verifHaut = 0;
        fausseBmp[i].verifBas = 1;
    }
    for (i = 17 ; i < 26 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 2);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 0);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 1; // type chemin
        fausseBmp[i].verifDroite = 1;
        fausseBmp[i].verifGauche = 1;
        fausseBmp[i].verifHaut = 1;
        fausseBmp[i].verifBas = 1;
    }
    for (i = 26 ; i < 35 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 3);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 0);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 1; // type chemin
        fausseBmp[i].verifDroite = 1;
        fausseBmp[i].verifGauche = 1;
        fausseBmp[i].verifHaut = 0;
        fausseBmp[i].verifBas = 0;
    }
    for (i = 35 ; i < 44 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 4);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 0);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 1; // type chemin
        fausseBmp[i].verifDroite = 0;
        fausseBmp[i].verifGauche = 1;
        fausseBmp[i].verifHaut = 0;
        fausseBmp[i].verifBas = 0;
    }
    for (i = 44 ; i < 46 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 2);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 1);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    for (i = 46 ; i < 48 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 3);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 1);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    for(i = 48 ; i < 50 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 4);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 1);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    fausseBmp[50].x = fausseBmpOG.x + (fausseBmpOG.width * 5);
    fausseBmp[50].y = fausseBmpOG.y + (fausseBmpOG.height * 1);
    fausseBmp[50].width = fausseBmpOG.width;
    fausseBmp[50].height = fausseBmpOG.height;
    fausseBmp[50].type = 4; // type map
    for(i = 51 ; i < 53 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 0);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    for(i = 53 ; i < 55 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 1);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    for(i = 55 ; i < 57 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 2);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 2; // type réparer
    }
    for(i = 57 ; i < 59 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 3);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 3; // type casser
    }
    for(i = 59 ; i < 61 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 4);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 3; // type casser
    }
    for(i = 61 ; i < 63 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 5);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 2);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 3; // type casser
    }
    for(i = 63 ; i < 65 ; i++) {
        fausseBmp[i].x = fausseBmpOG.x + (fausseBmpOG.width * 0);
        fausseBmp[i].y = fausseBmpOG.y + (fausseBmpOG.height * 3);
        fausseBmp[i].width = fausseBmpOG.width;
        fausseBmp[i].height = fausseBmpOG.height;
        fausseBmp[i].type = 3; // type casser
    }
    fausseBmp[65].x = fausseBmpOG.x + (fausseBmpOG.width * 1);
    fausseBmp[65].y = fausseBmpOG.y + (fausseBmpOG.height * 3);
    fausseBmp[65].width = fausseBmpOG.width;
    fausseBmp[65].height = fausseBmpOG.height;
    fausseBmp[65].type = 5; // type éboulement

    // MELANGE PIOCHE
    melangerPioche(fausseBmp);
    attribuerCarteJoueur(deckJoueur1, fausseBmp, MAXPIOCHE);
    MAXPIOCHE = MAXPIOCHE - 6;

    // TIMER FPS
    timer = al_create_timer(1.0 / FPS);


    // SETUP INTERFACE DE BASE
    al_get_monitor_info(0, &userMonitorInfo);
    userMonitorWidth = userMonitorInfo.x2;
    userMonitorHeight = userMonitorInfo.y2;
    double ratio_X = (2560.0 / userMonitorInfo.x2);
    double ratio_Y = (1440.0 / userMonitorInfo.y2);


    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(userMonitorWidth, userMonitorHeight);
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, "LE SABOTEUR EDITION STAR WARS");
    background = al_load_bitmap(BCG_MENU);
    al_draw_scaled_bitmap(background, 0, 0, 2560, 1440, 0, 0, userMonitorWidth, userMonitorHeight, 0);
    menuActif = 1;
    al_flip_display();


    // QUEUE SETUP
    queue = al_create_event_queue();
    if (queue == NULL) {
        al_destroy_display(display);
        exit(EXIT_FAILURE);
    }
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));


    // QUEUE
    while (!isEnd) {
        al_start_timer(timer);
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&mouse_state);

        srand(time(NULL));

        // CASE D'EVENTS
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                isEnd = 1;
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                al_draw_scaled_bitmap(background, 0, 0, 2560, 1440, 0, 0, userMonitorWidth, userMonitorHeight, 0);
                if (menuActif == 6) {
                    afficherCarteJoueurDeck(loading, filename, deckJoueur1);
                    placerCarteBaseGame(loading, filename, a, b);
                }
                if (selectionPseudo == 1) {
                    al_draw_filled_rectangle((btnNom1.x1 / ratio_X), (btnNom1.y1 / ratio_Y),
                                             (btnNom1.x2 / ratio_X), (btnNom1.y2 / ratio_Y),
                                             al_map_rgba(99, 99, 99, 0));
                }
                if (selectionPseudo == 2) {
                    al_draw_filled_rectangle((btnNom2.x1 / ratio_X), (btnNom2.y1 / ratio_Y),
                                             (btnNom2.x2 / ratio_X), (btnNom2.y2 / ratio_Y),
                                             al_map_rgba(99, 99, 99, 0));
                }
                if (selectionPseudo == 3) {
                    al_draw_filled_rectangle((btnNom3.x1 / ratio_X), (btnNom3.y1 / ratio_Y),
                                             (btnNom3.x2 / ratio_X), (btnNom3.y2 / ratio_Y),
                                             al_map_rgba(99, 99, 99, 0));
                }
                if (selectionPseudo == 4) {
                    al_draw_filled_rectangle((btnNom4.x1 / ratio_X), (btnNom4.y1 / ratio_Y),
                                             (btnNom4.x2 / ratio_X), (btnNom4.y2 / ratio_Y),
                                             al_map_rgba(99, 99, 99, 0));
                }
                al_flip_display();
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {


                    // ACTION ECRAN SUR LE MENU 1 (BCG_MENU)
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 1) {

                        // LANCER PARTIE
                        if (mouse_state.x > (btnMenuLancer.x1 / ratio_X) && mouse_state.x < (btnMenuLancer.x2 / ratio_X)
                            && (mouse_state.y > btnMenuLancer.y1 / ratio_Y) &&
                            mouse_state.y < (btnMenuLancer.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_CHOIX_JOUEURS);
                            menuActif = 3;
                        }

                        // AFFICHER LES REGLES
                        if (mouse_state.x > (btnMenuRules.x1 / ratio_X) && mouse_state.x < (btnMenuRules.x2 / ratio_X)
                            && (mouse_state.y > btnMenuRules.y1 / ratio_Y) &&
                            mouse_state.y < (btnMenuRules.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_RULES);
                            menuActif = 2;
                        }

                        // QUITTER
                        if (mouse_state.x > (btnMenuQuitter.x1 / ratio_X) &&
                            mouse_state.x < (btnMenuQuitter.x2 / ratio_X)
                            && (mouse_state.y > btnMenuQuitter.y1 / ratio_Y) &&
                            mouse_state.y < (btnMenuQuitter.y2 / ratio_Y)) {
                            isEnd = 1;
                        }
                    }


                    // ACTION ECRAN SUR LE MENU 2 (BCG_RULES)
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 2) {

                        // RETOUR
                        if (mouse_state.x > (btnRetour.x1 / ratio_X) && mouse_state.x < (btnRetour.x2 / ratio_X)
                            && (mouse_state.y > btnRetour.y1 / ratio_Y) && mouse_state.y < (btnRetour.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_MENU);
                            menuActif = 1;
                        }
                    }


                    //ACTION ECRAN SUR LE MENU 3 (BCG_CHOIX_JOUEURS)
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 3) {

                        // JOUER A 2J
                        if (mouse_state.x > (btnChoix2J.x1 / ratio_X) && mouse_state.x < (btnChoix2J.x2 / ratio_X)
                            && (mouse_state.y > btnChoix2J.y1 / ratio_Y) && mouse_state.y < (btnChoix2J.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_NOM_2J);
                            menuActif = 4, choixNbrJ = 2;
                        }

                        // JOUER A 3J
                        if (mouse_state.x > (btnChoix3J.x1 / ratio_X) && mouse_state.x < (btnChoix3J.x2 / ratio_X)
                            && (mouse_state.y > btnChoix3J.y1 / ratio_Y) && mouse_state.y < (btnChoix3J.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_NOM_3J);
                            menuActif = 4, choixNbrJ = 3;
                        }

                        // JOUER A 4J
                        if (mouse_state.x > (btnChoix4J.x1 / ratio_X) && mouse_state.x < (btnChoix4J.x2 / ratio_X)
                            && (mouse_state.y > btnChoix4J.y1 / ratio_Y) && mouse_state.y < (btnChoix4J.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_NOM_4J);
                            menuActif = 4, choixNbrJ = 4;
                        }

                        // RETOUR
                        if (mouse_state.x > (btnRetour.x1 / ratio_X) && mouse_state.x < (btnRetour.x2 / ratio_X)
                            && (mouse_state.y > btnRetour.y1 / ratio_Y) && mouse_state.y < (btnRetour.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_MENU);
                            menuActif = 1;
                        }
                    }

                    // ACTION ECRAN SUR LE MENU 4 (BCG_NOM)
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 4) {
                        // RETOUR
                        if (mouse_state.x > (btnRetour.x1 / ratio_X) && mouse_state.x < (btnRetour.x2 / ratio_X)
                            && (mouse_state.y > btnRetour.y1 / ratio_Y) && mouse_state.y < (btnRetour.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_MENU);
                            menuActif = 1, selectionPseudo = 0;
                        }
                        // SUIVANT
                        if (mouse_state.x > (btnSuivant.x1 / ratio_X) && mouse_state.x < (btnSuivant.x2 / ratio_X)
                            && (mouse_state.y > btnSuivant.y1 / ratio_Y) && mouse_state.y < (btnSuivant.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_REVEAL);
                            menuActif = 5, selectionPseudo = 0;
                        }
                        // SELECTION ENTREE PSEUDO
                        if (choixNbrJ == 2) {
                            // SELECTION J1 PSEUDO
                            if (mouse_state.x > (btnNom1.x1 / ratio_X) && mouse_state.x < (btnNom1.x2 / ratio_X)
                                && (mouse_state.y > btnNom1.y1 / ratio_Y) && mouse_state.y < (btnNom1.y2 / ratio_Y)) {
                                selectionPseudo = 1;
                            }
                            // SELECTION J2 PSEUDO
                            if (mouse_state.x > (btnNom2.x1 / ratio_X) && mouse_state.x < (btnNom2.x2 / ratio_X)
                                && (mouse_state.y > btnNom2.y1 / ratio_Y) && mouse_state.y < (btnNom2.y2 / ratio_Y)) {
                                selectionPseudo = 2;
                            }
                        }
                        // SELECTION ENTREE PSEUDO
                        if (choixNbrJ == 3) {
                            // SELECTION J1 PSEUDO
                            if (mouse_state.x > (btnNom1.x1 / ratio_X) && mouse_state.x < (btnNom1.x2 / ratio_X)
                                && (mouse_state.y > btnNom1.y1 / ratio_Y) && mouse_state.y < (btnNom1.y2 / ratio_Y)) {
                                selectionPseudo = 1;
                            }
                            // SELECTION J2 PSEUDO
                            if (mouse_state.x > (btnNom2.x1 / ratio_X) && mouse_state.x < (btnNom2.x2 / ratio_X)
                                && (mouse_state.y > btnNom2.y1 / ratio_Y) && mouse_state.y < (btnNom2.y2 / ratio_Y)) {
                                selectionPseudo = 2;
                            }
                            // SELECTION J3 PSEUDO
                            if (mouse_state.x > (btnNom3.x1 / ratio_X) && mouse_state.x < (btnNom3.x2 / ratio_X)
                                && (mouse_state.y > btnNom3.y1 / ratio_Y) && mouse_state.y < (btnNom3.y2 / ratio_Y)) {
                                selectionPseudo = 3;
                            }
                        }
                        // SELECTION ENTREE PSEUDO
                        if (choixNbrJ == 4) {
                            // SELECTION J1 PSEUDO
                            if (mouse_state.x > (btnNom1.x1 / ratio_X) && mouse_state.x < (btnNom1.x2 / ratio_X)
                                && (mouse_state.y > btnNom1.y1 / ratio_Y) && mouse_state.y < (btnNom1.y2 / ratio_Y)) {
                                selectionPseudo = 1;
                            }
                            // SELECTION J2 PSEUDO
                            if (mouse_state.x > (btnNom2.x1 / ratio_X) && mouse_state.x < (btnNom2.x2 / ratio_X)
                                && (mouse_state.y > btnNom2.y1 / ratio_Y) && mouse_state.y < (btnNom2.y2 / ratio_Y)) {
                                selectionPseudo = 2;
                            }
                            // SELECTION J3 PSEUDO
                            if (mouse_state.x > (btnNom3.x1 / ratio_X) && mouse_state.x < (btnNom3.x2 / ratio_X)
                                && (mouse_state.y > btnNom3.y1 / ratio_Y) && mouse_state.y < (btnNom3.y2 / ratio_Y)) {
                                selectionPseudo = 3;
                            }
                            // SELECTION J4 PSEUDO
                            if (mouse_state.x > (btnNom4.x1 / ratio_X) && mouse_state.x < (btnNom4.x2 / ratio_X)
                                && (mouse_state.y > btnNom4.y1 / ratio_Y) && mouse_state.y < (btnNom4.y2 / ratio_Y)) {
                                selectionPseudo = 4;
                            }
                        }
                    }


                    // ACTION ECRAN SUR LE MENU 5 (BCG_REVEAL)
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 5) {

                        // RETOUR
                        if (mouse_state.x > (btnRetour.x1 / ratio_X) && mouse_state.x < (btnRetour.x2 / ratio_X)
                            && (mouse_state.y > btnRetour.y1 / ratio_Y) && mouse_state.y < (btnRetour.y2 / ratio_Y)) {
                            background = al_load_bitmap(BCG_CHOIX_JOUEURS);
                            menuActif = 3;
                        }

                        // SUIVANT
                        if (mouse_state.x > (btnSuivant.x1 / ratio_X) && mouse_state.x < (btnSuivant.x2 / ratio_X)
                            && mouse_state.y > (btnSuivant.y1 / ratio_Y) && mouse_state.y < (btnSuivant.y2 / ratio_Y)) {
                            if (choixNbrJ == 2 && menuActif == 5) {
                                background = al_load_bitmap(BCG_PLT_2J);
                                menuActif = 6;
                            }
                            if (choixNbrJ == 3 && menuActif == 5) {
                                background = al_load_bitmap(BCG_PLT_3J);
                                menuActif = 6;
                            }
                            if (choixNbrJ == 4 && menuActif == 5) {
                                background = al_load_bitmap(BCG_PLT_4J);
                                menuActif = 6;
                            }
                        }
                    }

                    // ACTION SUR LE PLATEAU DE JEU
                    if ((mouse_state.buttons & 1) == 1 && menuActif == 6) {
                    }
                }
            }
        }
    }


    // ENDING
    al_destroy_display(display);
    display = NULL;
    al_destroy_event_queue(queue);
    queue = NULL;
    al_destroy_timer(timer);
    timer = NULL;
    return 0;
}


