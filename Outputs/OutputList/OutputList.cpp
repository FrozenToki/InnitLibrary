#include "OutputList.h"
#include "app/ApplicationInnit.h"

OutputList::OutputList(ApplicationInnit* a) : app(a), outputCount(0) {
    for (int i = 0; i < InnitConfig::MAX_OUTPUTS; i++) {
        outputList[i] = nullptr;
    }
}

void OutputList::addOutput(OutputBase* s) {
	for (int i = 0; i < outputCount; i++) {
		if (outputList[i]->getName() == s->getName()) {
			Serial.println("Outputname existiert schon!");
			return;
		}
	}

	if (outputCount < InnitConfig::MAX_OUTPUTS) {
		outputList[outputCount++] = s;
	}
}

OutputBase* OutputList::getOutputByName(const String& n) {
	for (int i = 0; i < outputCount; i++) {
		if (outputList[i]->getName() == n) {
			return outputList[i];
		}
	}
	return nullptr;
}

OutputBase* OutputList::get(int index) {
	if (index < 0 || index >= outputCount) {
		return nullptr;
	}
	return outputList[index];
}

int OutputList::getOutputCount() {
	return outputCount;
}
