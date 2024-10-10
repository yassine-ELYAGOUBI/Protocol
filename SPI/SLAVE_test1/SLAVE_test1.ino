
#include<SPI.h>
char buff [60];
 byte index;
volatile boolean process;

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE); //turn on SPI in slave mode
  
  index = 0;
  process = false;
  SPI.attachInterrupt(); // turn on interrupt
  Serial.println("this is the Slave");

}
ISR (SPI_STC_vect) {// SPI interrupt routine 
   byte c = SPDR;
    // read from SPI  Register
   if (index < sizeof buff) {
      buff [index++] = c; // save 
      
      if (c == '\r') //check for the end of the word
      process = true;
   }
}

void loop (void) {
  
   if (process) {
      process = false; //reset the process
      if (buff[0] == 'T')
      Serial.println ("test recieved"); 
      if (buff[0] == 'D')
      Serial.println ("data recieved"); 
      
      index= 0; //reset button to zero
   }
}