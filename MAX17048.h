// MAX17048/44 library for Arduino
//
// Luca Dentella (http://www.lucadentella.it)

#include "Arduino.h"

#ifndef _MAX17048_H
#define _MAX17048_H

#define MAX17048_ADDRESS	0x36

#define VCELL_REGISTER		0x02
#define SOC_REGISTER		0x04
#define MODE_REGISTER		0x06
#define VERSION_REGISTER	0x08
#define HIBRT_REGISTER		0x0A
#define CONFIG_REGISTER		0x0C
#define CRATE_REGISTER		0x16
#define COMMAND_REGISTER	0xFE


class MAX17048 {

	public:
	
		float getVCell();
		float getSoC();
		int getVersion();
		byte getCompensateValue();
		byte getAlertThreshold();
		void setAlertThreshold(byte threshold);
		boolean inAlert();
		void clearAlert();
		// HibThr UNIT: %/hr, ActThr UNIT: mV
		void getHibernateConfig(float &hibThrPercentPerHour, float &actThr_mV);
		// 53.04%/hr, 318.75mV (or bigger) = always hibernate (maximums)
		void setHibernateConfig(float hibThrPercentPerHour, float actThr_mV);;
		boolean inHibernate();
		// Approximate charge or discharge rate of the battery in %/h
		float getCrate();
		
		void reset();
		void quickStart();
	
	private:

		void readConfigRegister(byte &MSB, byte &LSB);
		void readRegister(byte startAddress, byte &MSB, byte &LSB);
		void writeRegister(byte address, byte MSB, byte LSB);
};

#endif
