#include "cDaThuc.h"
#include <cmath>
#include <iomanip>

cDaThuc::cDaThuc() {
    bac = 0;
    heSo = new double[1];
    heSo[0] = 0;
}

cDaThuc::cDaThuc(int bac) {
    this->bac = bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        heSo[i] = 0;
}


cDaThuc::cDaThuc(const cDaThuc& dt) {
    bac = dt.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
        heSo[i] = dt.heSo[i];
}

cDaThuc::~cDaThuc() {
    delete[] heSo;
}

int cDaThuc::getBac() const { return bac; }

double cDaThuc::getHeSo(int i) const {
    if (i < 0 || i > bac) return 0;
    return heSo[i];
}

void cDaThuc::setHeSo(int i, double hs) {
    if (i >= 0 && i <= bac)
        heSo[i] = hs;
}

void cDaThuc::Nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    delete[] heSo;
    heSo = new double[bac + 1];
    cout << "Nhap he so (tu bac cao nhat den hang so):\n";
    for (int i = 0; i <= bac; i++) {
        cout << "  He so x^" << (bac - i) << ": ";
        cin >> heSo[i];
    }
}

static void inHeSo(double hs) {
    if (hs == (int)hs)
        cout << (int)hs;
    else
        cout << hs;
}

void cDaThuc::Xuat() const {
    bool daCo = false;
    for (int i = 0; i <= bac; i++) {
        int luy = bac - i;
        double hs = heSo[i];
        if (hs == 0) continue;

        if (daCo)
            cout << (hs > 0 ? " + " : " - ");
        else if (hs < 0)
            cout << "-";

        double absHs = abs(hs);

        if (luy == 0) {
            inHeSo(absHs);
        } else if (luy == 1) {
            if (absHs != 1) inHeSo(absHs);
            cout << "x";
        } else {
            if (absHs != 1) inHeSo(absHs);
            cout << "x^" << luy;
        }
        daCo = true;
    }
    if (!daCo) cout << "0";
    cout << endl;
}

double cDaThuc::TinhGiaTri(double x) const {
    double kq = 0;
    for (int i = 0; i <= bac; i++)
        kq = kq * x + heSo[i];
    return kq;
}

cDaThuc cDaThuc::Cong(const cDaThuc& dt) const {
    int bacMax = max(bac, dt.bac);
    cDaThuc kq(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double hs1 = (i >= bacMax - bac)   ? heSo[i - (bacMax - bac)]    : 0;
        double hs2 = (i >= bacMax - dt.bac) ? dt.heSo[i - (bacMax - dt.bac)] : 0;
        kq.heSo[i] = hs1 + hs2;
    }
    return kq;
}

cDaThuc cDaThuc::Tru(const cDaThuc& dt) const {
    int bacMax = max(bac, dt.bac);
    cDaThuc kq(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double hs1 = (i >= bacMax - bac)    ? heSo[i - (bacMax - bac)]       : 0;
        double hs2 = (i >= bacMax - dt.bac) ? dt.heSo[i - (bacMax - dt.bac)] : 0;
        kq.heSo[i] = hs1 - hs2;
    }
    return kq;
}
