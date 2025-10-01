volatile unsigned int val = 0;

void setup() {
  cli();
  Serial.begin(9600);

  DDRD = DDRD | (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3);

  OCR1A = 62500;
  TCCR1A = 0;
  TCCR1B = 0;
  
  TCCR1B = TCCR1B | (1 << WGM12);
  TCCR1B = TCCR1B | (1 << CS12);
  TIMSK1 = TIMSK1| (1 << OCIE1A);

  sei();
}

void my_digit_write() {
  val++;
  int x = 2; 
  bool first = val%x==0;
  bool second = val%(x*2)==0;
  bool third = val%(x*3)==0;
  bool fourth = val%(x*4)==0;
  bool fifth = val%(x*5)==0;

  PORTD = PORTD ^ (first << 7);
  PORTD = PORTD ^ (second << 6);
  PORTD = PORTD ^ (third << 5);
  PORTD = PORTD ^ (fourth << 4);
  PORTD = PORTD ^ (fifth << 3);

  Serial.println(digitalRead(7));
}

ISR(TIMER1_COMPA_vect) {
  my_digit_write();
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(DDRB);
}
