int next(int cur, int *nums, int step) 
{
  while (step-- > 0)
    cur = nums[cur];
    
  return cur;
}

int findDuplicate(int *nums, int numsSize)
{
  if (numsSize == 0)
    return -1;
  
  int fast = 0, slow = 0;
  
  do {
    fast = next(fast, nums, 2);
    slow = next(slow, nums, 1);
  } while(fast != slow);
  
  // find entry
  fast = 0;
  while (fast != slow) {
    fast = next(fast, nums, 1);
    slow = next(slow, nums, 1);
  }
    
  return fast;
}
