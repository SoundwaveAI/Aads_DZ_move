#include <cstddef>

template <class T>
struct List {
    T val;
    List<T>* next;
};

template <class T>
struct Vec {
    T* data;
    size_t s, cap;
};
