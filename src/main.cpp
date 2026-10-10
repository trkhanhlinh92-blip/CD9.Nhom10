#include "../include/QuanLyTaiKhoan.h"

int main() {
    QuanLyTaiKhoan ql;
    int luachon;

    do {
        cout << "\n================ MENU QUAN LY TAI KHOAN ================\n";
        cout << "1. Nhap danh sach tai khoan\n";
        cout << "2. In danh sach tai khoan\n";
        cout << "3. Sap xep danh sach theo so du giam dan\n";
        cout << "4. Tim kiem tai khoan theo STK\n";
        cout << "5. Bo sung 1 tai khoan vao vi tri k\n";
        cout << "6. Xoa 1 tai khoan o vi tri k\n";
        cout << "7. Nap tien vao tai khoan\n";
        cout << "8. Rut tien tu tai khoan\n";
        cout << "9. Tinh tien lai du kien\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "========================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;

        switch (luachon) {
            case 1:
                ql.nhapDanhSach();
                break;
            case 2:
                ql.xuatDanhSach();
                break;
            case 3:
                ql.giamDan();
                break;
            case 4: {
                string tktim;
                cout << "Nhap so tai khoan can tim: ";
                cin >> tktim;
                int vt = ql.timKiem(tktim);
                if (vt != -1) {
                    cout << "=> Tim thay tai khoan tai vi tri " << vt + 1 << endl;
                } else {
                    cout << "=> Khong tim thay tai khoan co STK: " << tktim << endl;
                }
                break;
            }
            case 5: {
                int vitrithem;
                cout << "Nhap vi tri can them (tu 0 đen n): ";
                cin >> vitrithem;
                ql.boSung(vitrithem);
                break;
            }
            case 6: {
                int vitrixoa;
                cout << "Nhap vi tri can xoa (tu 0 đen n-1): ";
                cin >> vitrixoa;
                ql.xoa(vitrixoa);
                break;
            }
            case 7:
                ql.thaoTacNapRut(1);
                break;
            case 8:
                ql.thaoTacNapRut(2);
                break;
            case 9:
                ql.thaoTacNapRut(3);
                break;
            case 0:
                cout << "Da thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long nhap lai.\n";
        }
    } while (luachon != 0);

    return 0;
}
