int singleNumber(int* nums, int numsSize){
  int ans = 0, i = 0;
  
  while (i < numsSize) 
    ans ^= nums[i], i++;
  
  return ans;
}
