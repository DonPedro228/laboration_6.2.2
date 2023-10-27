#include <iostream>
#include <climits>
#include <ctime>

using namespace std;

int* GenerateArray(int n)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    return a;
}

void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

double AverageMinMax(int a[], int n, int index = 0, int min = INT_MAX, int max = INT_MIN) {
    if (index == n) {
        return static_cast<double>(min + max) / 2;
    }

    if (a[index] < min) {
        min = a[index];
    }
    if (a[index] > max) {
        max = a[index];
    }

    return AverageMinMax(a, n, index + 1, min, max);
}

int main() {
    int n;
    cout << "n = "; cin >> n;

    int* a = GenerateArray(n);
    PrintArray(a, n);

    double result = AverageMinMax(a, n);

    cout << "Average = " << result << endl;

    delete[] a;
    return 0;
}
