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