// Разделение программы на функции.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include <algorithm>

using namespace std;

double grade(double midterm, double final, const vector<double>& hw);
double grade (double midterm, double final, double homework);
double median(vector<double> vec);
istream& read_hw(istream& in, vector<double>& hw);

int main() {

    // Запрашиваем и считываем имя студента.
    cout << "Пожалуйста, введите свое имя: ";
    string name;
    cin >> name;
    cout << "Привет, " << name << "!" << endl;

    // Запрашиваем и считываем оценки по экзаменам, проведенным
    // в середине и конце семестра.
    cout << "Пожалуйста, введите оценки по экзаменам, "
            "проведенным в середине и конце семестра: ";
    
    double midterm, final;
    cin >> midterm >> final;

    // Запрашиваем оценки за выполнение домашних заданий.
    cout << "Введите все оценки за выполнение домашних заданий, "
            "завершив ввод признаком конца файла: ";

    vector<double> homework;

    // Считываем оценки за выполнение домашних заданий.
    read_hw(cin, homework);

    // Вычисляем итоговую оценку.
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Ваша итоговая оценка равна " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "Вы должны ввести свои оценки."
                        "пожалуйста, попытайтесь снова." << endl;
        return 1;
    }
    return 0;
}

double grade(double midterm, double final, const vector<double> &hw)
{
    if(hw.size() == 0)
        throw domain_error("Студент не сделал ни одного домашнего задания.");
    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    if(size == 0)
        throw domain_error("Медиана пустого вектора.");
    
    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

istream &read_hw(istream &in, vector<double> &hw)
{
    if (in) {
        hw.clear();

        double x;
        while (in >> x)
            hw.push_back(x);

        in.clear();
    }
    return in;
}
