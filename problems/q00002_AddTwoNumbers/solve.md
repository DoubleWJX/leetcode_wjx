q2: Add Two Numbers
===
- 一开始做的
用了一个vector&lt;int&gt;来保存结果的每一位，最后把这个vector利用for循环存为链表  
代码如下：
<pre><code>
/\*\*
 \* Definition for singly-linked list.
 \* struct ListNode {
 \*     int val;
 \*     ListNode *next;
 \*     ListNode(int x) : val(x), next(NULL) {}
 \* };
 \*/
class Solution {
public:
    ListNode\* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vn;
        int jin = 0;
        while(l1 && l2){
            int a = l1->val + l2->val + jin;
            jin = a / 10;
            vn.push_back(a % 10);
            l1 = l1->next; l2 = l2->next; 
        }
        while(l1){
            int a = l1->val + jin;
            jin = a / 10;
            vn.push_back(a % 10);
            l1 = l1->next;
        }
        while(l2){
            int a = l2->val + jin;
            jin = a / 10;
            vn.push_back(a % 10);
            l2 = l2->next;
        }
        if(jin > 0){
            vn.push_back(jin);
        }
        if(vn.size() == 0) return NULL;
        ListNode \*ln = (ListNode \*) malloc(sizeof(ListNode));
        ln->val = vn[0]; ln->next = NULL;
        if(vn.size() == 1) return ln;
        ListNode \*lnr = (ListNode \*) malloc(sizeof(ListNode));
        ln->next = lnr;
        for(int i = 1; i < vn.size(); i++){
            lnr->val = vn[i];
            if(i < vn.size() - 1){
                ListNode *tmp = (ListNode \*) malloc(sizeof(ListNode));
                lnr->next = tmp; lnr = tmp;
            }else{
                lnr->next = NULL;
            }
        }
        return ln;
    }
};
</code></pre>
可以看出其实没有必要采用一个vector保留结果； 而且3个循环保证两个链表结束了也比较繁琐。只不过这样看起来实现起来好像简单一些
  
- 其他比较好的代码
<pre><code>
/\*\*
 \* Definition for singly-linked list.
 \* struct ListNode {
 \*     int val;
 \*     ListNode *next;
 \*     ListNode(int x) : val(x), next(NULL) {}
 \* };
 \*/
class Solution {
public:
    ListNode\* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode \*ln = nullptr, \*lnr, \*tmp;
        while(l1 || l2){
            int v1 = l1 ? l1->val : 0, v2 = l2 ? l2->val : 0;
            int a = v1 + v2 + carry;
            carry = a / 10;
            tmp = new ListNode(a % 10);
            if(!ln)
                ln = lnr = tmp;
            else{
                lnr->next = tmp;
                lnr = lnr->next;
            }            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) lnr->next = new ListNode(carry);
        return ln;
    }
};
</code></pre>

- 总结
注意这种数据结构新建对象（变量）的方式
注意野指针
注意结点之间要连接上，不要断掉
注意一下第一个结点