//
// Created by Denis on 2019-05-24.
//

#include <map>
#include <vector>
#include <iostream>

#ifndef TEACHERS_AND_STUDENTS_HELPER_H
#define TEACHERS_AND_STUDENTS_HELPER_H

#define NUMBER_TASK 10
#define NUMBER_STUDENT 10

typedef enum
{
    ZERO,
    ONE,
    TWO,
    UNLIMITED
}NUMBROOTS;

struct expression {

    double a;
    double b;
    double c;
};

struct ans_task{
    NUMBROOTS quantity_ans;
    std::vector <double> ans_expression;
};

struct sol_student{
    std::string nameSt;
    std::multimap <expression, ans_task> solution;

/*    expression exersize;
    ans_task solution;*/
};


expression ReadExersize(std::fstream &in, bool &endOfFile);
std::vector <expression> ReadAllExersize(const std::string &filename);
bool operator > (const sol_student &first, const sol_student &second);
bool operator < (const sol_student &first, const sol_student &second);
bool operator > (const ans_task &first, const ans_task &second);
bool operator < (const ans_task &first, const ans_task &second);
bool operator > (const expression& first, const expression& second);
bool operator < (const expression& first, const expression& second);
bool operator == (const expression& first, const expression& second);
bool operator != (const std::vector <double>& first, const std::vector <double>& second);
#endif //TEACHERS_AND_STUDENTS_HELPER_H
