// first.c XCB Tutorial

#include <stdio.h>

#include <xcb/xcb.h>

int main(void) {
    xcb_connection_t *c;
    xcb_screen_t *screen;
    int screen_nbr;
    xcb_screen_iterator_t iter;

    c = xcb_connect(NULL, &screen_nbr);
    iter = xcb_setup_roots_iterator (xcb_get_setup(c));
    
    for(; iter.rem; --screen_nbr, xcb_screen_next (&iter))
        if(screen_nbr == 0) {
            screen = iter.data;
            break;
        }

    printf("\n");
    printf("Informations of screen %d:\n", screen->root);
    printf("    width.........: %d\n", screen->width_in_pixels);
    printf("    height........: %d\n", screen->height_in_pixels);
    printf("    white pixel...: %d\n", screen->white_pixel);
    printf("    black pixel...: %d\n", screen->black_pixel);

    return 0;
}