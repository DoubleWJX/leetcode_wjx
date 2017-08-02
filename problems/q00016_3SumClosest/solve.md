- 方法一  
类似于q15([3Sum](https://leetcode.com/problems/3sum/description/))，分解为1个元素和两个元素之和，下面是代码
<pre><code>class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target_0) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        if(res - target_0 == 0) return res;
        for(int i = 0; i < n;){
            int target = target_0 - nums[i];
            int begin = i + 1, end = n - 1;
            while(begin < end){
                int n2sum = nums[begin] + nums[end];
                if(abs(n2sum - target) < abs(res - target_0))
                    res = nums[i] + n2sum;
                if(n2sum > target) end--;
                else if(n2sum < target) begin++;
                else return target_0;
            }
            i++;
            while(nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};</code></pre>