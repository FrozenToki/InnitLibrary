#pragma once

#include <Arduino.h>
#include <vector>

struct SerialValueItem {
	String name;
	String value;
};

class SerialValuePool {
private:
	std::vector<SerialValueItem> pool;

public:
	void set(const String& name, const String& value);

	void set(const String& name, int value);
	void set(const String& name, float value);
	void set(const String& name, const char* value);
	void set(const String& name, bool value);

	const std::vector<SerialValueItem>& getValues() const;

	void clearPool();
};
