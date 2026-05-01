#ifndef cTamGiac_H
#define cTamGiac_H

class Diem{
private:
    double x;
    double y;
public:
    Diem();
    Diem(double a, double b);
    Diem (Diem &A);
    void Nhap();
    void Xuat();
    double GetX() const;
    double GetY() const;
    void SetX(double x);
    void SetY(double y);
};

class cTamGiac{
private:
    Diem A;
    Diem B;
    Diem C;
public:
    cTamGiac();
    cTamGiac(Diem X, Diem Y, Diem Z);
    cTamGiac(cTamGiac &ABC);
    void Nhap();
    void Xuat();
    void KiemTra();
    double ChuVi();
    double DienTich();
    void TinhTien(double x, double y);
    void Quay(double k);
    void PhongTo(double k);
    void ThuNho(double k);
};

#endif // cTamGiac_H
