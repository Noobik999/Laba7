#include <iostream>
#include "functions_of_laba7.h"
int main() {
    std::vector<Student> students_of_11 {
                                {"Serafim", 2007, {{"Математика", Good}, {"Информатика", Excellent}}},
                                {"Nikita", 2007, {{"Математика", Excellent}, {"Информатика", Excellent}}}
    };
    std::vector<Student> students_of_12 {
                                {"Daria", 2007, {{"Математика", Satisfactorily}, {"Информатика", Good}}},
                                {"Nikita", 2007, {{"Математика", Good}, {"Информатика", Satisfactorily}}}
    };
    std::vector<Student> students_of_13 {
                                    {"Leonid", 2007, {{"Математика", Excellent}, {"Информатика", Satisfactorily}}},
                                    {"Kristina", 2007, {{"Математика", Good}, {"Информатика", Good}}}
    };
    std::vector<Student> students_of_14 {
                                    {"Maksim", 2007, {{"Математика", Good}, {"Информатика", Satisfactorily}}},
                                    {"Olga", 2007, {{"Математика", Excellent}, {"Информатика", Excellent}}}
    };
    std::vector<Student> students_of_15 {
                                    {"Arina", 2007, {{"Математика", Excellent}, {"Информатика", Good}}},
                                    {"Sofia", 2007, {{"Математика", Good}, {"Информатика", Excellent}}}
    };
    std::map<std::string, std::vector<Student>> Groups = {
        {"IU8-11", students_of_11},
        {"IU8-12", students_of_12},
        {"IU8-13", students_of_13},
        {"IU8-14", students_of_14},
        {"IU8-15", students_of_15},
    };
    saveToFile_3("3rdTask.txt", Groups);

    return 0;}