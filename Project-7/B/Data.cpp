// Jimmy Liu
// Project 7
// December 4 2015 (Extension Requested)
// XCode 7.0

#include <iostream>
using namespace std;

// Person Data Class
class PersonData {
	private:
		string lastName;
		string firstName;
		string address;
		string city;
		string state;
		int zip;
		int phone;
	public:
		// Setter for lastname
		void setLastName(string temp) {
			lastName = temp;
		}
		// Getter for lastname
		string getLastName() {
			return lastName;
		}
		// Setter for firstname
		void setFirstName(string temp) {
			firstName = temp;
		}
		// Getter for firstname
		string getFirstName() {
			return firstName;
		}
		// Setter for address
		void setAddress(string temp) {
			address = temp;
		}
		// Getter for address
		string getAddress() {
			return address;
		}
		// Setter for city
		void setCity(string temp) {
			city = temp;
		}
		// Getter for city
		string getCity() {
			return city;
		}
		// Setter for state
		void setState(string temp) {
			state = temp;
		}
		// Getter for state
		string getState() {
			return state;
		}
		// Setter for zip
		void setZip(int temp) {
			zip = temp;
		}
		// Getter for zip
		int getZip() {
			return zip;
		}
		// Setter for phone
		void setPhone(int temp) {
			phone = temp;
		}
		// Getter for phone
		int getPhone() {
			return phone;
		}
};

// CustomerData class derived from PersonData class
class CustomerData: public PersonData {
	private:
		int customerNumber;
		bool mailingList;
	public:
		// Setter for customer number
		void setNumber(int temp) {
			customerNumber = temp;
		}
		// Getter for customer number
		int getNumber() {
			return customerNumber;
		}
		// Setter for mail bool
		void setMailing(bool temp) {
			mailingList = temp;
		}
		// Getter for mail bool
		bool getMailing() {
			return mailingList;
		}
};

// Main tester function of program
int main() {
	CustomerData temp;
	temp.setLastName("Liu");
	temp.setFirstName("Jimmy");
	temp.setAddress("123 Apple Drive");
	temp.setCity("Cupertino");
	temp.setState("California");
	temp.setZip(95014);
	temp.setPhone(2500629);
	temp.setNumber(126321);
	temp.setMailing(true);
	cout << temp.getLastName() << " " << temp.getFirstName() << " " << temp.getAddress() << " " << temp.getCity() << " " << temp.getState() << " " << temp.getZip() << " " << temp.getNumber() << " " << temp.getPhone() << " " << temp.getMailing() << endl;
	return 0;
}

/*
MacBook-Pro-3:B jimmyliu$ ./a.out
Liu Jimmy 123 Apple Drive Cupertino California 95014 126321 2500629 1
*/