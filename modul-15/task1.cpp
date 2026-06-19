#include <iostream>
#include <cstring>

int main()
{
    double speed = 0.0;
    double delta = 0.0;
    char speed_str[50];

    do{
        std::cout << "Speed delta: ";
        std::cin >> delta;

        speed += delta;

        if(speed > 150.0) speed = 150.0;

        if(speed <= 0.01) speed = 0.0;

        //printf("Speed: %.1lf km/h", speed); На мой взгляд так бы было лучше

        std::sprintf(speed_str, "Speed: %.1f", speed);
        std::cout << speed_str << std::endl;

    } while(speed > 0.01);

    return 0;
}