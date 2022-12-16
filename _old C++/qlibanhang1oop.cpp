#include <bits/stdc++.h>
using namespace std;

int xxx(string s) {
    int res = 0;
    for (auto i : s) res = res * 10 + i - '0';
    return res;
}

class KhachHang;
class MatHang;
vector <KhachHang> idd;
vector <MatHang> m;



class KhachHang {
private:
    int idcus;
    static int xcus;
    string namecus, gender, dob, add;
public:
    friend istream& operator>> (istream& is, KhachHang& a) {
        scanf("\n");
        a.idcus = xcus++;
        getline(is, a.namecus);
        is >> a.gender >> a.dob;
        scanf("\n");
        getline(is, a.add);
        idd.push_back(a);
        return is;
    }

    void output() {
        cout << namecus << " " << add << " ";
    }

    int getidcus() {
        return idcus;
    }
};


class MatHang {
private:
    string namegoods, unit;
    int inprice, outprice, idg;
    static int xgoods;
public:
    friend istream& operator>> (istream& is, MatHang& a) {
        scanf("\n");
        a.idg = xgoods++;
        getline(is, a.namegoods);
        getline(is, a.unit);
        is >> a.inprice >> a.outprice;
        m.push_back(a);
        return is;
    }
    void output() {
        cout << namegoods << " " << unit << " " << inprice << " " << outprice << " ";
    }

    int getidgoods() {
        return idg;
    }

    int getoutprice() {
        return outprice;
    }
};



class HoaDon {
private:
    int idbill, idc, idg, number;
    string idcus, idgoods;
    static int xbill;
    static int cnt;
public:
    friend istream& operator>> (istream& is, HoaDon& a) {
        a.idbill = xbill++;
        is >> a.idcus >> a.idgoods >> a.number;
        a.idcus = a.idcus.substr(2, 3);
        a.idc = xxx(a.idcus);
        a.idgoods = a.idgoods.substr(2, 3);
        a.idg = xxx(a.idgoods);
        return is;
    }

    friend ostream& operator<<(ostream& os, HoaDon a) {
        for (int i = 0; i < idd.size(); i++) {
            if (a.idc == idd[i].getidcus()) {
                if (cnt < 10) os << "HD00" << cnt++ << " ";
                else os << "HD0" << cnt++ << " ";
                idd[i].output();
                for (int j = 0; j < m.size(); j++) {
                    if (a.idg == m[j].getidgoods()) {
                        m[j].output();
                        cout << a.number << " " << m[j].getoutprice() * a.number << endl;
                        break;
                    }
                }
                break;
            }
        }
        return os;
    }
};

int HoaDon :: xbill = 1;
int HoaDon :: cnt = 1;
int MatHang :: xgoods = 1;
int KhachHang :: xcus = 1;

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];
    
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}