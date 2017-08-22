## q17: Letter Combinations of a Phone Number 
- 方法一：递归（减治？) 
<pre><code>class Solution {
public:
    vector&lt;string> myLetter(string digits) {
        int n = digits.size();
        vector&lt;string> vs;
        if(n == 0) {
            
        } else if(n == 1) {
            char c = digits[0];
            string sTmp = "a";
            for(int i = 0; i < map[c].size(); i++){
                sTmp[0] = map[c][i];
                vs.push_back(sTmp);
            }
        } else {
            char c = digits[0];
            string s = digits.substr(1, n - 1);
            vector&lt;string> vsTmp = myLetter(s);
            for(int i = 0; i < map[c].size(); i++){
                for(int j = 0; j < vsTmp.size(); j++){
                    string s1 = vsTmp[j];
                    s1.insert(0, 1, map[c][i]);
                    vs.push_back(s1);
                }
            }
        }
        return vs;
    }
    vector&lt;string> letterCombinations(string digits) {
        vector&lt;char> vc2 = {'a', 'b', 'c'};
        vector&lt;char> vc3 = {'d', 'e', 'f'};
        vector&lt;char> vc4 = {'g', 'h', 'i'};
        vector&lt;char> vc5 = {'j', 'k', 'l'};
        vector&lt;char> vc6 = {'m', 'n', 'o'};
        vector&lt;char> vc7 = {'p', 'q', 'r', 's'};
        vector&lt;char> vc8 = {'t', 'u', 'v'};
        vector&lt;char> vc9 = {'w', 'x', 'y', 'z'};
        map['2'] = vc2;
        map['3'] = vc3;
        map['4'] = vc4;
        map['5'] = vc5;
        map['6'] = vc6;
        map['7'] = vc7;
        map['8'] = vc8;
        map['9'] = vc9;
        vector&lt;string> vs = myLetter(digits);
        return vs;
    } 
private:
    std::map&lt;char, vector&lt;char>> map;
};</code></pre>

- 方法二：迭代  
<pre><code>class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vs;
        if(digits.size() == 0) return vector<string>();
        static const vector<string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vs.push_back("");
        for(int i = 0; i < digits.size(); i++){
            int n = digits[i] - '0';
            string str = strs[n];
            vector<string> tmp;
            for(int j = 0; j < vs.size(); j++){
                for(int k = 0; k < str.size(); k++){
                    tmp.push_back(vs[j] + str[k]);
                }
            }
            vs.swap(tmp);
        }
        return vs;
    }
};
</code></pre>
