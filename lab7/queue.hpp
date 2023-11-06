#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "stack.hpp"

namespace il {
    template <class T>
    class Queue : public Stack<T> {
    public:
        void push(T value) {
            List<T>::addEnd(value);
        }
    };
}

#endif // QUEUE_HPP