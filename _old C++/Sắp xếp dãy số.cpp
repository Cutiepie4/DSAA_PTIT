/*
Tí được cho bài tập sắp xếp mảng các số nguyên. Mảng có N số nguyên từ 1 đến N đôi một khác nhau. Tí được yêu cầu thực hiện thuật toán sắp xếp với N bước như sau:

- Bước 1: Số 1 được di chuyển về vị trí 1 bằng cách đổi chỗ các phần tử liên tiếp

- Bước 2: Số N được di chuyển về vị trí N bằng cách đổi chỗ các phần tử liên tiếp

- Bước 3: Số 2 được di chuyển về vị trí 2 bằng cách đổi chỗ các phần tử liên tiếp

- Bước 4: Số N-1 được di chuyển về vị trí N-1 bằng cách đổi chỗ các phần tử liên tiếp

Cứ tiếp tục như vậy. Tức là ở bước thứ i:

- Nếu i lẻ thì di chuyển số bé nhất chưa di chuyển để di chuyển về đúng vị trí của nó

- Nếu i chẵn thì di chuyển số lớn nhất chưa di chuyển để di chuyển về đúng vị trí của nó

Tính số lần đổi chỗ ở mỗi bước.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    //input
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    //process
    vector <int> b = a;
    sort(b.begin(), b.end());
    int count = 0, index1 = 0, index2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                if (a[j] == b[index1]) {
                    for (int z = j; z > index1; z--) {
                        swap(a[z], a[z - 1]);
                        count++;
                    }
                    index1++;
                    break;
                }
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                if (a[j] == b[n - 1 - index2]) {
                    for (int z = j; z < n - 1 - index2; z++) {
                        swap(a[z], a[z + 1]);
                        count++;
                    }
                    index2++;
                    break;
                }
            }
        }
        cout << count << endl;
        count = 0;
    }
}