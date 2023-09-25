#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int numRows = rand() % 10 + 1;       
    int maxElements = rand() % 10 + 1;  

    int** matrix = new int* [numRows];

    for (int i = 0; i < numRows; i++) {
        int numElements = rand() % (maxElements + 1);
        matrix[i] = new int[numElements];

        if (numElements > 0) {
            cout << "Str" << i + 1 << ":";
            for (int j = 0; j < numElements; j++) {
                matrix[i][j] = rand() % 100;
                cout << " " << matrix[i][j];
            }
            cout << endl;
        }
        else {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
    }

    for (int i = 0; i < numRows; i++) {
        if (matrix[i] != nullptr) {
            delete[] matrix[i];
        }
    }
    delete[] matrix;

    return 0;
}