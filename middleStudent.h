//
// Created by Denis on 2019-05-06.
//

#include "helper.h"
#include "human.h"


#ifndef TEACHERS_AND_STUDENTS_MIDDLESTUDENT_H
#define TEACHERS_AND_STUDENTS_MIDDLESTUDENT_H

class middleStudent: public Human{
public:
    middleStudent();
    middleStudent(std::string &nameIn);
    std::vector <ans_task> ResolveTask(const std::string &filename);
};


#endif //TEACHERS_AND_STUDENTS_MIDDLESTUDENT_H
