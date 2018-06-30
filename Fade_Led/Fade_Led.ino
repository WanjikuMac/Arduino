// This code shows how to fade a light

int potPin= A0;  //Declare potPin to be analog pin A0
int LEDPin= 11;  // Declare LEDPin to be arduino pin 11
int readValue;  // Use this variable to read Potentiometer
int writeValue; // Use this variable for writing to LED
 
void setup() {
  pinMode(potPin, INPUT);  //set potPin to be an input
  pinMode(LEDPin, OUTPUT); //set LEDPin to be an OUTPUT
  Serial.begin(9600);      // turn on Serial Port
}
 
void loop() {
  
 readValue = analogRead(potPin);  //Read the voltage on the Potentiometer
 writeValue = (255./1023.) * readValue; //Calculate Write Value for LED
 analogWrite(LEDPin, writeValue);      //Write to the LED
 Serial.print("You are writing a value of ");  //for debugging print your values
 Serial.println(writeValue);
}
