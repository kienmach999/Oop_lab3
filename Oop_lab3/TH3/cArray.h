#ifndef cArray_H
#define cArray_H
#include <iostream>
using namespace std;

class cArray {
private:
    int  n;
    int* arr;

    bool laNguyenTo(int x) const;
    void QuickSort(int* a, int l, int r);

public:
    cArray();
    cArray(int n);
    cArray(const cArray& a);
    cArray& operator=(const cArray& a);
    ~cArray();

    int  getN()        const;
    int  getArr(int i) const;

    void Nhap();
    void Xuat() const;

    int  demSoLanXuatHien(int x) const;
    bool kiemTraTangDan()         const;
    int  timPhanTuLeNhat()        const;
    int  timNguyenToLonNhat()     const;

    void sapXepTangDan();
    void sapXepGiamDan();
};

#endif // cArray_H

