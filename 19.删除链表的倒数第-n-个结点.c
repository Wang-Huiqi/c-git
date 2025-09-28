/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  if(head==NULL||head->next==NULL) return NULL;
    struct ListNode *temp=head;
    int count=1,i;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    temp=head;
    for(i=1;i<count-n;i++){
        temp=temp->next;
    }
    if(temp->next->next==NULL&&n==1) {
        temp->next=NULL;
        return head;
    }
    if(count==n){
        head=head->next;
        return head;
    }
    struct ListNode *temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return head;
}