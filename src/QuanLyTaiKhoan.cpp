#include "../include/QuanLyTaiKhoan.h"

QuanLyTaiKhoan::QuanLyTaiKhoan() {
    n = 0;
}

int QuanLyTaiKhoan::getSoLuong() const {
    return n;
}

// Nhap danh sach tai khoan
void QuanLyTaiKhoan::nhapDanhSach() {
    do {
        cout << "Nhap so luong tai khoan (0 < n < 200): ";
        cin >> n;
    } while (n <= 0 || n >= 200);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin tai khoan thu " << i + 1 << " ---\n";
        while (true) {
            ds[i].nhap();
            bool trung = false;
            for (int j = 0; j < i; j++) {
                if (ds[j].getSTK() == ds[i].getSTK()) {
                    trung = true;
                    break;
                }
            }
            if (trung) {
                cout << "=> LOI: So tai khoan nay da ton tai! Vui long nhap lai.\n";
            } else {
                break;
            }
        }
    }
    cout << "\n=> Da nhap thanh cong danh sach " << n << " tai khoan!\n";
}

// Xuat danh sach tai khoan
void QuanLyTaiKhoan::xuatDanhSach() const {
    if (n == 0) {
        cout << "=> Danh sach tai khoan dang trong!\n";
        return;
    }
    cout << "\n================================ DANH SACH TAI KHOAN NGAN HANG ================================\n";
    cout << left << setw(12) << "STK" 
         << setw(22) << "Ho va Ten" 
         << setw(15) << "Loai TK" 
         << setw(15) << "So Du (VND)" 
         << setw(10) << "Lai Suat" << endl;
    cout << "------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
    cout << "================================================================================================\n";
}

// Tim kiem theo So tai khoan
int QuanLyTaiKhoan::timKiemBySTK(string stk) const {
    for (int i = 0; i < n; i++) {
        if (ds[i].getSTK() == stk) {
            return i;
        }
    }
    return -1;
}

// Tim kiem theo Ten chu tai khoan
void QuanLyTaiKhoan::timKiemTheoTen() const {
    if (n == 0) {
        cout << "=> Danh sach trong!\n";
        return;
    }
    cin.ignore();
    string tenCanTim;
    cout << "Nhap ho ten (hoac tu khoa) can tim: ";
    getline(cin, tenCanTim);

    bool timThay = false;
    cout << "\n--- KET QUA TIM KIEM THEO TEN ---\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getTen().find(tenCanTim) != string::npos) {
            ds[i].xuat();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "=> Khong tim thay tai khoan phu hop voi tu khoa!\n";
    }
}
