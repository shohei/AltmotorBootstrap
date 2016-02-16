#define apwm OCR2B
#define bpwm OCR0B
#define cpwm OCR0A
#define dtime 10

int val;

int asd   = 2;
int ahigh = 3;//PWM OC2B
int bsd   = 4;
int bhigh = 5;//PWM OC0B
int csd   = 7;  
int chigh = 6;//PWM OC0A

int pwmval = 254;

void setup() {

  initPWM();

  for(int i=0;i<6;i++){
    pinMode(asd,OUTPUT);
    pinMode(ahigh,OUTPUT);
    pinMode(bsd,OUTPUT);
    pinMode(bhigh,OUTPUT);
    pinMode(csd,OUTPUT);
    pinMode(chigh,OUTPUT);
  }

}
void initPWM(){
  TCCR0A = 0b10100011;
  TCCR0B = 0b00000010;
  TCCR2A = 0b10100011;
  TCCR2B = 0b00000010;
}
void loop() {
  spin();
}
void spin(){
  setOne();
  setTwo();
  setThree();
  setFour();
  setFive();
  setSix();   
}
void setOne(){
  PORTD=(1<<PD2)|(1<<PD4);
  setAH();
  _delay_ms(dtime);
}
void setTwo(){
  PORTD=(1<<PD2)|(1<<PD7);
  setAH();
  _delay_ms(dtime);
}
void setThree(){
  PORTD=(1<<PD4)|(1<<PD7);
  setBH();
  _delay_ms(dtime);
}
void setFour(){
  PORTD=(1<<PD2)|(1<<PD4);
  setBH();
  _delay_ms(dtime);
}
void setFive(){
  PORTD=(1<<PD2)|(1<<PD7);
  setCH();
  _delay_ms(dtime);
}
void setSix(){
  PORTD=(1<<PD4)|(1<<PD7);
  setCH();
  _delay_ms(dtime);
}
void setAH(){
  apwm = pwmval;
  bpwm = 0;  
  cpwm = 0;
}
void setBH(){
  apwm = 0;
  bpwm = pwmval;
  cpwm = 0;
}
void setCH(){
  apwm = 0;
  bpwm = 0;
  cpwm = pwmval;
}


