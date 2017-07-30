##q1: Two Sum
- 方法一：暴力法
通过两层循环
不能有效的利用之前遍历过程中得到的信息

- 方法二：比较好的方法（最好的？？？）
一层循环，用一个**map**记录下之前遍历过的元素的值及其位置；对于当前遍历到的元素，看看它还差多少就能够达到target，只需要把这个差作为key去map里面找（因为map里面存放了当前元素前面的元素的值和位置），如果找到了则达到目标，否则把当前元素加入map，继续遍历，直到找到；如果没有找到返回{}
- 下面是c++代码
------------
<pre><code>class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map&lt;int, int&gt; map;
		for(int i = 0; i < nums.size(); i++){
			if(map.find(target - nums[i]) != map.end())
				return {i, map[target - nums[i]]};
			map[nums[i]] = i;
		}
		return {};
    }
};</code></pre>