#include "OutputManger.h"
#include "app/ApplicationInnit.h"


OutputManager::OutputManager(ApplicationInnit* a) : app(a) {
    // Application code should create outputs explicitly via createLed, createMotor and createSsd1306.
}

// === LED ===

Led* OutputManager::createLed(int p, String n) {
	Led* l = new Led(p, n); 
	app->getOutputList().addOutput(l);

	return l;
}

Led* OutputManager::getLedByName(String n) {
	OutputBase* output = app->getOutputList().getOutputByName(n);
	String outputType;
	outputType = output->getType();
	//if(sensor_type != SensorBase::BUTTON){
	//	__throw_invalid_argument( "Sensor is not a button, dude!" );
	//}
	return static_cast<Led*>(output);
}

// === MOTOR ===

Motor* OutputManager::createMotor(int pInA, int pInB, int pPwm, int pAmp, String n, bool turnDirection) {
	Motor* l = new Motor(pInA, pInB, pPwm,pAmp, n, turnDirection);
	app->getOutputList().addOutput(l);

	return l;
}

Motor* OutputManager::getMotorByName(String n) {
	OutputBase* output = app->getOutputList().getOutputByName(n);
	return static_cast<Motor*>(output);
}

// === SSD_1306 ===

Ssd1306* OutputManager::getSsd1306ByName(String n) {
	OutputBase* output = app->getOutputList().getOutputByName(n);
	return static_cast<Ssd1306*>(output);
}

Ssd1306* OutputManager::createSsd1306(String n) {
	Ssd1306* l = new Ssd1306(n);
	app->getOutputList().addOutput(l);

	return l;
}


