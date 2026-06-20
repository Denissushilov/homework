#include <iostream>
#include <string>
#include <sstream>


enum switches 
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

int main()
{
    int switches_state = 0;
    int color_temp = 5000;

    for (int hour_total = 0; hour_total < 48; ++hour_total) {
        int hour = hour_total % 24;

  
        if (hour == 0) {
            color_temp = 5000;
        }

        if (hour >= 16 && hour <= 20) {
            color_temp = 5000 - (hour - 16) * 575;
        } else if (hour > 20) {
            color_temp = 2700;
        }

        std::cout << "[" << (hour < 10 ? "0" : "") << hour << ":00] "
                  << "Temperature inside, temperature outside, movement, lights:\n";
        
        std::string input_buffer;
        std::getline(std::cin, input_buffer);

        if (input_buffer.empty()) {
            std::getline(std::cin, input_buffer);
        }

        std::stringstream ss(input_buffer);
        double temp_inside = 0, temp_outside = 0;
        std::string movement, lights_inside_input;

        if (!(ss >> temp_inside >> temp_outside >> movement >> lights_inside_input)) {
            std::cout << "Error: Invalid input format! Try again.\n";
            --hour_total;
            continue;
        }

        int prev_state = switches_state;

        if (temp_outside < 0) {
            switches_state |= WATER_PIPE_HEATING;
        } else if (temp_outside > 5) {
            switches_state &= ~WATER_PIPE_HEATING;
        }


        if (temp_inside < 22) {
            switches_state |= HEATERS;
        } else if (temp_inside >= 25) {
            switches_state &= ~HEATERS;
        }

        if (temp_inside >= 30) {
            switches_state |= CONDITIONER;
        } else if (temp_inside <= 25) {
            switches_state &= ~CONDITIONER;
        }

        bool is_evening = (hour >= 16 || hour < 5);
        if (is_evening && movement == "yes") {
            switches_state |= LIGHTS_OUTSIDE;
        } else {
            switches_state &= ~LIGHTS_OUTSIDE;
        }

        if (lights_inside_input == "on") {
            switches_state |= LIGHTS_INSIDE;
        } else {
            switches_state &= ~LIGHTS_INSIDE;
        }

  
        if ((switches_state & WATER_PIPE_HEATING) != (prev_state & WATER_PIPE_HEATING)) {
            std::cout << "Water pipe heating " << ((switches_state & WATER_PIPE_HEATING) ? "ON!" : "OFF!") << "\n";
        }
        if ((switches_state & HEATERS) != (prev_state & HEATERS)) {
            std::cout << "Heaters " << ((switches_state & HEATERS) ? "ON!" : "OFF!") << "\n";
        }
        if ((switches_state & CONDITIONER) != (prev_state & CONDITIONER)) {
            std::cout << "Conditioner " << ((switches_state & CONDITIONER) ? "ON!" : "OFF!") << "\n";
        }
        if ((switches_state & LIGHTS_OUTSIDE) != (prev_state & LIGHTS_OUTSIDE)) {
            std::cout << "Outside lights " << ((switches_state & LIGHTS_OUTSIDE) ? "ON!" : "OFF!") << "\n";
        }
        if ((switches_state & LIGHTS_INSIDE) != (prev_state & LIGHTS_INSIDE)) {
            std::cout << "Lights " << ((switches_state & LIGHTS_INSIDE) ? "ON!" : "OFF!") << "\n";
        }

        if (switches_state & LIGHTS_INSIDE) {
            std::cout << "Color temperature: " << color_temp << "K\n";
        }
    }

    return 0;
}
