#include "Snake.hh"
#include "Map.hh"
#include "Apple.hh"

int main( void )
{
    Snake nils;
    Apple apple(nils);
    Map nils_garden;
    char step = 'd';

    nils_garden.refresh(nils, apple);
    std::cout << nils_garden << std::endl;

    while (step != 'p') {
        std::cin >> step;
        std::cout << step << std::endl;
        nils.run(step, apple);
        nils_garden.refresh(nils, apple);
        std::cout << nils_garden << std::endl;
    }
    std::cout<< "Your score is " << nils.get_snake_len() - 3 << std::endl;
    return 0;
}

/* Suite :
*   Colisions
*   live
*   end of game
*   presentation end screen and start screen
*/
