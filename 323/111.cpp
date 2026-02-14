#include <iostream>

using namespace std;

// 1. Hàm đệ quy kiểm tra số nguyên tố
bool laNguyenTo(int x, int d) {
    if (x < 2) return false;
    if (d * d > x) return true; // Điều kiện dừng: không tìm thấy ước nào
    if (x % d == 0) return false;
    return laNguyenTo(x, d + 1); // Thử với số chia tiếp theo
}

// 2. Hàm đệ quy tính tổng n số nguyên tố đầu tiên
long long tinhTong(int n, int bienDem, long long tong) {
    if (n == 0) return tong; // Điều kiện dừng: đã tìm đủ n số
    
    if (laNguyenTo(bienDem, 2)) {
        // Nếu là số nguyên tố: giảm n, cộng vào tổng, kiểm tra số tiếp theo
        return tinhTong(n - 1, bienDem + 1, tong + bienDem);
    } else {
        // Nếu không: giữ nguyên n và tổng, kiểm tra số tiếp theo
        return tinhTong(n, bienDem + 1, tong);
    }
}

// 3. Hàm đệ quy nhập n (nhập lại nếu n không thỏa 0 < n <= 50)
int nhapN() {
    int n;
    cin >> n;
    if (n <= 0 || n > 50) {
        cout << "Gia tri vua nhap la " << n << ", khong hop le. Vui long nhap lai." << endl;
        return nhapN(); // Gọi đệ quy để nhập lại
    }
    return n;
}

int main() {
    int n = nhapN();
    
    // Bắt đầu tìm số nguyên tố từ số 2, tổng ban đầu là 0
    cout << "Tong " << n << " so nguyen to dau tien la: " << tinhTong(n, 2, 0);
    
    return 0;
}