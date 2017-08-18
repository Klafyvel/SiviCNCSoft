#include "melody.h"

void initMelody()
{
	pinMode(PIEZO_PIN, OUTPUT);
}

void startMelody()
{
	tone(PIEZO_PIN, NOTE_E6, 150);
	delay(150);
	tone(PIEZO_PIN, NOTE_E6, 150);
	delay(150);
	delay(150);
	tone(PIEZO_PIN, NOTE_E6, 150);
	delay(150);
	delay(150);
	tone(PIEZO_PIN, NOTE_C6, 150);
	delay(150);
	tone(PIEZO_PIN, NOTE_E6, 150);
	delay(150);
	delay(150);
	tone(PIEZO_PIN, NOTE_G6, 150);
	delay(150);
	delay(450);
	tone(PIEZO_PIN, NOTE_G5, 150);
	delay(150);
}

void validateMelody()
{
	tone(PIEZO_PIN, NOTE_C6, 50);
}

void successMelody()
{
	tone(PIEZO_PIN, NOTE_G3, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_C4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_E4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_G4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_C5, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_E5, 66);
	delay(66);

	tone(PIEZO_PIN, NOTE_G5, 200);
	delay(200);
	tone(PIEZO_PIN, NOTE_E5, 200);
	delay(200);

	tone(PIEZO_PIN, NOTE_FS3,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_C4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_DS4,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_GS4,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_C5, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_DS5,66);
	delay(66);

	tone(PIEZO_PIN, NOTE_GS5, 200);
	delay(200);
	tone(PIEZO_PIN, NOTE_DS5, 200);
	delay(200);

	tone(PIEZO_PIN, NOTE_AS3,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_D4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_F4, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_AS4,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_D5, 66);
	delay(66);
	tone(PIEZO_PIN, NOTE_F5, 66);
	delay(66);

	tone(PIEZO_PIN, NOTE_AS5, 200);
	delay(200);

	tone(PIEZO_PIN, NOTE_AS5,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_AS5,66);
	delay(66);
	tone(PIEZO_PIN, NOTE_AS5,66);
	delay(66);

	tone(PIEZO_PIN, NOTE_C6, 800);
	delay(800);


}