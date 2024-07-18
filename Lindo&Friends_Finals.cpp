#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <deque>

using namespace std;

//Laptop ADT
class Laptop{
protected:

public:


// Customer ADT
class Customer {
public:
	int customerID;
	string name;
	string address;

	Customer(int id, string n, string a)
 	: customerID(id), name(n), address(a); {}

void display() const {
	cout << "Customer ID: " << customerID << "\nName: " << name << "\nAddress: " << address << endl; 
}
	static void addCustomer (VideoStore &store, int id, string name, string address);
	static void showCustomerDetails (VideoStore &store, int customerID);
	static void listAllCustomers (VideoStore &store);
	static void listVideosRentedByCustomer (VideoStore &store, int customerID);

 // CustomerRent ADT (inherits from Customer)
 class CustomerRent : public Customer {
 public:
	list<int> rentedLaptops;

	CustomerRent(int id, string n, string a) : Customer(id, n, a) {}

	void rentLaptop(int laptopID) {
	rentedLaptops.push_back(laptopID);
	}

	void returnLaptop(int laptopID) {
	rentedLaptops.remove(laptopID);
	}

	void displayRentedLaptops() const {
	cout << "Laptops rented by Customer ID " << customerID << ":\n"; 
	for (list<int>::const_iterator it = rentedLaptops.begin(); it != rentedLaptops.end(); ++it) {
		cout << "Video ID: " << *it << endl;
	}
	}

	void returnAllLaptops() {
		rentedLaptops.clear();
	}
};
	
	

void mainMenu(){
cout<<"Welcome to Lindo & Friends Laptop Rental\n"
<<"[1] - Add New Laptop\n"
<<"[2] - Rent Laptop\n"
<<"[3] - Return a Laptop\n"
<<"[4] - Show Laptop Specs\n"
<<"[5] - Display all Laptop\n"
<<"[6] - Check Laptop Availability\n"
<<"[7] - Laptop Maintenance\n"
<<"[8] - Exit\n"
<<"Choice: ";

}

	
};


void addNew(){
	int c;
	string s,m,g,os,a;
	
	cout<<"\t\tSpecifications \n"
	<<"Proccesor: ";
	cin>>s;
	cout<<"Memory: ";
	cin>>m;
	cout<<"Graphics: ";
	cin>>g;
	cout<<"Operating System: ";
	cin>>os;
	cout<<"Audio: ";
	cin>>a;
}


//Make the bottom voids or functions an inheritance
void rent(){
	int id;
	string n,a;
	cout<<"Customer ID: "<<id
	<<"Name: ";
	cin>>n;
	cout<<"Address: ";
	cin>>a;
}

//Change if needed and look at the pdf and word if what

void give(){
	cout<<"Return a Laptop";
}

void show(){
	cout<<"Show Laptop";
}

void display(){
	cout<<"Display Laptop";
}

void check(){
	cout<<"Availability of ";
}

void maintenance(){
	cout<<"Laptop need to";
}




int main(){
	int choice;//Lipat sa class kung kaya
	
	Laptop P;

	
	do{
	P.mainMenu();
	cin>>choice;

	//the code here is for no infinite loop especially when pressing letters or others.
		if (cin.fail()){
		cin.clear();
		cin.ignore(10000, '\n');
		cout<<"Invalid. Choose only what is shown.\n\n";
		continue;
	}
	
	switch(choice){
		case 1:
			addNew();
		case 2:
			rent();
		case 3:
			give();
		case 4:
			show();
		case 5:
			display();
		case 6:
			check();
		case 7:
			maintenance();
		case 8:
			cout<<"\n Exiting";
			return 0;
		default:
			cout<<"Invalid Choice. Try again\n\n";
	} 
} while (choice !=8);
	return 0;
}
