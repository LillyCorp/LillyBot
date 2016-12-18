#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

String command = ""; // Stores response of the HC-06 Bluetooth device
const int LeftA1 = 11;
const int LeftA2 = 10;

//const int RightEnable = 2;
const int RightA1 = 5;
const int RightA2 = 6;


void setup() {
  // Open serial communications:
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  pinMode(LeftA1,OUTPUT);
  pinMode(LeftA2,OUTPUT);

  //pinMode(RightEnable,OUTPUT);

  pinMode(RightA1,OUTPUT);
  pinMode(RightA2,OUTPUT);
  
  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(9600);
}

void loop() {
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command = (char)mySerial.read();
      
    }
    
    Serial.println(command);
  
  
 

String input = command;

   if(command=="F") {                                  //Move forward
      
      analogWrite(LeftA1,255);
      analogWrite(RightA2,255);
      delay(100);
      //Serial.println("forward  " + command);
      analogWrite(LeftA1,0);
      analogWrite(RightA2,0); 
  
   }
else if(command=="B") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("back");
           analogWrite(LeftA2,255);
           analogWrite(RightA1,255);
           delay(100); 
           analogWrite(LeftA2,0);
           analogWrite(RightA1,0);
  }

else if(command=="R") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("left");
           analogWrite(LeftA2,255);
           analogWrite(RightA2,255);
           delay(100); 
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
  }

//else if(command=="I") {                                  //Move forward
//           //Serial.print(input);
//           //Serial.println("left");
//           analogWrite(LeftA2,245);
//           analogWrite(RightA2,255);
//           delay(100); 
//           analogWrite(LeftA2,0);
//           analogWrite(RightA2,0);
//  }


else if(command=="L") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("right");
           analogWrite(LeftA1,255);
           analogWrite(RightA1,255);
           delay(100); 
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
  
}

//else if(command=="G") {                                  //Move forward
//           //Serial.print(input);
//           //Serial.println("right");
//           analogWrite(LeftA1,255);
//           analogWrite(RightA1,245);
//           delay(100); 
//           analogWrite(LeftA1,0);
//           analogWrite(RightA1,0);
//  
//}

else if(command=="I") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("right");
           analogWrite(13,255);
           //analogWrite(RightA1,245);
           delay(100); 
           analogWrite(13,0);
           //analogWrite(RightA1,0);
  
}
else if(command=="G") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("right");
           analogWrite(12,255);
           //analogWrite(RightA1,245);
           delay(100); 
           analogWrite(12,0);
           //analogWrite(RightA1,0);
  
}

else if(command=="H") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("right");
           analogWrite(9,255);
           //analogWrite(RightA1,245);
           delay(100); 
           analogWrite(9,0);
           //analogWrite(RightA1,0);
  
}
else if(command=="J") {                                  //Move forward
           //Serial.print(input);
           //Serial.println("right");
           analogWrite(8,255);
           //analogWrite(RightA1,245);
           delay(100); 
           analogWrite(8,0);
           //analogWrite(RightA1,0);
  
}



  
 else if(command == "S"){
          //Serial.println("STOP");
           analogWrite(LeftA1,0);
           analogWrite(RightA1,0);
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
    
    }

        command = ""; // No repeats

  }
}
