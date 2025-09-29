/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *Reverse(struct ListNode *head,int n){
    struct ListNode *pre=NULL;
    struct ListNode *cur=head;
    while(cur&&n--){
        struct ListNode *nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    head->next=cur;
    return pre;
 }
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *headptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    headptr->val=0;
    headptr->next=head;
    struct ListNode *dummy=headptr;
    while(1){
        struct ListNode *temp=dummy;
        for(int i=0;i<k&&temp;i++){
            temp=temp->next;
        }
        if(!temp){
            return headptr->next;
        }
        struct ListNode *GroupHead=dummy->next;
        struct ListNode *GroupTail=Reverse(GroupHead,k);
        dummy->next=GroupTail;
        dummy=GroupHead;
    }
    return headptr->next;
}
// @lc code=end

