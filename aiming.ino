#include <Servo.h>

Servo X_servo;
Servo Y_servo;

const int button = 7;
const int laser = 13;

int button_press = 0;
int state;

void aiming(void);

void setup() {
  // put your setup code here, to run once:
   Serial.begin (9600);
   //Serial.setTimeout(10);
   X_servo.attach(9);
   X_servo.write(90);
   Y_servo.attach(10);
   Y_servo.write(90);
   pinMode(button, INPUT_PULLUP);
   pinMode(laser, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  button_press = digitalRead(button);
  
  if (button_press == LOW){
    digitalWrite(laser, !digitalRead(laser));
    state = digitalRead(laser);
    delay(150);
  }
   
   switch (state)
   {
    case 1:
    aiming();

    default:
    break;
   }
}
void aiming()
{

  int X_axis;
  int Y_axis;
  int raw_X_axis;
  int raw_Y_axis;

  raw_X_axis = analogRead(A0);  //red the input on A0 input then store in raw_X_axis variable
  //Serial.print("X_Axis input = ");  //print on serial the text in quotes
  //Serial.println(raw_X_axis); //print out the value being read by the X axis pot
  
  raw_Y_axis = analogRead(A1);
  //Serial.print("Y_Axis input = ");
  //Serial.println(raw_Y_axis); //print out the value being read by the Y axis pot

  X_axis = map(raw_X_axis, 0, 1023, 0, 180);  //this maps the input of the X axis pot to be used later and stores the value in variable X_axis
  Serial.print("X_Axis output = ");
  Serial.println(X_axis);
  Y_axis = map(raw_Y_axis, 0, 1023, 0, 180);  //this maps the input of the Y axis pot to be used later and stores the value in variable Y_axis
  Serial.print("Y_Axis output = ");
  Serial.println(Y_axis);
  
  X_servo.write(X_axis);  //this writes the mapped values of the X axis to the servo giving it it's angles 
  Y_servo.write(Y_axis);  //this writes the mapped values of the Y axis to the servo giving it it's angles 
  
  delay(20);
}
