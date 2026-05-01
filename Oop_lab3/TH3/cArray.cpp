#include "cArray.h"
#include <climits>

cArray::cArray() {
    n   = 0;
    arr = nullptr;
}

cArray::cArray(int n) {
    this->n = n;
    arr = new int[n]();
}

cArray::cArray(const cArray& a) {
    n   = a.n;
    arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = a.arr[i];
}

cArray& cArray::operator=(const cArray& a) {
    if (this == &a) return *this;
    delete[] arr;
    n   = a.n;
    arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = a.arr[i];
    return *this;
}

cArray::~cArray() {
    delete[] arr;
}
int cArray::getN()        const { return n; }
int cArray::getArr(int i) const { return arr[i]; }

void cArray::Nhap() {
    cout << "Nhap so phan tu n: ";
    cin  >> n;
    delete[] arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin  >> arr[i];
    }
}

void cArray::Xuat() const {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int cArray::demSoLanXuatHien(int x) const {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == x) dem++;
    return dem;
}
bool cArray::kiemTraTangDan() const {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

bool cArray::laNguyenTo(int x) const {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int cArray::timPhanTuLeNhat() const {
    int  minVal = INT_MAX;
    bool found  = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            if (!found || arr[i] < minVal) {
                minVal = arr[i];
                found  = true;
            }
        }
    }
    return found ? minVal : INT_MAX;
}
int cArray::timNguyenToLonNhat() const {
    int  maxVal = INT_MIN;
    bool found  = false;
    for (int i = 0; i < n; i++) {
        if (laNguyenTo(arr[i])) {
            if (!found || arr[i] > maxVal) {
                maxVal = arr[i];
                found  = true;
            }
        }
    }
    return found ? maxVal : -1;
}

void cArray::QuickSort(int* a, int l, int r) {
    if (l >= r) return;

    int x = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    QuickSort(a, l, j);
    QuickSort(a, i, r);
}

void cArray::sapXepTangDan() {
    QuickSort(arr, 0, n - 1);
}

void cArray::sapXepGiamDan() {
    QuickSort(arr, 0, n - 1);
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(arr[i], arr[j]);
}



