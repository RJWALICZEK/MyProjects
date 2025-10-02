#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <filesystem>

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
void saveToFile(const std::vector<Room>&rooms);
void loadFromFile(std::vector<Room> &rooms);
void showHotelSummary(std::vector<Room>&rooms);

int main() {

    std::vector<Room> rooms;
    roomsList(rooms);
    int choice;
    while(true) {
        showHotelSummary(rooms);
        std::cout << "\n\tReservation Manager\n1.View rooms info\n2. Book room\n3.Cancel Booking\n4.Save room status\n5.Load room status\n0.Exit\n>>";
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
            case 4: {
                saveToFile(rooms);
                break;
            }
            case 5: {
                loadFromFile(rooms);
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
    std::cout << "\n****************** Rooms info *********************\n\n";
    for(auto i : rooms) {
        if(option == 2 && !i.isBooked) {

            std::cout << "Room number : " << i.number << "\n";
            std::cout << "Status : " << (i.isBooked ? "Booked\n\n" : "Free\n\n" );


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
        std::cout << "\nWrong room number, or room is free.";
    }
     std::cout << "\n******************Press button*********************\n\n";
    getchar();
}
void saveToFile(const std::vector<Room> &rooms) {
    if(!std::filesystem::exists("data")) {
        std::filesystem::create_directories("data");
        std::cout << "\ndirectory 'data' created\n";
    }
    std::ofstream file("data/room_state.csv");
    if(!file) {
        std::cerr << "\n******************Can't find file!*********************\n\n";
        return;
    }
    for(auto r : rooms) {
        file << r.number << ";" << r.isBooked << ";" << r.clientName << ";" << r.description <<"\n";
    }
    file.close();
    std::cout << "Room status save succesfull!\n";
    getchar();

}
void loadFromFile(std::vector<Room> &rooms) {
    int choice = 0;
    if( !rooms.empty()) {
        std::cout << "This operation overwrite actual rooms status!\n1.Continue\n2.Cancel\n>>";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                break;
            }
            case 2: {
                return;
            }

        }
    }
    std::ifstream file("data/room_state.csv");
    if(!file) {
        std::cerr << "\n*********************Can't find file!*********************\n\n";
        return;
    }
    rooms.clear();
    Room temp;
    std::string line;
    while(std::getline(file, line)) {
        
        size_t pos = 0;
        size_t next;

       

        next = line.find(";");
        if(next == std::string::npos) continue;
        temp.number = stoi(line.substr(pos, next));
        pos = next + 1;
        next = line.find(";", pos);
        if(next == std::string::npos) continue;
        temp.isBooked = stoi(line.substr(pos, next - pos));
        pos = next + 1;
        next = line.find(";", pos);
        if(next == std::string::npos) continue;
        temp.clientName = line.substr(pos, next - pos);
        pos = next + 1;
        temp.description = line.substr(pos);

   
        

         

        rooms.push_back(temp);
    }
    file.close();
    std::cout << "Room status load succesfull!\n";
    getchar();

}
void showHotelSummary(std::vector<Room>&rooms) {
    unsigned int free = 0;
    unsigned int booked = 0;
    unsigned int sumOfRooms = 0;
    for(auto r : rooms) {
        if(r.isBooked) {
            booked++;
        }
        else {
            free++;
        }
        sumOfRooms++;
    }
    std::cout << "\n| Rooms : " << sumOfRooms << " | Booked : " << booked << " | free : " << free << "\n";
}