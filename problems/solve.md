- 结题思路  
如下题目可以按照同样的套路来解决：  
1 [#1 Two Sum](https://leetcode.com/problems/two-sum/description/)  
2 [#15 3Sum](https://leetcode.com/problems/3sum/description//)  
3 [# 3Sum Closest](https://leetcode.com/problems/3sum-closest/description/)  
思路  
第一步：对数组进行排序  
第二步：第一层循环控制第一个数，里面的保证后面 ```n - 1``` 个数的和等于 ```target - nums[i]```，并在循环最后面跳过和当前元素值不一样的那一个元素  
第三步：重复第二步骤，之后最里面只需要计算两个元素的和，并跳过重复的元素  
本题代码如下：  
<pre><code>class Solution {
public:
    vector&lt;vector&lt;int&gt;&gt fourSum(vector<int>& nums, int target) {
        vector&lt;vector&lt;int&gt;&gt; res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n;){
            for(int j = i + 1; j < n;){
                int targetTmp = target - nums[i] - nums[j];
                int begin = j + 1, end = n - 1;
                while(begin < end){
                    if(nums[begin] + nums[end] < targetTmp) begin++;
                    else if(nums[begin] + nums[end] > targetTmp) end--;
                    else{
                        vector&lt;int&gt; vnTmp(4, 0);
                        vnTmp[0] = nums[i];
                        vnTmp[1] = nums[j];
                        vnTmp[2] = nums[begin];
                        vnTmp[3] = nums[end];
                        res.push_back(vnTmp);
                        while(vnTmp[2] == nums[begin]) begin++;
                        while(vnTmp[3] == nums[end]) end--;
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j - 1]) j++;
            }
            i++;
            while(i < n && nums[i] == nums[i - 1]) i++;
        }
        return res;
    }
};</code></pre>