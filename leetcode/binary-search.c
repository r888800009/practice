int search(int *nums, int numsSize, int target){
  int front = 0, last = numsSize;
  int mid = (front + last) / 2;
  
  while (front < last) {
    if (target == nums[mid])
      return mid ;
    else if (target < nums[mid])
      last = mid; 
    else if (target > nums[mid])
      front = mid + 1; 
    mid = (front + last) / 2;
  } 
  
  return -1; 
}
