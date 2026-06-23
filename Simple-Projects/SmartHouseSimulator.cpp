/*
===========================================================
          SMART HOME AUTOMATION SIMULATOR IN C++
===========================================================

PROJECT DESCRIPTION
-------------------
This project simulates a simple Smart Home Automation System
where the user can control devices such as lights, fans,
air conditioners, TVs, and security cameras.

The system allows the user to:
1. View all devices
2. Turn devices ON
3. Turn devices OFF
4. View total power consumption
5. View devices that are currently ON
6. Save report to a file

This project demonstrates:
- Object-Oriented Programming (OOP)
- STL containers like vector and map
- Inheritance
- Polymorphism
- Encapsulation
- File Handling

===========================================================
OOP CONCEPTS USED
===========================================================

1. CLASS AND OBJECT
   - Device, Light, Fan, AC, TV, Camera are classes.

2. ENCAPSULATION
   - Device properties like name, status, room, and power
     are protected inside the class.

3. INHERITANCE
   - Light, Fan, AC, TV, Camera inherit from Device.

4. POLYMORPHISM
   - displayStatus() is a virtual function overridden
     in derived classes.

5. ABSTRACTION
   - Device acts as a base class for all devices.

===========================================================
STL USED
===========================================================

1. vector<Device*>
   - Stores all smart devices.

2. map<int, Device*>
   - Maps device ID to device object for easy access.

===========================================================
FEATURES
===========================================================

1. View all devices
2. Turn ON a device
3. Turn OFF a device
4. View total power consumption
5. View currently active devices
6. Save report to file
7. Exit

===========================================================
*/

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

// ======================= BASE CLASS =======================
class Device {
protected:
    int id;
    string name;
    string room;
    int powerUsage;
    bool status;

public:
    Device(int id, string name, string room, int powerUsage) {
        this->id = id;
        this->name = name;
        this->room = room;
        this->powerUsage = powerUsage;
        status = false; // Initially OFF
    }

    virtual ~Device() {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getRoom() const {
        return room;
    }

    int getPowerUsage() const {
        return powerUsage;
    }

    bool isOn() const {
        return status;
    }

    void turnOn() {
        if (!status) {
            status = true;
            cout << name << " in " << room << " is now ON.\n";
        } else {
            cout << name << " is already ON.\n";
        }
    }

    void turnOff() {
        if (status) {
            status = false;
            cout << name << " in " << room << " is now OFF.\n";
        } else {
            cout << name << " is already OFF.\n";
        }
    }

    virtual void displayStatus() const {
        cout << left << setw(5) << id
             << setw(20) << name
             << setw(18) << room
             << setw(12) << powerUsage
             << (status ? "ON" : "OFF") << endl;
    }
};

// ======================= DERIVED CLASSES =======================
class Light : public Device {
public:
    Light(int id, string room) : Device(id, "Light", room, 60) {}
};

class Fan : public Device {
public:
    Fan(int id, string room) : Device(id, "Fan", room, 80) {}
};

class AC : public Device {
public:
    AC(int id, string room) : Device(id, "Air Conditioner", room, 1500) {}
};

class TV : public Device {
public:
    TV(int id, string room) : Device(id, "Smart TV", room, 200) {}
};

class Camera : public Device {
public:
    Camera(int id, string room) : Device(id, "Security Camera", room, 100) {}
};

// ======================= SMART HOME CLASS =======================
class SmartHome {
private:
    vector<Device*> devices;      // STL vector
    map<int, Device*> deviceMap;  // STL map

public:
    ~SmartHome() {
        for (Device* d : devices) {
            delete d;
        }
    }

    void addDevice(Device* device) {
        devices.push_back(device);
        deviceMap[device->getId()] = device;
    }

    void showAllDevices() const {
        if (devices.empty()) {
            cout << "\nNo devices found.\n";
            return;
        }

        cout << "\n==================== DEVICE LIST ====================\n";
        cout << left << setw(5) << "ID"
             << setw(20) << "Device"
             << setw(18) << "Room"
             << setw(12) << "Power(W)"
             << "Status" << endl;
        cout << "-----------------------------------------------------\n";

        for (const Device* d : devices) {
            d->displayStatus();
        }
    }

    void turnOnDevice(int id) {
        if (deviceMap.find(id) != deviceMap.end()) {
            deviceMap[id]->turnOn();
        } else {
            cout << "Invalid device ID.\n";
        }
    }

    void turnOffDevice(int id) {
        if (deviceMap.find(id) != deviceMap.end()) {
            deviceMap[id]->turnOff();
        } else {
            cout << "Invalid device ID.\n";
        }
    }

    void showActiveDevices() const {
        bool found = false;

        cout << "\n=========== ACTIVE DEVICES ===========\n";
        for (const Device* d : devices) {
            if (d->isOn()) {
                d->displayStatus();
                found = true;
            }
        }

        if (!found) {
            cout << "No devices are currently ON.\n";
        }
    }

    void showTotalPowerConsumption() const {
        int total = 0;

        for (const Device* d : devices) {
            if (d->isOn()) {
                total += d->getPowerUsage();
            }
        }

        cout << "\nTotal Power Consumption of ON devices: "
             << total << " W\n";
    }

    void saveReportToFile() const {
        ofstream file("smart_home_report.txt");

        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        file << "SMART HOME AUTOMATION REPORT\n";
        file << "========================================\n";
        file << left << setw(5) << "ID"
             << setw(20) << "Device"
             << setw(18) << "Room"
             << setw(12) << "Power(W)"
             << "Status" << endl;
        file << "-----------------------------------------------------\n";

        int total = 0;
        for (const Device* d : devices) {
            file << left << setw(5) << d->getId()
                 << setw(20) << d->getName()
                 << setw(18) << d->getRoom()
                 << setw(12) << d->getPowerUsage()
                 << (d->isOn() ? "ON" : "OFF") << endl;

            if (d->isOn()) {
                total += d->getPowerUsage();
            }
        }

        file << "\nTotal Power Consumption (ON devices): "
             << total << " W\n";

        file.close();
        cout << "\nReport saved successfully in smart_home_report.txt\n";
    }
};

// ======================= MAIN FUNCTION =======================
int main() {
    SmartHome home;

    // Adding default devices
    home.addDevice(new Light(1, "Living Room"));
    home.addDevice(new Fan(2, "Bedroom"));
    home.addDevice(new AC(3, "Hall"));
    home.addDevice(new TV(4, "Guest Room"));
    home.addDevice(new Camera(5, "Entrance"));

    int choice, id;

    do {
        cout << "\n\n========== SMART HOME AUTOMATION MENU ==========\n";
        cout << "1. View All Devices\n";
        cout << "2. Turn ON a Device\n";
        cout << "3. Turn OFF a Device\n";
        cout << "4. View Active Devices\n";
        cout << "5. View Total Power Consumption\n";
        cout << "6. Save Report to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                home.showAllDevices();
                break;

            case 2:
                home.showAllDevices();
                cout << "\nEnter Device ID to turn ON: ";
                cin >> id;
                home.turnOnDevice(id);
                break;

            case 3:
                home.showAllDevices();
                cout << "\nEnter Device ID to turn OFF: ";
                cin >> id;
                home.turnOffDevice(id);
                break;

            case 4:
                home.showActiveDevices();
                break;

            case 5:
                home.showTotalPowerConsumption();
                break;

            case 6:
                home.saveReportToFile();
                break;

            case 7:
                cout << "\nExiting Smart Home Automation Simulator...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
