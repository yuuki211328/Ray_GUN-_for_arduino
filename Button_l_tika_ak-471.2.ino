// --sound array--//
const unsigned char ak4716k_raw[] PROGMEM  = {
  0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80,
   0x82, 0x82,
  0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81
  //sound data(raw)
};
unsigned int ak4716k_raw_len = 16000;  //bitrate(Hz)


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 6;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

 //play sound:
    pinMode (3,OUTPUT); //the number of the sound output pin
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);

}




void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
      play();
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
void play() {
  for(int i=0;i<ak4716k_raw_len;i++) {
    OCR2B = pgm_read_byte_near(&ak4716k_raw [i]);
    delayMicroseconds(63); // write the result of 1/(bitrate)
    }
  
  }
