#ifndef cDaThuc_H
#define cDaThuc_H
#include <iostream>
using namespace std;

class cDaThuc {
private:
    int bac;
    double* heSo;

public:
    cDaThuc();
    cDaThuc(int bac);
    cDaThuc(const cDaThuc& dt);
    ~cDaThuc();

    int getBac() const;
    double getHeSo(int i) const;
    void setHeSo(int i, double hs);

    void Nhap();
    void Xuat() const;
    double TinhGiaTri(double x) const;

    cDaThuc Cong(const cDaThuc& dt) const;
    cDaThuc Tru(const cDaThuc& dt) const;
};


#endif // cDaThuc_H
