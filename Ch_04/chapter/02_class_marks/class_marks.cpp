// Хранение оценок в классе.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

istream& read(istream& is, Student_info& s);
istream& read_hw(istream& in, vector<double>& hw);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double homework);
double grade(const Student_info& s);
double median(vector<double> vec);
bool compare(const Student_info& x, const Student_info& y);

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // Считываем и сохраняем все записи,
    // затем находим длину самой длинной фамилии.
    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Упорядочиваем записи по алфавиту.
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

        // Выводим фамилию, дополненную справа
        // maxlen + 1 символами.
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
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

istream &read(istream &is, Student_info &s)
{
    // cout << "Введите имя студента, оценки за экзамены проведенные в середине и конце семестрa\n"
    //         "оценки за выполненные домашние задания, завершите ввод признаком конца файла: ";
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);

    return is;
}

double grade(const Student_info &s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
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