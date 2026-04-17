#ifndef SOPHUC_H
#define SOPHUC_H


class SoPhuc {
private:
    int iThuc;
    int iAo;


public:
    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc ps);
    SoPhuc Hieu(SoPhuc ps);
    SoPhuc Tich(SoPhuc ps);
    SoPhuc Thuong(SoPhuc ps);
};


#endif
