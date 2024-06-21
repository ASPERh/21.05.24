#include <iostream>
using namespace std;

class Lighting {
	bool mode;
	int lightLevel = 0;

public:
	void On() {
		cout << "Lighting on\n";
		lightLevel = 100;
		mode = true;
	}
	void Off() {
		cout << "Lighting off\n";
		lightLevel = 0;
		mode = false;
	}
	void Setting(int light) {
		if (light < 0 || light > 100)
			throw "0 to 100";
		else
			lightLevel = light;
	}
};

class ClimateControl {
	int temperature = 0;
	bool mode;

public:
	void On() {
		cout << "Климат контроль включен\n";
		temperature = 20;
		mode = true;
	}
	void Off() {
		cout << "Климат контроль выключен\n";
		temperature = 0;
		mode = false;
	}
	void Setting(int level) {
		if (level < 20 || level > 30)
			throw "0 до 30";
		else
			temperature = level;
	}
};

class SecuritySystem {
private:
	bool mode;

public:
	void On() {
		cout << "Защита включена\n";
		mode = true;
	}
	void Off() {
		cout << "Защита выключена\n";
		mode = false;
	}
	bool GetMode() {
		return mode;
	}
};

class Multimedia {
private:
	bool mode;
	int volume = 0;

public:
	void On() {
		cout << "Мультимедия включена\n";
		volume = 100;
		mode = true;
	}
	void Off() {
		cout << "Мультимедия выключена\n";
		volume = 0;
		mode = false;
	}
	void Setting(int level) {
		if (level < 0 || level > 100)
			throw "0 до 100";
		else
			volume = level;
	}
};

class SmartHome {
private:
	Lighting lighting;
	ClimateControl climate_control;
	SecuritySystem security_system;
	Multimedia multimedia;

public:
	void GoodMorning() {
		lighting.On();
		lighting.Setting(2);
		climate_control.On();
		climate_control.Setting(22);
		security_system.Off();
		multimedia.Off();
	}

	void GoodNight() {
		lighting.Off();
		climate_control.On();
		climate_control.Setting(20);
		security_system.On();
		multimedia.Off();
	}

	void LeaveHome() {
		lighting.Off();
		climate_control.Off();
		security_system.On();
		multimedia.Off();
	}

	void ComeHome() {
		lighting.On();
		lighting.Setting(100);
		climate_control.On();
		climate_control.Setting(22);
		security_system.Off();
		multimedia.On();
		multimedia.Setting(45);
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	SmartHome smarthome;
	smarthome.GoodMorning();
	cout << "\n=========================================================\n";
	smarthome.GoodNight();
	cout << "\n=========================================================\n";
	smarthome.LeaveHome();
	cout << "\n=========================================================\n";
	smarthome.ComeHome();
}