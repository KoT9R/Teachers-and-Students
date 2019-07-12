//
// Created by Denis on 2019-05-28.
//

#include "helper.h"
#include "human.h"

#ifndef TEACHERS_AND_STUDENTS_BADSTUDENT_H
#define TEACHERS_AND_STUDENTS_BADSTUDENT_H


class badStudent: public Human {
public:
    badStudent();
    badStudent(std::string &nameIn);
    std::vector <ans_task> ResolveTask(const std::string &filename);
};


#endif //TEACHERS_AND_STUDENTS_BADSTUDENT_H
