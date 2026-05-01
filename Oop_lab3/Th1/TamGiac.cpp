#include <iostream>
#include <math.h>
#include <iomanip>
#include "TamGiac.h"

using namespace std;


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

cTamGiac::cTamGiac(){}
cTamGiac::cTamGiac(Diem X, Diem Y, Diem Z){
    this->A=X;
    this->B=Y;
    this->C=Z;
}
cTamGiac::cTamGiac(cTamGiac &ABC){
    A=ABC.A;
    B=ABC.B;
    C=ABC.C;
}

double TinhDoDai(Diem A, Diem B){
    return sqrt((A.GetX()-B.GetX())*(A.GetX()-B.GetX())+(A.GetY()-B.GetY())*(A.GetY()-B.GetY()));
}

bool Bang(double a, double b){
    return fabs(a-b)<=0;
}

void cTamGiac::Nhap(){
    cout<<"Nhap toa dinh A: \n";
    A.Nhap();
    cout<<"Nhap toa dinh B: \n";
    B.Nhap();
    cout<<"Nhap toa dinh C: \n";
    C.Nhap();
}

void cTamGiac::Xuat(){
    cout<<"Toa do 3 dinh:\n";
    A.Xuat();
    B.Xuat();
    C.Xuat();
    cout<<endl;
}

void cTamGiac::KiemTra(){
    bool Vuong=0, Can=0;
    double a=TinhDoDai(B,C);
    double b=TinhDoDai(A,C);
    double c=TinhDoDai(A,B);
    if (Bang(a,b+c) || Bang(b,a+c) || Bang(c, a+b)) {
        cout<<"Day khong phai tam giac\n";
        return;
    }

    if (a==b && a==c) {
        cout<<"Day la tam giac deu\n";
        return;
    }

    if (Bang(a*a,b*b+c*c) || Bang(b*b,a*a+c*c) || Bang(c*c,a*a+b*b)) Vuong=1;

    if (a==b || a==c || b==c) Can=1;

    if (Vuong && Can) cout<<"Day la tam giac vuong can\n";

    else if (Vuong) cout<<"Day la tam giac vuong\n";

    else if (Can) cout<<"Day la tam giac can\n";

    else cout<<"Day la tam giac thuong\n";

}

double cTamGiac::ChuVi(){
    return TinhDoDai(A,B)+TinhDoDai(A,C)+TinhDoDai(B,C);
}
double cTamGiac::DienTich(){
    long double p=(TinhDoDai(A,B)+TinhDoDai(A,C)+TinhDoDai(B,C))/2;
    return sqrt(p*(p-TinhDoDai(A,B))*(p-TinhDoDai(A,C))*(p-TinhDoDai(B,C)));
}
void cTamGiac::TinhTien(double x, double y){
    A.SetX(A.GetX()+x); A.SetY(A.GetY()+y);
    B.SetX(B.GetX()+x); B.SetY(B.GetY()+y);
    C.SetX(C.GetX()+x); C.SetY(C.GetY()+y);
}

void cTamGiac::Quay(double k) {
    double xMoi, yMoi;
    k = k * M_PI / 180.0;
    xMoi = A.GetX()*cos(k) - A.GetY()*sin(k);
    yMoi = A.GetX()*sin(k) + A.GetY()*cos(k);
    A.SetX(xMoi); A.SetY(yMoi);

    xMoi = B.GetX()*cos(k) - B.GetY()*sin(k);
    yMoi = B.GetX()*sin(k) + B.GetY()*cos(k);
    B.SetX(xMoi); B.SetY(yMoi);

    xMoi = C.GetX()*cos(k) - C.GetY()*sin(k);
    yMoi = C.GetX()*sin(k) + C.GetY()*cos(k);
    C.SetX(xMoi); C.SetY(yMoi);
}
void cTamGiac::PhongTo(double k) {
    A.SetX(A.GetX() * k); A.SetY(A.GetY() * k);
    B.SetX(B.GetX() * k); B.SetY(B.GetY() * k);
    C.SetX(C.GetX() * k); C.SetY(C.GetY() * k);
}
void cTamGiac::ThuNho(double k) {
    if (k == 0) {cout<<"Ti le thu nho khong hop le!\n"; return;}
    A.SetX(A.GetX() / k); A.SetY(A.GetY() / k);
    B.SetX(B.GetX() / k); B.SetY(B.GetY() / k);
    C.SetX(C.GetX() / k); C.SetY(C.GetY() / k);
}
