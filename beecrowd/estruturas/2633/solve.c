#include <stdio.h>
#include <string.h>

typedef struct MEAT {
    int valid;
    char name[50];
} Meat;

void read_string(char *str_read){
    char ch = 'a';
    char str[50];
    int i = 0;
    while(ch != ' ') {
        ch = getchar();
        if(ch == '\n') continue;
        str[i++] = ch;
        
    }
    str[i] = '\0';
    strcpy(str_read, str);
}

void solve(int N) {
    Meat meat[N];
    int i, j, count_spaces, len_name;
    char name[50];
    for(i = 0; i < N; i++) {
        read_string(name);
        len_name = strlen(name);
        count_spaces = 0;
        for(j = 0; j < len_name; j++) {
            if(name[j] == ' ') {
                name[j] = name[j + 1];
                count_spaces++;
            }
        }
        name[len_name-count_spaces] = '\0';
        strcpy(meat[i].name, name);
        scanf("%d", &meat[i].valid);
    }
    
    for(i = 0; i < N; i++) {
        for(j =  0; j < N; j++) {
            if(meat[i].valid < meat[j].valid) {
                Meat aux = meat[i];
                meat[i] = meat[j];
                meat[j] = aux;
            }
        }
    }
    for(i = 0; i < N; i++) {
        printf("%s%c", meat[i].name, (i + 1 == N ? '\n' : ' '));
    }
}

int main() {
    int N;
    while(scanf("%d", &N) != EOF) {
        solve(N);
    }
    return 0;
}