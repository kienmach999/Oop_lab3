#include "cNhanVienSX.h"
#include <iostream>
#include <string>
using namespace std;

//------NhanVien------
cNhanVienSX::cNhanVienSX() {
    MaNV = 0;
    Name = "";
    NgaySinh = {1, 1, 2000};
    SoSP = 0;
    GiaSP = 0.0;
}
cNhanVienSX::cNhanVienSX(int MaNV, string Name, Birth NgaySinh, int SoSP, double GiaSP) {
    this->MaNV = MaNV;
    this->Name = Name;
    this->NgaySinh = NgaySinh;
    this->SoSP = SoSP;
    this->GiaSP = GiaSP;
}
cNhanVienSX::cNhanVienSX(const cNhanVienSX &nv) {
    MaNV = nv.MaNV; Name = nv.Name;
    NgaySinh = nv.NgaySinh; SoSP = nv.SoSP; GiaSP = nv.GiaSP;
}

int cNhanVienSX::getMaNV() {return MaNV;}
string cNhanVienSX::getName() {return Name;}
Birth cNhanVienSX::getNgaySinh() {return NgaySinh;}
int cNhanVienSX::getSoSP() {return SoSP;}
double cNhanVienSX::getGiaSP() {return GiaSP;}
void cNhanVienSX::setMaNV(int maNV) {MaNV = maNV;}
void cNhanVienSX::setName(string name) {Name = name;}
void cNhanVienSX::setNgaySinh(Birth ns) {NgaySinh = ns;}
void cNhanVienSX::setSoSP(int soSP) {SoSP = soSP;}
void cNhanVienSX::setGiaSP(double giaSP) {GiaSP = giaSP;}

long double cNhanVienSX::getLuong() {
    return (long double)SoSP * GiaSP;
}

void cNhanVienSX::Nhap() {
    cout << "Ma nhan vien: "; cin >> MaNV;
    cin.ignore();
    cout << "Ho ten: "; getline(cin, Name);
    cout << "Ngay sinh (dd mm yyyy): ";
    cin >> NgaySinh.d >> NgaySinh.m >> NgaySinh.y;
    cout << "So san pham gia cong: "; cin >> SoSP;
    cout << "Don gia mot san pham: "; cin >> GiaSP;
}

void cNhanVienSX::Xuat() {
    cout << "Ma NV: " << MaNV
         << " | Ho ten: " << Name
         << " | Ngay sinh: " << NgaySinh.d << "/" << NgaySinh.m << "/" << NgaySinh.y
         << " | So SP: " << SoSP
         << " | Don gia: " << GiaSP
         << " | Luong: " << getLuong()
         << endl;
}

//-----Cong ty-----
CongTy::CongTy() {
    soNV = 0;
    dsNV = nullptr;
}

CongTy::CongTy(int n, cNhanVienSX* ds) {
    soNV = n;
    dsNV = new cNhanVienSX[n];
    for (int i = 0; i < n; i++)
        dsNV[i] = ds[i];
}

CongTy::CongTy(const CongTy &cty) {
    soNV = cty.soNV;
    dsNV = new cNhanVienSX[soNV];
    for (int i = 0; i < soNV; i++)
        dsNV[i] = cty.dsNV[i];
}

CongTy::~CongTy() {
    delete[] dsNV;
}

void CongTy::Nhap() {
    cout << "Nhap so nhan vien: "; cin >> soNV;
    delete[] dsNV;
    dsNV = new cNhanVienSX[soNV];
    for (int i = 0; i < soNV; i++) {
        cout << "\n--- Nhan vien thu " << i + 1 << " ---\n";
        dsNV[i].Nhap();
    }
}

void CongTy::Xuat() {
    cout << "\n===== DANH SACH NHAN VIEN SAN XUAT =====\n";
    for (int i = 0; i < soNV; i++) {
        cout << i + 1 << ". ";
        dsNV[i].Xuat();
    }
}

cNhanVienSX* CongTy::NvMinLuong() {
    if (soNV == 0) return nullptr;
    int minIdx = 0;
    for (int i = 1; i < soNV; i++)
        if (dsNV[i].getLuong() < dsNV[minIdx].getLuong())
            minIdx = i;
    return &dsNV[minIdx];
}

long double CongTy::TongLuong() {
    long double tong = 0;
    for (int i = 0; i < soNV; i++)
        tong += dsNV[i].getLuong();
    return tong;
}

cNhanVienSX* CongTy::NvMaxTuoi() {
    if (soNV == 0) return nullptr;
    int maxIdx = 0;
    for (int i = 1; i < soNV; i++) {
        Birth b1 = dsNV[i].getNgaySinh();
        Birth b2 = dsNV[maxIdx].getNgaySinh();
        // Tuoi cao nhat = nam sinh nho nhat
        if (b1.y < b2.y ||
           (b1.y == b2.y && b1.m < b2.m) ||
           (b1.y == b2.y && b1.m == b2.m && b1.d < b2.d))
            maxIdx = i;
    }
    return &dsNV[maxIdx];
}

void CongTy::SapXepTheoLuongTangDan() {
    for (int i = 0; i < soNV - 1; i++)
        for (int j = 0; j < soNV - i - 1; j++)
            if (dsNV[j].getLuong() > dsNV[j + 1].getLuong())
                swap(dsNV[j], dsNV[j + 1]);
}

