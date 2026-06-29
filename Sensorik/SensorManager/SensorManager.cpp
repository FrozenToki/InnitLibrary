#include "SensorManager.h"
#include "app/ApplicationInnit.h"

SensorManager::SensorManager(ApplicationInnit* a) : app(a) {
    // Application code should create sensors explicitly.
}

// === BUTTON ===
Button *SensorManager::createButton(int p, String n) {
	Button* btn = new Button(p, n, app);
	app->getSensorList().addSensor(btn);

	return btn;
}

Button* SensorManager::getButtonByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	String sensorType;
	sensorType = sensor->getType();
	//if(sensor_type != SensorBase::BUTTON){
	//	__throw_invalid_argument( "Sensor is not a button, dude!" );
	//}
	return static_cast<Button*>(sensor);
}

// === BNO055 ===
Bno055* SensorManager::createBno055(int p, String n) {
	Bno055* bno = new Bno055(p, n, app);
	app->getSensorList().addSensor(bno);

	return bno;
}

Bno055* SensorManager::getBno055ByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	String sensorType;
	sensorType = sensor->getType();
	return static_cast<Bno055*>(sensor);
}

// === SR04 ===
Sr04* SensorManager::createSr04(int trig, int echo, String n)	{
	Sr04* sr04 = new Sr04(trig, echo, n, app);
	app->getSensorList().addSensor(sr04);

	return sr04;
}

Sr04 *SensorManager::getSr04ByName(String n)
{
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	return static_cast<Sr04*>(sensor);
}

// === IR_SENSOR ===

IrSensor* SensorManager::createIrSensor(int p, String n, float a) {
	IrSensor* i = new IrSensor(p, n, a, app);
	app->getSensorList().addSensor(i);

	return i;
}

IrSensor* SensorManager::getIrSensorByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
  	return static_cast<IrSensor*>(sensor);
}

IrSensor* SensorManager::getIrSensorByIndex(int i) {
	SensorBase* sensor = app->getSensorList().get(i);
	return static_cast<IrSensor*>(sensor);
}



// === IR_RING ===

SerialReciever* SensorManager::createSerialReciever(BoardSerialType* serialConnection,String n, uint8_t valueCount) {
	SerialReciever* serialReciever = new SerialReciever(serialConnection, n, valueCount, app);
	app->getSensorList().addSensor(serialReciever); 

	return serialReciever;
}

SerialReciever* SensorManager::getSerialRecieverByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	return static_cast<SerialReciever*>(sensor);

}

// === BUTTON_CROSS ===

ButtonCross* SensorManager::createButtonCross(String n, int pin, float v1, float v2, float v3, float v4, float v5) {
	ButtonCross* buttonCross = new ButtonCross(n, pin, v1, v2, v3, v4, v5, app);
	app->getSensorList().addSensor(buttonCross);

	return buttonCross;
}

ButtonCross *SensorManager::getButtonCrossByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	return static_cast<ButtonCross*>(sensor);
}

// === EZ ===

EZ* SensorManager::createEZ(int p, String n) {
	EZ* ez = new EZ(p, n, app);
	app->getSensorList().addSensor(ez);

	return ez;
}

EZ *SensorManager::getEZByName(String n) {
	SensorBase* sensor = app->getSensorList().getSensorByName(n);
	return static_cast<EZ*>(sensor);
}
