#ifndef cDaGiac_H
#define cDaGiac_H

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

class cDaGiac {
private:
    Diem *dinh;
    int n;
public:
    cDaGiac();
    cDaGiac(int n, Diem *ds);
    cDaGiac(const cDaGiac &dg);
    ~cDaGiac();
    void Nhap();
    void Xuat();
    bool KiemTra();
    double ChuVi();
    long double DienTich();
    void TinhTien(double x, double y);
    void Quay(double k);
    void PhongTo(double k);
    void ThuNho(double k);
};

#endif // cDaGiac_H
