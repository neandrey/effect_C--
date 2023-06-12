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
    virtual ~Core() {} // виртуальный деструктор
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

std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare_Core_ptrs(const Core* cp1, const Core* cp2);
bool compare(const Core& c1, const Core& c2);
#endif