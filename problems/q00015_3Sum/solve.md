- 方法一
3个元素的和为0，可以看成是固定一个元素的情况下，寻找两个元素之和等于当前这个元素值的相反数，而我们在leetcode中做的第1题：Two Sum[](https://leetcode.com/problems/two-sum/description/)，就和这里的寻找两个元素的和等于固定元素差不多。因此可以按照如下思路编写程序：  
1 外层循环遍历数组
2 在当前遍历到的元素后面（前面的元素不用考虑，只要每次都是在后面找所有的解就行）寻找所有两个元素之和等于当前元素的值的相反数
3 判断当前求得的解是否重复，不重复则加入到结果里面  
为了保证是否重复，一时想不到好的办法，就先用最简单的遍历方法吧；为了使每次比较的时候尽量简单点，我让每次存入结果的解都按照非递减序排列。  
为了减少排序的复杂度，我先把输入的数组按照非递减序列排序
<pre><code>class Solution {
public:
    vector&lt;vector&lt;int&gt;&gt; threeSum(vector<int>& nums) {
        vector&lt;vector&lt;int&gt;&gt; vvn;
        map&lt;int, int&gt; mapTmp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target = -nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                if(mapTmp.find(target - nums[j]) != mapTmp.end() && mapTmp[target - nums[j]] != j) {
                   if(mapTmp[target - nums[j]] > i ){
                       int min1 = nums[i];
                       int min2 = min(nums[j], target - nums[j]);
                       int min3 = max(nums[j], target - nums[j]);
                       bool tag = false;
                       for(int ik = 0; ik < vvn.size(); ik++){
                           if(vvn[ik][0] == min1 && vvn[ik][1] == min2 && vvn[ik][2] == min3){
                               tag = true;
                           }
                       }
                       if(!tag) vvn.push_back({min1, min2, min3});
                   }
                }else{
                    mapTmp[nums[j]] = j;
                }
            }
        }
        return vvn;
    }
};</code></pre>抱着试一下是心态提交了代码，果然，在数据很多的情况下出现： Time LImit Exceeded，看了一下没有通过的那个测试例，果然数据很多。不过也说明代码能够保证正确性，不过时间复杂度高。  
分析代码我觉得最浪费时间的就是保证不重复，不过半天也想不到更好的解决方法。下面看看其他我觉得很好的方法吧
- 方法二
该方法就是来自leetcode提交后的Discussion那个部分，因为自己的代码没有ac之前好像看不到别人ac的代码？？  
保证不重复的思路就是：当某个元素的被考虑了之后就跳过该元素直到下一个与该元素不同的元素。具体的讲，在外层循环中，某个元素处理完成之后，跳过与该元素相同的其他元素直到某个与当前元素不同的元素；；；在内层循环里面也是一样的，某个元素被访问过（不管是不是解的一部分）以后，直接跳到下一个与当前元素不同的那个元素继续扫描。下面看代码
<pre><code>class Solution {
public:
    vector&lt;vector&lt;int&gt;&gt; threeSum(vector<int>& nums) {
        vector&lt;vector&lt;int&gt;&gt; res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n;){
            int target = -nums[i];
            int begin = i + 1, end = n - 1;
            while(begin < end){
                if(nums[begin] + nums[end] > target) end--;
                else if(nums[begin] + nums[end] < target) begin++;
                else{
                    vector&lt;int&gt; vTmp(3, 0);
                    vTmp[0] = nums[i]; vTmp[1] = nums[begin]; vTmp[2] = nums[end];
                    res.push_back(vTmp);
                    while(begin < end && nums[begin] == vTmp[1]) begin++;
                    while(begin < end && nums[end] == vTmp[2]) end--;
                }
            }
            i++;
            while(i < n && nums[i-1] == nums[i]) i++;
        }
        return res;
    }
};</code></pre>其中内层循环遍历采用首尾两个指针（大概就这意思）的方法，两个元素的和太大了，尾指针向前移动（因为后面的元素大），反之首指针向后移动，如果两个元素相等就加入结果。