#include <iostream>
using namespace std;

const int maxN = 100;
const int maxM = 100;

void input(int& number) {
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\nError input\n";
        }
        else {
            // cin.ignore(32767, '\n');
            break; //выпрыгиваем из ближайшего while (true)
        }
    }
}
void init(int matrix[maxN][maxM], int n, int m) {
    /*
    srand(time(0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = 1 + rand() % 100; //от 1 до 100
      }
    }
  */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            input(matrix[i][j]);
        }
    }
}
void print(int matrix[maxN][maxM], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//сковозная сортировка матрицы
void sortedBubble(int* matrix, int n, int m) {
    int size = n * m;
    //Задача отсортировать по возрастанию массив

    for (int i = 0; i < size; i++) {
        cout << matrix[i] << " ";
    }
    cout << endl;

    for (int j = 0; j < size - 1; j++) { //количество проходов
        //перестановка элементов
        for (int i = 0; i < size - 1; i++) {

            // cout << matrix[i] << " " << matrix[i + 1] << endl;
            //сравнить из пары элементы
            //  5 > 4 - меняем местами
            if (matrix[i] > matrix[i + 1]) {
                swap(matrix[i], matrix[i + 1]);
            }
        }
    }

    // алгоритм сортировки остается тот же для двумерной матрицы
    // 5, 4, 3, 2, 1
    // 4, 5, 3, 2, 1  5 > 3
    // 4, 3, 5, 2, 1  5 > 2
}

int main() {

    int m, n;
    do {
        cout << "SET count rows - n <= 100:  ";
        input(n);
        cout << "SET count of columns - m <= 100: ";
        input(m);
    } while (n > maxN || m > maxM);
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    int a = 10;
    int matrix[maxN][maxM];
    cout << "input elem of matrix\n";
    init(matrix, n, m);
    cout << "Matrix\n";
    print(matrix, n, m);

    sortedBubble(&matrix[0][0], n, m);
    //при вызове сортировки для двумерной матрицы передается адрес начала памяти
    cout << "Matrix\n";
    print(matrix, maxN, maxM);
}