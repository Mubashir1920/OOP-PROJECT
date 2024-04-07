#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void setCredentials(string id, string password)
{
    fstream file("credentials.csv", ios::out | ios::app);

    file << id << ","
    << password <<"\n";
}


int main (){
    string  id,pass;
    cout << "Enter  the user ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> pass;
    setCredentials(id,pass);
    return 0;
}

