#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<assert.h>
#define sz(x) (ll)x.size()
#define ll long long
using namespace std;
// const int LIM = 1000 + 4;
// int arr[LIM][LIM];


// ll get_val(int ind, int curr_sum, int total_sum, string &S, const int N){
//     const int MOD = 2012;
//     if(curr_sum < 0) return 0;
//     if(ind == N){
//         // assert(total_sum == 0);
//         if(curr_sum == 0) {arr[ind][curr_sum] = 1; return 1;}
//         else {arr[ind][curr_sum] = 0; return 0;}
//     }
//     if(arr[ind][curr_sum] != -1) return arr[ind][curr_sum];
//     int val;
//     if(S[ind] == '(') val = 1;
//     else val = -1;
//     ll ans = 0;
//     ans += get_val(ind + 1, curr_sum, total_sum + val, S, N);
//     ans += get_val(ind + 1, curr_sum + val, total_sum + val, S, N);
//     ans %= MOD;
//     arr[ind][curr_sum] = ans;
//     return ans;
// }

// The condition on line 62 was the most critical part!. Without
// it I was getting a Wrong Answer.

void solve(){
    // for(int i = 0; i<LIM; i++){
    //     for(int j = 0; j<LIM; j++) arr[i][j] = -1;
    // }
    string S;
    cin>>S;
    const ll N = sz(S);
    // cout<<get_val(0, 0, 0, S, N)<<endl;
    vector<ll> prefix_sum(N + 1, 0);
    for(int i = 0; i<N; i++){
        prefix_sum[i+1] = prefix_sum[i] + ((S[i] == '(')? 1: -1);
    }

    vector<vector<ll>> dp(N + 1, vector<ll> (N + 1, 0));
    ll current_sum = 0;
    ll total_sum = prefix_sum[N];
    assert(total_sum == 0);
    const ll MOD = 2012;
    for(ll i = 0; i<=N; i++){
        dp[N][i] = 0;
    }
    dp[N][0] = 1;
    for(ll i = N - 1; i>=0; i--){
        for(ll sum = 0; sum<=N; sum++){
            ll val = (S[i] == '(')? 1: -1;
            dp[i][sum] = 0;
            if(prefix_sum[i] - sum>=0){
                dp[i][sum] += dp[i+1][sum];
                if(sum + val >= 0 && sum + val <= N) dp[i][sum] += dp[i+1][sum + val];
                dp[i][sum] %= MOD;
            }
            // cout<<i<<" "<<sum<<" "<<dp[i][sum]<<endl;
        }
    }
    cout<<dp[0][0]<<endl;


    // dp[i][s] = dp[i + 1][s + val] + dp[i + 1][s];






    
}


int main(){
    ll test;
    // cin>>test;
    test = 1;
    freopen("bbreeds.in", "r", stdin);
 
    // Prlling the Output to output.txt file
    freopen("bbreeds.out", "w", stdout);

    for(ll i = 0; i<test; i++){
        solve();
    }
}

