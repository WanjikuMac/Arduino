
//array of notes
  //the frequencies corespond to the frequencies of middle 
  //c,d,e and f
int notes []={
  
  262,294,330, 349
};
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
//create a local variable to hold the input from A0
int sound = analogRead(A0);
//send the value from A0 to the serial monitor
Serial.println(sound);
//play the note corresponding each value
//tone needs to know what pin to play and the note
if (sound == 1023){
  tone(8, notes[0]); //plays middle c
}
else if (sound >=990 && sound <= 1010){
  tone (8, notes[1]);//plays middle d
}
else if (sound >=505 && sound <= 515){
  tone (8, notes[2]);//plays middle e
}
else if (sound >=5 && sound <= 10){
  tone (8, notes[3]);//plays middle f
}
else{
  noTone(8);
}
}
