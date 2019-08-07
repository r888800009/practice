void moveZeroes(int* nums, int numsSize){
  int writeHead = 0;
  int readHead = 0;
  
  while (readHead < numsSize) {
    if (nums[readHead] != 0) {
      nums[writeHead] = nums[readHead];
      writeHead++;
    }
    
    readHead++;
  }
  
  // fill 0
  while (writeHead < numsSize)
    nums[writeHead++] = 0;

}
