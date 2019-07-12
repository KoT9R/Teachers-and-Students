//
// Created by Denis on 2019-05-29.
//

#include "helper.h"
#include "goodStudent.h"
#include "badStudent.h"
#include "middleStudent.h"
#include <fstream>

expression ReadExersize(std::fstream &in, bool &endOfFile){
	expression test = { 0 , 0 ,0 };
    if (!in){
		endOfFile = true;
        return test;
    }

    if (!in.eof()){
        in >> test.a;
    }
    else{
		endOfFile = true;
        return test;
    }

    if (!in.eof()){
        in >> test.b;
    }
    else{
		endOfFile = true;
        return test;
    }

    if (!in.eof()){
        in >> test.c;
    }
    else{
		endOfFile = true;
        return test;
    }

    return test;
}

std::vector <expression> ReadAllExersize(const std::string &filename){
    std::fstream in(filename);
    std::vector <expression> test;
    expression cash;

    while(!in.eof()){
        if (!in.eof()){
            in >> cash.a;
        }
        if (!in.eof()){
            in >> cash.b;
        }
        if (!in.eof()){
            in >> cash.c;
		}
		else
		{
			in.close();
			return test;
		}
        test.push_back(cash);
    }

    in.close();
    return test;
}

bool operator == (const expression& first, const expression& second) {
	if (first.a != second.a) {
		return false;
	}
	if (first.b != second.b) {
		return false;
	}
	if (first.c != second.c) {
		return false;
	}
	else
	{
		return true;
	}
}
bool operator < (const expression &first, const expression &second){
    if (first.a + first.b + first.c < second.a + second.b + second.c){
        return true; 
    }
    else{
		return false;
    }

}

bool operator > (const expression &first, const expression &second){
    if (first.a + first.b + first.c > second.a + second.b + second.c){
        return true;
    }
    else{
		return false;
    }

}

bool operator < (const ans_task &first, const ans_task &second) {
    if (first.ans_expression < second.ans_expression){
        return true;
    }else{
        return false;
    }
}
bool operator > (const ans_task &first,const ans_task &second) {
    if (first.ans_expression > second.ans_expression){
        return true;
    }else{
        return false;
    }
}

bool operator < (const sol_student &first, const sol_student &second){
    int checkFirst = 0;
    int checkSecond = 0;
    for (auto &secondIterator: second.solution){
        for (auto &firstIterator: first.solution){
            if (firstIterator.second > secondIterator.second)
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
bool operator > (const sol_student &first, const sol_student &second){
    int checkFirst = 0;
    int checkSecond = 0;
    for (auto &secondIterator: second.solution){
        for (auto &firstIterator: first.solution){
            if (firstIterator.second > secondIterator.second)
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


bool operator != (const std::vector <double>& first, const std::vector <double>& second) {
	if (first.size() != second.size()) {
		return false;
	}
	bool ans = true;
	for (size_t i = 0; i < first.size(); ++i) {
		if (first[i] != second[i]) {
			ans = false;
			break;
		}
	}
	return ans;
}



