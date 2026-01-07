#include <iostream>

using namespace std;

template <class T>
T findMax(T a[], int n) {
    T maxVal = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] > maxVal)
            maxVal = a[i];
    }
    return maxVal;
}

int main()
{
    const int n = 3;
    string a[n];

    cout << "Nhap 3 xau ky tu" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nhap xau thu " << i + 1 << ":";
        cin >> a[i];
    }

    string maxString = findMax(a, n);
    cout << "\nGia tri lon nhat la: " << maxString << endl;

    return 0;
}
