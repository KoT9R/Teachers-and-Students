//
// Created by Denis on 2019-05-04.
//

#include "goodStudent.h"
#include "exersize.h"
#include <fstream>

goodStudent::goodStudent():Human() {}

goodStudent::goodStudent(std::string &nameIn):Human(nameIn){}

//ans_task SaveSolution(std::vector <double> const &ansExpression, NUMBROOTS const &solves){
//    ans_task partOfTask;
//    partOfTask.ans_expression = ansExpression;
//    partOfTask.quantity_ans = solves;
//    return partOfTask;
//}

std::vector <ans_task> goodStudent::ResolveTask(const std::string &filename) {
    std::fstream in(filename);
    std::vector <ans_task> ans;
    ans_task partOfTask;
    NUMBROOTS solves;
    expression test;
    std::vector <double> ansExpression;
	bool endOfFile = false;

    while (!in.eof()){
        test = ReadExersize(in,endOfFile);
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


