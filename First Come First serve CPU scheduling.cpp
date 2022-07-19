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
	cout << "ENTER THE TOTAL NUMBER OF PROCESSES : " << endl ;
	int n ;
	cin >> n ;
	 cout << "ENTER THE PROCESSES , THEIR ARRIVAL TIME and their burst time  : " << endl ;
	vector<pair<int,int>> arr ;
	
	for(int i=0 ; i<n ; ++i){
		int at , bt ;
		cin >> at >> bt ;
		arr.pb({at,bt}) ;
	}
	vector<int> completed_time(n) ;
	vector<int> turnAroundTime(n) , WaitingTime(n) ;
	
	sort(arr.begin(),arr.end(),[&](const pair<int,int>a , const pair<int,int> b){
		return (a.first < b.first) ;
	});
	
	int last = 0 ;
	
	for(int i=0 ; i<n ; ++i){
		completed_time[i] = max(last,arr[i].first) + arr[i].second ;
		last = completed_time[i] ;
	//	cout << last << " " << endl ;
		turnAroundTime[i] = completed_time[i] - arr[i].first ;
		WaitingTime[i] = turnAroundTime[i] - arr[i].second ;
	}
	
	int avg_wtTime = 0 ;
	
	for(auto &it : WaitingTime){
		avg_wtTime+=it ;
	}
	
	 cout << (avg_wtTime)/n << endl ;
	
	
	
	
	
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
