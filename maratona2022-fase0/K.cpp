#include <bits/stdc++.h>

using namespace std;

struct lap {
    int m, s,ms;

    int comp(lap &other) {
        if(this->m == other.m && this->s == other.s && this->ms == other.ms) return 0;
        if(this->m < other.m) return 1;
        if(this->m == other.m && this->s < other.s) return 1;
        if(this->m == other.m && this->s == other.s && this->ms < other.ms) return 1;
        return 2;
    }

};

struct pilot {
    vector<lap> laps;
    int id;
    long long int total;
    void init() {
        this->total = 0;
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    vector<pilot> p;
    p.resize(n);
    lap min_l; min_l.m = min_l.s = min_l.ms = 10000;
    for(int i = 0; i < n; i++) {
        p[i].init();
        scanf("%d", &p[i].id);
        for(int j = 0; j < v; j++) {
            int m, s, ms;
            scanf("%d:%d:%d", &m, &s, &ms);
            lap l;
            l.m = m;
            l.s = s;
            l.ms = ms;
            if(l.comp(min_l) == 1) {
                min_l = l;
            }
            p[i].laps.push_back(l);
            p[i].total += (l.m * 60000) + (l.s * 1000) + l.ms;
        }
    }
    sort(p.begin(), p.end(), [](pilot a, pilot b) {
		return a.total < b.total;
	});
    int ans = -1;
    for(int j = 0; j < v; j++) {
        for(int i = 0; i < 10; i++) {        
            if(min_l.comp(p[i].laps[j]) == 0) {
                ans = p[i].id;
                break;
            }
        }
        if(ans != -1) break;
    }
    if(ans == -1) {
        cout << "NENHUM" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}