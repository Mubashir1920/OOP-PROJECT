#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<limits>

using namespace std;

bool login(int);
void sellerDashboard();
bool checkID(int);
bool checkPassword(int,string);
void loginScreen(int &, string &);
void loggedIn(int, string);
bool search(string, string);

int main()
{
    int ID;
    string password;

    cout << "_______________________________________________" << endl;
    cout << "          Welcome to Car Dealership" << endl;
    cout << "_______________________________________________" << endl << endl;
    Sleep(900);

    loginScreen(ID,password);

    cout << endl;

    loggedIn(ID,password);


    return 0;
}

void loginScreen(int &id, string &password)
{
    password = "";
    int ch;

    while(true)
    {
        cout << "************************************************" << endl ;
        cout << "                Login Page" << endl;
        cout << "************************************************" << endl << endl;
        Sleep(900);

        cout << "ID: ";
        cin >> id;
    
        cout << "Password: ";
        ch = getch();

        while(ch != 13)
        {
            password.push_back(ch);
            cout << "*";
            ch = getch();
        }

        cout << endl;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID format";
            char c = 46;
            for(int i=0; i<5; i++)
            {
                cout << c;
                Sleep(500);
            }

            system("cls");
            continue;
        }
        else
        break;
    }
}

bool login(int id)
{
    if(id != 0000)
    return false;
    
    else
    return true;
}

void sellerDashboard()
{
    // showCars();
    cout << "showCars()" << endl;
}

bool checkID(int id)
{
    fstream infile;
    vector<string> row;
    // int id2;
    string line,word;

    infile.open("credentials.csv", ios::in);

    if(!infile.is_open())
    cout << "An error has occured" << endl;

    while(getline(infile, line))
    {
        if(search(line,to_string(id)))
        {
            infile.close();
            return true;
        }
    }

    infile.close();
    return false;
}

bool checkPassword(int id,string password)
{
    fstream infile;
    vector<string> row;
    int id2;
    string line,word, password2;

    infile.open("credentials.csv", ios::in);

    if(!infile.is_open())
    cout << "An error has occured" << endl;

    getline(infile,line);

    while(getline(infile,line))
    {
        row.clear();

        stringstream s(line);

        while(getline(s, word, ','))
        {
            row.push_back(word);
        }

        id2 = stoi(row[0]);

        if(id2 == id)
        {
            password2 = row[1];
            if(password == password2)
            {
                infile.close();
                return true;
            }
        }
    }

    infile.close();
    return false;
}

void loggedIn(int ID, string password)
{
    char loading = 222;
    if(!login(ID))
    {
        if(checkID(ID) && checkPassword(ID,password))
        {
            cout << endl;
            for(int i=0; i<20; i++)
            {
                cout << loading;
                Sleep(100);
            }
            system("cls");
            sellerDashboard();
        }
        else 
        {
            while(!checkID(ID) || !checkPassword(ID,password))
            {
                cout << "Invalid Password or ID" << endl;
                for(int i=0; i<20; i++)
                {
                    cout << loading;
                    Sleep(100);
                }
                system("cls");
                loginScreen(ID, password);
            }
            cout << endl;
            for(int i=0; i<20; i++)
            {
                cout << loading;
                Sleep(100);
            }
            system("cls");
            sellerDashboard();
    
        }
    }   
}

bool search(string line ,string word)
{
    return line.find(word) != string::npos;
}