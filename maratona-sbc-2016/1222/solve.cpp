#include <bits/stdc++.h>

using namespace std;

#define DBG 0

int solve(int n, int l, int c) {
    string str;
    int qnt_chars=0, cur_len_lines=1, start_word=0, len_str;
    getline(cin, str);
    len_str = str.size();
    for(int i = 0; i < len_str; i++) {
        if(i && str[i-1] == ' ') {
            start_word = i;
        }
        if(qnt_chars == c) {
            cur_len_lines++;
            if(str[i] == ' ') qnt_chars = 0;
            else qnt_chars = i - start_word + 1;
        } else qnt_chars++;
    }
    return cur_len_lines / l + (cur_len_lines % l ? 1 : 0);
}


int main() {
    int n, l, c;
    char clear_cin;
    while(cin >> n >> l >> c) {
        clear_cin = cin.get();
        cout << solve(n, l, c) << endl;
    }
    return 0;
}