//
// Created by Denis on 2019-05-04.
//

#include <cmath>
#include "helper.h"

#ifndef TEACHERS_AND_STUDENTS_EXERSIZE_H
#define TEACHERS_AND_STUDENTS_EXERSIZE_H



class exersize {
public:
    exersize(int const &size);
    std::vector <expression> GetTask() const;
    std::vector <ans_task> GetAns() const ;
    std::multimap <expression, ans_task> &GetHashTable();
    void WriteToFile (const std::string &fileExpres, const std::string &fileAns);
    ~exersize();
private:
    std::multimap <expression, ans_task> taskAndAnswers;
};

bool operator > (const std::multimap <expression, ans_task> &first, const std::multimap <expression, ans_task> &second);
bool operator < (const std::multimap <expression, ans_task> &first, const std::multimap <expression, ans_task> &second);

std::vector<double> Solving_Equations(const expression &reference, NUMBROOTS *solves);



#endif //TEACHERS_AND_STUDENTS_EXERSIZE_H
