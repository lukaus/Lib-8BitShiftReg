void stuff()
{
  boolean on[8] = {1,1,1,1, 1,1,1,1};
  pushDataArray(on);
  delay(500);
  clearReg();
  delay(500);
  pushDataArray(on);
  delay(500);
  clearReg();
  delay(500);
  
  boolean alt[8] = {1,0,1,0, 1,0,1,0};
  pushDataArray(alt);
  delay(200);
  for(int i = 1; i <8; i++)
  {
    push(toPush);
    toPush = !toPush;
    delay(150);
  }
  
  clearReg();
  push(true);
  delay(200);
  for(int i = 1; i < 8; i++)
  {
    push(0);
    delay(100);
  }
  
  for(int i = 6; i >= 0; i--)
  {
    setBit(i, 1);
    setBit(i+1,0);
    delay(100);
  }
  
  pushDataArray(on);
  push(false);
  delay(100);
  for(int i = 1; i < 8; i++)
  {
    push(1);
    delay(100);
  }
  for(int i = 1; i < 8; i++)
  {
    for(int j = 0; j < i; j++)
    {
      push(1);
    }
    push(0);
    for(int k = 0; k < 8-(i+1); k++)
    {
      push(1);
    }
    delay(100);
  }
  
   clearReg();
  for(int count = 0; count < 8; count++)
  {
    if(count != 4)
     {
      setBit(count, true);
      setBit(7-count, true);
      delay(200);
      setBit(count, false);
      setBit(7-count, false);
     }
  }
  delay(200);
  pushDataArray(on);
  for(int count = 0; count < 8; count++)
  {
    if(count != 4)
     {
      setBit(count, 0);
      setBit(7-count, 0);
      delay(200);
      setBit(count, 1);
      setBit(7-count, 1);
     }
  }
  delay(200);
   clearReg();
  for(int count = 0; count < 4; count++)
  {
    if(count != 4)
     {
      setBit(count, true);
      setBit(7-count, true);
      delay(100);
     }
  }
  for(int count = 0; count < 4; count++)
  {
    if(count != 4)
     {
      setBit(count, 0);
      setBit(7-count, 0);
      delay(100);
     }
  } 
  
   clearReg();
  for(int count = 0; count < 4; count++)
  {
    if(count != 4)
     {
      setBit(count, true);
      setBit(7-count, true);
      delay(100);
     }
  }
  for(int count = 0; count < 4; count++)
  {
    if(count != 4)
     {
      setBit(count, 0);
      setBit(7-count, 0);
      delay(100);
     }
  } 
  clearReg();
  delay(100);
  for(int y = 0; y < 2; y++)
  {
    int jf = 0;
    for(int i = 4; i < 8; i++)
    {
      setBit(3-jf,1);
      setBit(i,1);
      jf++;
      delay(100);
    }  
    
    maxReg();
    int jg = 0;
    for(int i = 4; i < 8; i++)
    {
      setBit(3-jg,0);
      setBit(i,0);
      jg++;
      delay(100);
    }  
  }
  clearReg();
  push(true);
  delay(200);
  for(int i = 1; i < 8; i++)
  {
    push(0);
    delay(50);
  }
  
  for(int i = 6; i >= 0; i--)
  {
    setBit(i, 1);
    setBit(i+1,0);
    delay(50);
  }
  
}
