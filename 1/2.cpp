#include <iostream>
#include <string>

using namespace std;

class SinhVien {
public:
    string name;
    float diem[3];
    float diem_trung_binh;

    void tinh_diem_trung_binh() {
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += diem[i];
        }
        diem_trung_binh = sum / 3;
    }
};

int main() {
    int n;
    SinhVien sv_highest;
    cin >> n;

    SinhVien *ds_sv = new SinhVien[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, ds_sv[i].name);
        cin >> ds_sv[i].diem[0] >> ds_sv[i].diem[1] >> ds_sv[i].diem[2];
        cin.ignore();
        ds_sv[i].tinh_diem_trung_binh();

        if (i == 0 || ds_sv[i].diem_trung_binh > sv_highest.diem_trung_binh) {
            sv_highest = ds_sv[i];
        } else if (ds_sv[i].diem_trung_binh == sv_highest.diem_trung_binh
                   && ds_sv[i].name < sv_highest.name) {
            sv_highest = ds_sv[i];
        }
    }

    cout << sv_highest.name << endl;

    delete[] ds_sv;

    return 0;
}
