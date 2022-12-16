#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f;
    f.open("PTIT.in", ios::in);
    fstream f1;
    f1.open("PTIT.out", ios::out);
    while (!f.eof()) {
        string data;
        getline(f, data);
        f1 << data << endl;
    }
    f.close();
    f1.close();
    return 0;
}

// #include<iostream>
// #include<fstream>
// #include<cstring>
// using namespace std;
// int main()
// {
// 	int k=0;
// 	string s;
// 	fstream fg("PTIT.in", ios::in|ios::binary);
// 	fstream fd("PTIT.out", ios::out|ios::binary);
// 	while(getline(fg, s))
// 	{
// 		if(k==0)
// 		{
// 			fd << s;
// 			k=1;
// 		}
// 		else 
// 			fd << endl << s;
// 	}
// 	fd.close();
// 	fg.close();
// 	return 0;
// }
