// anodes
int row[] = {8,9,10,11,12,13,A0,A1};
// cathodes
int col[] = {2,3,4,5,6,7};

// bit patterns for each row
byte data[] = {0,0,0,0,0,0,0,0};

// defines the size of the matrix 
int columns = 6;
int rows = 8;

//millisecond delay between displaying each row
int pause = 1;


/*
 * Initializes all of the pins with all of them on.
 */
void setup()
{
  for (int i=0;i<rows;i++)
  {
    pinMode(row[i], OUTPUT);
  } 
  
  for (int i=0;i<columns;i++)
  {
    pinMode(col[i], OUTPUT);
  }

  for(int i = 0; i < rows; ++i) {
    digitalWrite(row[i], HIGH);
  }
  for(int i = 0; i < columns; ++i) {
    digitalWrite(col[i], LOW);
  }

}

/*
 * Loops through each of the methods as a demo of what the LEDs can do
 */
void loop()
{
  for(int i=0; i<10; i++){
     scanRow();
  }
  
  for(int i=0; i<1000; i++){
     showPattern();
  }
  
  allOff();
  delay(2000);
  
  for(int i=0; i<1000; i++){
    allOn();
  }
  
  allOff();
  delay(2000);
  
  for(int i=0; i<10; i++){
     scanColumn();
  }
  
  allOff();
  delay(2000);
  
}

/*
 * Turns off all of the LEDs.
 */
void allOff()
{
  for (int i=0;i<8;i++)
  {
    digitalWrite(row[i], LOW);
  }
  for (int i = 0; i< 6; i++){
    digitalWrite(col[i], HIGH);
  }
}
  
  /*
   * Uses a 2-D array to tell the LED to turn on (1) or off (0).
   */
  void showPattern()
{
  
  data[0] =  B00000000;
  data[1] =  B00111111;
  data[2] =  B00001000;
  data[3] =  B00001000;
  data[4] =  B00111111;
  data[5] =  B00000000;
  data[6] =  B00111010;
  data[7] =  B00000000;
  
  for (int thisrow=0;thisrow<rows;thisrow++)
  {
    //turn everything off
    allOff();
    //turn on current row
    digitalWrite(row[thisrow], HIGH);
    // loop through columns of this row and light
    for (int thiscol=0;thiscol<columns;thiscol++)
    {
      if (bitRead(data[thisrow],columns-thiscol-1)==1)
      {
        digitalWrite(col[thiscol], LOW);
      }
      else
      {
        digitalWrite(col[thiscol], HIGH);
      }
    }
    delay(pause);
    
  }
  
  
 /*
  * Lights up the LEDs by row, scanning across the board. 
  */
}
  void scanRow()
{
  
  data[0] =  B00111111;
  data[1] =  B00111111;
  data[2] =  B00111111;
  data[3] =  B00111111;
  data[4] =  B00111111;
  data[5] =  B00111111;
  data[6] =  B00111111;
  data[7] =  B00111111;
  
  for (int thisrow=0;thisrow<rows;thisrow++)
  {
    //turn everything off
    allOff();
    //turn on current row
    digitalWrite(row[thisrow], HIGH);
    // loop through columns of this row and light
    for (int thiscol=0;thiscol<columns;thiscol++)
    {
      if (bitRead(data[thisrow],columns-thiscol-1)==1)
      {
        digitalWrite(col[thiscol], LOW);
      }
      else
      {
        digitalWrite(col[thiscol], HIGH);
      }
    }
    delay(100);
    
  }
    
}


/*
 * Turns on all of the LEDs.
 */
void allOn(){
    
  for (int thisrow=0;thisrow<rows;thisrow++)
  {
    //turn everything off
    allOff();
    //turn on current row
    digitalWrite(row[thisrow], HIGH);
    // loop through columns of this row and light
    for (int thiscol=0;thiscol<columns;thiscol++)
    {
        digitalWrite(col[thiscol], LOW);
    }
    delay(pause);
  }
}


/*
 * Lights up the LEDs by row, scanning across the board.
 */
 void scanColumn()
{
  data[0] =  B11111111;
  data[1] =  B11111111;
  data[2] =  B11111111;
  data[3] =  B11111111;
  data[4] =  B11111111;
  data[5] =  B11111111;
  
  for (int thiscol=0;thiscol<columns;thiscol++)
  {
    //turn everything off
    allOff();
    //turn on current row
    digitalWrite(col[thiscol], LOW);
    // loop through columns of this row and light
    for (int thisrow=0;thisrow<rows;thisrow++)
    {
      if (bitRead(data[thiscol],rows-thisrow-1)==1)
      {
        digitalWrite(row[thisrow], HIGH);
      }
      else
      {
        digitalWrite(row[thisrow], LOW);
      }
    }
    delay(100);
    
  }
    
}
