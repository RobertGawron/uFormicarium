/*
 * DisplayDevice.h
 *
 *  Created on: 9 wrz 2018
 *      Author: robert
 */

#ifndef DISPLAYDEVICE_H_
#define DISPLAYDEVICE_H_

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class DisplayDevice {
public:
    typedef Adafruit_PCD8544 DeviceHandle_t;

	DisplayDevice();
	virtual ~DisplayDevice();
	void init();

	DeviceHandle_t& getDisplayHandle();
	void clean();

private:

	Adafruit_PCD8544 display;
	static const uint8_t contrastLevelDefault = 45U;
};

#endif /* DISPLAYDEVICE_H_ */