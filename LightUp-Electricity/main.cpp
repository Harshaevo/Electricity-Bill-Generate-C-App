#include <iostream>
#include <fstream>
#include <istream>
#include <stdlib.h>
#include<iomanip>
using namespace std;

//Prototype
char mainMenu();
void login();
void userRegister();
void loginMenu();
int main();
void addnewcus();
void viewcus();
void searchcus();
float calculateBill();
void printbill();


//Strucutre Declaration
struct customers {
  int cusId;
  string fName;
  string sName;
  string city;
  int mobile;
};


int main() {
  char userChoice = mainMenu();

  switch (userChoice) {
    case 'a': 
      login();
      break;
    
    case 'b' : 
      userRegister();
      break;

    case 'q' : 
      cout << "\033[2J\033[1;1H"; // Clear Screen
      cout << "\n\n\n\t\tThank you Choosing LightUp Electricity";
      cin.get();
      cout << "\n\nPress Any Key to Continue";
      cin.get();
      break;

    default:
      cout << "\n\nPlease Enter Valid a Letter";
      cin.get();
      cout << "\n\nPress Any Key to Continue";
      cin.get();
      cout << "\033[2J\033[1;1H"; // Clear Screen
      mainMenu();
  }
  
}

//Main Menu
char mainMenu() {
  cout << "\n\n##### Welcome to LightUp Electricity ####\n";
  cout << "------------------------------------------\n";
  cout << "*********** Admin login Panel ***********\n\n";

  char choice;

  cout << "\t\t(a) - Login\n";
  cout << "\t\t(b) - Register\n";
  cout << "\t\t(q) - Exit\n\n";

  cout << "Please Make a Choice : ";
  cin >> choice;

  return choice;
}


// Login Function
void login() {
  cout << "\033[2J\033[1;1H"; // Clear Screen
  cout << "\n\n\t######## Welcome to LightUp Electricity #######\n";
  cout << "\t-----------------------------------------------\n";
  cout << "\t\nWelcome Back.. Enter Your User Credentials To Log in\n\n";

  int validator;

  //Asking For User name and Password
  string userName, userPass, tempName, tempPass;
  cout << "\n\t\tEnter Your User Name - ";
  cin >> userName;
  cout << "\n\t\tEnter Your Password - ";
  cin >> userPass;

  // Checking if the user name is available in the database
  ifstream userDetails("adminDatabase.txt");

  while (userDetails>>tempName>>tempPass) {

    if (tempName == userName && tempPass == userPass) {
      validator = 1;
    }

  }
 
  userDetails.close();

  // Checking Whether User Name is Correct Or Not
  if (validator == 1) {
    cout << "\033[2J\033[1;1H"; // Clear Screen
    
    loginMenu();

  }else {
    cout << "\033[2J\033[1;1H"; // Clear Screen
    cout << "\n\nYou Have Entered Wrong Password. Please Re-enter Correct User Name & Password\n\n";
    cout << "Press Enter to Continue...\n\n";
    cin.get();
    cin.get();
    login();
  }

}


// User Register Function
void userRegister() {
  cout << "\033[2J\033[1;1H"; // Clear Screen
  cout << "\n\n\t######## Welcome to LightUp Electricity #######\n";
  cout << "\t-----------------------------------------------\n";
  cout << "\n\nPlease Enter Your User Credentials To Register\n\n";

  string regUser, regPass;
  cout << "\tEnter the User Name - ";
  cin >> regUser;
  cout << "\n\tEnter the Password - ";
  cin >> regPass;

  ofstream regMembers("adminDatabase.txt", ios::app);
  regMembers << regUser << " " << regPass<<endl;
  cout << "\033[2J\033[1;1H"; // Clear Screen

  cout << "\n\nYou are Successfully Registered\n\n";
  main();
}


// Menu For Regitered Users
void loginMenu() {
  cout << "\n\n\t######## LightUp Electricity #######\n";
  cout<<"\n\n\t\tHello  Welcome Back...!\n";
  cout << "-----------------------------------------\n";

  char choice;

  cout << "\n\t\t(a) - Add New Customers\n";
  cout << "\t\t(b) - View All Customers\n";
  cout << "\t\t(c) - Search Customers\n";
  cout << "\t\t(d) - Print Bill Infomations\n\n";
  cout << "\t\t(d) - Exit the Program\n\n";

  cout << "Please Make a Choice : ";
  cin >> choice;

  switch (choice) {
    case 'a':
      addnewcus();
      break;

    case 'b':
      viewcus();
      break;

    case 'c':
      searchcus();
      break;

    case 'd':
      printbill();
      break;

    case 'q':
      cout << "\033[2J\033[1;1H"; // Clear Screen
      cout << "\n\n\n\t\tThank you Choosing LightUp Electricity";
      cin.get();
      cout << "\n\nPress Any Key to Continue";
      cin.get();
      break;

    default:
      cout << "\n\nPlease Enter Valid a Letter";
      cin.get();
      cout << "\n\nPress Any Key to Continue";
      cin.get();
      cout << "\033[2J\033[1;1H"; // Clear Screen
      loginMenu();

  }
  
}


void addnewcus() {
  customers cus1;

  cout << "\033[2J\033[1;1H"; // Clear Screen
  cout << "\n\n\t######## LightUp Electricity #######\n";
  cout << "\n\n\n\t\t\tNew Customer Registration\n";
  cout << "\t\t--------------------------------------\n\n";

  cout<<"\t\tEnter Customer ID : ";
  cin>>cus1.cusId;
  cout<<"\t\tEnter First Name : ";
  cin>>cus1.fName;
  cout<<"\t\tEnter Second Name : ";
  cin>>cus1.sName;
  cout<<"\t\tEnter Customer City : ";
  cin>>cus1.city;
  cout<<"\t\tEnter Mobile No : ";
  cin>>cus1.mobile;

  //writing customerDatabase file
  ofstream addNewCustomer ("customerDatabase.txt", ios::app);
  addNewCustomer<<cus1.cusId <<" "<<cus1.fName<<" "<<cus1.sName<<" "<<cus1.city<<" "<<cus1.mobile<<endl;

  cout << "\n\n\n\t\t\tSuccessfully Added New Customer\n";
  cin.get();
  cout << "\n\nPress Any Key to Continue";
  cin.get();
  cout << "\033[2J\033[1;1H"; // Clear Screen

  loginMenu();
}

void viewcus() {
  cout << "\033[2J\033[1;1H"; // Clear Screen
  
  customers cus2;

  //open customerDatabase file for data read
  ifstream cusView ("customerDatabase.txt");

  if (cusView) {
    cusView>>cus2.cusId>>cus2.fName>>cus2.sName>>cus2.city>>cus2.mobile;

    cout << "\n\n\t######## LightUp Electricity #######\n";
    cout << "\n\n\n\t\t\t\t\tView All Customers\n";
    cout << "\t\t--------------------------------------\n\n";
    cout <<left<<setw(15)<<"Customer ID"<<setw(15)<<"First Name"<<setw(15)<<"Sur-Name"<<setw(15)<<"City"<<setw(20)<<"Mobile Number"<<endl;

    while(cusView) {
      cout <<left<<setw(15)<<cus2.cusId<<setw(15)<<cus2.fName<<setw(15)<<cus2.sName<<setw(15)<<cus2.city<<setw(20)<<cus2.mobile<<endl;

      cusView>>cus2.cusId>>cus2.fName>>cus2.sName>>cus2.city>>cus2.mobile;
    }

    cusView.close();

  }else {
    cout<<"Error Opening File";
  }

  cin.get();
  cout << "\n\nPress Any Key to Rerun Menu";
  cin.get();
  cout << "\033[2J\033[1;1H"; // Clear Screen

  loginMenu();

}


//Search Customers By User ID
void searchcus() {
  cout << "\033[2J\033[1;1H"; // Clear Screen

  int cus_Id;
  int found = 0;
  customers cus3;

  ifstream cusSearch ("customerDatabase.txt");

  cout << "\n\n\t######## LightUp Electricity #######\n";
  cout << "\n\n\n\t\t\t\t\tSearch Customers\n";
  cout << "\t\t--------------------------------------\n\n";
  
  cout << "Enter Customer User ID ";
  cin>>cus_Id;

  if(cusSearch) {
    cusSearch>>cus3.cusId>>cus3.fName>>cus3.sName>>cus3.city>>cus3.mobile;

    while(cusSearch) {

      if (cus3.cusId == cus_Id) {
        cout<<"Customer Found...\n\n";

        cout <<left<<setw(15)<<"Customer ID"<<setw(15)<<"First Name"<<setw(15)<<"Sur-Name"<<setw(15)<<"City"<<setw(20)<<"Mobile Number"<<endl;

        cout <<left<<setw(15)<<cus3.cusId<<setw(15)<<cus3.fName<<setw(15)<<cus3.sName<<setw(15)<<cus3.city<<setw(20)<<cus3.mobile<<endl;

        found = 1;

        break;
      }

      cusSearch>>cus3.cusId>>cus3.fName>>cus3.sName>>cus3.city>>cus3.mobile;

    }
    if (found == 1) {
      cin.get();
      cout << "\n\nPress Any Key to Rerun Menu";
      cin.get();
      cout << "\033[2J\033[1;1H"; // Clear Screen
      loginMenu();
    }else {
      cout<<"\n\tSorry... Invalid account number given. Try again..."<<endl;
      cin.get();
      cout << "\n\nPress Any Key to Rerun Menu";
      cin.get();
      cout << "\033[2J\033[1;1H"; // Clear Screen
    }
  
  }
    
}

float calculateBill() {
  float unitBurned;
  float amount;

  cout << "Enter Total Unit Burned : ";
  cin >> unitBurned;

  if (unitBurned <= 30) {
    amount = unitBurned * 8; //charges for first 30 units

  }else if(unitBurned <= 60) {
    amount = (30 * 8) + ((unitBurned - 30) * 10); //charges for Second 30 units

  }else if (unitBurned <= 90) {
    amount = ((30 * 8) + (30 * 10)) + ((unitBurned - 60) * 12); ////charges for next 30 units

  }else {
    amount = ((30 * 8) + (30 * 10) + (30 * 12)) + ((unitBurned - 90) * 15);
  }

  return amount;

}


void printbill() {
  cout << "\033[2J\033[1;1H"; // Clear Screen
  cout << "\n\n\t######## LightUp Electricity #######\n";
  cout << "\n\t\t\t\t\tSearch Customers\n";
  cout << "\t\t--------------------------------------\n\n";

  customers cus4;
  float bill;
  int cus_Id;

  cout << "Enter Customer User ID ";
  cin>>cus_Id;
  bill = calculateBill();

  ifstream billFile ("customerDatabase.txt");
  
  if(billFile){

    billFile>>cus4.cusId>>cus4.fName>>cus4.sName>>cus4.city>>cus4.mobile;

    while(billFile) {

      if (cus4.cusId == cus_Id){

        cout << "\n\t\t\t\t\tElectricity Bill\n";
        cout << "\t\t--------------------------------------\n\n";
        cout <<left <<setw(20)<<"Customer ID"<<setw(15)<<"Name"<<setw(15)<<"Total Bill"
        <<"City"<<endl;
        cout <<left <<setw(20)<<cus4.cusId<<setw(15)<<cus4.fName<<setw(15)<<bill
        <<cus4.city<<endl;

        break;
        
      }

      billFile>>cus4.cusId>>cus4.fName>>cus4.sName>>cus4.city>>cus4.mobile;

    } 

    }

  cin.get();
  cout << "\n\nPress Any Key to Rerun Menu";
  cin.get();
  cout << "\033[2J\033[1;1H"; // Clear Screen

  loginMenu();

  }






 

