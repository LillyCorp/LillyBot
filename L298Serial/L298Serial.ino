
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

String command = ""; // Stores response of the HC-06 Bluetooth device

//const int LeftEnable = 3;
const int LeftA1 = 11;
const int LeftA2 = 10;

//const int RightEnable = 2;
const int RightA1 = 5;
const int RightA2 = 6;

String input; 
//String command
String readString="";
 


void setup() {
  // initialize serial communications at 9600 bps:
  //pinMode(LeftEnable,OUTPUT);
  pinMode(LeftA1,OUTPUT);
  pinMode(LeftA2,OUTPUT);

  //pinMode(RightEnable,OUTPUT);

  pinMode(RightA1,OUTPUT);
  pinMode(RightA2,OUTPUT);
  
  mySerial.begin(115200);
}

void loop() {


  while (mySerial.available()) // this will be skipped if no data present, leading to
                             // the code sitting in the delay function below
  {
    //delay(30);  //delay to allow buffer to fill 
   
      //char input = mySerial.read();  //gets one byte from serial buffer
      //readString += input; //makes the string readString


       // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }
    
    Serial.println(command);
    command = ""; // No repeats
  }
  input = command;
  
  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    mySerial.write(Serial.read());
  }
    

     if (Serial.read() != '\n') {

    if(input=='F') {                                  //Move forward
           Serial.print(input);
           analogWrite(LeftA1,250);
           analogWrite(RightA2,250);
           delay(70);
           analogWrite(LeftA1,0);
           analogWrite(RightA2,0); 
  }
else if(input=='B') {                                  //Move forward
           Serial.print(input);
           analogWrite(LeftA2,255);
           analogWrite(RightA1,255);
           delay(50); 
           analogWrite(LeftA2,0);
           analogWrite(RightA1,0);
  }

else if(input=='L') {                                  //Move forward
           Serial.print(input);
           analogWrite(LeftA1,255);
           analogWrite(RightA1,255);
           delay(40); 
           analogWrite(LeftA1,0);
           analogWrite(RightA1,0);
  }

else if(input=='R') {                                  //Move forward
           Serial.print(input);
           analogWrite(LeftA2,255);
           analogWrite(RightA2,255);
           delay(40); 
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
  
}

  
 else{
           analogWrite(LeftA1,0);
           analogWrite(RightA1,0);
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
    
    }
  }
  
  }
}
