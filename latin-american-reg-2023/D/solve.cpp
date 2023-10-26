#include <bits/stdc++.h>

#define DEBUG if(false)

using namespace std;

int word_counts[1001][28];

bool read_arr(vector<string> &arr, int &size, bool is_word) {
    if(scanf("%d", &size) == EOF) return false;
    arr.resize(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        if(is_word) {
            for(int j = 0; j < 5; j++) {
                word_counts[i][arr[i][j] - 'a']++;
            }
        }
    }
    return true;
}

int check_words(string secret, int word_idx, string cur_word, string pattern) {
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        if(pattern[i] == 'X') {
            ans += (word_counts[0][cur_word[i] - 'a'] == 0);
        } else if(pattern[i] == '*') {
            ans += (secret[i] == cur_word[i]);
        } else {
            ans += (secret[i] != cur_word[i] && word_counts[0][cur_word[i] - 'a']);
        }
        DEBUG cout << pattern[i] << " " << secret[i] << " " << cur_word[i] << " " << ans << " " << word_counts[0][cur_word[i] - 'a'] << endl;
    }
    DEBUG cout << (ans == 5 ? "YES" : "NO") << endl;
    return ans == 5;
}

bool solve() {
    int w, p;
    vector<string> words, patterns;
    memset(word_counts, 0, sizeof(word_counts));
    bool continue_solve = read_arr(words, w, true);
    if(!continue_solve) return false;
    read_arr(patterns, p, false);
    
    for(auto pattern : patterns) {
        int ok = 0, idx = 0;
        for(auto word : words) {
            ok += check_words(words[0], idx++, word, pattern);
            DEBUG cout << "\n-----------------------------------------" << endl;
        }
        cout << ok << endl;
    }
    return true;
}

int main() {
    while(solve()) DEBUG cout << "-------------------" << endl;
    return 0;
}