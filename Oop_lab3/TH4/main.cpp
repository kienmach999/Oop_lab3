// main.cpp
#include "cDaThuc.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cDaThuc p1, p2;

    cout << "===== NHAP DA THUC P1 =====\n";
    p1.Nhap();

    cout << "\n===== NHAP DA THUC P2 =====\n";
    p2.Nhap();


    cout << "\n===== XUAT DA THUC =====\n";
    cout << "P1(x) = "; p1.Xuat();
    cout << "P2(x) = "; p2.Xuat();

    cout << "\n===== TINH GIA TRI =====\n";
    double x;
    cout << "Nhap x: "; cin >> x;

    cout << "P1(" << x << ") = " << p1.TinhGiaTri(x) << endl;
    cout << "P2(" << x << ") = " << p2.TinhGiaTri(x) << endl;


    cout << "\n===== CONG HAI DA THUC =====\n";
    cDaThuc tong = p1.Cong(p2);
    cout << "P1 + P2 = "; tong.Xuat();

    cout << "\n===== TRU HAI DA THUC =====\n";
    cDaThuc hieu = p1.Tru(p2);
    cout << "P1 - P2 = "; hieu.Xuat();

    return 0;
}
