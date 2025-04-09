// Majority Element II
// Difficulty: MediumAccuracy: 48.1%Submissions: 137K+Points: 4Average Time: 15m
// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: o candidate occur more than n/3 times.
// Constraint:
// 1 <= arr.size() <= 106
// -109 <= arr[i] <= 109


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    vector<int> findMajority(vector<int>& arr) {
    int n=arr.size();
    if(n==0)return{};
    
    int count1=0, count2=0;
    int candidate1=INT_MIN, candidate2=INT_MIN;
    
    for(int num:arr){
        if(num==candidate1){
            count1++;
        }else if(num==candidate2){
            count2++;
        }else if(count1==0){
            candidate1=num;
            count1=1;
        }else if(count2==0){
            candidate2=num;
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    
    count1=count2=0;
    for(int num:arr){
        if(num==candidate1)count1++;
        else if (num==candidate2)count2++;
    }
    
    vector<int> result;
    if(count1>n/3) result.push_back(candidate1);
    if(count2>n/3) result.push_back(candidate2);
    
    sort(result.begin(),result.end());
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
