#include <iostream>
#include "CApplication.h"


int main()
{
    CApplication app ( CInterface ( std::cin, std::cout ));
    return app.run();
}
