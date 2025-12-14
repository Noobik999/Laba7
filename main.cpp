#include <iostream>
#include "functions_of_laba7.h"
int main() {
    std::map<std::string, std::vector<Student>> outData;
    loadFromFile_3("3rdTask.txt", outData);
    for (const auto& group : outData) {
        std::cout<<"Группа студента: "<<group.first<<std::endl;
        for (const auto& nameyear : group.second) {
            std::cout<<"Имя студента: "<<nameyear.Name<<", "<<"Год рождения студента: "<<nameyear.Year<<", ";
            for (const auto& marks : nameyear.RecordBook) {
                std::cout<<"Предмет и оценка: "<<marks.first<<" - "<<marks.second<<std::endl;
            }
            std::cout<<std::endl;
        }
    }
    return 0;}