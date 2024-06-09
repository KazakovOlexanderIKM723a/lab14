#include <iostream>
#include <windows.h>

using namespace std;

bool isPerfectNumber(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            if (i * i != num) {
                sum += i + num / i;
            }
            else {
                sum += i;
            }
        }
    }
    return sum == num && num != 1;
}

int interpolationSearch(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x) {
            return pos;
        }

        if (arr[pos] < x) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int N;
    cout << "Enter number N: ";
    cin >> N;

    int* perfectNumbers = new int[N];
    int count = 0;

    for (int i = 2; i < N; ++i) {
        if (isPerfectNumber(i)) {
            perfectNumbers[count++] = i;
        }
    }

    cout << "Perfect numbers less than " << N << ": ";
    for (int i = 0; i < count; ++i) {
        cout << perfectNumbers[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Enter number for searching: ";
    cin >> x;

    int result = interpolationSearch(perfectNumbers, count, x);
    if (result != -1) {
        cout << "Number " << x << " found in position " << result << endl;
    }
    else {
        cout << "Number " << x << " not found" << endl;
    }

    delete[] perfectNumbers;

    return 0;
}

