## q20: Valid Parentheses
- 方法一
<pre><code>class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        if(s.size() & 1) return false;
        std::map<char, char> mapCC;
        mapCC[')'] = '(';
        mapCC['}'] = '{';
        mapCC[']'] = '[';
        std::stack<char> sk;
        for(int i = 0; i < s.size(); i++){
            if(sk.empty()){
                sk.push(s[i]);
            }else{
                if(sk.top() == mapCC[s[i]]) sk.pop();
                else sk.push(s[i]);
            }
        }
        return sk.empty();
    }
};
</code></pre>