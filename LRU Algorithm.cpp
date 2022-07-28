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
	string s ;
	cin >> s ;
	cout << "Reference String is : " << s << endl ;
	
	unordered_set<char> st ;
	
	int n ;
	cin >> n ;
	cout << "Length of main memory is : " << n << endl ;
	
	
	int pageFault = 0 , pageHit = 0 ;
	
	map<char,int> mp ;
	
	int cnt = 0 ;
	
	for(int i=0 ; i < s.length() ; ++i){
		
		if(!st.count(s[i]) && cnt < n){
			mp[s[i]] = i ;
			st.insert(s[i]);
			cnt++;
			pageFault++;
 		}else if(!st.count(s[i]) && cnt == n){
 			int mnm = INT_MAX ;
 			for(auto &it : mp){
 				mnm = min(mnm,it.second) ;
 			}
 			st.erase(s[mnm]);
 			pageFault++;
 			st.insert(s[i]);
 			mp[s[i]] = i ;
 		}else if(st.count(s[i])){
 			pageHit++;
 		}
	}
	
	cout << "Number of Page Faults are : " << pageFault << endl;
	cout << "Number of Page Hits are : " << pageHit << endl ;
	
	
}

int32_t main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      int t ;
      //cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}
