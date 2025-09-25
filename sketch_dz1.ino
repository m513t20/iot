volatile bool firstState = false;
volatile bool secondState = false;
volatile uint32_t overflowCount = 0;
volatile uint32_t timer1_millis = 0;
bool switchBlink = false;

unsigned long prev_t = 0;
bool manualState = false;
unsigned long lastAnalogRead = 0;
const int analogPin = A0;
uint16_t delays[2] = {100, 150};

void setup() {
  cli();
  
  // 8-bit timer
  TCCR2A = 0;
  TCCR2B = 0;
  TCCR2B |= (1 << CS11);
  TIMSK2 |= (1 << TOIE2);
  
  // timer for myMillis
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B = TCCR1B | (1 << CS10);
  TIMSK1 = TIMSK1 | (1 << TOIE1);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  sei();
}

// overflow timer
ISR(TIMER2_OVF_vect){
  overflowCount++;
  if (overflowCount > 1000){
  	firstState=!firstState;
    overflowCount=0;
  }
}

//timer for millis
ISR(TIMER1_OVF_vect) {
  timer1_millis++; 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, firstState);
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case '1': switchBlink = false; break;
      case '2': switchBlink = true; break;
    }
  }
  if (switchBlink){
    millisBlink();
  }
  else{
    delayBlink();
  }
  readAnalogSensor();
}

//delay blink
void delayBlink(){
  digitalWrite(8, HIGH);  
  delay(1000);               
  digitalWrite(8, LOW);   
  delay(1000);   
}

// time counting blink
void millisBlink(){
  unsigned long t = myMillis();
  bool secondState = digitalRead(8);
  if(t-prev_t > delays[int(secondState)]){
    digitalWrite(8, !secondState);
    prev_t = t;
  }
}

long int myMillis(){
  unsigned long m;
  cli();
  m = timer1_millis;
  sei();
  return m;
}

//analog questioning
void readAnalogSensor() {
  unsigned long currentMillis = myMillis();
  if (currentMillis - lastAnalogRead >= 250) {
    lastAnalogRead = currentMillis;
    int sensorValue = analogRead(analogPin);
    Serial.print("Analog: ");
    Serial.println(sensorValue);
  }
}
