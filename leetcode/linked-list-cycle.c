struct ListNode *next(struct ListNode *head, int step) 
{
  while (step-- > 0 && head != NULL)  
    head = head->next;
  return head;   
}

bool hasCycle(struct ListNode *head) 
{
  if (head == NULL)  
    return false;
  
  struct ListNode *fast = next(head, 2),
                  *slow = head;
  
  while (fast != NULL && slow != NULL) {
    if (fast == slow)
      return true;
    
    fast = next(fast, 2);
    slow = next(slow, 1);
  }
    
  return false;
}
