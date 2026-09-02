#ifndef HC_SR04_H
#define HC_SR04_H

#include <Arduino.h>

class HC_SR04
{
	unsigned long lastMicros = 0;
	static volatile unsigned long highStart, highEnd;
	static int echoPin;
	static bool is_done;
	int trigPin;
	bool trigHL = false;

	static void getHigh();
public:
	HC_SR04(int trigPin, int echoPin);
	void initAttach();
	float getD();
	bool available();
};

#endif // !HC_SR04_H
