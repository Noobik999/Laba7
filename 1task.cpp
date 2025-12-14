#include <iostream>
#include "functions_of_laba7.h"
int main() {
    std::string filename = "1stTask.txt";
    std::vector<std::string> data = {"Троллейбус, который идёт на восток!"};
    saveToFile_1(filename, data);
    return 0;}