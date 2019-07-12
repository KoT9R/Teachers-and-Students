//
// Created by Denis on 2019-05-04.
//

#include "human.h"
#include "badStudent.h"
#include "middleStudent.h"
#include "goodStudent.h"
#include <ctime>




Human::Human() {
    char* word = new char [NAME_SIZE];
    for (size_t i = 0; i != NAME_SIZE - 1; ++i){
        word[i] = LETTER_A + rand() % 15;
    }
	word[NAME_SIZE - 1] = '\0';
    name = word;
    delete [] word;
}
Human::Human(std::string name):name(name)
{}

std::string Human::GetFullName() const{
    return name;
}

std::vector <Human *> GenerateStudents(size_t size){
    std::vector <Human *> studentsOfUniversity;
	srand((unsigned)time(0));
    for (size_t i = 0; i != size; ++i){
		badStudent* third = new badStudent;
        middleStudent* second = new middleStudent;
        goodStudent* first = new goodStudent;
        Human *a;
        switch (rand() % 3){
            case 0:
                a = first;
                studentsOfUniversity.push_back(a);
                break;
            case 1:
                a = second;
                studentsOfUniversity.push_back(a);
                break;
            case 2:
                a = third;
                studentsOfUniversity.push_back(a);
                break;
        }
    }
    return studentsOfUniversity;
}


