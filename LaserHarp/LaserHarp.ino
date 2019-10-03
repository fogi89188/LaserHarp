//pin numbers and definitions
const int ledPIN = 13;
const int ldrPIN = A0;
int roomAmbientLight; //ambient light level so that the LDR synchronises with it's surroundings upon starting

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPIN, OUTPUT); //init the ledPIN as an output
  pinMode(ldrPIN, INPUT); //init the ldrPIN as an input
  roomAmbientLight = analogRead(ldrPIN);
}

void loop() {
  // put your main code here, to run repeatedly:

  //check if the LDR status is lower than a light value
  
  //if it is, the LED is HIGH
  Serial.println(analogRead(ldrPIN));
  Serial.println(roomAmbientLight);
  
  //Check if a laser is being obstructed
  //if it is, it should play a sound (not yet implemented)
  //it should check the position of the motor to figure out which sound to play(not yet implemented)

  int ldrStatus = analogRead(ldrPIN); //read the status of the LDR value (checks if there is light on the LDR)
  
  if(ldrStatus >= roomAmbientLight + 5){
    digitalWrite(ledPIN, HIGH); //turn LED On/Off
    Serial.println("False. No lasers are being obstructed. Sound is off.");
  }
  else{
    digitalWrite(ledPIN, LOW); //turn LED On/Off
    Serial.println("True. A laser is obstructed. Sound is on.");
  }
}
