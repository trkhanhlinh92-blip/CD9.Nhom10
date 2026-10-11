#include <iostream>
#include <string>
#include "../include/QuanLyTaiKhoan.h"

using namespace std;

void hienThiMenu() {
    cout << "\n========================================================\n";
    cout << "      CHUYEN DE 9: QUAN LY TAI KHOAN NGAN HANG (OOP)     \n";
    cout << "========================================================\n";
    cout << " 1. Nhap danh sach tai khoan moi                       \n";
    cout << " 2. In danh sach tai khoan                             \n";
    cout << " 3. Tim kiem tai khoan theo So Tai Khoan (STK)         \n";
    cout << " 4. Tim kiem tai khoan theo Ten chu tai khoan          \n";
    cout << " 5. Sap xep danh sach giam dan theo So Du              \n";
    cout << " 6. Them 1 tai khoan moi vao vi tri k                  \n";
    cout << " 7. Xoa 1 tai khoan tai vi tri k                       \n";
    cout << " 8. Thuc hien giao dich (Nap / Rut tien)               \n";
    cout << " 9. In bang tinh tien lai du kien hang nam             \n";
    cout << " 0. Thoat chuong trinh                                 \n";
    cout << "========================================================\n";
    cout << "Nhap lua chon cua ban (0-9): ";
}

int main() {
    QuanLyTaiKhoan ql;
    int chon;

    do {
        hienThiMenu();
        cin >> chon;

        switch (chon) {
        case 1:
            ql.nhapDanhSach();
            break;
        case 2:
            ql.xuatDanhSach();
            break;
        case 3: {
            if (ql.getSoLuong() == 0) {
                cout << "=> Danh sach trong!\n";
                break;
            }
            string stk;
            cout << "Nhap STK can tim: ";
            cin >> stk;
            int pos = ql.timKiemBySTK(stk);
            if (pos != -1) {
                cout << "=> Tim thay tai khoan tai vi tri index [" << pos << "]:\n";
            } else {
                cout << "=> Khong tim thay tai khoan co STK: " << stk << endl;
            }
            break;
        }
        case 4:
            ql.timKiemTheoTen();
            break;
        case 5:
            ql.sapXepGiamDanSoDu();
            ql.xuatDanhSach();
            break;
        case 6: {
            int k;
            cout << "Nhap vi tri k can them (0 <= k <= " << ql.getSoLuong() << "): ";
            cin >> k;
            ql.themTaiKhoan(k);
            break;
        }
        case 7: {
            if (ql.getSoLuong() == 0) {
                cout << "=> Danh sach trong!\n";
                break;
            }
            int k;
            cout << "Nhap vi tri k can xoa (0 <= k < " << ql.getSoLuong() << "): ";
            cin >> k;
            ql.xoaTaiKhoan(k);
            break;
        }
        case 8:
            ql.thucHienGiaoDich();
            break;
        case 9:
            ql.inBangTinhLai();
            break;
        case 0:
            cout << "\nCam on ban da su dung chuong trinh! Tam biet.\n";
            break;
        default:
            cout << "\n=> Lua chon khong hop le! Vui long nhap tu 0 den 9.\n";
            break;
        }

    } while (chon != 0);

    return 0;
}
