#include <MIDI.h>
#define LDR A0
int startingLDRValue = 0;
int note = 70;
byte prevNote = 0;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup(){
  MIDI.begin(MIDI_CHANNEL_OFF);
  pinMode(LDR, INPUT);
  startingLDRValue = analogRead(LDR);
  prevNote = 0;
}

void loop(){
  if(analogRead(LDR) < startingLDRValue - 5){
    if(prevNote == 0){
      MIDI.sendNoteOn(note, 127, 1); 
      prevNote = 1;
    }
  }
  else{
    if(prevNote = 1){
      MIDI.sendNoteOff(note, 0, 1);
      prevNote = 0;
    }
  }
}
