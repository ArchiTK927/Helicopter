#include <headers/window.h>

int main() {

    graphics::Window window(1024, 480, "Helicopter");

    while (!window.closed()) {

        window.clean();
        window.update();

    }

    return 0;

}