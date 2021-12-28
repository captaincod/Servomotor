#include <Servo.h>

int east = A0;
int north = A1;
int west = A2;
int south = A3;

int servo_pin = 11;
Servo servo;

int servo_angle = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(servo_pin);
}

void loop() {
  int east_value = analogRead(east);
  int north_value = analogRead(north);
  int west_value = analogRead(west);
  int south_value = analogRead(south);
  
  int directions[] = {east_value, north_value, west_value, south_value};
  int directions_size = sizeof(directions) / sizeof(directions[0]);

  int max_value = 0;
  String earth_corner = "Not found";
  
  for (int i = 0; i < directions_size; i++){
    if (directions[i] > max_value){
      max_value = directions[i];
    }
  }


  if (max_value == east_value){
    servo_angle = 0;
    earth_corner = "East";
  }
  else if (max_value == north_value){
    servo_angle = 60;
    earth_corner = "North";
  }
  else if (max_value == west_value){
    servo_angle = 120;
    earth_corner = "West";
  }
  else if (max_value == south_value){
    servo_angle = 180;
    earth_corner = "South";
  }

  servo.write(servo_angle);
  
  Serial.println("Servo angle: " + String(servo_angle));
  Serial.println("Direction: " + earth_corner);
  Serial.println();

  delay(1500);
}
