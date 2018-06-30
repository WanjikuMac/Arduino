//variable for the temperature sensor
const int SensorPin =A0;
//variable that holds the baseline temperature of the room float base
void setup() {
  //open a serial port to display values-specifies the speed
  Serial.begin(9600);
  //set the LED pins as outputs
  //the for() loop saves some extra coding
  for(int x=2; x<5;x++){
    pinMode (x,OUTPUT);
    digitalWrite(x, LOW);
  }

}

void loop() {
  // read the value on the Analog In pin and store it in a variable
  int sensorVal =analogRead(SensorPin);
  //send the 10-bit sensor value out the serial port
  Serial.print(sensorVal);
  Serial.print("ADC");
  //convert the ADC reading to voltage -raw value from analog to digital
  float voltage =(sensorVal/1024.0)*5.0;
  //send the voltage level out the serial port
  Serial.print(voltage);
  Serial.print("Volts");//string to specify the number was volts
  //convert the voltage to temperature in degrees c
  //the sensor reports 10mv per degree with 500mv offset
  //to degrees((voltage - 500mv) times 100)
  float temperature = (voltage - .5)*100;
  Serial.print(temperature);
  Serial.println("degrees C");//prints on a new line
  //Use the baseline temperature as a starting point, increment
  //the number lEDs that are on for every 2 degrees of increase
  // if the current temperature is lower than the baseline
  //turn off all LEDs
  float baselineTemp;
  if(temperature< baselineTemp){
    digitalWrite (2, LOW);
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    
  }
  else if (temperature >= baselineTemp+2 && temperature < baselineTemp+3){
     digitalWrite (2, HIGH);
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
  }
  else if (temperature >= baselineTemp+4 && temperature < baselineTemp+5){
     digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, LOW);
  }
  else if (temperature >= baselineTemp+6){
     digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
  }

  

}
