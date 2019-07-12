//
// Created by Denis on 2019-05-04.
//
#include "helper.h"

#ifndef TEACHERS_AND_STUDENTS_HUMAN_H
#define TEACHERS_AND_STUDENTS_HUMAN_H

#define LETTER_A 65
#define NAME_SIZE 10

class Human {
public:
    Human ();
    Human (std::string name);
    virtual std::string GetFullName () const;
    virtual std::vector <ans_task> ResolveTask(const std::string &filename) = 0;
private:
    std::string name;
};

std::vector <Human *> GenerateStudents(size_t size);

#endif //TEACHERS_AND_STUDENTS_HUMAN_H
