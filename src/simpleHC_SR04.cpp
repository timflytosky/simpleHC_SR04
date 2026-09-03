#include "simpleHC_SR04.h"

volatile unsigned long HC_SR04::highStart = 0; 
volatile unsigned long HC_SR04::highEnd = 0;
int HC_SR04::echoPin = 0;
bool HC_SR04::is_done = false;

HC_SR04::HC_SR04(int trigPin, int echoPin)
{
	this->trigPin = trigPin;
	HC_SR04::echoPin = echoPin;
}

bool HC_SR04::initAttach()
{
	pinMode(this->trigPin, OUTPUT);
    pinMode(HC_SR04::echoPin, INPUT);

	if (digitalPinToInterrupt(HC_SR04::echoPin) == -1) return false;
	attachInterrupt(HC_SR04::echoPin, getHigh, CHANGE);
	digitalWrite(this->trigPin, this->trigHL);
	return true;
}

bool HC_SR04::available()
{
	unsigned long cMicros = micros();
	if (this->trigHL)
	{
		if (cMicros - this->lastMicros >= 10)
		{
			this->lastMicros = cMicros;
			this->trigHL = false;
			digitalWrite(this->trigPin, this->trigHL);
		}
	}
	else if (cMicros - this->lastMicros >= 60000)
	{
		this->lastMicros = cMicros;
		this->trigHL = true;
		digitalWrite(this->trigPin, this->trigHL);
	}
	return HC_SR04::is_done;
}

void HC_SR04::getHigh()
{
	if (digitalRead(HC_SR04::echoPin))
		HC_SR04::highStart = micros();
	else {
		HC_SR04::highEnd = micros();
		HC_SR04::is_done = true;
	}
}

float HC_SR04::getD()
{
	HC_SR04::is_done = false;
	return (this->highEnd - this->highStart) / 58.0;
}
