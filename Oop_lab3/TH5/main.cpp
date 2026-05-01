#include "cNhanVienSX.cpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    CongTy cty;
    cty.Nhap();
    cout<<fixed<<setprecision(0);
    int chon;
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Xuat danh sach nhan vien\n";
        cout << "2. Nhan vien luong thap nhat\n";
        cout << "3. Tong luong cong ty\n";
        cout << "4. Nhan vien tuoi cao nhat\n";
        cout << "5. Sap xep theo luong tang dan\n";
        cout << "0. Thoat\n";
        cout << "Chon: "; cin >> chon;

        switch (chon) {
            case 1:
                cty.Xuat();
                break;
            case 2: {
                cNhanVienSX* nv = cty.NvMinLuong();
                if (nv) {
                    cout << "\nNhan vien luong thap nhat:\n";
                    nv->Xuat();
                }
                break;
            }
            case 3:
                cout << "\nTong luong: " << cty.TongLuong() << endl;
                break;
            case 4: {
                cNhanVienSX* nv = cty.NvMaxTuoi();
                if (nv) {
                    cout << "\nNhan vien tuoi cao nhat:\n";
                    nv->Xuat();
                }
                break;
            }
            case 5:
                cty.SapXepTheoLuongTangDan();
                cout << "\nDa sap xep. Danh sach moi:\n";
                cty.Xuat();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);

    return 0;
}
