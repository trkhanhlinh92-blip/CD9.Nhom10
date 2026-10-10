#ifndef QUANLYTAIKHOAN_H
#define QUANLYTAIKHOAN_H

#include "TaiKhoan.h"

class QuanLyTaiKhoan {
private:
    TaiKhoan ds[200];
    int n;

public:
    QuanLyTaiKhoan();

    // Module Lê Kim Huế
    void nhapDanhSach();
    void xuatDanhSach() const;
    int timKiem(string tk) const;
    void thaoTacNapRut(int loai);

    // Module Đoàn Quang Huy
    void giamDan();
    void boSung(int vitri);
    void xoa(int vitri);
};

#endif
