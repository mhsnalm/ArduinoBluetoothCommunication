char junk;
char inputString;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600  , SERIAL_8N1);           // set the baud rate to 9600, same should be of your Serial Monitor
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) 
  {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    
    while (Serial.available() > 0)
    {
      junk = Serial.read() ;  // clear the serial buffer
      Serial.println(junk);
    }
    
    Serial.flush();

    Serial.println(inputString);

    if (inputString == 'a') // Lock Door
    {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
    }
    else if (inputString == 'b') // unlock Door
    {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
    }
    else if (inputString == 'c') // Blink lights
    {
      digitalWrite(10, LOW);
      delay(500);
      digitalWrite(10, HIGH);
      delay(500);
      digitalWrite(10, LOW);
      delay(500);
      digitalWrite(10, HIGH);
      delay(500);
      digitalWrite(10, LOW);
           delay(500);
      digitalWrite(10, HIGH);
 
    }

    inputString = 0;
  }
}
