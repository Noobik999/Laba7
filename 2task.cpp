#include <iostream>
#include "functions_of_laba7.h"
#include <vector>
int main() {
    std::vector<Book> library {
                    {"Stephen King","Joyland",2013},
                    {"Stephen King","Langoliers",1990},
                    {"Stephen King","IT",1986}
    };
    saveToFile_2("2ndTask.txt", library);
    return 0;
}