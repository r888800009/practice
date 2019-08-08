int removeDuplicates(int *nums, int numsSize){
  if (numsSize == 0)
    return 0;
  
  int read = 0, write = 0;
  int cur = nums[0] + 1; 
  
  while (read < numsSize) {
    if (nums[read] != cur) 
      nums[write++] = cur = nums[read];
    read++;
  }
  
  return write;
}
