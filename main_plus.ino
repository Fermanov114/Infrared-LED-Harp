#include "pitches.h"

#define DEBUG_MODE 0  //Switch to debug mode to print out values of variables during programming.
#define CHORD_MODE 0  //1: chord mode, 0: arpeggio mode

#define speakerPin 12 //Control the pin which drives the speaker.
#define note_time 500  //Control the duration time of each note.
#define duration_time 500  //Control the duration time between notes.

#define NOTE_RANGE 8  //Control the range of notes played in program.
const unsigned short note[NOTE_RANGE] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5}; //Control the specific notes played in program.
unsigned short note_num;  //Count the number of pins with LOW input.
unsigned short sensor_val[NOTE_RANGE];  //This array stores the signals from input pins.

//Variables which can decide the order of notes when CHORD_MODE is 0.
unsigned short last_note = 0; //Store last played note.
unsigned short next_last_note;  //Record the last one of current input notes.
unsigned short median_note; //Record the median one of current input notes.
unsigned short median_note_position;  //Position of median note in sensor_val[] array.

int i, j; //General counters.

void setup() {
  #if DEBUG_MODE
  Serial.begin(9600); 
  #endif

  //Setup input pins
  for(i = 2; i < 10; i++){
    pinMode(i, INPUT);
  }
}

void loop() {
  note_num = 0; //Reset note_num before each loop.
  j = 0;  //Reset counter.

  // Read signals from input pins.
  for(i = 0; i < 8; i++){
    sensor_val[i] = digitalRead(i + 2);
    
    //note_num counts how many strings are plucked / how manys notes are played at the same time.
    if(sensor_val[i] == LOW){
      note_num++;
    }
  }

  //Print the value of note_num for debugging.
  if(note_num != 0){
    #if DEBUG_MODE
    Serial.print("note_num: ");
    Serial.println("note_num: "note_num);
    #endif

    int melody[note_num];

    median_note_position = (note_num / 2);  //Record the median position in the melody.

    //Store notes into the "melody" array
    for(i = 0; i < 8; i++){
      if (sensor_val[i] == LOW){
        melody[j] = note[i];

        if(j == median_note_position){
          median_note = i;  //Record note at median position of the melody.
        }

        if(j == (note_num -1)){
          next_last_note = i; //Record last note of the melody.
        }
        
        j++;      
      }
    }

    #if DEBUG_MODE
    for(i = 0; i < note_num; i++){
      Serial.print(i);
      Serial.print("\t");
      Serial.println(melody[i]);
    }
    #endif
    
    //If there is only one note input, play it for preset seconds.
    if(note_num == 1){
      tone(speakerPin, melody[0], note_time);
      delay(duration_time);
      noTone(speakerPin);
    }

    #if CHORD_MODE
    for( i = 0; i < (note_time / (50 * note_num) + 1); i++){
      for(j = 0; j < note_num; j++){
        tone(speakerPin, melody[j], 50);
        delay(50);
        noTone(speakerPin);
      }
    }


    #else //In this mode, when there are various input, the notes will be played one by one.
   
    //If the median note of the melody is lower than last played note, reverse the order of notes, which may make the melody sound more smooth.
    if(median_note <= last_note){
      int temp = 0;

      for(i = 0; i < (note_num) / 2; i++){
        temp = melody[i];
        melody[i] = melody[note_num - 1 - i];
        melody[note_num - 1 - i] = temp;
      }
    }
      
    //Play the melody in the processed order and the last note will last longer than previous ones.
    for(i = 0; i < note_num; i++){
      if(i == (note_num - 1)){
      tone(speakerPin, melody[note_num - 1], note_time);
      delay(duration_time);
      noTone(speakerPin);
      }
      else if(i < (note_num - 1)){
        tone(speakerPin, melody[i], note_time / 2);
        delay(duration_time / 2);
        noTone(speakerPin);
      }
    }
  
    last_note = next_last_note; //Update last_note for next loop.
    #endif
  }
}