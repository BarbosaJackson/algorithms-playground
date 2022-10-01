#include <stdio.h>
#include <string.h>
#define MAXN ((1000 * 80) + 1)

int solve(int n, int l, int c) {
    char text[MAXN];
    int i, qnt_chars=0, cur_len_lines = 1, start_word=0, len_str;
    scanf("%[^\n]s", text);
    len_str = strlen(text);
    // printf("%s\n", text);
    for(i = 0; i < len_str; i++) {
        if(i && text[i - 1] == ' ') {
            start_word = i;
        }
        if(qnt_chars == c) {
            cur_len_lines++;
            qnt_chars = (text[i] == ' ' ? 0 : (i - start_word + 1));
        } else qnt_chars++;
    }
    return cur_len_lines / l + (cur_len_lines % l ? 1 : 0);
}

int main() {
    int n, l, c;
    char clear_read;
    while(scanf("%d %d %d", &n, &l, &c) != EOF) {
        clear_read = getchar();
        // printf("[ * ] %c", clear_read);
        printf("%d\n", solve(n, l, c));
    }
    return 0;
}