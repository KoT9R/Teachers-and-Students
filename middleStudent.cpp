//
// Created by Denis on 2019-05-06.
//

#include "middleStudent.h"
#include "exersize.h"
#include <fstream>
#include <ctime>

middleStudent::middleStudent():Human() {}

middleStudent::middleStudent(std::string &nameIn):Human(nameIn) {}

ans_task SaveSolution(std::vector <double> const &ansExpression, NUMBROOTS const &solves){
    ans_task partOfTask;
    partOfTask.ans_expression = ansExpression;
    partOfTask.quantity_ans = solves;
    return partOfTask;
}


std::vector <ans_task> middleStudent::ResolveTask(const std::string &filename) {
    std::fstream in(filename);
    std::vector <double> ansExpression;
    std::vector <ans_task> ans;
    expression test;
    NUMBROOTS solves;
    ans_task partOfTask;
    bool trueOrFalseAns;
	bool endOfFile = false;

    while (!in.eof()){
        test = ReadExersize(in, endOfFile);
        if (endOfFile){
			in.close();
            return ans;
        }
        trueOrFalseAns = rand() % 2;
        if (trueOrFalseAns){
            ansExpression = Solving_Equations(test, &solves);
            partOfTask = SaveSolution(ansExpression,solves);
            ans.push_back(partOfTask);
            ansExpression.clear();
        }
        else{
            ansExpression.push_back((rand() % 100 - 50) / 10.);
            ansExpression.push_back((rand() % 100 - 50) / 10.);
            solves = TWO;
            partOfTask = SaveSolution(ansExpression,solves);
            ans.push_back(partOfTask);
        }
    }
    in.close();
    return ans;
}