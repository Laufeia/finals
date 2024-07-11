#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

class Placeholder{
protected:

public:
	
	

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

//Fix this maybe idk ask master coder AKA Admain Abdullah Omar
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
	
	Placeholder P;

	
	P.mainMenu();
	cin>>choice;
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
			cout<<"\nThank you for using Lindo & Friends Laptop Rental."
			<<"\nDeveloped By: Lead Programmer/Master Coder: Admain, Abdullah"
			<<"\nDeveloped By: Lindo, Lance"
			<<"\nDeveloped By: Alvarado, Rod"
			<<"\nDeveloped By: Passion, Precious";
			return 0;
			break;
		default:
			cout<<"\nInvalid Choice.";
			break;
	} while (choice !=8);
	
	return 0;
}
