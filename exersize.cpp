//
// Created by Denis on 2019-05-04.
//

#include "exersize.h"
#include <fstream>
#include <ctime>

exersize::exersize(int const &size) {
    expression my;
    ans_task elemOfTask;
    NUMBROOTS solves;
    std::vector <double> ansExpression;
	srand((unsigned)time(0));
    for (size_t i = 0; i < (size_t)size; ++i){
        my.a = (rand() % 100 - 50) / 10.;
        my.b = (rand() % 100 - 50) / 10.;
        my.c = (rand() % 100 - 50) / 10.;
        ansExpression = Solving_Equations(my,&solves);
        elemOfTask.ans_expression = ansExpression;
        elemOfTask.quantity_ans = solves;
        taskAndAnswers.insert(std::pair<expression,ans_task> (my, elemOfTask));
        ansExpression.clear();
    }
}

std::vector <expression> exersize::GetTask() const{
    std::vector <expression> task;
    for (auto &i:taskAndAnswers){
        task.push_back(i.first);
    }
    return task;
}

std::vector <ans_task> exersize::GetAns() const {
    std::vector <ans_task> ans;
    for (auto &i:taskAndAnswers){
        ans.push_back(i.second);
    }
    return ans;
}

bool operator <(const std::multimap<expression, ans_task> &first,
        const std::multimap <expression, ans_task> &second) {
    int checkFirst = 0;
    int checkSecond = 0;
    for (auto &secondIterator: second){
        for (auto &firstIterator: first){
            if (firstIterator.first > secondIterator.first)
                checkFirst++;
            else
                checkSecond++;
        }
    }

    if (checkFirst < checkSecond){
        return true;
    }else{
        return false;
    }
}

bool operator >(const std::multimap<expression, ans_task> &first,
                const std::multimap <expression, ans_task> &second) {
    int checkFirst = 0;
    int checkSecond = 0;
    for (auto &secondIterator: second){
        for (auto &firstIterator: first){
            if (firstIterator.first > secondIterator.first)
                checkFirst++;
            else
                checkSecond++;
        }
    }

    if (checkFirst > checkSecond){
        return true;
    }else{
        return false;
    }
}

void exersize::WriteToFile(const std::string &fileExpres, const std::string &fileAns) {
    std::ofstream outExpres(fileExpres);
    std::ofstream outAnsw(fileAns);
    for (auto &i: taskAndAnswers){
        outExpres << i.first.a << " " << i.first.b << " " << i.first.c << std::endl;
		for (int j = 0; j < i.second.quantity_ans; ++j) {
			outAnsw << i.second.ans_expression[j] << " ";
		}
		if (i.second.quantity_ans == ZERO) {
			outAnsw << "None" << " ";
		}
		outAnsw << std::endl;

    }
    outAnsw.close();
    outExpres.close();
}

std::multimap <expression, ans_task> &exersize::GetHashTable() { return taskAndAnswers;}

exersize::~exersize() {
    taskAndAnswers.clear();
}

double Find_Discriminant(const expression &reference)
{
    double d;
    d = reference.b * reference.b - 4 * reference.a * reference.c;
    return d;
}

void Square_exersize_minus(const expression &reference, std::vector<double> &ans, const double &d)
{
    ans.push_back( -reference.b - sqrt(d) / (2 * reference.a));
}

void Square_exersize_plus(const expression &reference, std::vector<double> &ans, const double &d)
{
    ans.push_back(-reference.b + sqrt(d) / (2 * reference.a));
}


std::vector<double> First_Coeff_Zero(const expression &reference, NUMBROOTS *solves)
{
    double d = Find_Discriminant(reference);
    std::vector<double> ans;

    if (d > 0) {

        Square_exersize_minus(reference, ans, d);
        Square_exersize_plus(reference, ans, d);
        *solves = TWO;
        return ans;
    }

    if (d == 0) {
        Square_exersize_plus(reference, ans, d);
        *solves = ONE;
        return ans;
    }

    if (d < 0) {
        *solves = ZERO;
        return ans;
    }
    return ans;
}

std::vector<double> First_Or_Second_Coef_Not_Zero(const expression &reference, NUMBROOTS *solves)
{
    std::vector<double> ans;
    if (reference.a != 0) {
        ans.push_back(0);
        ans.push_back(0);
        *solves = TWO;
        return ans;
    }
    else
    {
        ans.push_back(0);
        *solves = ONE;
        return ans;
    }
}

std::vector<double> Third_Or_Fourth_Coef_Not_Zero(const expression &reference, NUMBROOTS *solves)
{
    std::vector<double> ans;
    ans.push_back (-reference.c / reference.b);
    *solves = ONE;
    return ans;
}

std::vector<double> Fourth_Coef_Not_Zero(const expression &reference, NUMBROOTS *solves)
{
    std::vector<double> ans;
    *solves = ZERO;
    return ans;
}

std::vector<double> Solving_Equations(const expression &reference, NUMBROOTS *solves)
{
    std::vector<double> ans;
    if (reference.a != 0 && (reference.a != 0 || reference.b != 0)) {
        ans = First_Coeff_Zero(reference, solves);
        return ans;
    }

    if (reference.a != 0 || reference.b != 0) {
        ans = First_Or_Second_Coef_Not_Zero(reference, solves);
        return ans;
    }

    if (reference.b != 0 && reference.c != 0) {
        ans = Third_Or_Fourth_Coef_Not_Zero(reference, solves);
        return ans;
    }

    if (reference.c != 0) {
        ans = Fourth_Coef_Not_Zero(reference, solves);
        return ans;
    }

    if (reference.a == 0 && reference.b == 0 && reference.c == 0) {
        *solves = UNLIMITED;
        return ans;
    }
    return ans;
}