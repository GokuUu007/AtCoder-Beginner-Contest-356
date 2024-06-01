/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifdef AKSHAT
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}



void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> tests(m);
    vector<int> res(m);
    for (int i = 0; i < m; ++i) {
        int c; cin >> c;
        tests[i].resize(c);
        for (auto &x : tests[i]) {
            cin >> x, --x;
        }
        
        char ch; cin >> ch;
        res[i] = ch == 'o' ? 1 : 0;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> is_real(n);
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                is_real[j] = 1;
            }
        }

        bool ok = 1;
        for (int j = 0; j < m; ++j) {
            auto t = tests[j];
            int real = 0, open = 0;
            for (auto &key : t) {
                real += is_real[key];
                if (real >= k) {
                    open = 1;
                    break;
                }
            }
            ok &= res[j] == open; 
        }
        ans += ok;
    }

    cout << ans;
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifdef AKSHAT   
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    // cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifdef AKSHAT
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
