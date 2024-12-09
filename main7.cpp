#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *cur, ListNode *pre) {
    if (cur == NULL) return pre;
    //先保存下一个节点，不然指针翻转后连接不到下一个节点
    ListNode *temp = cur->next;
    //cur->next代表下一个节点 pre代表上一个节点,这一步代表指向翻转
    cur->next = pre;
    reverse(temp,cur);
}

ListNode *reverse2(ListNode *cur) {
    ListNode *pre = NULL;
    while (cur) {
        //先保存下一个节点，不然指针翻转后连接不到下一个节点
        ListNode *temp = cur->next;
        //cur->next代表下一个节点 pre代表上一个节点,这一步代表指向翻转
        cur->next = pre;
        //节点替换
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main() {
    ListNode *listNode1 = new ListNode(1);
    ListNode *listNode2 = new ListNode(2);
    ListNode *listNode3 = new ListNode(3);
    listNode1->next = listNode2;
    listNode2->next = listNode3;
    printf("before listNode1:%d,listNode2:%d,listNode3:%d\n", listNode1->val, listNode1->next->val,
           listNode2->next->val);

    reverse(listNode1,NULL);

    printf("after listNode3:%d,listNode2:%d,listNode1:%d\n", listNode3->val, listNode3->next->val,
           listNode2->next->val);
    return 0;
}