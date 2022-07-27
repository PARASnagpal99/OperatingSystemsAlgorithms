// Priority Scheduling Preamptive
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ll long long
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
typedef pair<int, int> pi;
  

int main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
      cout << "Enter the total number of processes : " << endl ;
      int n ;
      cin >> n ;      
      vector<vector<int>> arr ;  // arrivalTime - burstTime 
      
      map<int,int> mp ; // priority - indice ;
      
      
      for(int i=0 ; i<n ; ++i){
      	int at , bt , pt ; // arrival time , burst time , priority 
      	cin >> at >> bt >> pt ;
      	arr.pb({at,bt,pt});
      	mp[pt] = i ;
      }
      
      vector<vector<int>> temp = arr ;


      sort(arr.begin(),arr.end(),[&](const vector<int> &a , const vector<int> &b){
      	 return (a[0] < b[0])  ;
      });

      int time = 0 ;
      int cnt = 0 ;
      
      int indx = 0 ;
      
      
      vector<int> CT(n,0) ;
      vector<int> Tat(n,0) ;
      vector<int> Wt(n,0) ;
      
      
      priority_queue<pi, vector<pi>, greater<pi> > pq; // priority - burstTime 
      
      while(cnt < n){
      	
      	while(indx < n && arr[indx][0] <= time ){
      		pq.push(make_pair(arr[indx][2],arr[indx][1])) ;
      		indx++; 
      	}
      	
      	if(!pq.empty()){
      	   auto curr = pq.top() ;
      	   pq.pop() ;
      	   int newBt = curr.second - 1 ;
      	   int priority = curr.first ;
      	   if(newBt == 0){
      	   	 cnt++;
      	   	 int i = mp[priority] ;
      	   	 CT[i] = time ;
      	   	 Tat[i] = (time - temp[i][0]) ;
      	   	 Wt[i] = (Tat[i] - temp[i][1]) ;
      	   }else{
      	   	pq.push(make_pair(priority,newBt));
      	   }		
      	}
      	time++;
      }

     int totalWt = 0 ;
     for(auto &it : Wt){
     	totalWt += it ;
     }
     
     cout << "The Average Waiting time of process is : " ;
     cout << totalWt/n << endl ;
     

}
