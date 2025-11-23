#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 26;

void fillArray(int a[], int n, int low, int high);
void printArray(const int a[], int n);

int countByCriterion(const int a[], int n);
int sumByCriterion(const int a[], int n);
void replaceByCriterion(int a[], int n);
bool criterion(int value, int index);


int main() {
    srand(time(NULL));

    int a[N];

    fillArray(a, N, -40, 20);

    cout << "Pochatkovyi masyv:\n";
    printArray(a, N);

    int k = countByCriterion(a, N);
    int s = sumByCriterion(a, N);
    replaceByCriterion(a, N);

    cout << "\nKilkist: " << k << endl;
    cout << "Suma: " << s << endl;

    cout << "\nZminenyi masyv:\n";
    printArray(a, N);

    return 0;
}

void fillArray(int a[], int n, int low, int high) {
    for (int i = 0; i < n; i++) {
        a[i] = low + rand() % (high - low + 1);
    }
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

bool criterion(int value, int index) {
    return (value <= 0 && index % 2 == 0);
}

int countByCriterion(const int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (criterion(a[i], i)) c++;
    return c;
}

int sumByCriterion(const int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        if (criterion(a[i], i)) s += a[i];
    return s;
}

void replaceByCriterion(int a[], int n) {
    for (int i = 0; i < n; i++)
        if (criterion(a[i], i)) a[i] = 0;
}
