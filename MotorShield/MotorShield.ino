int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

//uncomment if using channel B, and remove above definitions
//int directionPinB = 13;
//int pwmPinB = 11;
//int brakePinB = 8;

//boolean to switch direction
bool directionState;

void setup() {
  
//define pins
pinMode(directionPinA, OUTPUT);
pinMode(pwmPinA, OUTPUT);
pinMode(brakePinA, OUTPUT);

//pinMode(directionPinB, OUTPUT);
//pinMode(pwmPinB, OUTPUT);
//pinMode(brakePinB, OUTPUT);
}

void loop() {

//change direction every loop()
directionState = !directionState;

//write a low state to the direction pin (13)
if(directionState == false){
  digitalWrite(directionPinA, LOW);
}

//write a high state to the direction pin (13)
else{
  digitalWrite(directionPinA, HIGH);
}

//release breaks
digitalWrite(brakePinA, LOW);

//set work duty for the motor
analogWrite(pwmPinA, 30);

delay(2000);

//activate breaks
digitalWrite(brakePinA, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);

delay(2000);
}
