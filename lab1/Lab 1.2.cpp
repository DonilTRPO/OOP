#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(int* arr);
int* genRandArray(int size, int maxValue);
void freeArray(int* arr);
int** genRandMatrix(int size, int maxValue);
void printMatrix(int** matrix, int size);
void freeMatrix(int** matrix, int size);

void printArray(int* arr) {
    if (arr) {
        cout << arr[0] << ":";
        for (int i = 1; i < arr[0] + 1; i++) cout << " " << arr[i];
        cout << endl;
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

void printMatrix(int** matrix, int size) {
    if (matrix && size) {
        cout << size << endl;
        for (int i = 0; i < size; i++) printArray(matrix[i]);
    }
}

void freeMatrix(int** matrix, int size) {
    if (matrix && size) {
        for (int i = 0; i < size; i++) freeArray(matrix[i]);
        delete[] matrix;
    }
}

int** genRandMatrix(int size, int maxValue) {
    if (size < 1) return NULL;

    int** m = new int* [size];

    if (m) {
        for (int i = 0; i < size; i++) {
            int s = (rand() % 10) + 1;
            m[i] = genRandArray(s, maxValue);
        }
    }

    return m;
}

int main(void) {
    srand(time(NULL));
    int size = (rand() % 10) + 1;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    freeMatrix(matrix, size);
    return 0;
}