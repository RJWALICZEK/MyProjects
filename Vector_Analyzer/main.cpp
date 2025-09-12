#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void enterValues(std::vector<int>&values);
void clearData(std::vector<int>&values);
void viewInfo(const std::vector<int>&values);
int calculateSum(const std::vector<int>&values);
float calculateAverage(const std::vector<int>&values, int sum);
float calculateStandardDeviation(const std::vector<int>&values, const float avg);
void countAboveBelowAverage(const std::vector<int>&values, const float avg);
void printData(const std::vector<int>&values);
void findMinMax(const std::vector<int>&values);
void findValue(const std::vector<int>&values);
void sortASC(std::vector<int>&values);
void sortDESC(std::vector<int>&values);

int main() {
    std::vector<int>values;
    unsigned int choice = 0;
    while (true) {
        std::cout << "\nMemory : ";

        printData(values);
        
        std::cout << "\n\n\tMENU\n1.Enter values\n2.Analyze data\n3.Analyze specyfic value\n4.Sort ASC\n"
        "5.Sort DESC\n6.Clear data\n0.Exit\n>> ";
        std::cin >> choice;
        switch(choice) {
            case 1: {
                enterValues(values);
                break;
            }
            case 2: {
                viewInfo(values);
                break;
            }
            case 3: {
                findValue(values);
                break;
            }
            case 4: {
                sortASC(values);
                break;
            }
            case 5: {
                sortDESC(values);
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
        std::cerr << "\n**Memory is empty**\n";
    }
    std::cout << "\n**************************************\n";
}
void viewInfo(const std::vector<int>&values){
    if(!values.empty()) {
        unsigned const int sum = calculateSum(values);
        const float avg = calculateAverage(values, sum);
        std::cout << "\nsum > " << sum << "\nAverage > " << avg << "\n";
        findMinMax(values);
        countAboveBelowAverage(values, avg);
        std::cout << "\nStandardDeviation > " << calculateStandardDeviation(values, avg) << "\n";
    }
    else {
        std::cerr << "\n**Memory is empty**\n";
    }
     std::cout << "\n**************************************\n";
}
int calculateSum(const std::vector<int>&values){
    unsigned sum = 0;
    for (int i : values) {
        sum += i;
    }
    return sum;
}
float calculateAverage(const std::vector<int>&values, int sum){
    return (float)sum/(float)values.size();
}
void countAboveBelowAverage(const std::vector<int>&values, const float avg) {
    std::vector<int>above;
    std::vector<int>below;
    for(int i : values){
        if(avg < i) {
            above.push_back(i);
        }
        else {
            below.push_back(i);
        }
    }
    std::cout << "\nValues above average :" ;
    printData(above);
    std::cout << "\nValues below average :" ;
    printData(below);
}
float calculateStandardDeviation(const std::vector<int>&values, const float avg) {
    float standardDeviation = 0;
    for(int i : values) {
        standardDeviation += pow(i - avg, 2);
    }
    standardDeviation = sqrt(standardDeviation / values.size());
    return standardDeviation;
}
void printData(const std::vector<int>&values) {
    if (!values.empty()) {
            for (int i : values) {
                std::cout << i << " ";
            }
        }
        else {
            std::cout << " empty";
        }
}
void findMinMax(const std::vector<int>&values) {
    int min = values[0], max = values[0];
    for(int i : values) {
        if(max < i) {
            max = i;
        }
        if(min > i) {
            min = i;
        }
    }
    std::cout << "\nMinimal value > " << min << "\nMaximal value > " << max << "\n";
}

void findValue(const std::vector<int>&values) {
    if (!values.empty()) {
    int value = 0;
    unsigned int counter = 0;
    std::cout << "\n Enter value >> ";
    std::cin >> value;

    for(int i : values) {
        if(value == i) {
            counter ++;
        }
    }
    if (counter > 0) {
        std::cout << "\nSearching value found ! There is " << counter << " repetitions of this value.\n";
    }
    else {
        std::cerr << "\nNo value found\n";
    }
     }
    else {
        std::cerr << "\n**Memory is empty**\n";
    }
     std::cout << "\n**************************************\n";
}
void sortASC(std::vector<int>&values) {
    if (!values.empty()) {
   sort(values.begin(), values.end());
    }
   else {
        std::cerr << "\n**Memory is empty**\n";
   }
         std::cout << "\n**************************************\n";
}
void sortDESC(std::vector<int>&values) {
    if (!values.empty()) {
   sort(values.rbegin(), values.rend());
    }
   else {
        std::cerr << "\n**Memory is empty**\n";
   }
         std::cout << "\n**************************************\n";
}