#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Laptop {
public:
int id;
string processor;
string memory;
string graphics;
string os;
string audio;
bool available;

Laptop(int id, string processor, string memory, string graphics, string os, string audio)
    : id(id), processor(processor), memory(memory), graphics(graphics), os(os), audio(audio), available(true) {}

Laptop() : id(0), available(true) {}
};

class Customer {
public:
int id;
string name;
string address;
vector<int> rentedLaptops;

Customer(int id, string name, string address) : id(id), name(name), address(address) {}

Customer() : id(0) {}
};

class LaptopRentalSystem {
private:
vector<Laptop> laptops;
map<int, Customer> customers;
int nextLaptopId = 1;
int nextCustomerId = 1;

void loadLaptops() {
    ifstream file("laptops.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            int id;
            string processor, memory, graphics, os, audio;
            bool available;
            file >> id >> processor >> memory >> graphics >> os >> audio >> available;
            if (file.fail()) break;
            laptops.emplace_back(id, processor, memory, graphics, os, audio);
            laptops.back().available = available;
            if (id >= nextLaptopId) nextLaptopId = id + 1;
        }
        file.close();
    }
}

void loadCustomers() {
    ifstream file("customers.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            int id;
            string name, address;
            file >> id >> name >> address;
            if (file.fail()) break;
            customers[id] = Customer(id, name, address);
            if (id >= nextCustomerId) nextCustomerId = id + 1;
        }
        file.close();
    }
}

void saveLaptops() {
    ofstream file("laptops.txt");
    for (const auto& laptop : laptops) {
        file << laptop.id << " " << laptop.processor << " " << laptop.memory << " " 
		<< laptop.graphics << " " << laptop.os << " " << laptop.audio << " " << laptop.available << endl;
    }
    file.close();
}

void saveCustomers() {
    ofstream file("customers.txt");
    for (const auto& [id, customer] : customers) {
        file << id << " " << customer.name << " " << customer.address << endl;
    }
    file.close();
}

public:
    LaptopRentalSystem() {
        loadLaptops();
        loadCustomers();
    }

    ~LaptopRentalSystem() {
        saveLaptops();
        saveCustomers();
    }

void addNewLaptop() {
    string processor, memory, graphics, os, audio;
    cout << "\t\tSpecifications\n";
    cout << "Processor: ";
    cin.ignore();
    getline(cin, processor);
    cout << "Memory: ";
    getline(cin, memory);
    cout << "Graphics: ";
    getline(cin, graphics);
    cout << "Operating System: ";
    getline(cin, os);
    cout << "Audio: ";
    getline(cin, audio);
    laptops.emplace_back(nextLaptopId++, processor, memory, graphics, os, audio);
    cout << "New laptop added successfully!\n\n";
}


void rentLaptop() {
    char choice;
    do {
        int customerId, laptopId;
        cout << "Customer ID: ";
        cin >> customerId;
        cout << "Laptop ID: ";
        cin >> laptopId;
        auto laptop = find_if(laptops.begin(), laptops.end(), [laptopId](Laptop& l) { return l.id == laptopId; });
        if (laptop != laptops.end() && laptop->available) {
            laptop->available = false;
            customers[customerId].rentedLaptops.push_back(laptopId);
            cout << "Laptop rented successfully!\n\n";
        } else {
            cout << "Laptop is not available.\n\n";
        }

        cout << "Rent another Laptop? [Y/N]: ";
        cin >> choice;
        cin.ignore();
        cout<< "\n";
    } while (choice == 'Y' || choice == 'y');
}


void returnLaptop() {
    int customerId, laptopId;
    cout << "Customer ID: ";
    cin >> customerId;
    cout << "Laptop ID: ";
    cin >> laptopId;
    auto laptop = find_if(laptops.begin(), laptops.end(), [laptopId](Laptop& l) { return l.id == laptopId; });
    if (laptop != laptops.end() && !laptop->available) {
        laptop->available = true;
        auto& rentedLaptops = customers[customerId].rentedLaptops;
        rentedLaptops.erase(remove(rentedLaptops.begin(), rentedLaptops.end(), laptopId), rentedLaptops.end());
        cout << "Laptop returned successfully!\n\n";
    } else {
        cout << "Laptop is not currently rented.\n\n";
    }
}

void showLaptopSpecs() {
    int laptopId;
    cout << "Laptop ID: ";
    cin >> laptopId;
    auto laptop = find_if(laptops.begin(), laptops.end(), [laptopId](Laptop& l) { return l.id == laptopId; });
    if (laptop != laptops.end()) {
        cout << "Processor: " << laptop->processor << "\n"
        << "Memory: " << laptop->memory << "\n"
        << "Graphics: " << laptop->graphics << "\n"
        << "Operating System: " << laptop->os << "\n"
        << "Audio: " << laptop->audio << "\n"
        << "Available: " << (laptop->available ? "Yes" : "No") << "\n\n";
    } else {
        cout << "Laptop not found.\n\n";
    }
}

void displayAllLaptops() {
    for (const auto& laptop : laptops) {
        cout << "ID: " << laptop.id << ", Processor: " << laptop.processor << ", Memory: " 
		<< laptop.memory << ", Graphics: " << laptop.graphics << ", OS: " << laptop.os 
		<< ", Audio: " << laptop.audio << ", Available: " << (laptop.available ? "Yes" : "No") << "\n\n";
    }
}

void checkLaptopAvailability() {
    int laptopId;
    cout << "Laptop ID: ";
    cin >> laptopId;
    auto laptop = find_if(laptops.begin(), laptops.end(), [laptopId](Laptop& l) { return l.id == laptopId; });
    if (laptop != laptops.end()) {
        cout << "Available: " << (laptop->available ? "Yes" : "No") << "\n\n";
    } else {
        cout << "Laptop not found.\n\n";
    }
}

void addNewCustomer() {
    string name, address;
    cout << "Name: ";
    cin.ignore(); // To clear the newline character left by previous cin
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    customers[nextCustomerId] = Customer(nextCustomerId, name, address);
    cout << "New customer added successfully! Customer ID: " << nextCustomerId++ << "\n\n";
}

void showCustomerDetails() {
    int customerId;
    cout << "Customer ID: ";
    cin >> customerId;
    if (customers.find(customerId) != customers.end()) {
        auto& customer = customers[customerId];
        cout << "Name: " << customer.name << "\n";
        cout << "Address: " << customer.address << "\n\n";
    } else {
        cout << "Customer not found.\n\n";
    }
}

void listLaptopsRentedByCustomer() {
    int customerId;
    cout << "Customer ID: ";
    cin >> customerId;
    if (customers.find(customerId) != customers.end()) {
        auto& customer = customers[customerId];
        for (int laptopId : customer.rentedLaptops) {
            cout << "Laptop ID: " << laptopId << "\n\n";
        }
    } else {
        cout << "Customer not found.\n\n";
    }
}

void maintenanceMenu() {
    int choice;
    cout << "[1] Add new Customer\n"
        << "[2] Show Customer Details\n"
        << "[3] List of Laptops Rented by a Customer\n"
        << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addNewCustomer();
                break;
            case 2:
                showCustomerDetails();
                break;
            case 3:
                listLaptopsRentedByCustomer();
                break;
            default:
                cout << "Invalid choice.\n\n";
                break;
        }
    }

void mainMenu() {
    int choice;
    bool running = true;
    while (running) {
        cout << "Welcome to Lindo & Friends Laptop Rental\n"
            << "[1] - Add New Laptop\n"
            << "[2] - Rent Laptop\n"
            << "[3] - Return a Laptop\n"
            << "[4] - Show Laptop Specs\n"
            << "[5] - Display all Laptops\n"
            << "[6] - Check Laptop Availability\n"
			<< "[7] - Laptop Maintenance\n"
			<< "[8] - Exit\n"
			<< "Choice: ";
			cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid. Choose only between 1 and 8.\n\n";
        continue;
    }

switch (choice) {
    case 1:
        addNewLaptop();
        break;
    case 2:
        rentLaptop();
        break;
    case 3:
        returnLaptop();
        break;
    case 4:
        showLaptopSpecs();
        break;
    case 5:
        displayAllLaptops();
        break;
    case 6:
        checkLaptopAvailability();
        break;
    case 7:
        maintenanceMenu();
        break;
    case 8:
        running = false;
        cout << "Exiting.\n";
        break;
    default:
        cout << "Invalid Choice. Try again.\n\n";
    }
}
}

};

int main() {
	LaptopRentalSystem system;
	system.mainMenu();
	return 0;
}
