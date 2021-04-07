#include "dragAndDrop.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void dessinerCarte(Rect r, ALLEGRO_BITMAP *image) {
    al_draw_bitmap(image, r.x, r.y, 0);
}

unsigned char clicDansRectangle(Rect r, int x, int y) {
    if(x >= r.x && x <= r.x+400 && y >= r.y && y <= r.y+400) {
        return 1;
    }
    return 0;
}

void replacerSiDebordement(Rect* rectangle) {
    if (rectangle->x < 0) { rectangle->x = 0; }
    if (rectangle->x + 400 > 800) { rectangle->x = 800-400; }
    if (rectangle->y < 0) { rectangle->y = 0; }
    if (rectangle->y + 400 > 800) { rectangle->y = 800-400; }
}


void repeindre(Rect rectangle, ALLEGRO_BITMAP *image) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    dessinerCarte(rectangle, image);
    al_flip_display();
}

void drapAndDrop(ALLEGRO_BITMAP *cards, ) {
    int fini = 0;
    int repeint = 0;
    int glisserDeposer = 0;
    int decalageXGlisserDeposer = 0;
    int decalageYGlisserDeposer = 0;
    Rect rectangle = {0};
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_BITMAP *image = NULL;
    unsigned char touchesEnfoncees[NB_TOUCHES_GEREES] = {0};
    assert(al_init());
    al_init_image_addon();
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());

    // Créations (al_create...())
    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);
    al_set_window_title(display, "TP2");
    timer = al_create_timer(1.0 / 40.0);
    if (timer == NULL) {
        al_destroy_display(display);
        exit(EXIT_FAILURE);
    }
    queue = al_create_event_queue();
    if (queue == NULL) {
        al_destroy_display(display);
        al_destroy_timer(timer);
        exit(EXIT_FAILURE);
    }
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    image = al_load_bitmap("../dick.png");
    rectangle.x = 800/2;
    rectangle.y = 800/2;

    repeindre(rectangle, image);

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
                    repeindre(rectangle, image);
                    repeint = 0;
                }
                break;
            }
        }
    }

    al_destroy_bitmap(image);
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}