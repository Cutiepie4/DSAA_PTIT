#include <bits/stdc++.h>
using namespace std;

class nhanvien {
private:
    int manhanvien, luongcoban;
    string hoten;
public:
    void nhapnhanvien() {
        cout << "nhap ma nhan vien, ho ten, luong co ban: ";
        cin >> manhanvien >> hoten >> luongcoban;
    }
    void xemnhanvien() {
        cout << manhanvien << " " << hoten << " " << luongcoban << endl;
    }
    int getmanv() {
        return manhanvien;
    }
    string gethoten() {
        return hoten;
    }
    int getluongcoban() {
        return luongcoban;
    }
    void setmanv(int x) {
        manhanvien = x;
    }
    void sethoten(string a) {
        hoten = a;
    }
    void setluongcoban(int x) {
        luongcoban = x;
    }
};

class danhsach {
private:
    vector <nhanvien> ds;
    int sonv;
public:
    void nhapnhanvien() {
        cout << "nhap so nhan vien: ";
        cin >> sonv;
        for (int i = 0; i < sonv; i++) {
            nhanvien a;
            a.nhapnhanvien();
            ds.push_back(a);
        }
    }
    void xemds() {
        for (int i = 0; i < sonv; i++) {
            ds[i].xemnhanvien();
        }
    }
    void sapxep() {
        cout << "sau khi da sap xep: " << endl;
        for (int i = 0; i < sonv; i++) {
            for (int j = i + 1; j < sonv; j++) {
                if (ds[i].getmanv() > ds[j].getmanv()) swap(ds[i], ds[j]);
            }
        }
    }
    vector <nhanvien> getds() {
        return ds;
    }
};

class luongnv : public nhanvien {
private:
    int ngaycong, luong;
public:
    void nhapluongnv() {
        nhanvien::xemnhanvien();
        cin >> ngaycong;
        luong = ngaycong * 100000 + nhanvien::getluongcoban();
    }

    void xemluongnv() {
        nhanvien::xemnhanvien();
        cout << "tong luong la: " << luong << endl;
    }

    int getngaycong() {
        return ngaycong;
    }
    void setngaycong(int x) {
        ngaycong = x;
        luong = ngaycong * 100000 + nhanvien::getluongcoban();
    }
    friend istream& operator>>(istream& is, luongnv& a) {
        int a1, b, c;
        string m;
        is >> a1 >> m >> b >> c;
        a.setmanv(a1), a.sethoten(m), a.setluongcoban(b), a.setngaycong(c);
        return is;
    }
};

class bangluong {
private:
    int thang, tongluong, sonv;
    vector <luongnv> dsluong;
public:
    bangluong() {
        thang = -1, tongluong = -1;
    }
    bangluong(danhsach a) {
        sonv = a.getds().size();
        vector <nhanvien> tmp = a.getds();
        for (int i = 0; i < tmp.size(); i++) {
            luongnv x;
            x.sethoten(tmp[i].gethoten());
            x.setmanv(tmp[i].getmanv());
            x.setluongcoban(tmp[i].getluongcoban());
            dsluong.push_back(x);
        }
    }

    void nhapbangluong() {
        cout << "NHAP THANG: ";
        cin >> thang;
        cout << "NHAP LUONG CHO THANG " << thang << ":" << endl;
        for (int i = 0; i < dsluong.size(); i++) {
            cout << "nhap NGAY CONG cho nhan vien: ";
            dsluong[i].nhapluongnv();
        }
    }

    void xembangluong() {
        cout << "BANG LUONG CUA THANG " << thang << " LA:" << endl;
        for (int i = 0; i < dsluong.size(); i++) {
            dsluong[i].xemluongnv();
        }
    }

    void ghitep() {
        fstream out;
        out.open("DATA.out", ios::out);
        out << thang << endl;
        out << sonv << endl;
        for (int i = 0; i < dsluong.size(); i++) {
            out << dsluong[i].getmanv() << endl
                << dsluong[i].gethoten() << endl
                << dsluong[i].getluongcoban() << endl
                << dsluong[i].getngaycong() << endl;
        }
        out.close();
    }

    void doctep() {
        // doc tep theo thu tu la thang, so nhan vien, ma nhan vien, ten nhan vien, luong co ban
        fstream in;
        in.open("DATA.out", ios::in);
        in >> thang;
        in >> sonv;
        for (int i = 0; i < sonv; i++) {
            luongnv a;
            in >> a;
            dsluong.push_back(a);
        }
        in.close();
    }
};

int main() {
    danhsach a;
    a.nhapnhanvien();
    a.xemds();
    a.sapxep();
    a.xemds();

    bangluong b(a);
    b.nhapbangluong();
    b.xembangluong();
    b.ghitep();

    bangluong c;
    c.doctep();
    c.xembangluong();
}