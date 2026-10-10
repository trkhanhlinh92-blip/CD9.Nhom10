#ifndef TAIKHOAN_H
#define TAIKHOAN_H

#include <iostream>
#include <string>

using namespace std;

class TaiKhoan {
private:
    string stk;
    string ten;
    string loaitk;
    double sodu;
    double laisuat;

public:
    TaiKhoan();
    TaiKhoan(string s, string t, string l, double sd, double ls);

    // Getters and Setters
    string getSTK() const;
    string getTen() const;
    string getLoaiTK() const;
    double getSodu() const;
    double getLaisuat() const;

    void setSodu(double sd);

    // Cac phuong thuc nghiep vu
    void nhap();
    void xuat() const;
    void naptien(double tien);
    void ruttien(double tien);
    double tinhlai() const;
};

#endif
