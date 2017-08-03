- 方法一  
两次遍历： 第一次遍历得到整个链表的长度，并且得到要删除的结点的顺序序号（len - n + 1）； 第二次遍历执行删除操作。  
如果要删除第一个元素，直接返回head->next  
删除某元素之后，记得最好free一下  
代码如下：  
<pre><code>/\*\*
 \* Definition for singly-linked list.
 \* struct ListNode {
 \*     int val;
 \*     ListNode \*next;
 \*     ListNode(int x) : val(x), next(NULL) {}
 \* };
 \*/
class Solution {
public:
    ListNode\* removeNthFromEnd(ListNode\* head, int n) {
        int ns = 0;
        ListNode \*ltmp = head;
        while(ltmp){
            ns++;
            ltmp = ltmp->next;
        }        
        n = ns - n + 1;
        if(n == 1){
            ListNode \*tmp = head;
            head = head->next;
            free(tmp);
            return head;
        }
        ltmp = head;
        ns = 0;
        while(ltmp){
            ns++;
            if(ns + 1 == n){
                ListNode \*tmp = ltmp->next;
                ltmp->next = tmp->next;
                free(tmp);
                return head;
            }
            ltmp = ltmp->next;
        }
    }
};</code></pre>

- 方法二
时间复杂度应该和上面差不多，但是看起来好看  
一个指针一开始出发，每走一个元素计数一次，当走到要求的那个 n 的时候，第二个指针开始出发和第一个指针同步走，当第一个指针走到头以后，第二个指针就指向了要被删除的那个元素。  
下面是代码：  
<pre><code>class Solution {
public:
    ListNode\* removeNthFromEnd(ListNode\* head, int n) {
        int ns = 0;
        ListNode \*fast = head, \*slow = head;
        while(ns < n){
            fast = fast->next;
            ns++;
        }
        ns = 0;
        while(fast){
            fast = fast->next;
            if(fast) slow = slow->next;
            ns++;
        }
        if(ns == 0){
            ListNode \*tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        ListNode \*tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return head;
    }
};</code></pre>