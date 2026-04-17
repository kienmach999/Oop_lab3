#include <iostream>
#include "SoPhuc.cpp"
using namespace std;


int main() {
    SoPhuc a, b;


    cout << "Nhap So phuc A:\n";
    a.Nhap();


    cout << "Nhap So phuc B:\n";
    b.Nhap();


    cout << "\nSo Phuc A: ";
    a.Xuat();


    cout << "\nSo Phuc B: ";
    b.Xuat();


    // Tính toán
    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);


    cout << "\n\nTong: ";
    tong.Xuat();


    cout << "\nHieu: ";
    hieu.Xuat();


    cout << "\nTich: ";
    tich.Xuat();


    cout << "\nThuong: ";
    thuong.Xuat();
    cout<<'\n';
    return 0;
}
