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
        ds[i].xuat();
    }
    cout << "================================================================--------------------\n";
}

int QuanLyTaiKhoan::timKiem(string tk) const {
    for (int i = 0; i < n; i++) {
        if (ds[i].getSTK() == tk) return i;
    }
    return -1;
}

void QuanLyTaiKhoan::thaoTacNapRut(int loai) {
    if (n == 0) {
        cout << "Danh sach tai khoan dang trong!\n";
        return;
    }
    string stk;
    cout << "Nhap so tai khoan can thao tac: "; cin >> stk;
    int idx = timKiem(stk);
    if (idx == -1) {
        cout << "Khong tim thay tai khoan co STK: " << stk << endl;
        return;
    }
    if (loai == 1) {
        double tien; cout << "Nhap so tien nap: "; cin >> tien;
        ds[idx].naptien(tien);
    } else if (loai == 2) {
        double tien; cout << "Nhap so tien rut: "; cin >> tien;
        ds[idx].ruttien(tien);
    } else if (loai == 3) {
        cout << "Tien lai du kien nhan duoc: " << fixed << setprecision(2) << ds[idx].tinhlai() << endl;
    }
}
