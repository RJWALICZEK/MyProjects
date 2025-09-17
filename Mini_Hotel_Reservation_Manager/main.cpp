#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

struct Room{
    std::string clientName;
    int number;
    bool isBooked;
    std::string description;
};

void roomsList(std::vector<Room>&rooms);
void roomsInfo(const std::vector<Room>&rooms, int option);
void bookRoom(std::vector<Room>&rooms);
void cancelBooking(std::vector<Room>&rooms);

int main() {

    std::vector<Room> rooms;
    roomsList(rooms);
    int choice;
    while(true) {
        std::cout << "\tReservation Manager\n1.View rooms info\n2. Book room\n3.\n0.Exit\n>>";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                roomsInfo(rooms, 1);
                break;
            }
            case 2:{
                bookRoom(rooms);
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                std::cerr << "Wrong choice\n***************************************\n";
            }
        }
    }


    return 9;
}

void roomsInfo(const std::vector<Room>&rooms, int option) {
    for(auto i : rooms) {
        if(option == 2 && !i.isBooked) {

            std::cout << i.number << "\n";
            std::cout << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << i.clientName << "\n\n";

        }
        else if(option == 1) {
            std::cout << i.number << "\n";
            std::cout << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << i.clientName << "\n\n";
        }
        else if(option == 3 && i.isBooked) {
            std::cout << i.number << "\n";
            std::cout << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << i.clientName << "\n\n";
        }
    }
    std::cout << "\n******************Press button*********************\n\n";
    getchar();
}
void roomsList(std::vector<Room>&rooms) {
    Room newRoom;
    for (int i = 0; i<10; i++) {
        newRoom.clientName = "None";
        newRoom.number = i+1;   
        newRoom.isBooked = false;
        rooms.push_back(newRoom);
    }
    
}
void bookRoom(std::vector<Room>&rooms){
    static int option = 2;
    roomsInfo(rooms, option);
    int roomNumber;
    std::cout << "Select room\n >>";

    std::cin >> roomNumber;
    roomNumber = roomNumber - 1;


    if(!rooms[roomNumber].isBooked && (roomNumber >= 0 && roomNumber <rooms.size())) {
        std::string name;
        std::string description;
        std::cout << "Enter client name : \n >>";
        std::cin.ignore();
        std::getline(std::cin, name);
        
        std::cout << "Add descryption\n>>";
        std::cin.ignore();
        std::getline(std::cin, description);
        rooms[roomNumber].clientName = name;
        rooms[roomNumber].description = description;
        rooms[roomNumber].isBooked = true;
    }
    else {
        std::cout << "Wrong room number, or room is booked.";
    }
     std::cout << "\n******************Press button*********************\n\n";
    getchar();


}
void cancelBooking(std::vector<Room>&rooms) {

}