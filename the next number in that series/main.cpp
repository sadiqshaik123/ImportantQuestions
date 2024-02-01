#include <iostream>

using namespace std;

bool isarthematic(int arr[], int size) {
    int commondiff = arr[1] - arr[0];
    for (int i = 2; i < size; i++) {
        if (arr[i] - arr[i - 1] != commondiff) {
            return false;
        }
    }
    return true;
}

bool isgeometric(int arr[], int size) {
    int commonratio = arr[1] / arr[0];
    for (int i = 2; i < size; i++) {
        if (arr[i] / arr[i - 1] != commonratio) {
            return false;
        }
    }
    return true;
}

bool isfibo(int arr[], int size) {
    for (int i = 2; i < size; i++) {
        if (arr[i - 2] + arr[i - 1] != arr[i]) {
            return false;
        }
    }
    return true;
}

int findnum(int arr[], int size) {
    int len = size-1;
    int nextnum;

    if (isarthematic(arr, size)) {
        int commondiff = arr[1] - arr[0];
        nextnum = arr[len] + commondiff;
    } else if (isgeometric(arr, size)) {
        int commonratio = arr[1] / arr[0];
        nextnum = arr[len] * commonratio;
    } else if (isfibo(arr, size)) {
        nextnum = arr[len] + arr[len - 1];
    } else {
        nextnum = -1;
    }

    return nextnum;
}

int main() {
    int len;
    cout << "Enter the length: ";
    cin >> len;
    int arr[len];
    cout << "Enter Elements: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    int ans = findnum(arr, len);
    if (ans != -1) {
        cout << ans << endl;
    }
    return 0;
}
