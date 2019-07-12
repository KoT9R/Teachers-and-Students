//
// Created by Denis on 2019-05-04.
//

#include "human.h"

#ifndef TEACHERS_AND_STUDENTS_GOODSTUDENT_H
#define TEACHERS_AND_STUDENTS_GOODSTUDENT_H



class goodStudent: public Human{
public:
    goodStudent();
    goodStudent(std::string &nameIn);
    std::vector <ans_task> ResolveTask (const std::string &filename);
};


#endif //TEACHERS_AND_STUDENTS_GOODSTUDENT_H
