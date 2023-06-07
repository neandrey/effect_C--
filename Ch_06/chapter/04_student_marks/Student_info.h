#ifndef GUARD_Student_info
#define GUARD_Student_info

// Заголовочный файл Student_info.h
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool did_all_hw(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double grade_aux(const Student_info&);
void write_analysis(std::ostream& out, const std::string& name,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);
double averenge_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info& s);
double optimistic_median_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info &);
double average(const std::vector<double>&);

#endif