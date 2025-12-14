#include <iostream>
#include "functions_of_laba7.h"
#include <vector>
int main() {
    std::vector<Book> outData;
    loadFromFile_2("2ndTask.txt", outData);
    for (const auto& i : outData) {
        std::cout<<"Название книги: "<<i.Title<<", "<<"Автор: "<<i.Author<<", "<<"Год издания: "<<i.Year<<std::endl;
    }
    return 0;}