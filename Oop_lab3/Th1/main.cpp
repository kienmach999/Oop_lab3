#include <iostream>
using namespace std;
#include "TamGiac.cpp"

int main(){
    cTamGiac ABC;
    ABC.Nhap();
    ABC.KiemTra();
    cout<<"Chu vi tam giac: "<<ABC.ChuVi()<<endl;
    cout<<"Dien tich tam giac: "<<ABC.DienTich()<<endl;
    double x,y;
    cout<<"Nhap vector de tinh tien:\nx=";cin>>x;cout<<"y=";cin>>y;
    ABC.TinhTien(x,y);
    ABC.Xuat();
    double alpha;cout<<"Nhap goc quay (do): ";cin>>alpha;
    ABC.Quay(alpha);
    ABC.Xuat();
    double k1;cout<<"Nhap ti le phong to: ";cin>>k1;
    ABC.PhongTo(k1);
    ABC.Xuat();
    double k2;cout<<"Nhap ti le thu nho: ";cin>>k2;
    ABC.ThuNho(k2);
    ABC.Xuat();

    return 0;
}
