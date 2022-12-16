string form(string n) {
    string ans[100], res;
    int x = 0;
    char s[100];
    strcpy(s, n.c_str());
    char* p = strtok(s, " ");
    while (p != NULL) {
        ans[x++] = p;
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < x; i++) {
        ans[i][0] = toupper(ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            ans[i][j] = tolower(ans[i][j]);
        }
        res += ans[i];
        if (i != x - 1) res += " ";
    }
    return res;
}