#include <iostream>
#include "functions_of_laba7.h"
int main() {
    std::string filename = "1stTask.txt";
    std::vector<std::string> outData;
    loadFromFile_1(filename, outData);
    for (std::string letter : outData) {
        std::cout<<"Прочтённая строка из файла: "<<letter;
    }
    return 0;}