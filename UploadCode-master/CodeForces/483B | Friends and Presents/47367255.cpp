#include <bits/stdc++.h>
using namespace std;
int main(){
 // freopen("input.txt", "r", stdin);
 // freopen("output.txt", "w", stdout);
 ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 int cnt1, cnt2, x, y;
 cin>>cnt1>>cnt2>>x>>y;
 int left = -1, right = 2e9;
 while (right - left > 1){
  int mid = left + (right - left) / 2;
  int a = mid / x - mid / (x * y);
  int b = mid / y - mid / (x * y);
  int mid_temp = mid - a - b - mid / (x * y);
  int cnt1_temp = max(0, cnt1 - b);
  int cnt2_temp = max(0, cnt2 - a);
  if (mid_temp >= cnt1_temp + cnt2_temp){
   right = mid;
  }
  else{
   left = mid;
  }
 }
 cout<<right;
}