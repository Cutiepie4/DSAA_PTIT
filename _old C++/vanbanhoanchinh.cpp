#include<stdio.h>
#include<string.h>
#include<ctype.h>
main() {
	char s[100][200];
	char str[20000], str1[100];
	int k = 0;
	while (scanf("%s", &str1) != -1) {
		strcat(str, str1);
		strcat(str, " ");
	}
	char* p = strtok(str, ".?!"), ch[100][200];
	while (p != NULL) {
		strcpy(ch[k++], p);
		p = strtok(NULL, ".?!");
	}

	for (int i = 0; i < k; i++) {
		while (ch[i][0] == ' ') {
			for (int j = 0; j < strlen(ch[i]); j++) {
				ch[i][j] = ch[i][j + 1];
			}
		}
		for (int j = 0; j < strlen(ch[i]); j++) {
			if (j == 0) ch[i][j] = toupper(ch[i][j]);
			else ch[i][j] = tolower(ch[i][j]);
		}
		if (i == k - 1) printf("%s", ch[i]);
		else puts(ch[i]);
	}
}
// code c++
#include <bits/stdc++.h>
using namespace std;

string process(char s[]) {
    string res = s;
    while (res.front() == ' ') res.erase(res.begin());
    res[0] = toupper(res[0]);
    for (int i = 1; i < res.size(); i++) res[i] = tolower(res[i]);
    return res;
}

int main() {
    string tmp, x, res[100];
    int cnt = 0;
    while (cin >> tmp) {
        x += tmp;
        x += " ";
    }
    char s[2001];
    strcpy(s, x.c_str());
    char* p = strtok(s, ".?!");
    while (p != NULL) {
        res[cnt++] = process(p);
        p = strtok(NULL, ".?!");
    }
    for (int i = 0; i < cnt; i++) cout << res[i] << endl;
}