#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

namespace il {
    template <class T>
    class Stack : public List<T> {
    private:
        void addEnd();
        void addFront();
        void deleteNodeAt();
        void nodeAt();
        void valueAt();
    public:
        void push(T value) {
            List<T>::addFront(value);
        }

        void pop(void) {
            List<T>::deleteNodeAt(1);
        }

        T top(void) {
            return List<T>::valueAt(1);
        }
    };
}

#endif // STACK_HPP