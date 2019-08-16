int maxProfit(int* prices, int pricesSize)
{
  if (pricesSize == 0) 
    return 0;
  
  int minIndex = 0, sellMax = 0;
  
  for (int i = 1; i < pricesSize; i++) {
    int sell = prices[i] - prices[minIndex];
    if (sell > sellMax)
      sellMax = sell;
      
    if (prices[minIndex] > prices[i])
      minIndex = i;  
  }
  
  return sellMax;
}
