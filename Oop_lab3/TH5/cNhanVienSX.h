#ifndef cNhanVienSX_H
#define cNhanVienSX_H
#include <string>
using namespace std;
struct Birth {
    int d;
    int m;
    int y;
};

class cNhanVienSX{
private:
    int MaNV;
    string Name;
    Birth NgaySinh;
    int SoSP;
    double GiaSP;
public:
    cNhanVienSX();
    cNhanVienSX(int MaNV, string Name, Birth NgaySinh, int SoSP, double GiaSP);
    cNhanVienSX(const cNhanVienSX &nv);
    int getMaNV();
    string getName();
    Birth getNgaySinh();
    int getSoSP();
    double getGiaSP();
    void setMaNV(int maNV);
    void setName(string name);
    void setNgaySinh(Birth ns);
    void setSoSP(int soSP);
    void setGiaSP(double giaSP);
    void Nhap();
    void Xuat();
    long double getLuong();
};

class CongTy{
private:
    int soNV;
    cNhanVienSX* dsNV;
public:
    CongTy();
    CongTy(int n, cNhanVienSX* ds);
    CongTy(const CongTy &cty);
    ~CongTy();
    void Nhap();
    void Xuat();
    cNhanVienSX* NvMinLuong();
    long double TongLuong();
    cNhanVienSX* NvMaxTuoi();
    void SapXepTheoLuongTangDan();
};

#endif // cNhanVienSX_H
