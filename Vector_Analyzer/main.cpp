#include <iostream>
#include <vector>

void enterValues(std::vector<int>&values);
void clearData(std::vector<int>&values);

int main() {
    std::vector<int>values;
    unsigned int choice = 0;
    while (true) {
        std::cout << "\nMemory : ";
        if (!values.empty()) {
            for (int i : values) {
                std::cout << i << " ";
            }
        }
        else {
            std::cout << " empty";
        }
        std::cout << "\n\n\tMENU\n1.Enter values\n2.Analyze data\n3.Analyze specyfic value\n4.Sort ASC\n"
        "5.Sort DESC\n6.Clear data\n0.Exit\n>> ";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                enterValues(values);
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                clearData(values);
                break;
            }
            case 0: {
                return 0;
            }
        }
    }
    return 0;
}

void enterValues(std::vector<int>&values) {
    unsigned int size = 0;
    unsigned int data = 0;
    std::cout << "Enter vector size : ";
    std::cin >> size;
    std::cout << "Enter values : \n";
    for(int i = 0; i < size; i++) {
        std::cout << i+1 << " > ";
        std::cin >> data;
        values.push_back(data);
    }
    std::cout << "\n**************************************\n";
}
void clearData(std::vector<int>&values) {
    if(!values.empty())
    {
        values.clear();
    }
    else {
        std::cerr << "**Memory is empty**";
    }
    std::cout << "\n**************************************\n";
}