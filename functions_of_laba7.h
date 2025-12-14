#ifndef LABA7_FUNCTIONS_OF_LABA7_H
#define LABA7_FUNCTIONS_OF_LABA7_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

//Структуры данных
struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;

//Сохраняющая для 1 задания
void saveToFile_1(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream out;
    out.open(filename);
    for (std::string letter : data)
    {
        out<<letter<< std::endl;
    }
    out.close();
    std::cout<<"Информация была успешно загружена в файл";
}
//Загружающая функция для 1 задания
void loadFromFile_1(const std::string& filename, std::vector<std::string>& outData) {
    std::string letter;
    std::ifstream in(filename);
    if (in.is_open()) {
        while (std::getline(in, letter)) {
            outData.push_back(letter);
        }
    }
    in.close();
}

//Сохраняющая функция для 2 задания
void saveToFile_2(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream file(filename);
    for (const auto& word : data) {
        file<<word.Author<<'\n';
        file<<word.Title<<'\n';
        file<<word.Year<<'\n';
    }
    file.close();
    std::cout<<"Информация была успешно загружена в файл";
}
//Загружающая функция для 2 задания
void loadFromFile_2(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream file(filename);
    outData.clear();
    std::string author, title, year;
    while (getline(file, author) and (getline(file, title)) and (getline(file,year))) {
        int intyear = std::stoi(year);
        outData.push_back({author, title, intyear});
    }
    file.close();
}

//Сохраняющая функция для 3 задания
void saveToFile_3(const std::string& filename, const Groups& groups) {
    std::ofstream file(filename);
    for (const auto& group : groups) {
        file<<group.first<<'\n';
        for (const auto& student : group.second) {
            file<<student.Name<<" "<<student.Year<<'\n';
            for (const auto& records : student.RecordBook) {
                file<<records.first<<" "<<records.second<<", ";
            }
            file<<"\n";
        }
        file << "---\n";
    }
    file.close();
    std::cout<<"Информация была успешно загружена в файл";
}
//Загружающая функция для 3 задания
void loadFromFile_3(const std::string& filename, Groups& outGroups) {
    //Функция будет работать только при записи файлов через функцию выше
    outGroups.clear();
    std::ifstream file(filename);
    std::string nameyear, submark;
    std::string group, name, year1, subjects, marks1;
    std::map<std::string, Score> subject_and_mark;
    int year, marks2;
    Score marks;

    while (std::getline(file, group)) {
        subject_and_mark.clear();
        while (std::getline(file, nameyear) and nameyear != "---") {
            submark.clear();
            if (!group.empty() and nameyear != "---") {
                std::stringstream nameyear_razd(nameyear);//Созда]м переменную nameyear_raz, чтобы взять и имя и год по разным значениям и записать их сразу по нужным переменным
                nameyear_razd>>name>>year;
                std::getline(file, submark);
                int zapcount = std::count(submark.begin(), submark.end(), ',');
                for (int i = 0; i < zapcount; i++) {
                    int first_ind = 0;
                    int second_ind;
                    std::string mark_and_subject;
                    std::stringstream submark1(submark);
                    std::getline(submark1, mark_and_subject, ',');
                    second_ind = submark.find(', ');
                    submark.erase(first_ind, second_ind+4);
                    std::stringstream mark_and_subject_razd(mark_and_subject);
                    mark_and_subject_razd>>subjects>>marks1;
                    marks2 = stoi(marks1);
                    marks = static_cast<Score>(marks2);
                    subject_and_mark.insert({subjects, marks});
                }
                outGroups[group].push_back({name, year, subject_and_mark});
                subject_and_mark.clear();
            }
        }
            group.clear();

    }
    file.close();
}
#endif //LABA7_FUNCTIONS_OF_LABA7_H