struct ListNode *next(struct ListNode *cur, int *val) {
  *val = cur->val;
  return cur->next; 
}
  
struct ListNode *newNode(int val)
{
  struct ListNode *result = malloc(sizeof(struct ListNode));
  result->val = val; 
  return result;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *head = NULL, *cur = NULL;
  
  while (l1 != NULL || l2 != NULL) {
    int max;
    if (l2 == NULL || l1 != NULL && l1->val < l2->val)
      l1 = next(l1, &max);
    else 
      l2 = next(l2, &max);
    
    if (head == NULL)
      head = cur = newNode(max); 
    else  
      cur = cur->next = newNode(max);
  }
    
  if (cur != NULL)
    cur->next = NULL;
  
  return head;
}
