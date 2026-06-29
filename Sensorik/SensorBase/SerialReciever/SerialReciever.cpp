#include "SerialReciever.h"

SerialReciever::SerialReciever(HardwareSerialIMXRT* s,String n, uint8_t valueCount, ApplicationInnit* a) : SensorBase(0, n, a), serialType(s), valueCount(valueCount)  {
	values = new float[valueCount]();  
	
	serialType->begin(115200);
	
}
// https://forum.arduino.cc/t/serial-input-basics-updated/382007/3



//============

void SerialReciever::update() {
	this->recvWithStartEndMarkers();
	if (newData == true) {
		strcpy(tempChars, receivedChars);
			// this temporary copy is necessary to protect the original data
			//   because strtok() used in parseData() replaces the commas with \0
		this->parseData();
		//showParsedData();
		newData = false;
	}
}

//============
void SerialReciever::recvWithStartEndMarkers() {
	static bool recvInProgress = false;
	static byte ndx = 0;
	char rc;

	while (serialType->available() > 0) {
		rc = serialType->read();

		// IMMER neu starten bei <
		if (rc == '<') {
			recvInProgress = true;
			ndx = 0;
			continue;
		}

		if (recvInProgress) {
			if (rc == '>') {
				receivedChars[ndx] = '\0';
				recvInProgress = false;
				newData = true;
			}
			else {
				if (ndx < numChars - 1) {
					receivedChars[ndx++] = rc;
				}
				else {
					// Overflow → reset
					recvInProgress = false;
					ndx = 0;
				}
			}
		}
	}
}


//============

void SerialReciever::parseData() {
    char* ptr = tempChars;
    
    for (uint8_t i = 0; i < valueCount; i++) {
        char* next;
        values[i] = strtof(ptr, &next);
        
        if (ptr == next) break;  // kein gültiger Wert mehr
        
        ptr = next;
        if (*ptr == ',') ptr++;  // Komma überspringen
    }
}


//============

void SerialReciever::showParsedData() {
	Serial.print("angle ");
	Serial.println(angleFromRing);
	Serial.print("strength ");
	Serial.println(strengthFromRing);
}

float SerialReciever::rawData() {
	return 0.0f;
}

float SerialReciever::getValue(uint8_t i) {
	i++;
	if (i < valueCount) {
		return values[i];
	} 
	return 0.0f;
}


