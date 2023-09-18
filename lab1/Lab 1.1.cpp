#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(int* arr);
int* genRandArray(int size, int maxValue);
void freeArray(int* arr);

void printArray(int* arr) {
    if (arr) {
        cout << arr[0] << ":";
        for (int i = 1; i < arr[0] + 1; i++) cout << " " << arr[i];
    }
}

void freeArray(int* arr) {
    if (arr) delete[] arr;
}

int* genRandArray(int size, int maxValue) {
    if (size < 1) return NULL;

    int* arr = new int[size + 1];
    if (arr) {
        arr[0] = size;
        for (int i = 1; i < size + 1; i++) arr[i] = (rand() % maxValue) + 1;
    }

    return arr;
}

int main(void) {
    srand(time(NULL));
    int size = (rand() % 10) + 1;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    printArray(arr);
    freeArray(arr);
    return 0;
}