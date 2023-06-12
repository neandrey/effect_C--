#ifndef HANDLE_H
#define HANDLE_H
#include <iostream>
#include <string>
#include <vector>

template <class T>
class Handle {
public:
    Handle(): p{nullptr} {}
    Handle(const Handle& s): p{nullptr}
    { if (s.p) p = s.p->clone(); }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t): p(t) {}

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

class Core {
public:
    friend class Student_info;
    Core(): midterm{0}, final{0}
    {}
    Core(std::istream& is) { read(is); }
    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    virtual Core* clone() const { return new Core(*this); }
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
protected:
    Grade* clone() const { return new Grade(*this); }
private:
    double thesis;
};

template <class T>
Handle<T> &Handle<T>::operator=(const Handle & rhs)
{
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p->clone() : nullptr;
    } 
    return *this;
}
#endif


