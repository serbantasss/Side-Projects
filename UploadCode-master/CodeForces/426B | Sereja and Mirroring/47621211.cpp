#include <iostream>
using namespace std;
 
int main() {
 int n, m,res,arr[105][105],zeros,ones;
 bool flag =true;
 cin >> n >>m; 
 if ( n %2 !=0){
  cout << n;
  return 0;
 }
 for ( int i=0; i<n ; i++){
  for ( int j=0; j <m; j++){
   cin >> arr[i][j];
  }
 }
  int solution = n;
 while (flag){
 for (int i=0; i<n/2; i++){
  for (int j=0; j<m; j++){
   if ( arr[i][j]==arr[n-1-i][j] ){
    res = i+1;
  }
  else {
  cout << solution; 
   return 0; 
  }
 }
 }
 if (res %2==0){
  n =res;
  solution = res;
 }
 else{
  solution = res;
  flag =false;
 }
 }
 
 cout << solution; 
 return 0;
}