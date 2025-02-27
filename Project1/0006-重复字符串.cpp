vector<int> nextArray(string& s) {
    int len = s.size();
    vector<int> next(len);
    if (len == 1) {
        next.push_back(-1);
        return next;
    }

    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while (i < len) {
        if (s[i - 1] == s[cn]) {
            next[i++] = ++cn;
        }
        else if (cn > 0) {
            cn = next[cn];
        }
        else {
            next[i++] = 0;
        }
    }
    return next;
}
bool repeatedSubstringPattern(string s) {
    int len = s.size();
    if (len <= 1) return false;

    vector<int> next = nextArray(s);

    if (next[len - 1] != -1 && s[len - 1] == s[next[len - 1]] && len % (len - (next[len - 1] + 1)) == 0) {
        return true;
    }
    return false;
}