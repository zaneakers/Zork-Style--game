#include <iostream>
#include <string>

// Define the Room class
class Room {
public:
    std::string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;

    Room(std::string desc) : description(desc), north(NULL), south(NULL), east(NULL), west(NULL) {}
};

// Function to handle player input
void handleInput(std::string input, Room*& currentRoom) {
    if (input == "go north" && currentRoom->north != NULL) {
        currentRoom = currentRoom->north;
    }
    else if (input == "go south" && currentRoom->south != NULL) {
        currentRoom = currentRoom->south;
    }
    else if (input == "go east" && currentRoom->east != NULL) {
        currentRoom = currentRoom->east;
    }
    else if (input == "go west" && currentRoom->west != NULL) {
        currentRoom = currentRoom->west;
    }
    else {
        std::cout << "You can't go that way.\n";
    }
}

int main() {
    // Create rooms
    Room* room1 = new Room("You are in room 1.");
    Room* room2 = new Room("You are in room 2.");
    room1->north = room2;  // Room 2 is north of Room 1
    room2->south = room1;  // Room 1 is south of Room 2

    Room* currentRoom = room1;

    // Game loop
    while (true) {
        std::cout << currentRoom->description << "\n";
        std::string input;
        std::getline(std::cin, input);
        handleInput(input, currentRoom);
    }

    delete room1;
    delete room2;

    return 0;
}
