// Отделяем записи с проходными баллами от записей с 
// проходными: первая попытка
#include <vector>
#include "../../Student_info/Student_info.h"
#include "../../Student_info/grade.h"

using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    while (iter != students.end())
    {
        if(fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    
    return fail;
}