#include <iostream>
#include <iomanip>
using namespace std;

int* allocArray(int size) {
    if (size < 1) return NULL;
    int* arr = new int[size];
    return arr;
}

int* genRandArray(int size, int maxValue) {
    if (size < 1) return NULL;

    int* arr = new int[size];
    if (arr) {
        for (int i = 0; i < size; i++) arr[i] = (rand() % maxValue) + 1;
    }

    return arr;
}

void printArray(int* arr, int size, int w) {
    if (arr) {
        cout << size << ":";
        for (int i = 0; i < size; i++) cout << " " << setw(w) << arr[i];
        cout << endl;
    }
    else cout << "NULL ptr" << endl;
}

void freeArray(int* arr) {
    if (arr) delete[] arr;
}

int** genMatrix(int size, int maxValue) {
    if (size < 1) return NULL;

    int** m = new int* [size];

    if (m) {
        for (int i = 0; i < size; i++) {
            m[i] = genRandArray(size, maxValue);
        }
    }

    return m;
}

void printMatrix(int** matrix, int size) {
    if (matrix) {
        cout << size << endl;
        for (int i = 0; i < size; i++) printArray(matrix[i], size, 3);
    }
}

void freeMatrix(int** matrix, int size) {
    if (matrix) {
        for (int i = 0; i < size; i++) freeArray(matrix[i]);
        delete[] matrix;
    }
}

void toArrayByRightDiag(int** matrix, int size, int* arr) {
    if (!matrix || !arr) return;

    int r = 0;
    int c = size - 1;
    int j = 1;

    for (int i = 0; i < size * size; i++) {
        arr[i] = matrix[r][c];
        // случай 1: не последняя строка, последний столбец
        // переход к первой строке и столбцу левее
        if ((r < size - 1) and (c == size - 1)) {
            r = r - j + 1;
            c -= j;
            j++;
        }
        // случай 2: не последняя строка, не последний столбец
        // спуск вправо вниз, пока не будет случай 1
        else if ((r < size - 1) and (c < size - 1)) {
            r++;
            c++;
        }
        // случай 3: последняя строка => спустились по всем диагоналям текущей строки
        // переход к следующей строке
        else if ((r == size - 1) and (c <= size - 1)) {
            j--;
            r = r - j + 1;
            c -= j;
        }
    }
}

void toArrayByLeftDiag(int** matrix, int size, int* arr) {
    if (!matrix || !arr) return;

    int r = 0, c = 0;
    // направление вдоль диагонали вверх или вниз
    bool isUp = true;

    for (int i = 0; i < size * size;) {
        // идём по диагонали вверх
        if (isUp) {
            for (; r >= 0 && c < size; c++, r--, i++) arr[i] = matrix[r][c];

            // меняем номера строки и столбца в соотв. с направлением
            if (r < 0 && c <= size - 1) r = 0;
            if (c == size) r = r + 2, c--;
        }
        // идём по диагонали вниз
        else {
            for (; c >= 0 && r < size; r++, c--, i++) arr[i] = matrix[r][c];

            // меняем номера строки и столбца в соотв. с направлением
            if (c < 0 && r <= size - 1) c = 0;
            if (r == size) c = c + 2, r--;
        }

        // меняем направление вдоль диагонали
        isUp = !isUp;
    }
}

void toArrayByLeftSpiral(int** matrix, int i, int j, int m, int n, int* arr, int c) {
    if (!matrix || !arr) return;

    // если выходим по линиям i или j за границы матрицы
    if (i >= m || j >= n) return;

    // верхняя строка
    for (int p = j; p < n; p++, c++) arr[c] = matrix[i][p];

    // правый столбец
    for (int p = i + 1; p < m; p++, c++) arr[c] = matrix[p][n - 1];

    // нижняя строка (если не равна верхней)
    if ((m - 1) != i) for (int p = n - 2; p >= j; p--, c++) arr[c] = matrix[m - 1][p];

    // левый столбец (если не равен правому)
    if ((n - 1) != j) for (int p = m - 2; p > i; p--, c++) arr[c] = matrix[p][j];

    // рекурсивный переход внутрь
    toArrayByLeftSpiral(matrix, i + 1, j + 1, m - 1, n - 1, arr, c);
}

void toArrayByCentralSpiral(int** matrix, int i, int j, int m, int n, int* arr, int c) {
    if (!matrix || !arr) return;

    // вспомогательный массив для разворота
    int* b_arr = new int[m * n];

    // обход по спирали с левого верхнего элемента
    if (b_arr) toArrayByLeftSpiral(matrix, i, j, m, n, b_arr, c);

    // запись в arr в обратном порядке
    for (int i = 0, j = (m * n) - 1; i < m * n; i++, j--) arr[i] = b_arr[j];

    delete[] b_arr;
}

int main(void) {
    setlocale(0, "");
    srand(time(NULL));
    int n = (rand() % 10) + 1;
    int maxValue = 100;
    int** matrix = genMatrix(n, maxValue);
    printMatrix(matrix, n);

    cout << endl << "a)along the right diagonals, starting from the top right element: " << endl;
    int* a = allocArray(n * n);
    toArrayByRightDiag(matrix, n, a);
    printArray(a, n * n, 0);
    freeArray(a);

    cout << endl << "b)along the left diagonals, starting from the top left element:" << endl;
    int* b = allocArray(n * n);
    toArrayByLeftDiag(matrix, n, b);
    printArray(b, n * n, 0);
    freeArray(b);

    cout << endl << "c)in a spiral, starting from the central element:" << endl;
    int* c = allocArray(n * n);
    toArrayByCentralSpiral(matrix, 0, 0, n, n, c, 0);
    printArray(c, n * n, 0);
    freeArray(c);

    cout << endl << "d)in a spiral, starting from the top left element:" << endl;
    int* d = allocArray(n * n);
    toArrayByLeftSpiral(matrix, 0, 0, n, n, d, 0);
    printArray(d, n * n, 0);
    freeArray(d);

    freeMatrix(matrix, n);
    return 0;
}
