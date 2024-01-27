#include<bits/stdc++.h>
using namespace std;

int main(){

   string s;
   getline(cin,s);
   int n = s.length();
   if(n%2 == 0) reverse(s.begin()+n/2,s.end());
   else{
    cout << "Not even length string" ;
    return 0;
   }
   cout << s << endl;


    return 0;
}