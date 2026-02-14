#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

int timUCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void SetPhanSo(PhanSo &ps, int tu, int mau = 1) {
    ps.tu = tu;
    ps.mau = (mau == 0) ? 1 : mau; 
}

void RutGon(PhanSo &ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) { 
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

void Nhap(PhanSo &ps) {
    int t, m;
    cin >> t >> m;
    SetPhanSo(ps, t, m);
    RutGon(ps);
}

void Xuat(PhanSo ps) {
    if (ps.mau == 1) cout << ps.tu;
    else cout << ps.tu << "/" << ps.mau;
}

PhanSo Cong(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    RutGon(kq);
    return kq;
}

PhanSo Cong(PhanSo ps, int n) {
    PhanSo psN;
    SetPhanSo(psN, n, 1);
    return Cong(ps, psN);
}

int SoSanh(PhanSo ps1, PhanSo ps2) {
    float v1 = (float)ps1.tu / ps1.mau;
    float v2 = (float)ps2.tu / ps2.mau;
    if (v1 > v2) return 1;
    if (v1 < v2) return -1;
    return 0;
}

int SoSanh(PhanSo ps, int n) {
    PhanSo psN; SetPhanSo(psN, n, 1);
    return SoSanh(ps, psN);
}

void NhapMang(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
        Nhap(a[i]);
    }
}

void XuatMang(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        Xuat(a[i]); cout << "  ";
    }
    cout << endl;
}

PhanSo TinhTongMang(PhanSo a[], int n) {
    PhanSo tong; SetPhanSo(tong, 0, 1);
    for (int i = 0; i < n; i++) {
        tong = Cong(tong, a[i]);
    }
    return tong;
}

PhanSo TimMax(PhanSo a[], int n) {
    PhanSo m = a[0];
    for (int i = 1; i < n; i++)
        if (SoSanh(a[i], m) == 1) m = a[i];
    return m;
}

PhanSo TimMin(PhanSo a[], int n) {
    PhanSo m = a[0];
    for (int i = 1; i < n; i++)
        if (SoSanh(a[i], m) == -1) m = a[i];
    return m;
}

void SapXepTang(PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (SoSanh(a[i], a[j]) == 1) swap(a[i], a[j]);
}

void SapXepGiam(PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (SoSanh(a[i], a[j]) == -1) swap(a[i], a[j]);
}

int main() {
    int n;
    cout << "Nhap so luong phan so n: "; cin >> n;
    PhanSo ds[n];

    NhapMang(ds, n);

    cout << "\n--- KET QUA ---" << endl;
    cout << "Danh sach vua nhap (rut gon): "; XuatMang(ds, n);

    PhanSo tong = TinhTongMang(ds, n);
    cout << "Tong cac phan so: "; Xuat(tong); cout << endl;

    PhanSo maxPS = TimMax(ds, n);
    PhanSo minPS = TimMin(ds, n);
    cout << "Phan so lon nhat: "; Xuat(maxPS); cout << endl;
    cout << "Phan so nho nhat: "; Xuat(minPS); cout << endl;

    SapXepTang(ds, n);
    cout << "Mang tang dan: "; XuatMang(ds, n);

    SapXepGiam(ds, n);
    cout << "Mang giam dan: "; XuatMang(ds, n);

    return 0;
}