#include "../include/TaiKhoan.h"

TaiKhoan::TaiKhoan() {
    stk = ten = loaitk = "";
    sodu = laisuat = 0.0;
}

TaiKhoan::TaiKhoan(string s, string t, string l, double sd, double ls)
    : stk(s), ten(t), loaitk(l), sodu(sd), laisuat(ls) {}

string TaiKhoan::getSTK() const { return stk; }
string TaiKhoan::getTen() const { return ten; }
string TaiKhoan::getLoaiTK() const { return loaitk; }
double TaiKhoan::getSodu() const { return sodu; }
double TaiKhoan::getLaisuat() const { return laisuat; }

void TaiKhoan::setSodu(double sd) { sodu = sd; }

void TaiKhoan::nhap() {
    cout << "  - Nhap so tai khoan: "; cin >> stk;
    cin.ignore();
    cout << "  - Nhap ho ten chu tk: "; getline(cin, ten);
    cout << "  - Nhap loai tai khoan: "; getline(cin, loaitk);
    do {
        cout << "  - Nhap so du hien tai (>= 0): "; cin >> sodu;
    } while (sodu < 0);
    do {
        cout << "  - Nhap lai suat (%/nam): "; cin >> laisuat;
    } while (laisuat < 0);
}

void TaiKhoan::xuat() const {
    cout << left << setw(12) << stk 
         << setw(22) << ten 
         << setw(15) << loaitk 
         << setw(15) << fixed << setprecision(2) << sodu 
         << setw(10) << fixed << setprecision(2) << laisuat << "%\n";
}

void TaiKhoan::naptien(double tien) {
    if (tien > 0) {
        sodu += tien;
        cout << "=> Nap tien thanh cong. So du moi: " << fixed << setprecision(2) << sodu << " VND\n";
    } else {
        cout << "=> LOI: So tien nap phai > 0!\n";
    }
}

void TaiKhoan::ruttien(double tien) {
    if (tien > 0 && tien <= sodu) {
        sodu -= tien;
        cout << "=> Rut tien thanh cong. So du moi: " << fixed << setprecision(2) << sodu << " VND\n";
    } else {
        cout << "=> LOI: So du khong du hoac so tien rut khong hop le!\n";
    }
}

double TaiKhoan::tinhlai() const {
    return sodu * (laisuat / 100.0);
}
