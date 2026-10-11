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
void QuanLyTaiKhoan::sapXepGiamDanSoDu() {
    if (n == 0) {
        cout << "=> Danh sach trong, khong the sap xep!\n";
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getSodu() < ds[j].getSodu()) {
                swap(ds[i], ds[j]);
            }
        }
    }
    cout << "=> Da sap xep danh sach giam dan theo so du thanh cong!\n";
}
void QuanLyTaiKhoan::themTaiKhoan(int k) {
    if (n >= 200) {
        cout << "=> LOI: Danh sach da day (toi da 200 tai khoan)!\n";
        return;
    }
    if (k < 0 || k > n) {
        cout << "=> LOI: Vi tri k = " << k << " khong hop le! (Cho phep tu 0 den " << n << ")\n";
        return;
    }

    TaiKhoan tkMoi;
    cout << "\n--- Nhap thong tin tai khoan can them ---\n";
    while (true) {
        tkMoi.nhap();
        bool trung = false;
        for (int i = 0; i < n; i++) {
            if (ds[i].getSTK() == tkMoi.getSTK()) {
                trung = true;
                break;
            }
        }
        if (trung) {
            cout << "=> LOI: So tai khoan da ton tai! Vui long nhap lai.\n";
        } else {
            break;
        }
    }

    for (int i = n; i > k; i--) {
        ds[i] = ds[i - 1];
    }
    ds[k] = tkMoi;
    n++;
    cout << "=> Da them tai khoan thanh cong vao vi tri " << k << "!\n";
}
void QuanLyTaiKhoan::xoaTaiKhoan(int k) {
    if (n == 0) {
        cout << "=> Danh sach trong, khong the xoa!\n";
        return;
    }
    if (k < 0 || k >= n) {
        cout << "=> LOI: Vi tri k = " << k << " khong hop le! (Cho phep tu 0 den " << n - 1 << ")\n";
        return;
    }

    for (int i = k; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    n--;
    cout << "=> Da xoa tai khoan tai vi tri " << k << " thanh cong!\n";
}
void QuanLyTaiKhoan::thucHienGiaoDich() {
    if (n == 0) {
        cout << "=> Danh sach trong!\n";
        return;
    }
    string stk;
    cout << "Nhap so tai khoan can giao dich: ";
    cin >> stk;

    int pos = timKiemBySTK(stk);
    if (pos == -1) {
        cout << "=> Khong tim thay tai khoan co STK: " << stk << endl;
        return;
    }

    cout << "\nTai khoan: " << ds[pos].getTen() << " - So du hien tai: " << fixed << setprecision(2) << ds[pos].getSodu() << " VND\n";
    cout << "1. Nap tien\n2. Rut tien\nChon thao tac (1-2): ";
    int luaChon;
    cin >> luaChon;

    if (luaChon == 1) {
        double tien;
        cout << "Nhap so tien muon nap: ";
        cin >> tien;
        ds[pos].naptien(tien);
    } else if (luaChon == 2) {
        double tien;
        cout << "Nhap so tien muon rut: ";
        cin >> tien;
        ds[pos].ruttien(tien);
    } else {
        cout << "=> Lua chon khong hop le!\n";
    }
}
void QuanLyTaiKhoan::inBangTinhLai() const {
    if (n == 0) {
        cout << "=> Danh sach trong!\n";
        return;
    }
    cout << "\n============================== BANG TINH TIEN LAI DU KIEN (1 NAM) ==============================\n";
    cout << left << setw(12) << "STK" 
         << setw(22) << "Ho va Ten" 
         << setw(15) << "So Du (VND)" 
         << setw(12) << "Lai Suat" 
         << setw(18) << "Tien Lai/Nam" << endl;
    cout << "------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << ds[i].getSTK()
             << setw(22) << ds[i].getTen()
             << setw(15) << fixed << setprecision(2) << ds[i].getSodu()
             << setw(10) << fixed << setprecision(2) << ds[i].getLaisuat() << "%"
             << setw(18) << fixed << setprecision(2) << ds[i].tinhlai() << endl;
    }
    cout << "================================================================================================\n";
}
