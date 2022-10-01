#include<stdio.h>
#include<string.h>

short is_vocal(char c) {
    char vocals[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++) {
        if(c == vocals[i]) return 1;
    }
    return 0;
}

char solve(char *str, int len_str) {
    char ans = 'S';
    int i = 0, j = len_str - 1;
    while(i < j) {
        while(i < len_str && !is_vocal(str[i])) i++;
        while(j && !is_vocal(str[j])) j--;
        if(str[i] != str[j]) {
            ans = 'N';
            break;
        }
        i++;
        j--;
    }
    return ans;
}

int main() {
    char str[100];
    while(scanf("%s", str) != EOF) printf("%c\n", solve(str, strlen(str)));
    return 0;
}