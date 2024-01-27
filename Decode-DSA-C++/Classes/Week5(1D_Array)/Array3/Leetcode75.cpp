#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
    // void sort1(vector<int> &v){
    //     int n = v.size();
    //     int no0 = 0;
    //     int no1 = 0;
    //     int no2 = 0;
    //     for(int i=0;i<n;i++){
    //         if(v[i]==0) no0++;
    //         else if(v[i]==2) no2++;
    //         else no1++;
    //     }

    //     for(int i=0;i<n;i++){
    //         if(i<=no0-1){ 
    //             v[i] = 0;
    //         }
    //         else if(i<(no1+no0)){
    //             v[i] = 1;
    //         }
    //         else v[i] = 2;
    //     }
    // }

    //Dutch Flag algo
    /*  1) mid ke bare me socho
        2) 0 to low - 1 -> 0
        3) high + 1 to end -> 2
        4) low to mid - 1 -> 1 */

    void sort2(vector<int> &v){
        int n = v.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(v[mid]==2){
                swap(v[mid],v[high]);
                high--;
            }
            if(v[mid]==0){
                swap(v[mid],v[low]);
                low++;
                mid++;
            }
            if(v[mid]==1){
                mid++;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        //sort1(nums);
        sort2(nums);
        for(int i=0;i<nums.size();i++){
            cout << nums[i] << ",";
        }
    }
};