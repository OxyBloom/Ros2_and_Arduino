//for queries, email "esugamopah@gmail.com"
//Hey this is the arduino code!
//A demo on how to work with ros2 and arduino using serial communication
//It's not really optimized since it is a demo
//make sure the pin values are correct for you else you can replace these with the correct values
//Ensure that the ros node is not running when you plug your arduino in.... you might have issues uploading the sketch
//if you have issues uploading the sketch, unplug the controller and ensure that no process is running

const int lm1=8,lm2=7,rm1=13,rm2=12,lms=10,rms=11;
bool continuousRun = false;
bool continuousRun1 = false;
bool continuousRun2 = false;
bool continuousRun3 = false;

void motorPinConfig(){
  pinMode(lm1,OUTPUT);pinMode(lm2,OUTPUT);pinMode(lms,OUTPUT);
  pinMode(rm1,OUTPUT);pinMode(rm2,OUTPUT);pinMode(rms,OUTPUT);
  
}
void forward(int ls,int rs){
  digitalWrite(lm1,LOW);digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);digitalWrite(rm2,LOW);
  analogWrite(lms,ls);analogWrite(rms,rs);
}
void back(int ls,int rs){
  digitalWrite(lm1,HIGH);digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);digitalWrite(rm2,HIGH);
  analogWrite(lms,ls);analogWrite(rms,rs);
}
void left(int speed){
  digitalWrite(lm1,HIGH);digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);digitalWrite(rm2,LOW);
  analogWrite(lms,speed);analogWrite(rms,speed);
}
void right(int speed){
  digitalWrite(lm1,LOW);digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);digitalWrite(rm2,HIGH);
  analogWrite(lms,speed);analogWrite(rms,speed);
}
void stop(){
  digitalWrite(lm1,HIGH);digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);digitalWrite(rm2,HIGH);
  analogWrite(lms,0);analogWrite(rms,0);
}
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  motorPinConfig();

}

void loop() {
  if (Serial.available()) {
    char chr = Serial.read();

    if (chr == 'f') {
      //forward();
      continuousRun = true;
      continuousRun1 = false;
      continuousRun2 = false;
      continuousRun3 = false;
    } else if (chr == 'b') {
      //back();
      continuousRun = false;  // Reset continuous run flag
      continuousRun1 = true;
      continuousRun2 = false;
      continuousRun3 = false;
    } else if (chr == 'l') {
      //left(50);
      //flag = 1;
      continuousRun1 = false;
      continuousRun = false;  // Reset continuous run flag
      continuousRun2 = true;
      continuousRun3 = false;
    } else if (chr == 'r') {
      //right(50);//flag = 1;
      continuousRun = false;
      continuousRun1 = false;// Set continuous run flag
      continuousRun2 = false;
      continuousRun3 = true;
    } else if (chr == 's') {
      stop();//flag = 1;
      continuousRun = false;
      continuousRun1 = false;// Set continuous run flag
      continuousRun2 = false;
      continuousRun3 = false;
    }
    
  }

  // Run continuously if continuousRun flag is set
  if (continuousRun) {
    forward(100,100);
  }

  if (continuousRun1){
    back(100, 100);
  }

  if (continuousRun2){
    left(100);
  }

  if (continuousRun3){
    right(100);
  }
}
