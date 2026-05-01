#include <iostream>
#include <math.h>
#include <iomanip>
#include "cDaGiac.h"
using namespace std;

bool Bang(double a, double b) {
    return fabs(a - b) <= 0;
}

double TinhDoDai(Diem A, Diem B) {
    return sqrt((A.GetX()-B.GetX())*(A.GetX()-B.GetX()) + (A.GetY()-B.GetY())*(A.GetY()-B.GetY()));
}

Diem::Diem(){
    x=0;
    y=0;
}

Diem::Diem(double a, double b){
    this->x=a;
    this->y=b;
}
Diem::Diem(Diem &A){
    x=A.x;
    y=A.y;
}

void Diem::Nhap(){
    cout<<"x = ";cin>>x;
    cout<<"y = ";cin>>y;
    cout<<endl;
}

void Diem::Xuat(){
    cout<<fixed<<setprecision(2);
    cout<<"Toa do diem: x="<<x<<", y="<<y<<endl;
}

double Diem::GetX()const {return x;}
double Diem::GetY()const {return y;}

void Diem::SetX(double x){this->x=x;}
void Diem::SetY(double y) {this->y=y;}


cDaGiac::cDaGiac() {
    n=0;
    dinh=nullptr;
}
cDaGiac::cDaGiac(int n, Diem *ds) {
    this->n=n;
    dinh=new Diem[n];
    for(int i = 0; i < n; i++)
        dinh[i] = ds[i];
}
cDaGiac::cDaGiac(const cDaGiac &dg) {
    n = dg.n;
    dinh = new Diem[n];
    for (int i = 0; i < n; i++)
        dinh[i] = dg.dinh[i];
}
cDaGiac::~cDaGiac() {
    delete[] dinh;
}

void cDaGiac::Nhap() {
    cout<<"Nhap so dinh: ";cin>>n;
    delete[] dinh;
    dinh=new Diem[n];
    for (int i = 0; i < n; i++) {
        cout<<"Nhap toa do dinh thu "<<i+1<<":\n";
        dinh[i].Nhap();
    }
}
void cDaGiac::Xuat() {
    cout << "Toa do " << n << " dinh:\n";
    for (int i = 0; i < n; i++)
        dinh[i].Xuat();
    cout << endl;
}

bool cDaGiac::KiemTra() {
    if (n < 3) {
        cout << "Day khong phai da giac (can it nhat 3 dinh)\n";
        return false;
    }
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (Bang(dinh[i].GetX(), dinh[j].GetX()) && Bang(dinh[i].GetY(), dinh[j].GetY())) {
                cout << "Day khong phai da giac (co 2 dinh trung nhau)\n";
                return false;
            }
    cout << "Day la da giac hop le\n";
    return true;
}

double cDaGiac::ChuVi() {
    double cv= 0;
    for (int i = 0; i < n; i++)
        cv += TinhDoDai(dinh[i],dinh[(i+1)%n]);
    return cv;
}

long double cDaGiac::DienTich() {
    long double s=0;
    for (int i = 0; i < n; i++) {
        int j = (i+1) % n;
        s += dinh[i].GetX() * dinh[j].GetY();
        s -= dinh[j].GetX() * dinh[i].GetY();
    }
    return fabs(s) / 2.0;
}

void cDaGiac::TinhTien(double x, double y) {
    for (int i = 0; i < n; i++) {
        dinh[i].SetX(dinh[i].GetX() + x);
        dinh[i].SetY(dinh[i].GetY() + y);
    }
}

void cDaGiac::Quay(double k) {
    k = k * M_PI / 180.0;
    double xMoi, yMoi;
    for (int i = 0; i < n; i++) {
        xMoi = dinh[i].GetX()*cos(k) - dinh[i].GetY()*sin(k);
        yMoi = dinh[i].GetX()*sin(k) + dinh[i].GetY()*cos(k);
        dinh[i].SetX(xMoi);
        dinh[i].SetY(yMoi);
    }
}

void cDaGiac::PhongTo(double k) {
    for (int i = 0; i < n; i++) {
        dinh[i].SetX(dinh[i].GetX() * k);
        dinh[i].SetY(dinh[i].GetY() * k);
    }
}

void cDaGiac::ThuNho(double k) {
    if (k == 0) { cout << "Ti le thu nho khong hop le!\n"; return; }
    for (int i = 0; i < n; i++) {
        dinh[i].SetX(dinh[i].GetX() / k);
        dinh[i].SetY(dinh[i].GetY() / k);
    }
}
