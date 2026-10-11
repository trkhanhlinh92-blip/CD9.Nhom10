#ifndef QUANLYTAIKHOAN_H
#define QUANLYTAIKHOAN_H

#include "TaiKhoan.h"

class QuanLyTaiKhoan {
private:
    TaiKhoan ds[200];
    int n;

public:
    QuanLyTaiKhoan();

    int getSoLuong() const;

    // Phan he I/O & Tim kiem 
    void nhapDanhSach();
    void xuatDanhSach() const;
    int timKiemBySTK(string stk) const;
    void timKiemTheoTen() const;
    void sapXepGiamDanSoDu();
    void themTaiKhoan(int k);
    void xoaTaiKhoan(int k);
    void thucHienGiaoDich();
    void inBangTinhLai() const;
};

#endif
