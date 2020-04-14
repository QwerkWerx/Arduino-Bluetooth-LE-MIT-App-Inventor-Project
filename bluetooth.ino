#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9); // TX, RX
int LED = 13; // the on-board LED
int Data; // the data received

void setup() {
  
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
  pinMode(LED,OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);

}

void loop() {

  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    Serial.println(Data);
    if(Data==1){  
      digitalWrite(LED,1);
      Serial.println("LED On!");
      Bluetooth.println("LED On!");
      digitalWrite(4,LOW);
    }
    else if(Data==0){
       digitalWrite(LED,0);
       Serial.println("LED Off!");
       Bluetooth.println("LED  On D13 Off ! ");
         digitalWrite(4, HIGH);
    }
    else{;}
  }
delay(100);
}
