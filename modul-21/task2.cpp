#include <iostream>
#include <vector>
#include <string>

enum RoomType {
    LIVING,
    CHILDREN,
    BEDROOM,
    KITCHEN,
    BATHROOM
};

enum BuildingType {
    HOUSE,
    GARAGE,
    BARN,
    BATHHOUSE
};

struct Room {
    RoomType type;
    double area{0.0};
};

struct Floor {
    double ceilingHeight{0.0};
    std::vector<Room> rooms;
};


struct Building {
    BuildingType type;
    double area{0.0};
    
 
    bool hasOven{false}; 
    std::vector<Floor> floors;
};

struct Plot {
    int number{0};
    double totalArea{0.0};
    std::vector<Building> buildings;
};

RoomType inputRoomType() {
    std::cout << "Choose room type (0 - Living, 1 - Children, 2 - Bedroom, 3 - Kitchen, 4 - Bathroom): ";
    int choice{0};
    std::cin >> choice;
    return static_cast<RoomType>(choice);
}

BuildingType inputBuildingType() {
    std::cout << "Choose building type (0 - House, 1 - Garage, 2 - Barn, 3 - Bathhouse): ";
    int choice{0};
    std::cin >> choice;
    return static_cast<BuildingType>(choice);
}

int main() 
{
    int totalPlots{0};
    std::cout << "=== VILLAGE MODEL GENERATOR ===" << std::endl;
    std::cout << "Enter total number of plots in the village: ";
    std::cin >> totalPlots;

    std::vector<Plot> village;
    double totalVillageArea{0.0};
    double totalBuildingsArea{0.0};

   
    for (int i = 0; i < totalPlots; ++i) {
        Plot currentPlot;
        std::cout << "\n--- Plot #" << i + 1 << " ---" << std::endl;
        std::cout << "Enter plot number: ";
        std::cin >> currentPlot.number;
        std::cout << "Enter total plot area (sq. meters): ";
        std::cin >> currentPlot.totalArea;
        totalVillageArea += currentPlot.totalArea;

        int buildingsCount{0};
        std::cout << "Enter number of buildings on this plot: ";
        std::cin >> buildingsCount;

        for (int j = 0; j < buildingsCount; ++j) {
            Building currentBuilding;
            std::cout << "  Building #" << j + 1 << ":" << std::endl;
            currentBuilding.type = inputBuildingType();
            std::cout << "  Enter building area: ";
            std::cin >> currentBuilding.area;
            totalBuildingsArea += currentBuilding.area;

     
            if (currentBuilding.type == HOUSE || currentBuilding.type == BATHHOUSE) {
                std::cout << "  Does it have an oven with a pipe? (1 - Yes, 0 - No): ";
                int ovenChoice{0};
                std::cin >> ovenChoice;
                currentBuilding.hasOven = (ovenChoice == 1);
            }

            if (currentBuilding.type == HOUSE) {
                int floorsCount{0};
                std::cout << "  Enter number of floors (1-3): ";
                std::cin >> floorsCount;

                for (int f = 0; f < floorsCount; ++f) {
                    Floor currentFloor;
                    std::cout << "    Floor #" << f + 1 << ":" << std::endl;
                    std::cout << "    Enter ceiling height: ";
                    std::cin >> currentFloor.ceilingHeight;

                    int roomsCount{0};
                    std::cout << "    Enter number of rooms (2-4): ";
                    std::cin >> roomsCount;

                    for (int r = 0; r < roomsCount; ++r) {
                        Room currentRoom;
                        std::cout << "      Room #" << r + 1 << ":" << std::endl;
                        currentRoom.type = inputRoomType();
                        std::cout << "      Enter room area: ";
                        std::cin >> currentRoom.area;
                        currentFloor.rooms.push_back(currentRoom);
                    }
                    currentBuilding.floors.push_back(currentFloor);
                }
            }
            currentPlot.buildings.push_back(currentBuilding);
        }
        village.push_back(currentPlot);
    }

  
    std::cout << "\n=== RESULTS ===" << std::endl;
    std::cout << "Total village area: " << totalVillageArea << " sq. m." << std::endl;
    std::cout << "Total buildings area: " << totalBuildingsArea << " sq. m." << std::endl;
    
    if (totalVillageArea > 0) {
        double percentage = (totalBuildingsArea / totalVillageArea) * 100.0;
        std::cout << "Percentage of land occupied by buildings: " << percentage << "%" << std::endl;
    }

    return 0;
}
