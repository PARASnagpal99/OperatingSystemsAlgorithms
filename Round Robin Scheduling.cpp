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
	cout << "Enter the Total number of Processes : " << endl ;
	int n ;
	cin >> n ;
	
	cout << "Enter the value of Time Quantum : " << endl ;
	int Q ;
	cin >> Q ;
	
	map<int,int> mp ;
	
	vector<pair<int,int>> arr ;
	
	for(int i=0 ; i<n ; ++i){
		int at , bt ;
		cin >> at >> bt ;
		arr.pb(make_pair(at,bt));
		mp[at] = i ;
	}
	
	vector<pair<int,int>> temp = arr ;
	
	sort(arr.begin(),arr.end(),[&](const pair<int,int> &a , const pair<int,int> &b){ 
		 return (a.first < b.first) ;   
	});
	
	
	vector<int> Ct(n,0) ; // completed time 
	vector<int> Tat(n,0) ; // TurnAround time 
	vector<int> Wt(n,0) ;  // Waiting Time 
	
	int indx = 0 , cnt = 0 ;
	
	int time = 0 ;
	
	queue<pair<int,int>>q ;
	
	while(cnt < n){
		
		while(indx < n && arr[indx].first <= time){
			q.emplace(make_pair(arr[indx].first,arr[indx].second)) ;
			indx++;
		}
		
		if(!q.empty()){
			auto curr = q.front() ; 
			q.pop() ;
			int newBt = curr.second - Q ;
			int at = curr.first ;
			if(newBt <= 0){
				cnt++;
				int i = mp[at] ;
				Ct[i] = time ;
				Tat[i] = (Ct[i] - temp[i].first) ;
				Wt[i] = (Tat[i] - temp[i].second) ; 
			}else{
				q.emplace(make_pair(at,newBt)) ;
			}
		}
		time+=Q ;
	}
	
	int waitingTime = 0 ;
	
	for(auto &it : Wt){
		waitingTime += it ;
	}
	
	cout << "Average Waiting Time is : " << (waitingTime/n) << endl ;
	
	
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
