#include "cArray.cpp"
#include <iostream>
#include <climits>
using namespace std;

int main() {
    cArray a;

    cout << "===== NHAP MANG =====\n";
    a.Nhap();

    cout << "\n===== MANG VUA NHAP =====\n";
    a.Xuat();

    cout << "\n===== DEM SO LAN XUAT HIEN =====\n";
    int x;
    cout << "Nhap gia tri x can dem: "; cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang: "
         << a.demSoLanXuatHien(x) << endl;

    cout << "\n===== KIEM TRA TANG DAN =====\n";
    if (a.kiemTraTangDan())
        cout << "Mang co thu tu TANG DAN.\n";
    else
        cout << "Mang KHONG co thu tu tang dan.\n";

    cout << "\n===== TIM PHAN TU LE NHO NHAT =====\n";
    int pl = a.timPhanTuLeNhat();
    if (pl == INT_MAX)
        cout << "Mang khong co so le.\n";
    else
        cout << "Phan tu le nho nhat: " << pl << endl;

    cout << "\n===== TIM SO NGUYEN TO LON NHAT =====\n";
    int nt = a.timNguyenToLonNhat();
    if (nt == -1)
        cout << "Mang khong co so nguyen to.\n";
    else
        cout << "So nguyen to lon nhat: " << nt << endl;

    cout << "\n===== SAP XEP TANG DAN =====\n";
    cArray tangDan(a);
    tangDan.sapXepTangDan();
    tangDan.Xuat();

    cout << "\n===== SAP XEP GIAM DAN =====\n";
    cArray giamDan(a);
    giamDan.sapXepGiamDan();
    giamDan.Xuat();

    return 0;
}

