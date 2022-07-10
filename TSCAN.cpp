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
      cout << "Enter the number of requests : "  << endl ;
	 vector<int> arr(n) ;
	 cout << "Enter the requests : " << endl ;
	 for(auto &it : arr) cin >> it ;
	
	 int head ;
	 cin >> head ;
	 
	 sort(arr.begin(),arr.end());
	 auto indx = n-1 ;
	 int prev = head ;
      int seekingTime = 0 ;
      
	 indx = lower_bound(arr.begin(),arr.end(),head) - arr.begin() ;
	 
	 for(int i=indx ; i<n ; ++i){
	 	seekingTime += abs(arr[i] - prev ) ;
	 	prev = arr[i] ;
	 }
	 
	 seekingTime += abs(prev-arr[0]) ;
	 prev = arr[0] ;
	 
	 for(int i=1 ; i<indx ; i++){
	 	seekingTime += abs(prev-arr[i]) ;
	 	prev = arr[i] ;
	 }
	 
	 cout << seekingTime << endl ;
     
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
