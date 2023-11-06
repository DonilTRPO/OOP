#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

namespace il {
    template <class T>
    class ListNode {
    private:
        ListNode<T>* _next;
        T _value;
    public:
        ListNode(T value = 0, ListNode<T>* next = NULL) : _next(next), _value(value) {};
        void setValue(T value) {
            this->_value = value;
        }
        T getValue(void) {
            return this->_value;
        }
        void setNextNode(ListNode<T>* next) {
            this->_next = next;
        }
        ListNode<T>* getNextNode(void) {
            return this->_next;
        }
    };

    template <class T>
    class List {
    private:
        ListNode<T>* _head;
        ListNode<T>* _tail;

        int _size;

        ListNode<T>* createNode(void) {
            ListNode<T>* node = NULL;
            try {
                node = new ListNode<T>;
            } catch (std::bad_alloc e) {
                throw e;
            }

            node->setValue((T) 0);
            node->setNextNode(NULL);

            return node;
        }
    public:
        List() : _head(NULL), _tail(NULL), _size(0) {};

        List(int size) : _head(NULL), _tail(NULL), _size(0) {
            if (!size) {
                std::cerr << "Size given to List() constructor < 0: " << size << std::endl
                          << "Assuming size as 0" << std::endl;
            }

            for (T i = (T) 0; i < size; i++) {
                this->addEnd(i + (T) 1);
            }
        }

        ~List() {
            this->clear();
        }

        void addFront(T value) {
            ListNode<T>* node = NULL;
            try {
                node = this->createNode();
            } catch (std::bad_alloc e) {
                std::cerr << "Can't allocate memory for addFront(" << value << "), skipping..." << std::endl;
                return;
            }

            node->setValue(value);

            node->setNextNode(this->_head);
            this->_head = node;
            this->_size++;

            if (!this->_tail) this->_tail = node;
        }

        void addEnd(T value) {
            ListNode<T>* node = NULL;
            try {
                node = this->createNode();
            } catch (std::bad_alloc e) {
                std::cerr << "Can't allocate memory for addEnd(" << value << "), skipping..." << std::endl;
                return;
            }

            node->setValue(value);

            if (this->_tail) this->_tail->setNextNode(node);
            this->_tail = node;
            this->_size++;

            if (!this->_head) this->_head = node;
        }

        void deleteNodeAt(int position) {
            ListNode<T>* node = this->nodeAt(position);

            if (this->_head == node) this->_head = this->_head->getNextNode();
            else {
                ListNode<T>* prev = this->_head;
                while (prev->getNextNode() != node) prev = prev->getNextNode();
                prev->setNextNode(node->getNextNode());
                if (this->_tail == node) this->_tail = prev;
            }

            this->_size--;
            delete node;
        }

        void clear(void) {
            ListNode<T>* node = this->_head;
            ListNode<T>* prev = NULL;

            while (node) {
                prev = node;
                node = node->getNextNode();

                delete prev;
            }

            this->_head = NULL;
            this->_tail = NULL;
            this->_size = 0;
        }

        ListNode<T>* nodeAt(int position) {
            if (position < 1 || position > this->getSize()) throw std::out_of_range("Index is out of range");

            ListNode<T>* node = this->_head;
            for (int i = 0; i < position - 1; i++) node = node->getNextNode();

            return node;
        }

        T valueAt(int position) {
            return this->nodeAt(position)->getValue();
        }

        int getSize(void) {
            return this->_size;
        }

        void print(void) {
            ListNode<T>* node = this->_head;
            while (node) {
                std::cout << node->getValue() << " ";
                node = node->getNextNode();
            }
            std::cout << std::endl;
        }
    };
}

#endif // LIST_HPP