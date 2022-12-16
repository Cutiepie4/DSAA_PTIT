#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

class sinhvien {
private:
    int maso;
    string hoten;
public:
    void setname(string name) {
        hoten = name;
    }

    void setmaso(int ma) {
        maso = ma;
    }

    void nhapsv() {
        cin >> maso >> hoten;
    }

    void xemsv() {
        cout << maso << " " << hoten << endl;
    }

    int getma() {
        return maso;
    }

    string getname() {
        return hoten;
    }
};

class lop {
private:
    string malop;
    vector <sinhvien> dssv;
public:
    vector <sinhvien> getdssv() {
        return dssv;
    }

    void nhapbp() {
        cout << "nhap so sv: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            sinhvien a;
            a.nhapsv();
            dssv.push_back(a);
        }
    }

    void xemmh() {
        cout << "danh sach lop co " << dssv.size() << " sinh vien:" << endl;
        for (int i = 0; i < dssv.size(); i++) {
            dssv[i].xemsv();
        }
    }

    void sapxep() {
        for (int i = 0; i < dssv.size(); i++) {
            for (int j = i + 1; j < dssv.size(); j++) {
                if (dssv[i].getma() > dssv[j].getma()) swap(dssv[i], dssv[j]);
            }
        }
    }
};

class diemsinhvien : public sinhvien {
private:
    int diem;
    string ketqua;
public:
    void nhapdslop(int x, string name) {
        diem = 0;
        ketqua = "TRUOT";
        sinhvien::setmaso(x);
        sinhvien::setname(name);
    }
    void nhapdiem() {
        cin >> diem;
        if (diem >= 4) ketqua = "QUA";
        else ketqua = "TRUOT";
    }
    void xemdiem() {
        sinhvien::xemsv();
        cout << "DIEM: " << diem << endl;
        cout << "KET QUA: " << ketqua << endl;
    }
};

class bangdiem {
private:
    string malop, monhoc;
    int tsqua, tshoclai;
    vector <diemsinhvien> dsdiem;
public:
    bangdiem(lop a) {
        vector <sinhvien> tmp = a.getdssv();
        for (int i = 0; i < tmp.size(); i++) {
            diemsinhvien a;
            a.nhapdslop(tmp[i].getma(), tmp[i].getname());
            dsdiem.push_back(a);
        }
    }
    void nhapbangdiem() {
        cout << "NHAP MA LOP, MON HOC: ";
        cin >> malop >> monhoc;
        for (int i = 0; i < dsdiem.size(); i++) {
            cout << "NHAP DIEM CHO SINH VIEN " << dsdiem[i].getname() << ": ";
            dsdiem[i].nhapdiem();
        }
    }
    void xembangdiem() {
        cout << "BANG DIEM LOP " << malop << " MON " << monhoc << " LA: " << endl;
        for (int i = 0; i < dsdiem.size(); i++) {
            dsdiem[i].xemdiem();
        }
    }
};

int main() {
    lop a;
    a.nhapbp();
    a.sapxep();
    a.xemmh();
    bangdiem b(a);
    b.nhapbangdiem();
    b.xembangdiem();
}