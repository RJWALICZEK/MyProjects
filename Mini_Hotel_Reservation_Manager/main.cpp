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
        std::cout << "\tReservation Manager\n1.View rooms info\n2. Book room\n3.Cancel Booking\n0.Exit\n>>";
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
            case 3:{
                cancelBooking(rooms);
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

            std::cout << "Room number : " << i.number << "\n";
            std::cout << "Status : " << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << "Client name : " << i.clientName << "\n";
            std::cout << "Description : " << i.description << "\n\n";

        }
        else if(option == 1) {
            std::cout  << "Room number : " << i.number << "\n";
            std::cout << "Status : " << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << "Client name : "<< i.clientName << "\n";
            std::cout  << "Description : "<< i.description << "\n\n";
        }
        else if(option == 3 && i.isBooked) {
            std::cout << "Room number : "  << i.number << "\n";
            std::cout << "Status : " << (i.isBooked ? "Booked\n" : "Free\n" );
            std::cout << "Client name : "<< i.clientName << "\n";
            std::cout  << "Description : "<< i.description << "\n\n";
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
        newRoom.description = "Room is empty";
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


    if((roomNumber >= 0 && roomNumber <rooms.size()) && !rooms[roomNumber].isBooked ) {
        std::string name;
        std::string description;
        std::cout << "Enter client name : \n >>";
        std::cin.ignore();
        std::getline(std::cin, name);
        
        std::cout << "Add description\n>>";
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
    static int option = 3;
    int roomNumber;
    roomsInfo(rooms, option);
    std::cout << "Select room\n>>";
    std::cin >> roomNumber;
    roomNumber -= 1;
    if((roomNumber >= 0 && roomNumber <rooms.size()) && rooms[roomNumber].isBooked)
    {
        rooms[roomNumber].clientName = "None";
        rooms[roomNumber].description = "Room is empty";
        rooms[roomNumber].isBooked = false;
    }
     else {
        std::cout << "Wrong room number, or room is free.";
    }
     std::cout << "\n******************Press button*********************\n\n";
    getchar();
}