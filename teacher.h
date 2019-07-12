//
// Created by Denis on 2019-05-29.
//

#include <queue>
#include "helper.h"
#include "human.h"
#include "exersize.h"

#ifndef TEACHERS_AND_STUDENTS_TEACHER_H
#define TEACHERS_AND_STUDENTS_TEACHER_H


class teacher: public Human {
public:
    teacher();
    teacher(std::string &nameIn);
    void CheckWorks(std::queue <sol_student>  &solutionOfStudents, exersize &task);
    bool CheckIsInTheTable(sol_student const& student);
    void ShowTablePerfomanceStudents();
    teacher& operator +=(sol_student const &student);
    std::vector <ans_task> ResolveTask (const std::string &filename);
	teacher& AddQuantityCorectAns(sol_student const& student, int quantity);
private:
    std::multimap <std::string, size_t> perfomanceOfStudents;
};



#endif //TEACHERS_AND_STUDENTS_TEACHER_H
