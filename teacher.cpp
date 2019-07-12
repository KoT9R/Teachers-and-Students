//
// Created by Denis on 2019-05-29.
//

#include "teacher.h"
#include <fstream>

int Compare(exersize &correctAns, sol_student const &solutionOfStudent){
	int quanAns = 0;
	for (auto &j: solutionOfStudent.solution){
		auto i = correctAns.GetHashTable().find(j.first);
        if (j.second.ans_expression == i->second.ans_expression){ //
			quanAns++;
        }
    }
	return quanAns;
}

teacher::teacher():Human() {}

teacher::teacher(std::string &nameIn):Human(nameIn){}

bool teacher::CheckIsInTheTable(sol_student const &student) {
    auto search = perfomanceOfStudents.find(student.nameSt);
    if (search != perfomanceOfStudents.end()){
        return true;
    }else
    {
        return false;
    }
}

teacher& teacher::operator+=(sol_student const &student) {
    auto search = perfomanceOfStudents.find(student.nameSt);
    search->second += 1;
    return *this;
}

teacher& teacher::AddQuantityCorectAns(sol_student const& student, int quantity) {
	auto search = perfomanceOfStudents.find(student.nameSt);
	search->second += quantity;
	return *this;
}

void teacher::CheckWorks(std::queue <sol_student>  &solutionOfStudents, exersize &task){
	size_t size = solutionOfStudents.size();
	for (size_t i = 0; i != size; ++i) {
		int ansQuantity = Compare(task, solutionOfStudents.front());
		if (CheckIsInTheTable(solutionOfStudents.front())) {
			AddQuantityCorectAns(solutionOfStudents.front(), ansQuantity);
		}
		else {
			perfomanceOfStudents.insert(std::pair<std::string, size_t>
				(solutionOfStudents.front().nameSt, ansQuantity));
		}
		//if (!CheckIsInTheTable(solutionOfStudents.front())) {
		//	perfomanceOfStudents.insert(std::pair<std::string, size_t>
		//		(solutionOfStudents.front().nameSt, ansQuantity));
		//}
		solutionOfStudents.pop();
	}
}

void teacher::ShowTablePerfomanceStudents() {
	std::cout << "Quantity task:" << NUMBER_TASK << std::endl;
    std::cout<<"Name of Student" << "    " << "How many correct answers" << std::endl;
    for (auto &i : perfomanceOfStudents){
        std::cout << i.first << "                          " << i.second << std::endl;
    }
}

std::vector <ans_task> teacher::ResolveTask(const std::string &filename) {
    std::fstream in(filename);
    std::vector <ans_task> ans;
    ans_task partOfTask;
    NUMBROOTS solves;
    expression test;
    std::vector <double> ansExpression;
	bool endOfFile = false;

    while (!in.eof()){
        test = ReadExersize(in, endOfFile);
        if (endOfFile){
			in.close();
            return ans;
        }

        ansExpression = Solving_Equations(test, &solves);
        partOfTask.quantity_ans = solves;
        partOfTask.ans_expression = ansExpression;
        ans.push_back(partOfTask);
    }

    in.close();
    return ans;
}