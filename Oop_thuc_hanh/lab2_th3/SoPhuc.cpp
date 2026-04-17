#include <iostream>
#include "SoPhuc.h"
using namespace std;

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void SoPhuc::Xuat() {
    cout << iThuc;
    if (iAo >= 0)
        cout << " + " << iAo << "i";
    else
        cout << " - " << -iAo << "i";
}

SoPhuc SoPhuc::Tong(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = iThuc + a.iThuc;
    kq.iAo = iAo + a.iAo;
    return kq;
}

SoPhuc SoPhuc::Hieu(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = iThuc - a.iThuc;
    kq.iAo = iAo - a.iAo;
    return kq;
}

SoPhuc SoPhuc::Tich(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = iThuc * a.iThuc - iAo * a.iAo;
    kq.iAo = iThuc * a.iAo + iAo * a.iThuc;
    return kq;
}

SoPhuc SoPhuc::Thuong(SoPhuc a) {
    SoPhuc kq;
    double mau = a.iThuc * a.iThuc + a.iAo * a.iAo;

    kq.iThuc = (iThuc * a.iThuc + iAo * a.iAo) / mau;
    kq.iAo = (iAo * a.iThuc - iThuc * a.iAo) / mau;

    return kq;
}