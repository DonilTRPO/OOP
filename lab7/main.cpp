#include "libs/list.hpp"
#include "libs/stack.hpp"
#include "libs/queue.hpp"
#include "libs/URNG/URNG.hpp"

#include <iostream>

int main(void) {
    il::List<int> list;
    il::Stack<float> stack;
    il::Queue<double> queue;

    for (int i = 0, r = 0; i < URNG(5, 10); i++) {
        r = URNG(-1000, 1000);

        if (r % 2) list.addEnd(r);
        else list.addFront(r);

        stack.push(r);
        queue.push(r);
    }

    std::cout << "List: ";
    list.print();

    std::cout << "Stack: ";
    stack.print();

    std::cout << "Queue: ";
    queue.print();

    std::cout << "------------------------" << std::endl;

    std::cout << "List after deleteNodeAt(4) (value was " << list.valueAt(4) << "): ";
    list.deleteNodeAt(4);
    list.print();

    std::cout << "Stack after pop() (value was " << stack.top() << "): ";
    stack.pop();
    stack.print();

    std::cout << "Queue after pop() (value was " << queue.top() << "): ";
    queue.pop();
    queue.print();

    std::cout << "------------------------" << std::endl;

    // Queue FIFO
    queue.clear();
    queue.push(50.5);
    queue.push(51.5);
    queue.push(52.5);
    queue.push(53.5);
    queue.push(54.5);
    std::cout << "Queue FIFO: ";
    queue.print();

    // Stack LIFO
    stack.clear();
    stack.push(50.5);
    stack.push(51.5);
    stack.push(52.5);
    stack.push(53.5);
    stack.push(54.5);
    std::cout << "Stack LIFO: ";
    stack.print();

    return 0;
}