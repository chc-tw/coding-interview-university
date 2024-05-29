#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lexicographicallyEarliestLIS(vector<int>& nums) {
    vector<int> dp;
    vector<int> idx(nums.size(), -1);
    vector<int> pre(nums.size(), -1);
    for(int i=0; i<nums.size(); i++) {
        // 使用 lower_bound 來找到第一個大於或等於 nums[i] 的元素
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        int j = it - dp.begin();
        // 若找不到或者找到的數字比 nums[i] 大，則在對應位置替換為 nums[i]
        if(it == dp.end() || *it > nums[i]) {
            if(it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            if(j > 0) {
                pre[i] = idx[j-1];
            }
            idx[j] = i;
        }
    }
    int i = idx[dp.size()-1];
    vector<int> ans(dp.size());
    for(int j = dp.size()-1; i>=0; j--) {
        ans[j] = nums[i];
        i = pre[i];
    }
    return ans;
}


int main(){
    vector<int> seq = {0,211, 152,5,245,73,72,241,7};
    vector<int> ans = lexicographicallyEarliestLIS(seq);
    for(auto i:ans) {
        cout<<i<<" ";
    }
}