#include <iostream>
using namespace std;
#include "cDaGiac.cpp"

int main() {
    cDaGiac DG;
    DG.Nhap();
    DG.KiemTra();
    cout << "Chu vi da giac: " << DG.ChuVi() << endl;
    cout << "Dien tich da giac: " << DG.DienTich() << endl;

    double x, y;
    cout << "Nhap vector de tinh tien:\nx="; cin >> x;
    cout << "y="; cin >> y;
    DG.TinhTien(x, y);
    DG.Xuat();

    double alpha;
    cout << "Nhap goc quay (do): "; cin >> alpha;
    DG.Quay(alpha);
    DG.Xuat();

    double k1;
    cout << "Nhap ti le phong to: "; cin >> k1;
    DG.PhongTo(k1);
    DG.Xuat();

    double k2;
    cout << "Nhap ti le thu nho: "; cin >> k2;
    DG.ThuNho(k2);
    DG.Xuat();

    return 0;
}
