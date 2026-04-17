    #include <iostream>
    #include "date.h"

    //ham tinh so ngay trong thang
    int TinhNgayTrongThang(int Thang, int Nam){
        if(Thang==2&&(Nam%400==0)||(Nam%4==0&&Nam%100!=0)){
            return 29;
        }
        else if(Thang==2){
            return 28;
        }
        else if((Thang%2==1 && Thang<8)||(Thang%2==0 && Thang>=8)){
            return 31;
        }
        else{
            return 30;
        }
    }

    //phuong thuc nhap
    void NgayThangNam::Nhap(){
        while(1){
            std::cout<<"vui long nhap nam: ";
            std::cin>>this->iNam;

            std::cout<<"vui long nhap thang: ";
            std::cin>>this->iThang;

            std::cout<<"vui long nhap ngay: ";
            std::cin>>this->iNgay;

            //xet lai ngay thang nam da nhap
            if(iNgay<=TinhNgayTrongThang(iThang,iNam)&&iNgay>=1&&iThang>=1&&iThang<=12){
                    break;
               }
            std::cout<<"Ngay Thang Nam da nhap khong hop he, vui long nhap lai."<<std::endl;
        }
    }

    //phuong thuc xuat ngay thang nam
    void NgayThangNam::Xuat(){
        std::cout<<"Ngay "<<iNgay<<" Thang "<<iThang<<" Nam "<<iNam<<std::endl;
    }

    //phuong thuc tinh ngay thang nam tiep theo
    void NgayThangNam::NgayThangNamTiepTheo(){
        int Ngay, Thang, Nam;
        if(iNgay==TinhNgayTrongThang(iThang,iNam)){
            Ngay=1;
            Thang = this->iThang+1;
        }
        else{
            Ngay=this->iNgay+1;
            Thang = this->iThang;
        }
        if(Ngay==1&&Thang>12){
            Nam=this->iNam+1;
            Thang=1;
        }
        else{
            Nam = this->iNam;
        }
        std::cout<<"Ngay Thang Nam tiep theo la: "<<"Ngay "<<Ngay<<" Thang "<<Thang<<" Nam "<<Nam<<std::endl;
    }
