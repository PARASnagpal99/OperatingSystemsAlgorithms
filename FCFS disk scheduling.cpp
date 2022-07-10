/*  ੴ   Satnam Waheguru */
#include<bits/stdc++.h>
#define REP(it,n) for(int i=it; i<n; i++)
#define mod 1000000007
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ll long long
#define INF 1000000000
#define prDouble(x) cout << fixed << setprecision(10) << x  
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
void solve(){
	int n ;
	cin >> n ;
	cout << "Enter the requests : " << endl ;
	vector<int> times(n) ;
	for(auto &it : times) cin >> it ;
	int head ;
	cin >> head ;
	int prev = head ;
	int seekingTime = 0 ;
	for(int i=0 ; i<n ; ++i){
		seekingTime += abs(times[i]-prev) ;
		prev = times[i] ;
	}
	
	cout << "Total seeking time is : " << endl ;
	cout << seekingTime << endl ;
	
}

int32_t main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      int t ;
     // cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}


