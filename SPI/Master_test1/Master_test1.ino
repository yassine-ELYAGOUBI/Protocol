
#include<SPI.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  digitalWrite(10,HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  Serial.println("this is the master");

}

void loop() {
  // put your main code here, to run repeatedly:

  char c;
  digitalWrite(10,LOW);

  for(const char *p = "T==> send test.\r"; c = *p; p++){

    SPI.transfer(c);
    Serial.print(c);
  }
  digitalWrite(10,HIGH);  
  delay(2000);


  digitalWrite(10,LOW);

  for(const char *p = "D==> send data.\r"; c = *p; p++){

    SPI.transfer(c);
    Serial.print(c);
  }
  digitalWrite(10,HIGH);  
  delay(2000);

}
