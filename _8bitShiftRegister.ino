// Luke Stanley
//  8 bit shift register library
//  Uses a few pins on the Arduino to control an eight bit shift register to create greater pin useage efficiency
//  Coded with a 74HC595 shift register
// Copyright 2014 Luke Stanley


int latchPin = 8;     //  pin that determines when output displays
int shiftPin = 12;    //  pin that pushes values when HIGH
int inputPin = 11;    //  pin that indicates boolean value to be pushed

boolean data[8] = {0,0,0,0, 0,0,0,0};
boolean toPush;
boolean toSet = false;


void setup()                  // setup of pins ect lol
{
  clearReg();
  pinMode(latchPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(inputPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  stuff();  // just a little LED show
}

void pushDataArray(boolean d[])          // pushes an array of values onto shift register
{
   digitalWrite(latchPin, LOW);
   for(int i = 7; i >= 0; i--)
   {
       toSet = d[i];
       digitalWrite(inputPin, toSet);
       digitalWrite(shiftPin, HIGH);
       digitalWrite(shiftPin, LOW);
   }
   copyArray(d, data);
   digitalWrite(latchPin, HIGH);
}

void setBit(int index, boolean val)      // changes a single bit on the register
{
  data[index] = val;
  pushDataArray(data);
}

void rawPush(boolean b)                    // pushes new value onto register, but doesn't update any data values elsewhere
{
  digitalWrite(latchPin, LOW);
  digitalWrite(inputPin, b);
  digitalWrite(shiftPin, HIGH);
  digitalWrite(shiftPin, LOW);
  digitalWrite(latchPin, HIGH);
}

void push(boolean b)                                // pushes data but updates data array
{
  rawPush(b);
  for(int i = 7; i > 1; i--)
  {
    data[i] = data[i-1];
  }
  data[0]= b;
}
void copyArray(boolean a[], boolean b[])    // logical use : copies A[] into B[]
{
  for(int i = 0; i <7; i++)
  {
    b[i] = a[i];
  }
}

void clearReg()                            // sets all pins to 0, also updates data variables
{
  boolean zeroArray[8] = {0,0,0,0 ,0,0,0,0};
  pushDataArray(zeroArray);
}
void maxReg()                            // sets all pins to 0, also updates data variables
{
  boolean onArray[8] = {1,1,1,1 ,1,1,1,1};
  pushDataArray(onArray);
}

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

