- 方法一  
遍历每一个字符，用一个变量记录当前不重复的子串开始的位置；如果当前元素出现过并且出现的位置在开始的位置后面，说明重复了；那么，更新当前最长的长度，更新记录子串开始的位置的变量。代码如下，别忘了最后还需要比较一下。
<pre><code>class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector&lt;int&gt; mapPosition(256, -1);
        int n = 0, start = -1, i = 0;
        for(; i < s.size(); i++){
            if(mapPosition[s[i]] > start){
                if(i - 1 - start > n){
                    n = i - 1 - start;
                }
                start = mapPosition[s[i]];
            }
            mapPosition[s[i]] = i;
        }
        if(i - 1 - start > n){
            n = i - 1 - start;
        }
        return n;
    }
};</code></pre>