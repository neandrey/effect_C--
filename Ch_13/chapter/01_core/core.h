#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <string>
#include <vector>

class Core {
public:
    Core(): midterm{0}, final{0}
    {}
    Core(std::istream& is) { read(is); }
    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    std::string n;
};

class Grade: public Core {
public:
    Grade(): thesis{0}
    {}
    Grade(std::istream& is) { read(is); }
    double grade() const;
    std::istream& read(std::istream&);
private:
    double thesis;
};

class Student_info {
public:
    Student_info(): cp{0}
    {}
    Student_info(std::istream& is): cp{0} { read(is); }
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { delete cp; }

    std::istream& read(std::istream&);

    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error(
            "Неинициализированные Student-данные"
        );
    }

    static bool compare(const Student_info& s1,
                        const Student_info& s2)
    {
        return s1.name() < s2.name();
    }

private:
    Core* cp;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
bool compare(const Core& c1, const Core& c2);
bool compare_grades(const Core& c1, const Core& c2);
#endif