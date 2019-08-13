class Solution {
  ListNode *end = NULL;
  
  ListNode *next(ListNode *cur, ListNode *nextHead) {
    if (cur->next != NULL) 
      return cur->next;
    
    if (end == NULL) 
      end = cur;
    else if (end != cur)
      return NULL;

    return nextHead;
    
  }
  
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) 
      return NULL;
    
    ListNode *a = headA, *b = headB;
    
    while (a != b) {
      a = next(a, headB);
      b = next(b, headA);
      if (a == NULL || b == NULL)
        return NULL;
    }
    
    return a;
  }
};
