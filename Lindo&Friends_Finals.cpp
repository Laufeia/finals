#include<iostream>
#include<iomanip>

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
<<"Choose: ";

}

	
};

//Fix this maybe idk ask master coder AKA Admain Abdullah Omar
void addNew(){
	cout<<"Processor & Chipset: ";
	cin>>choice1;
	cout<<"";
	cin>>choice2;
	cout<<"";
	cin>>choice3;
	cout<<"";
	cin>>choice4;
	cout<<"";
	cin>>choice5;
	cout<<"";
	cin>>choice6;
	cout<<"";
	cin>>choice7;
}


//Make the bottom voids or functions an inheritance
//void rent(){
//	cout<<;
//}






int main(){
	int choice;//Lipat sa class kung kaya
	
	Placeholder P;

	
	P.mainMenu();
	cin>>choice;
	switch(choice){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			cout<<"\nThank you for using Lindo & Friends Laptop Rental.";
			return 0;
			break;
		default:
			cout<<"\nInvalid Choice.";
			break;
	} while (choice !=8);
	
	return 0;
}
