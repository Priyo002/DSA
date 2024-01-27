#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string str = "Priyo is my name";

    cout << str.size() << endl;
    cout << str.length() << endl;//same as above

    string str1 = "abcd";
    str1.push_back('e'); // str1.push_back("something") -> Error
    cout << str1 << endl;
    str1.pop_back();
    cout << str1 << endl;

    string t = "abc";
    string s = "def";
    s = s + t;
    cout << s << endl;
    s = s + 'a';
    s = s + "xyz";
    cout << s << endl;
    t = "abs" + t;
    cout << t << endl;

    string m = "abcdef"; //0 1 2 3 4 5 (Index)
    //reverse(m.begin(),m.end());
    reverse(m.begin()+2,m.begin()+5);// 2 to 4 index
    cout << m << endl;

    //to_string(integer) {converts integer to string}
    int x = 12345;
    string k = to_string(x);
    cout << k << endl;
    int len = k.length();
    cout << len << endl;


}