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

int avg_wtTime = 0 ;

int process(vector<pair<int,int>>& arr , int last ){
	int n = arr.size() ;
	
	vector<int> completed_time(n) ;
	vector<int> turnAroundTime(n) , WaitingTime(n) ;
	
	sort(arr.begin(),arr.end(),[&](const pair<int,int> &a , const pair<int,int> &b){
		return (a.second < b.second) ;
	});
	
	for(int i=0 ; i<n ; ++i){
		completed_time[i] = max(last,arr[i].first) + arr[i].second ;
		last = completed_time[i] ;
	//	cout << last << " " << endl ;
		turnAroundTime[i] = completed_time[i] - arr[i].first ;
		WaitingTime[i] = turnAroundTime[i] - arr[i].second ;
	}
     
     for(auto &it : WaitingTime){
		avg_wtTime+=it ;
	}
    
    return last ;
     	
}






void solve(){
	 cout << "ENTER THE NUMBER OF PROCESSES : "  << endl ;
      int n ;
      cin >> n ;	
      
      vector<pair<int,int>>arr ;
      cout << "ENTER ARRIVAL TIME AND BURST TIME OF PROCESSES : "  << endl ;
      for(int i=0 ; i<n ; ++i){
      	int a , b ;
      	cin >> a >> b ;
      	arr.pb({a,b});
      }
      
      sort(arr.begin(),arr.end() , [&](const pair<int,int> &a , const pair<int,int> &b){
      	   return (a.first < b.first) ;
      });
      
      int last = arr[0].first ;
      
      int indx = 0 ;
      
      while(indx < n){
          
      	vector<pair<int,int>> temp ;
      	
        for(int i=0 ; i<n ; ++i){
            if(arr[i].first <= last && arr[i].first!=-1){
                temp.pb({arr[i].first,arr[i].second}) ;
                arr[i].first = -1 ;
            }
        }  
          
          indx+=(temp.size()-1);
      	int newLast = process(temp,last) ;
      	last = newLast ;
    //  	cout << last << endl ;
      }
      
      
     cout << "AVERAGE WAITING TIME IS : " << (avg_wtTime)/n  << endl ;
      
      
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
