struct ListNode* newEnd;

struct ListNode* reverseList(struct ListNode* head){
  if (head == NULL)
    return NULL;
  
  if(head->next == NULL) {
    newEnd = head; 
    return head;
  }
  
  struct ListNode* newHead = reverseList(head->next);
  newEnd->next = head;
  head->next = NULL;
  newEnd = head;
  
  return newHead;
}
