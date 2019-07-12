#include "goodStudent.h"
#include "middleStudent.h"
#include "badStudent.h"
#include "teacher.h"

std::queue <sol_student> DoTask(std::vector <Human *> students,const std::string &filename){
    std::queue <sol_student> solutionOfStudent;
    for (size_t i = 0; i != students.size(); ++i){
        sol_student oneSolution;
        oneSolution.nameSt = students[i]->GetFullName();

        std::vector <ans_task> answersOfStudentt = students[i]->ResolveTask(filename);
        std::vector <expression> expressionsOfStudent = ReadAllExersize(filename);

        for (size_t j = 0; j != answersOfStudentt.size(); ++j){
            oneSolution.solution.insert(std::pair <expression,ans_task>
                    (expressionsOfStudent[j],answersOfStudentt[j]));
        }
        solutionOfStudent.push(oneSolution);
    }
    return solutionOfStudent;
}

int main() {
    std::string fileForExpression("outExpression.txt");
    std::string fileForAnswers("outAnswers.txt");
    exersize square(NUMBER_TASK);
    teacher proffesorOfMath;
    std::vector <Human *> students;
    std::queue <sol_student> solutionOfStudents;

    square.WriteToFile(fileForExpression,fileForAnswers);
    students = GenerateStudents(NUMBER_STUDENT);
    solutionOfStudents = DoTask(students,fileForExpression);
    proffesorOfMath.CheckWorks(solutionOfStudents,square);
    proffesorOfMath.ShowTablePerfomanceStudents();

    return 0;
}