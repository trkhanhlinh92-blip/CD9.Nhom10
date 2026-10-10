#include "../include/QuanLyTaiKhoan.h"
#include <iomanip>

QuanLyTaiKhoan::QuanLyTaiKhoan() : n(0) {}

// === PHÂN HỆ CỦA LÊ KIM HUẾ ===
void QuanLyTaiKhoan::nhapDanhSach() {
    do {
        cout << "Nhap so luong tai khoan (0 < n < 200): ";
        cin >> n;
        if (n <= 0 || n >= 200) {
            cout << "So luong khong hop le! Vui long nhap lai.\n";
        }
    } while (n <= 0 || n >= 200);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin tai khoan thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }
}

void QuanLyTaiKhoan::xuatDanhSach() const {
    if (n == 0) {
        cout << "Danh sach tai khoan dang trong!\n";
        return;
    }
    cout << "\n================================ DANH SACH TAI KHOAN ================================\n";
    cout << left << setw(5) << "STT"
         << setw(12) << "STK" 
         << setw(22) << "Ho Ten" 
         << setw(15) << "Loai TK" 
         << setw(15) << "So Du" 
         << setw(10) << "Lai Suat" << endl;
    cout << "------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1;
void QuanLyTaiKhoan::giamDan() {
    if (n <= 0) {
        cout << "Danh sach dang trong!\n";
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getSodu() < ds[j].getSodu()) {
                TaiKhoan temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "=> Da sap xep danh sach theo so du giam dan thanh cong.\n";
}

void QuanLyTaiKhoan::boSung(int vitri) {
    if (n >= 200) {
        cout << "Danh sach da day (toi da 200), khong the bo sung!\n";
        return;
    }
    if (vitri < 0 || vitri > n) {
        cout << "Vi tri bo sung khong hop le!\n";
        return;
    }

    TaiKhoan tkm;
    cout << "Nhap thong tin tai khoan can bo sung:\n";
    tkm.nhap();
#include "../include/QuanLyTaiKhoan.h"
