#include <bits/stdc++.h>
using namespace std;

int xxx(string s) {
    int res = 0;
    for (auto i : s) {
        if (isdigit(i))
            res = res * 10 + i - '0';
    }
    return res;
}

class KhachHang;
class MatHang;
vector <KhachHang> k;
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
        k.push_back(a);
        return is;
    }
    string getname() {
        return namecus;
    }

    string getadd() {
        return add;
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
        cout << namegoods << " ";
    }

    string getname() {
        return namegoods;
    }

    int getidgoods() {
        return idg;
    }

    int getoutprice() {
        return outprice;
    }

    int getinprice() {
        return inprice;
    }
};



class HoaDon {
private:
    int idbill, idc, idg, number;
    long long val, valup;
    string idcus, idgoods, namegood, name, add;
    static int xbill;
public:
    friend istream& operator>> (istream& is, HoaDon& a) {
        a.idbill = xbill++;
        is >> a.idcus >> a.idgoods >> a.number;
        a.idc = xxx(a.idcus);
        a.idg = xxx(a.idgoods);
        for (int i = 0; i < k.size(); i++) {
            if (k[i].getidcus() == a.idc) {
                a.name = k[i].getname();
                a.add = k[i].getadd();
                break;
            }
        }
        for (int i = 0; i < m.size(); i++) {
            if (m[i].getidgoods() == a.idg) {
                a.namegood = m[i].getname();
                a.val = (long long)m[i].getoutprice() * a.number;
                a.valup = (long long)a.val - m[i].getinprice() * a.number;
                break;
            }
        }
        return is;
    }

    int getvalup() {
        return valup;
    }

    friend ostream& operator<<(ostream& os, HoaDon& a) {
        if (a.idbill < 10) os << "HD00" << a.idbill << " ";
        else if(a.idbill < 100) os << "HD0" << a.idbill << " ";
        else if(a.idbill >= 100) os << "HD" << a.idbill << " ";
        os << a.name << " "
            << a.add << " "
            << a.namegood << " "
            << a.number << " "
            << a.val << " "
            << a.valup << endl;
        return os;
    }
};

int cmp(HoaDon& a, HoaDon& b) {
    if (a.getvalup() >= b.getvalup()) return 1;
    return 0;
}

void sapxep(HoaDon dskh[], int K) {
    sort(dskh, dskh + K, cmp);
}

int HoaDon::xbill = 1;
int MatHang::xgoods = 1;
int KhachHang::xcus = 1;

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

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}