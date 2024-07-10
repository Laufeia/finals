#include<iostream>
#include<iomanip>

#include<string>

using namespace std;

class Placeholder{
protected:

public:
	
	

void mainMenu(){
cout<<"Lindo & Friends\n"
<<"[1] - New Computer/Laptop\n"
<<"[2] - Rent Computer/Laptop\n"
<<"[3] - Return a Computer/Laptop\n"
<<"[4] - Show Computer/Laptop Specs\n"
<<"[5] - Display all Computer/Laptop\n"
<<"[6] - Check Computer/Laptop Availability\n"
<<"[7] - Computer/Laptop Maintenance\n"
<<"[8] - Exit\n"
<<"Choose: ";

}

	
};








int main(){
	int choice;//Lipat sa class kung kaya
	
	Placeholder P;
	bool k;
	
	P.mainMenu();
	cin>>choice;
	while(k){
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
			cout<<"\nThank you for using Lindo & Friends Computer/Laptop Rental.";
			return 0;
			break;
	}
}
	
	return 0;
}
