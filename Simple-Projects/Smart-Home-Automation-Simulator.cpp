/*
===========================================================
            SMART HOME AUTOMATION SIMULATOR
===========================================================

Project Description:
--------------------
The Smart Home Automation Simulator is a C++ console-based
application that simulates the operation of smart devices
within a home environment. The system allows users to control
multiple devices such as lights, fans, and air conditioners,
monitor their status, calculate power consumption, and
generate usage reports.

This project demonstrates the practical implementation of
Object-Oriented Programming (OOP) concepts including
abstraction, encapsulation, inheritance, and polymorphism.

-----------------------------------------------------------
OBJECTIVES
-----------------------------------------------------------
1. Simulate smart home device management.
2. Allow users to turn devices ON/OFF.
3. Display real-time device status.
4. Calculate total power consumption.
5. Generate and save power usage reports.
6. Demonstrate OOP concepts in C++.

-----------------------------------------------------------
FEATURES
-----------------------------------------------------------
- Turn devices ON and OFF
- View device status
- Calculate power consumption
- Save power consumption report
- Menu-driven interface
- Uses inheritance and polymorphism

-----------------------------------------------------------
OOP CONCEPTS IMPLEMENTED
-----------------------------------------------------------

1. CLASS AND OBJECT
   - Device, Light, Fan, and AC are classes.
   - Objects are created from these classes.

2. ENCAPSULATION
   - Device information such as status and power usage
     are protected within the class.

3. INHERITANCE
   - Light, Fan, and AC inherit from the Device class.

4. POLYMORPHISM
   - The displayStatus() function is overridden in
     derived classes.

5. ABSTRACTION
   - Device is an abstract class containing a pure
     virtual function.

6. CONSTRUCTORS
   - Constructors initialize device properties.

-----------------------------------------------------------
DEVICE DETAILS
-----------------------------------------------------------

Device               Power Consumption
---------------------------------------
Living Room Light    60 Watts
Ceiling Fan          80 Watts
Bedroom AC           1500 Watts

-----------------------------------------------------------
FILE HANDLING
-----------------------------------------------------------

Report File:
power_report.txt

The report contains:
- Device Name
- Device Status
- Total Power Consumption

-----------------------------------------------------------
MENU OPTIONS
-----------------------------------------------------------

1. Turn ON Light
2. Turn OFF Light
3. Turn ON Fan
4. Turn OFF Fan
5. Turn ON AC
6. Turn OFF AC
7. View Device Status
8. View Power Consumption
9. Save Report
10. Exit

-----------------------------------------------------------
EXPECTED OUTPUT
-----------------------------------------------------------

Living Room Light turned ON.
Bedroom AC turned ON.

Current Power Usage: 1560 Watts

Report saved successfully!

-----------------------------------------------------------
FUTURE ENHANCEMENTS
-----------------------------------------------------------

1. User Authentication System
2. Smart TV Integration
3. Security Camera Simulation
4. Motion Detection Sensors
5. Temperature Monitoring
6. Device Scheduling
7. Electricity Bill Calculation
8. Database Connectivity
9. Graphical User Interface (GUI)
10. IoT Integration

-----------------------------------------------------------
TECHNOLOGIES USED
-----------------------------------------------------------

Language      : C++
Concepts      : OOP, File Handling
Compiler      : GCC / MinGW / Visual Studio
Platform      : Windows/Linux

===========================================================
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Abstract Base Class
class Device {
protected:
    string name;
    bool status;
    int powerUsage;

public:
    Device(string n, int p) {
        name = n;
        powerUsage = p;
        status = false;
    }

    virtual void displayStatus() = 0;

    void turnOn() {
        status = true;
        cout << name << " turned ON.\n";
    }

    void turnOff() {
        status = false;
        cout << name << " turned OFF.\n";
    }

    bool isOn() {
        return status;
    }

    int getPowerUsage() {
        if(status)
            return powerUsage;
        return 0;
    }

    string getName() {
        return name;
    }
};

// Derived Classes

class Light : public Device {
public:
    Light(string n, int p) : Device(n, p) {}

    void displayStatus() override {
        cout << name << " : "
             << (status ? "ON" : "OFF")
             << endl;
    }
};

class Fan : public Device {
public:
    Fan(string n, int p) : Device(n, p) {}

    void displayStatus() override {
        cout << name << " : "
             << (status ? "ON" : "OFF")
             << endl;
    }
};

class AC : public Device {
public:
    AC(string n, int p) : Device(n, p) {}

    void displayStatus() override {
        cout << name << " : "
             << (status ? "ON" : "OFF")
             << endl;
    }
};

void saveReport(vector<Device*> devices) {

    ofstream file("power_report.txt");

    int totalPower = 0;

    file << "SMART HOME POWER REPORT\n";
    file << "========================\n";

    for(auto device : devices) {
        file << device->getName()
             << " : "
             << (device->isOn() ? "ON" : "OFF")
             << endl;

        totalPower += device->getPowerUsage();
    }

    file << "\nTotal Power Consumption: "
         << totalPower
         << " Watts\n";

    file.close();

    cout << "\nReport saved successfully!\n";
}

int main() {

    Light livingRoomLight("Living Room Light", 60);
    Fan ceilingFan("Ceiling Fan", 80);
    AC bedroomAC("Bedroom AC", 1500);

    vector<Device*> devices;

    devices.push_back(&livingRoomLight);
    devices.push_back(&ceilingFan);
    devices.push_back(&bedroomAC);

    int choice;

    do {

        cout << "\n==============================\n";
        cout << " SMART HOME AUTOMATION SYSTEM\n";
        cout << "==============================\n";

        cout << "1. Turn ON Light\n";
        cout << "2. Turn OFF Light\n";
        cout << "3. Turn ON Fan\n";
        cout << "4. Turn OFF Fan\n";
        cout << "5. Turn ON AC\n";
        cout << "6. Turn OFF AC\n";
        cout << "7. View Device Status\n";
        cout << "8. View Power Consumption\n";
        cout << "9. Save Report\n";
        cout << "10. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            livingRoomLight.turnOn();
            break;

        case 2:
            livingRoomLight.turnOff();
            break;

        case 3:
            ceilingFan.turnOn();
            break;

        case 4:
            ceilingFan.turnOff();
            break;

        case 5:
            bedroomAC.turnOn();
            break;

        case 6:
            bedroomAC.turnOff();
            break;

        case 7:
            cout << "\nDevice Status:\n";
            for(auto device : devices)
                device->displayStatus();
            break;

        case 8: {

            int total = 0;

            for(auto device : devices)
                total += device->getPowerUsage();

            cout << "\nCurrent Power Usage: "
                 << total
                 << " Watts\n";

            break;
        }

        case 9:
            saveReport(devices);
            break;

        case 10:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 10);

    return 0;
}
