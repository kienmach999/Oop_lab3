#include <iostream>
#include <iomanip>
#include "GioPhutGiay.h"

using namespace std;

void ChuanHoaGioPhutGiay(int &Gio, int &Phut, int &Giay){
    //chuan hoa giay
    Phut+=Giay/60;
    Giay%=60;

    //chuan hoa phut
    Gio+=Phut/60;
    Phut%=60;

    //chuan hoa gio
    Gio%=24;
}

void GioPhutGiay::Nhap() {
    cout << "Nhap gio: ";
    cin >> iGio;
    cout << "Nhap phut: ";
    cin >> iPhut;
    cout << "Nhap giay: ";
    cin >> iGiay;
    ChuanHoaGioPhutGiay(iGio,iPhut,iGiay);
}

// Xuất
void GioPhutGiay::Xuat() {
    cout << setfill('0') << setw(2) << iGio << ":"
            << setw(2) << iPhut << ":"
            << setw(2) << iGiay;
}

// Cộng thêm 1 giây
void GioPhutGiay::TinhCongThemMotGiay() {
    iGiay++;    
    ChuanHoaGioPhutGiay(iGio,iPhut,iGiay);
}