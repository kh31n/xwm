#include <xcb/xcb.h>

int main(void) {
    xcb_connection *c;

    c = xcb_connect(NULL, NULL);

    return 0;
}