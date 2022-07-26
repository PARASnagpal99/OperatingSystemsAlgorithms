// Priority Scheduling non Preamptive
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


int main(){
 	 ios_base::sync_with_stdio(false); cin.tie(NULL); // fast input output
 	 cout << "Enter the total number of processes : " << endl ;
      int t ;
      cin >> t ;
      vector<pair<int,pair<int,int>>>arr ;
      
      cout << "Enter the arrival time , burst time and priority of processes : " << endl ;
      
      for(int i=0 ; i<t ; ++i){
      	int at , bt , p ;
      	cin >> at >> bt >> p ;
      	arr.pb({p,{at,bt}});
      }
      
      vector<int>CT(t) ;
      vector<int>TAT(t);
      vector<int>WT(t);
      
      sort(arr.begin(),arr.end(),[&](const pair<int,pair<int,int>>a , const pair<int,pair<int,int>>b ){
      	 return a.second.first < b.second.first ;
      });
      
      CT[0] = arr[0].second.first + arr[0].second.second ;
      TAT[0] = CT[0] - arr[0].second.first ;
      WT[0] = TAT[0] - arr[0].second.second ;
      
      sort(arr.begin()+1,arr.end() , [&](const pair<int,pair<int,int>>a , const pair<int,pair<int,int>>b ){
                   return a.first > b.first ;	
      });
      
      for(int i=1 ; i<t ; ++i){
      	CT[i] = max(CT[i-1],arr[i].second.first) + arr[i].second.second ;
      	TAT[i] = CT[i] - arr[i].second.first ;
      	WT[i] = TAT[i] - arr[i].second.second ;
      }
      
      ll sum = accumulate(WT.begin(),WT.end(),0);
      
      
      cout << "Average waiting time is : " ;
      cout << sum/t << endl  ;
     



}
