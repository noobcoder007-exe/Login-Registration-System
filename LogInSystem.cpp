#include<iostream>
#include<fstream>
#include<string>
using namespace std;


bool IsLoggedIn()
{
	string username, password, un, pw;
	
	cout << " Enter Username: " << endl;
	cin >> username;
	cout << " Enter password: " << endl;
	cin >> password;
	
	ifstream read( username + ".txt");
	getline(read, un);
	getline(read, pw);
	
	if(un == username && pw == password)
	{
		return true;
	}
	else{
		return false;
	}
	
}

int main()
{
	int ch;
	cout << " 1. Register\n2. Login\nYour choice: " << endl;
	cin >> ch;
	
	if(ch == 1){
		string username, password;
		
		cout << " Select a username: "; cin >> username;
		cout << " Select password: "; cin >> password;
		
		ofstream file;
		file.open("c\\" + username + ".txt");
		
		file << username << endl << password;
		file.close();
		
		main();
	} 
	else if(ch == 2){
		bool status = IsLoggedIn();
		
		if(status)
		{
			cout << " False Login! " << endl;
			system("PAUSE");
			return 0;
		}
	}
	else{
		cout << " Successfully Logged In! " << endl;
		system("PAUSE!");
		return 1;
	}
}