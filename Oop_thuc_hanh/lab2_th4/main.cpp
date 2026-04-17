#include <iostream>
#include "GioPhutGiay.cpp"
using namespace std;


int main() {
    GioPhutGiay tg;

    cout << "Nhap thoi gian:\n";
    tg.Nhap();

    cout << "\nThoi gian ban dau: ";
    tg.Xuat();
    
    //cong them 1 giay
    tg.TinhCongThemMotGiay();

    cout << "\nSau khi cong them 1 giay: ";
    tg.Xuat();

    return 0;
}