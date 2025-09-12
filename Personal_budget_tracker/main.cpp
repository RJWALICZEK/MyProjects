#include <iostream>
#include <vector>
#include <string>
#include <cctype>

struct Data{
    std::string title;
    std::string date;
    float value;
    
};
void addData(std::vector<Data>&transaction);
void printData(std::vector<Data>&transaction,int choice);
void summary(std::vector<Data>&transaction);
bool dataValidate(const std::string &date);

int main() {

    unsigned int choice = 0;
    std::vector<Data>transaction;

    while(true) {
        std::cout << "\n\tMENU\n1.Add transaction\n2.List transaction\n3.Show summary\n0.Exit\n>>";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                addData(transaction);
                break;
            }
            case 2: {
                std::cout <<"\n\tTRANSACTION\n1.Print incomes\n2.Print expenses\n3.Print all\n>>";
                std::cin >> choice;
                printData(transaction, choice);
                break;
            }
            case 3: {
                summary(transaction);
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
    return 0;
}

void addData(std::vector<Data>&transaction) {
    Data newData;
    std::string date; 
    std::cout << "\nEnter title : ";
    std::cin.ignore();
    std::getline(std::cin, newData.title);
    std::cout << "Enter income/expense : ";
    std::cin >> newData.value;
    do{
    std::cout << "Enter Date (dd-mm-yyyy): ";
    std::cin >> date;
        if(!dataValidate(date)) {
            std::cerr << "Invalid data format! Try again...";
        } 
    }while(!dataValidate(date));
        newData.date = date;
    transaction.push_back(newData);

    std::cout << "\n**************************************\n";

}
void printData(std::vector<Data>&transaction, int choice) {

    if(!transaction.empty()) {
            std::cout << "--------------------TRANSACTIONS-----------------------\n";
            for(auto i : transaction) {
                if(choice == 1 && i.value > 0){
                std::cout << "Title > " << i.title << "\n";
                std::cout << "Value : " << i.value << "\n";
                std::cout << "Date  : " << i.date << "\n";
                std::cout << ">>>>>>>>>>><<<<<<<<<<<\n";
                }
                else if(choice == 2 && i.value < 0){
                std::cout << "Title > " << i.title << "\n";
                std::cout << "Value : " << i.value << "\n";
                std::cout << "Date  : " << i.date << "\n";
                std::cout << ">>>>>>>>>>><<<<<<<<<<<\n";
                }
                else if(choice == 3) {
                    std::cout << "Title > " << i.title << "\n";
                std::cout << "Value : " << i.value << "\n";
                std::cout << "Date  : " << i.date << "\n";
                std::cout << ">>>>>>>>>>><<<<<<<<<<<\n";
                }
        }    
    }
     else {
        std::cerr << "\n**Memory is empty**\n";
    }
     std::cout << "\n**************************************\n";
}
void summary(std::vector<Data>&transaction) {
    
     if(!transaction.empty()) {
        
    float incomes = 0;
    float expenses = 0;
    float summary = 0;
    for (auto i : transaction) {
        if(i.value > 0) {
            incomes += i.value;
        }
        else {
            expenses += i.value;
        }
        summary += i.value;
    }
    std::cout << "-----------------------SUMMARY-------------------------\n";
    std::cout << "Incomes : " << incomes << "\nExpenses : " << expenses << "\nSummary : " << summary << "\n";
    }
     else {
        std::cerr << "\n**Memory is empty**\n";
    }
     std::cout << "\n**************************************\n";
}
bool dataValidate(const std::string &date) {

    if(date.size() != 10) {
        return false;
    }
    else if(!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[3]) || !isdigit(date[4]) || !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9])) {
        return false;
    }
    else if(date[2] != '-' || date[5] != '-') {
        return false;
    }
    else {
        return true;
    }
}
