#include "SerialComm.h"
#include "app/ApplicationInnit.h"

SerialComm::SerialComm(ApplicationInnit* a, Stream& ser, unsigned long RepeatingSendInterval, unsigned long OneTimeSendInterval)
    : app(a), serial(ser), repeatingSendInterval(RepeatingSendInterval), oneTimeSendInterval(OneTimeSendInterval) {
    
}



void SerialComm::sendRepeatingData() {
	unsigned long currentMillis = millis();
	if (currentMillis - lastSendTimeRepeating >= repeatingSendInterval) {
		lastSendTimeRepeating = currentMillis;
		sendString = "," + String(sendingProgress) + ","; 
		sendOtherValues();
		sendValueAsChar(sendString, sendBuffer, sizeof(sendBuffer));
	}
}

void SerialComm::sendOneTimeData() {
	unsigned long currentMillis = millis();
	if (currentMillis - lastSendTimeOneTime >= oneTimeSendInterval) {
		lastSendTimeOneTime = currentMillis;
		sendString = "," + String(sendingProgress) + ","; 

		sendOtherValuesNames();
		sendValueAsChar(sendString, sendBuffer, sizeof(sendBuffer));
	}
}


void SerialComm::sendOtherValues() {
	const auto& items = app->getSerialValuePool().getValues();
	sendString = "," + String(sendingProgress) + ",";

	for (const auto& item : items) {
		sendString += item.value + ",";
	}

}



void SerialComm::sendOtherValuesNames() {
	const auto& items = app->getSerialValuePool().getValues();

	for (const auto& item : items) {
		sendString += item.name + ",";
	}
}



void SerialComm::sendValueAsChar(String text, char* charrr,size_t bufferSize,bool newLine ) {
	snprintf(charrr, bufferSize,"%s", text.c_str());
	if (newLine) {
		Serial.println(charrr);
	} else {
		Serial.print(charrr);
	}
}

void SerialComm::enableSerialComm() {
	serialCommSending = true;
}

void SerialComm::disableSerialComm() {
	serialCommSending = false;
}

void SerialComm::sendingLoop() {
	if (serialCommSending) {
		if (sendingProgress == 0) {
			sendOneTimeData();
		}
		else if (sendingProgress == 1) {
			sendRepeatingData();
		}
	}

	if (Serial.available() > 0) {
		char incomingChar = Serial.read();

		if (incomingChar == 'R' || incomingChar == 'r') {
			sendingProgress = 1;
		}
		else if (incomingChar == 'S' || incomingChar == 's') {
			sendingProgress = 0;
		}
		else if (incomingChar == 'X' || incomingChar == 'x') {
			Serial.end();
			delay(100);
			Serial.begin(9600);
		}
	}
}

void SerialComm::startSerialConnection(bool fastBaudRate, bool waitForConnection) {
	if(fastBaudRate) {
		Serial.begin(115200);
	} else {
		Serial.begin(9600);
	}
	if(waitForConnection){
		#if defined(USBCON) || defined(TEENSYDUINO)
		while (!Serial);
		#endif
	}
	delay(2000);
	Serial.println("Connection established");

}