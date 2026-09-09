#ifndef HC_SR04_H
#define HC_SR04_H

#include <Arduino.h>

#if defined(__AVR_ATmega328P__)
	#define ATTACH_IRAMATTR
#elif defined(ESP32) || defined(ESP8266) || defined(ARDUINO_ARCH_ESP32)
	#define ATTACH_IRAMATTR IRAM_ATTR
#endif

class HC_SR04
{
	unsigned long lastMicros = 0;
	static volatile unsigned long highStart, highEnd;
	static int echoPin;
	static bool is_done;
	int trigPin;
	bool trigHL = false;

	static void ATTACH_IRAMATTR getHigh();
public:
	HC_SR04(int trigPin, int echoPin);
	bool initAttach();
	float getD();
	bool available();
};

#endif // !HC_SR04_H
