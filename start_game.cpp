#include "game.h"


int main() {
    Game game;
    while(game.isRunning()) {

        // Update
        game.update();

        //Render
        game.render();

        //Drawing

    }

    return 0;
}
