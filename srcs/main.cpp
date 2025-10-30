#include "Snake.hpp"
#include "Map.hpp"

int main( void )
{
    Snake nils;
    Map nils_garden(nils);
    char step = 'd';

    while (step != 'p') {
        std::cin >> step;
        std::cout << step << std::endl;
        nils.run(step);
        nils_garden.refresh(nils);
        std::cout << nils_garden << std::endl;
    }
    return 0;
}
