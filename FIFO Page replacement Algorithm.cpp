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
	vector<int> arr(n) ;
	
	int pageFault = 0 , pageHit = 0 ;
	
	int indx = 1 ;
	
    int cnt = 0 ;
    
	for(int i=0 ; i<s.length() ; ++i){
		
		if(!st.count(s[i]) && cnt < n){
			arr[cnt] = s[i] - '0' ;
            cnt++;
			st.insert(s[i]) ;
			pageFault++;
		}else if(!st.count(s[i]) && cnt == n){
               int curr = arr[indx-1] ; 
			   st.erase(curr + '0'); 
			   pageFault++;
               int x = s[i] - '0' ;
			   arr[indx-1] = x ; 
			   st.insert(s[i]);
			   indx = (indx+1) ;
               if(indx == n+1) indx = 1 ; 
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
      // cin >> t ;
      t = 1 ;
      while(t--){
      	solve() ;
      } 

}
