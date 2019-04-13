// second.c XCB Tutorial

#include <unistd.h>

#include <xcb/xcb.h>

int main(void) {
    xcb_connection_t *c;
    xcb_screen_t *screen;
    xcb_window_t win;

    c = xcb_connect(NULL, NULL);

    screen = xcb_setup_roots_iterator(xcb_get_setup (c)).data;

    win = xcb_generate_id(c);

    xcb_create_window(c,
                      XCB_COPY_FROM_PARENT,
                      win,
                      screen->root,
                      0, 0,
                      150, 150,
                      10,
                      XCB_WINDOW_CLASS_INPUT_OUTPUT,
                      screen->root_visual,
                      0, NULL);

    xcb_map_window(c, win);

    xcb_flush(c);

    pause();

    return 0;
}