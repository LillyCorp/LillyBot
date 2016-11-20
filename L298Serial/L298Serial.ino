


const int LeftEnable = 3;
const int LeftA1 = 10;
const int LeftA2 = 11;

const int RightEnable = 2;
const int RightA1 = 6;
const int RightA2 = 9;

char input; 

String readString="";
 


void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(LeftEnable,OUTPUT);
  pinMode(LeftA1,OUTPUT);
  pinMode(LeftA2,OUTPUT);

  pinMode(RightEnable,OUTPUT);
  pinMode(RightA1,OUTPUT);
  pinMode(RightA2,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {


  while (Serial.available()) // this will be skipped if no data present, leading to
                             // the code sitting in the delay function below
  {
    //delay(30);  //delay to allow buffer to fill 
   
      char input = Serial.read();  //gets one byte from serial buffer
      //readString += input; //makes the string readString
    

     if (Serial.read() != '\n') {

    if(input=='w') {                                  //Move forward
           Serial.print(input);
           digitalWrite(LeftEnable,HIGH);
           digitalWrite(RightEnable,HIGH);
           analogWrite(LeftA1,200);
           analogWrite(RightA2,255);
           delay(70);
           analogWrite(LeftA1,0);
           analogWrite(RightA2,0); 
  }
else if(input=='s') {                                  //Move forward
           Serial.print(input);
           digitalWrite(LeftEnable,HIGH);
           digitalWrite(RightEnable,HIGH);
           analogWrite(LeftA2,200);
           analogWrite(RightA1,200);
           delay(50); 
           analogWrite(LeftA2,0);
           analogWrite(RightA1,0);
  }

else if(input=='a') {                                  //Move forward
           Serial.print(input);
           digitalWrite(LeftEnable,HIGH);
           digitalWrite(RightEnable,HIGH);
           analogWrite(LeftA1,250);
           analogWrite(RightA1,200);
           delay(40); 
           analogWrite(LeftA1,0);
           analogWrite(RightA1,0);
  }

else if(input=='d') {                                  //Move forward
           Serial.print(input);
           digitalWrite(LeftEnable,HIGH);
           digitalWrite(RightEnable,HIGH);
           analogWrite(LeftA2,150);
           analogWrite(RightA2,250);
           delay(40); 
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
  
}

  
 else{
    digitalWrite(LeftEnable,LOW);
    digitalWrite(RightEnable,LOW);
           analogWrite(LeftA1,0);
           analogWrite(RightA1,0);
           analogWrite(LeftA2,0);
           analogWrite(RightA2,0);
    
    }
  }
  
  }
}
