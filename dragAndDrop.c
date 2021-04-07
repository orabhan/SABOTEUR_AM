#include "dragAndDrop.h"
#include "structure.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "fonctionSetup.h"

void dessinerCarte(Rect r, ALLEGRO_BITMAP *image, DeckJoueurCase deckJoueur1[]) {
    ALLEGRO_MONITOR_INFO userMonitorInfo;
    int userMonitorWidth, userMonitorHeight;
    al_get_monitor_info(0, &userMonitorInfo);
    userMonitorWidth = userMonitorInfo.x2;
    userMonitorHeight = userMonitorInfo.y2;
    double ratio_X = (2560.0 / userMonitorInfo.x2);
    double ratio_Y = (1440.0 / userMonitorInfo.y2);

    al_draw_tinted_scaled_rotated_bitmap_region(image, deckJoueur1[0].x, deckJoueur1[0].y,
                                                256, 162, al_map_rgb(255, 255, 255),
                                                0, 0, r.x, r.y, 1 / ratio_X, 1 / ratio_Y, 0, 0);
}

unsigned char clicDansRectangle(Rect r, int x, int y) {
    if(x >= r.x && x <= r.x + 256 && y >= r.y && y <= r.y + 162) {
        return 1;
    }
    return 0;
}

void replacerSiDebordement(Rect* rectangle) {
    ALLEGRO_MONITOR_INFO userMonitorInfo;
    int userMonitorWidth, userMonitorHeight;
    al_get_monitor_info(0, &userMonitorInfo);
    userMonitorWidth = userMonitorInfo.x2;
    userMonitorHeight = userMonitorInfo.y2;
    double ratio_X = (2560.0 / userMonitorInfo.x2);
    double ratio_Y = (1440.0 / userMonitorInfo.y2);
    if (rectangle->x < 0) { rectangle->x = 0; }
    if (rectangle->x + 256 > (2560 / ratio_X) - 300) { rectangle->x = (2560 / ratio_X) - 300; }
    if (rectangle->y < 0) { rectangle->y = 0; }
    if (rectangle->y + 162 > (1440 / ratio_Y) - 200) { rectangle->y = (1440 / ratio_Y) - 200; }
}


void repeindre(Rect rectangle, ALLEGRO_BITMAP *image, DeckJoueurCase deckJoueur1[], ALLEGRO_BITMAP *bcg,
               char filename[], int a, int b) {
    ALLEGRO_BITMAP *loading = NULL;
    ALLEGRO_MONITOR_INFO userMonitorInfo;
    int userMonitorWidth, userMonitorHeight;
    al_get_monitor_info(0, &userMonitorInfo);
    userMonitorWidth = userMonitorInfo.x2;
    userMonitorHeight = userMonitorInfo.y2;
    double ratio_X = (2560.0 / userMonitorInfo.x2);
    double ratio_Y = (1440.0 / userMonitorInfo.y2);

    al_draw_scaled_bitmap(bcg, 0, 0, 2560, 1440, 0, 0, userMonitorWidth, userMonitorHeight, 0);
    afficherCarteJoueurDeck(loading, filename, deckJoueur1);
    placerCarteBaseGame(loading, filename, a, b);
    dessinerCarte(rectangle, image, deckJoueur1);
    al_flip_display();
}

void drapAndDrop(ALLEGRO_BITMAP *cards, ALLEGRO_DISPLAY *display, char filename[], ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT event,
                 ALLEGRO_TIMER *timer, DeckJoueurCase deckJoueur1[], ALLEGRO_BITMAP *bcg, int a, int b) {
    int fini = 0;
    int repeint = 0;
    int glisserDeposer = 0;
    int decalageXGlisserDeposer = 0;
    int decalageYGlisserDeposer = 0;
    Rect rectangle = {0};

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    cards = al_load_bitmap(filename);
    rectangle.x = 256;
    rectangle.y = 162;

    repeindre(rectangle, cards, deckJoueur1, bcg, filename, a, b);

    al_start_timer(timer);
    while (!fini) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fini = 1;
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                if(clicDansRectangle(rectangle, event.mouse.x, event.mouse.y)) {
                    glisserDeposer = 1;
                    decalageXGlisserDeposer = event.mouse.x - rectangle.x;
                    decalageYGlisserDeposer = event.mouse.y - rectangle.y;
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                glisserDeposer = decalageXGlisserDeposer = decalageYGlisserDeposer = 0;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES: {
                if(glisserDeposer) {
                    rectangle.x = event.mouse.x - decalageXGlisserDeposer;
                    rectangle.y = event.mouse.y - decalageYGlisserDeposer;
                    replacerSiDebordement(&rectangle);
                    repeint = 1;
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                if (repeint) {
                    repeindre(rectangle, cards, deckJoueur1, bcg, filename, a, b);
                    repeint = 0;
                }
                break;
            }
        }
    }
}