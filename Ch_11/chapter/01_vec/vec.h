#ifndef VEC_H
#define VEC_H

#include <memory>

template <class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T())
    { create(n, val); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }

    Vec& operator=(const Vec&);

    ~Vec() { uncreate(); }

    size_type size() const { return avail - data; }

    T& operator[](size_type i ) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T& val) {
        if (avail == limit)
            grow(); // получаем память
        unchecked_append(val);
    }

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc; // управление выделением памяти.

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
};

#endif

