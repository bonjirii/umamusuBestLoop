#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define rep_r(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define rep3r(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

const int showcount = 1000;
const int searchid = 17;
const int limitscore = 46;

const int data[28][28] = {};


struct erabikata{
    int id1, id2, id3, id4, id5;
    int as, bs, cs, ds, es;
    int score;
};

struct erabiless{
    bool operator()(const erabikata& a, const erabikata& b) const noexcept {
        return std::tie(a.score) > std::tie(b.score);
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> have(n);
    rep(i, n) cin >> have[i];

    vector<erabikata> ans;

    rep(i, n)rep(j, i)rep(k, j)rep(l, k)rep(m, l){
        int sel[5];
        sel[0] = have[m]; sel[1] = have[l]; sel[2] = have[k]; sel[3] = have[j], sel[4] = have[i];
        do {
            int score = 0;
            int as, bs, cs, ds, es;
            as = data[sel[0]][sel[1]] + data[sel[0]][sel[2]];
            bs = data[sel[1]][sel[2]] + data[sel[1]][sel[4]];
            cs = data[sel[2]][sel[3]] + data[sel[2]][sel[4]];
            ds = data[sel[3]][sel[0]] + data[sel[3]][sel[1]];
            es = data[sel[4]][sel[0]] + data[sel[4]][sel[3]];
            score += data[sel[0]][sel[1]];
            score += data[sel[0]][sel[2]];
            score += data[sel[1]][sel[2]];
            score += data[sel[1]][sel[4]];
            score += data[sel[2]][sel[3]];
            score += data[sel[2]][sel[4]];
            score += data[sel[3]][sel[0]];
            score += data[sel[3]][sel[1]];
            score += data[sel[4]][sel[0]];
            score += data[sel[4]][sel[3]];
            
            
            if(as >= limitscore && bs >= limitscore && cs >= limitscore && ds >= limitscore && es >= limitscore)
            //if(sel[0] == searchid)
            ans.push_back(erabikata{sel[0], sel[1], sel[2], sel[3], sel[4], as, bs, cs, ds, es, score});
            
        } while(next_permutation(sel, sel + 5));
    }

    std::sort(ans.begin(), ans.end(), erabiless{});

    if(ans.size() < showcount){
        rep(i, ans.size()){
            cout << "a=" << ans[i].id1 << ", b="<< ans[i].id2<< ", c=" << ans[i].id3 << ", d=" << ans[i].id4  << ", e=" << ans[i].id5 << ", score = " << ans[i].score;
            cout << ", a_score=" << ans[i].as << ", b_score=" << ans[i].bs <<", c_score=" << ans[i].cs <<", d_score=" << ans[i].ds <<", e_score=" << ans[i].es << endl;
        }
        cout << showcount << "件未満です" << endl;
    }else{
        rep(i, showcount){
            cout << "a=" << ans[i].id1 << ", b="<< ans[i].id2<< ", c=" << ans[i].id3 << ", d=" << ans[i].id4  << ", e=" << ans[i].id5 << ", score = " << ans[i].score;
            cout << ", a_score=" << ans[i].as << ", b_score=" << ans[i].bs <<", c_score=" << ans[i].cs <<", d_score=" << ans[i].ds <<", e_score=" << ans[i].es << endl;
        }
    }
    return 0;
}
