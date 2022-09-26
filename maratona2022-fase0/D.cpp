#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli levenshtein_distance(const string &s1, const string &s2) {
  lli m = s1.size(), n = s2.size();
  if(!m) return n;
  if(!n) return m;
  
  lli costs[n + 1];

  for( lli k = 0; k <= n; k++) costs[k] = k;

  lli i = 0 ;
  for (char const &c1 : s1) {
    costs[0] = i + 1;
    lli corner = i, j = 0;
    for (char const &c2 : s2) {
      lli upper = costs[j+1];
      if( c1 == c2 ) {
        costs[j+1] = corner;
      } else {
        costs[j+1] = min({costs[j], upper, corner}) + 1;
      }

      corner = upper;
      j++;
    }
    i++;
  }

  return costs[n];
}

int main() {
    int N;
    cin >> N;
    vector<double> scoreboard;
    scoreboard.resize(6);
    double biggest_points = 0;
    while(N--) {
        unordered_map<int, vector<int>>  points;
        string s1, s2;
        cin >> s1;
        lli min_dist = LLONG_MAX;
        for(int i = 0; i < 5; i++) {
            cin >> s2;
            lli dist = levenshtein_distance(s1, s2);
            if(dist < min_dist) min_dist = dist;
            points[dist].push_back(i + 1);
        }
        for(auto v : points[min_dist]) {
            scoreboard[v] += (min_dist == 0 ? 1 : 0.5);
            biggest_points = max(biggest_points, scoreboard[v]);
        }
    }
    printf("%.1lf\n", biggest_points);
    vector<int> winners;
    for(int i = 1; i < 6; i++) {
        if(scoreboard[i] == biggest_points) {
            winners.push_back(i);
        }
    }
    int qnt_winner = winners.size();
    for(int i = 0; i < qnt_winner; i++) {
        printf("%d%c", winners[i], qnt_winner == i + 1 ? '\n' : ' ');
    }
    return 0;
}
