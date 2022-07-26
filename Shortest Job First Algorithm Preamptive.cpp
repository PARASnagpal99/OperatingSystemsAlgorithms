/*  ੴ   Satnam Waheguru */
#include<bits/stdc++.h>
#define REP(it,n) for(int i=it; i<n; i++)
#define mod 1000000007
#define int long long
#define pb push_back
#define ff first
#define ss second
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
typedef pair<int, int> pi;
void solve(){
	  cout << "ENTER the total number of processes : " << endl ;
       int n ;
       cin >> n ;
       
     cout << "Enter the process with arrival time and burst time : " << endl ;
     vector<pair<int,int>> arr ;  
     
     map<int,int> mp ;   // arrival time - index
     
    
     
     for(int i=0 ; i<n ; ++i){
     	int at , bt ;
     	cin >> at >> bt ;
     	arr.pb({bt,at});
     	mp[at] = i ;
     }  
       
      priority_queue<pi, vector<pi>, greater<pi> > pq;   // ({burstTime , arrivalTime })  
     
     int cnt = 0 ;
     
     int waitingTime = 0 ;
     
     int time = 0 ;
     
     vector<int> completed_time(n,0) ;
     vector<int> turn_around_time(n,0) ;
     
     while(true){
     	
     	if(cnt == n){
     		break ;
     	}
     	
     	if(mp.find(time) != mp.end()){
     		auto x = arr[mp[time]] ;
     		int BT = x.first , AT = x.second ;
     		pq.push(make_pair(BT,AT));
     	}
     	
     	auto top = pq.top() ;
     	pq.pop() ;
     	int BT = top.first , AT = top.second ;
     	BT-- ;
     	
     	time++;
     	
     	if(BT == 0){
     		cnt++;
     		int i = mp[AT] ;
     		completed_time[i] = time ;
     		turn_around_time[i] = (time - AT) ;
     	     waitingTime += (turn_around_time[i] - arr[i].first) ;
     	}else{
     		pq.push(make_pair(BT,AT)) ;
     	}
     	
     	
     }
     
     
    cout << "Average waiting time is : " << (waitingTime/n) << endl ;
    
              	
         	
         	
         	
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
