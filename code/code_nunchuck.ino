#include <Servo.h>
#include <WiiChuck.h>
Accessory nunchuck;
Servo myServo_base;

int potval_base;
int angle_base;

Servo myServo1;

int potval1;
int angle1;

Servo myServo2;

Servo myServopince;

int state;
int compteur = 0;


void setup() {
  myServo_base.attach(3);
  myServo1.attach(5);
  myServo2.attach(6);
  myServopince.attach(9);
  myServopince.write(0);
  Serial.begin(9600);
  myServo2.write(179);
  

	nunchuck.begin();
	if (nunchuck.type == Unknown) {
		nunchuck.type = NUNCHUCK;
	}
  }

void loop() {
  nunchuck.readData(); 
  potval_base = nunchuck.getJoyX();
  angle_base = map(potval_base, 24, 220, 0, 269);
  myServo_base.write(angle_base);
  potval1 = nunchuck.getJoyY();
  angle1 = map(potval1, 0, 220, 15, 165);
  myServo1.write(angle1); 
  myServo2.write(angle1-3);
  state = nunchuck.getButtonZ();
  if(state == 1){
    state = nunchuck.getButtonZ();
    compteur += 1;
  }
  if(compteur%2 == 0){
    myServopince.write(0);
  }
  else{
    myServopince.write(95);
  }
  delay(85);
}
