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
	cout << "Number of processes : " << n << endl ;
	
	vector<vector<int>> arr ;
	
	vector<vector<int>> need ;
	
	int A , B , C ;
	cin >> A >> B >> C ;
	cout << "Total resources are : " << A << " " << B << " " << C << endl ;
	cout << "allocated and needed resources entered sucessfuly" << endl ;
	for(int i=0 ; i<n ; ++i){
		int a , b , c ;
		cin >> a >> b >> c ;
		arr.pb({a,b,c});
		A-=a ;
		B-=b;
		c-=c;
	}
	
	
	for(int i=0 ; i<n ; ++i){
		int a , b , c ;
		cin >> a >> b >> c ;
		a = max(0*1ll,a-arr[i][0]);
		b = max(0*1ll,b-arr[i][1]);
		c = max(0*1ll,c-arr[i][2]);
		need.pb({a,b,c});
	}
	
	vector<int> ans ;
	
	vector<int> vis(n,0) ;
	
	int cnt = 0 ;
	
	while(cnt < n){
		
		for(int i=0 ; i<n ; ++i){
			int a = need[i][0] , b = need[i][1] , c = need[i][2] ;
			if(!vis[i] && A >= a && B >= b && C >= c){
				vis[i] = true ;
				A+=a ;
				B+=b ;
				C+=c ;
				ans.pb(i+1);
			}
			
		}
		cnt++;
	}
	
	int sz = ans.size() ;
	if(sz != n){
		cout << "There is a deadlock " ;
		return ;
	}
	
	cout << "Sequence of process to be carried out are : " ;
	for(auto &it : ans){
		cout << it << " " ;
	}
	cout << endl ;
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
