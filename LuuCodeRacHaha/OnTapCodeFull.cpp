#include <iostream>
#include <cmath>
using namespace std;

void soLonNhatTrong3So() {
    int a, b, c;
    cin >> a >> b >> c;
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << "Max = " << max << endl;
}

void soLonNhat_soLonNhi_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int max1 = a;
    int max2 = -1;
    if (b > max1)
    {
        max2 = max1;
        max1 = b;
    }
    if (c > max1)
    {
        max2 = max1;
        max1 = c;
    }
    if (d > max1)
    {
        max2 = max1;
        max1 = d;
    }
    if (b > max2 && b < max1)
    {
        max2 = b;
    }
    if (c > max2 && c < max1)
    {
        max1 = c;
    }
    if (d > max2 && d < max2)
    {
        max2 = d;
    }
    cout << "Max1 = " << max1 << endl;
    cout << "Max2 = " << max2 << endl;
}

void kiemTraCapSoCong_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp = b - a;
    if (c - b == temp)
    {
        if (d - c == temp)
        {
            cout << "Day la cap so cong" << endl;
        }
        else
        {
            cout << "Day khong la cap so cong" << endl;
        }
    }
}

void kiemTraCapSoNhan_Trong4So() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp = b / a;
    if (c / b == temp)
    {
        if (d / c == temp)
        {
            cout << "Day la cap so nhan" << endl;
        }
        else
        {
            cout << "Day khong la cap so nhan" << endl;
        }
    }
}
// Kết thúc bài tập buổi 2
// Bắt đầu bài tập buổi 5
void tongCacSoChan_1denN() {
    int n;
    int sum = 0;
    cin >> n;
    for (size_t i = 2; i <= n; i+=2)
    {
        sum = sum + i;
    }
    cout << sum << endl;
}

void inRaCacUocSoCuaN() {
    int n;
    cin >> n;
    int m = sqrt(n);
    if (m*m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                cout << i << " " << n / i << " ";
            }
        }
        cout << m;
    }
    else
    {
        for (size_t i = 0; i <= m; i++)
        {
            if (n % i == 0)
            {
                cout << i << " " << n / i << " ";
            }
        }
    }
    cout << endl;
}

void demCacUocSoCuaN() {
    int n;
    cin >> n;
    int count = 0;
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                count = count + 2;
            }
        }
        count = count + 1;
    }
    else
    {
        for (size_t i = 2; i <= m; i++)
        {
            if (n % i == 0)
            {
                count = count + 2;
            }   
        }
    }
    cout << count << endl;
}

void TinhTongCacUocSoChanNhoHonN() {
    int n;
    cin >> n;
    int sum = 0;
    for (size_t i = 2; i < n; i+=2)
    {
        sum = sum + i;
    }
}

void inRaCacUocSoChinhPhuongCuaN() {
    int n;
    int a = 2;
    cin >> n;
    cout << 1 << " ";
    for (size_t i = a*a; i <= n; a++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

void tongCacSoChinhPhuongNhoHonN() {
    int n;
    int sum = 1;
    int a = 2;
    cin >> n;
    for (size_t i = a*a; i <= n; a++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
}

void kiemTraSoNguyenTo() {
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << "Khong la so Nguyen To";
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << "Khong la so nguyen to";
            break;
        }
    }
    cout << "La so nguyen to";
    cout << endl;
}

bool SoNguyenTo(int n) {
    int n;
    cin >> n;
    if (n < 2)
    {
        return false;
    }
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void inRaCacSoNguyenToNhoN() {
    int n;
    cin >> n;
    for (size_t i = 2; i < n; i++)
    {
        if (SoNguyenTo(i))
        {
            cout << i << " ";
        }
    }
}

int demUocSo(int n) {
    int n;
    cin >> n;
    int count = 0;
    int m = sqrt(n);
    if (m * m == n)
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0 && i != m)
            {
                count = count + 2;
            }
        }
        count = count + 1;
    }
    else
    {
        for (size_t i = 2; i <= m; i++)
        {
            if (n % i == 0)
            {
                count = count + 2;
            }   
        }
    }
    return count;
}

void inRaSoCoCacUocSoNhieuHonKhoangN_M() {
    int n, m;
    cin >> n >> m;
    int countN = demUocSo(n);
    int countM = demUocSo(n);
    for (size_t i = n + 1; i < m; i++)
    {
        if (demUocSo(i) > n && demUocSo(i) > m)
        {
            cout << i << " ";
        }
    }
}

void tongCacChuSoN() {
    int n;
    int sum = 0;
    cin >> n;
    while (n)
    {
        sum = sum + n%10;
        n = n / 10;
    }
    cout << sum << endl;
}

void inRaSoLonNhat() {
    int n;
    cin >> n;
    int max = 0;
    while (n)
    {
        if (n % 10 > max)
        {
            max = n % 10;
        }
        n = n / 10;
    }
    cout << max << endl;
}

void inRaCacUocSoNguyenToN() {
    int n;
    cin >> n;
    for (size_t i = 2; i <= n; i++)
    {
        if (n % i == 0 && SoNguyenTo(i))
        {
            cout << i  << " " << endl;
        }
    }
}

void soHanhPhuc() {
    int n;
    cin >> n;
    int sum = 0;
    int m = sqrt(n);
    if (m*m == n)
    {
        for (size_t i = 1; i < m; i++)
        {
            if (n % i == 0)
            {
                sum = sum + i + n/i;
            }
        }
    }
    else
    {
        for (size_t i = 1; i <= m; i++)
        {
            if (n % i == 0)
            {
                sum = sum + i + n/i;
            }
        }
    }
    if (sum == 2*n)
    {
        cout << "La so hanh phuc" << endl;
    }
    else
    {
        cout << "Khong la so hanh phuc" << endl;
    }
}

void soDoiXung() {
    int n;
    cin >> n;
    int temp = n;
    int sodoixung = 0;
    while (temp)
    {
        sodoixung = sodoixung + temp%10;
        sodoixung = sodoixung * 10;
        temp = temp / 10;
    }
    if (sodoixung/10 == n)
    {
        cout << "La so doi xung" << endl;
    }
    else
    {
        cout << "Khong la so doi xung" << endl;
    }
}

void lietKeSoDoiXungNhoHonN() {
    int n;
    cin >> n;
    for (size_t i = 11; i < n; i++)
    {
        cout << i << " ";
    }
}

void UCLN() {
    int n, m;
    cin >> n; 
    cin >> m;
    while (n != 0 && m!= 0)
    {
        if (n > m)
        {
            n = n % m;
        }
        else
        {
            m = m % n;
        }
    }
    if (n != 0)
    {
        cout << "UCLN = " << n;
    }
    else
    {
        cout << "UCLN = " << m;
    }
}

int Check_UCLN(int a, int b) {
    while (a != 0 && b!= 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a != 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void BCNN() {
    int n, int m;
    cin >> n;
    cin >> m;
    cout << (n*m)/Check_UCLN(n, m);
}

void phanTichThuaSoNguyenTo() { 
    int n;
    cin >> n;
    int i = 2;
    if (n == 1)
    {
        cout << "Khong phan tich duoc" << endl;
    }
    while (n > 1)
    {
        if (n % i == 0 && SoNguyenTo(n))
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n = n / i;
            }   
        }
        i++;
    }   
}

void doiSoThapPhanSangNhiPhan(int n) {
    int n;
    cin >> n;
    while (n)
    {
        cout << n % 2;
        n = n / 2;
    }
}
//Kết thúc bài tập buổi 5

void nhapMang2Chieu(int a[][50]) {
    for (size_t i = 0; i < 50; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            cin >> a[i][j];
        }
    }
}

void xuatMang2Chieu(int a[][50]) {
    for (size_t i = 0; i < 50; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

void inCacPhanTuTrenDuongCheoChinh() {
    int a[50][50];
    int row;
    int col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    if (row != col)
    {
        cout << "Khong phai ma tran vuong";
    }
    else
    {
        int i = 0;
        int j = 0;
        while (i != row)
        {
            cout << a[i][j] << " ";
            i++; j++;
        }
    }
}

void inCacPhanTuNamTrenBien() {
    int a[50][50];
    int row, col;
    cin >> row;
    cin >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        if (i == 0 || i == row-1)
        {
            for (size_t j = 0; j < col; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << a[i][0] << " " << a[i][col-1] << endl;
        }
    }
}

void inTongMoiHang() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
        
    }
    for (size_t i = 0; i < row; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < col; j++)
        {
            sum = sum + a[i][j];
        }
        cout << sum << endl;
    }
}

void inTongMoiCot() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < row; j++)
        {
            sum = sum + a[j][i];
        }
        cout << sum << endl;
    }
}

void inHangCoTongLonNhat() {
    int a[50][50];
    int sum[50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            sum[i] = sum[i] + a[i][j];
        }
    }
    int max = 0;
    int pos = 0;
    for (size_t i = 0; i < row; i++)
    {
        if (max < sum[i])
        {
            max = sum[i];
            pos = i;
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        cout << a[pos][i];
    }
    
}

void inCotCoTongLonNhat() {
    int a[50][50];
    int sum[50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            sum[i] = sum[i] + a[j][i];
        }
    }
    int max = 0;
    int pos = 0;
    for (size_t i = 0; i < row; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
            pos = i;
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        cout << a[i][pos] << " ";
    }
}

void inGiaTriLonNhatMoiHang() {
    int a[50][50];
    int row, col;
    cin >> row, col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        int max = a[i][0];
        for (size_t j = 0; j < col; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        cout << max << endl;
    }
}

void inGiaTriNhoNhatMoiCot() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        int min = a[0][i];
        for (size_t j = 0; j < row; j++)
        {
            if (a[j][i] < min)
            {
                min = a[j][i];
            }
        }
        cout << min << endl;
    }
}

void sapXepThuTuGiamDanMoiHang() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col-1; j++)
        {
            for (size_t k = 0; k < col; k++)
            {
                int temp = 0;
                if (a[i][k] < a[i][k+1])
                {
                    temp = a[i][k];
                    a[i][k] = a[i][k+1];
                    a[i][k+1] = temp;
                }
            }
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void sapXepThuTuTangDanMoiHang() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        
        for (size_t j = 0; j < col; j++)
        {
            int temp = 0;
            for (size_t k = 0; k < col - 1; k++)
            {
                if (a[i][k] > a[i][k+1])
                {
                    temp = a[i][k+1];
                    a[i][k+1] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void sapXepThuTuGiamDanMoiCot() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            for (size_t k = 0; k < row-1; k++)
            {
                int temp = 0;
                if (a[k][i] < a[k+1][i])
                {
                    temp = a[k][i];
                    a[k][i] = a[k+1][i];
                    a[k+1][i] = temp;
                }
            }          
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void sapXepThuTuTangDanMoiCot() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row-1; j++)
        {
            for (size_t k = 0; k < row; k++)
            {
                int temp = 0;
                if (a[k][i] > a[k+1][i])
                {
                    temp = a[k+1][i];
                    a[k+1][i] = a[k][i];
                    a[k][i] = temp;
                }
            }
        }
    }
    
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool SoChinhPhuong(int n) {
    int sqrtN = sqrt(n);
    if (sqrtN * sqrtN == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inRaSoChinhPhuongMoiCot() {
    int a[50][50];
    int row, col;
    cin >> row >> col;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (SoChinhPhuong(a[j][i]))
            {
                cout << a[j][i] << " ";
            }
        }
        cout << endl;
    }
    
}

int main() {

}