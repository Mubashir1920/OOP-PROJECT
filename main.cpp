#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <limits>

using namespace std;

void SellCar();
void adminLogin();
void AddCar();
bool login(int);
bool checkID(int);
bool checkPassword(int, string);
void loginScreen(int &, string &);
void loggedIn(int, string);
bool search(string, string);
void sellerDashboard();
void ShowCars(int);
void capacitycheck();

void loading()
{
    char loading = 219;
    for (int i = 0; i < 20; i++)
    {
        cout << loading;
        Sleep(100);
    }
    cout << endl;
}

class cars // abstract class
{
protected:
    string carType;
    string id, numberPlate, make, model, company, name, engine_capacity, color, condition, status;
    static int Capacity;
    int rId;

public:
    // abstract functions

    void virtual setCarDetails() = 0;
    void virtual showDetails() = 0;

    static void Showcapacity()
    {
        cout << " Currently We Have Capacity Of " << Capacity << " cars" << endl;
    }
    // all setters
    void setNumberPlate(string cNumberPlate)
    {
        numberPlate = cNumberPlate;
    }

    void setId(string cId)
    {
        id = cId;
    }
    void setMake(string cMake)
    {
        make = cMake;
    }

    void setModel(string cModel)
    {
        model = cModel;
    }

    void setCompany(string cCompany)
    {
        company = cCompany;
    }

    void setName(string cName)
    {
        name = cName;
    }

    void setEngineCapacity(string cEngineCapacity)
    {
        engine_capacity = cEngineCapacity;
    }

    void setColor(string cColor)
    {
        color = cColor;
    }

    void setCondition(string cCondition)
    {
        condition = cCondition;
    }

    // all getters

    string getId()
    {
        return id;
    }

    string getNumberPlate()
    {
        return numberPlate;
    }

    string getMake()
    {
        return make;
    }

    string getModel()
    {
        return model;
    }

    string getCompany()
    {
        return company;
    }

    string getName()
    {
        return name;
    }

    string getEngineCapacity()
    {
        return engine_capacity;
    }

    string getColor()
    {
        return color;
    }

    string getCondition()
    {
        return condition;
    }
};

int cars::Capacity = 100;

class sedan : public cars
{
protected:
    string cNumberPlate, cMake, cModel, cCompany, cName, cEngine_capacity, cColor, cCondition, city, number, cnic;
    string soldID, data;
    int getid;

public:
    sedan()
    {
        carType = "sedan";
        Capacity = Capacity - 1;
    }
    void setData(int i, string n, string m, string mod, string c, string cap, string col, string cond)
    {
        // id, type, num, make, model, company, capacity, color, condition;
        getid = i;
        cNumberPlate = n,
        cMake = m;
        cModel = mod;
        cCompany = c;
        cEngine_capacity = cap;
        cColor = col;
        cCondition = cond;
    }

    void setCarDetails() override
    {
        fstream f;
        f.open("sellers.csv");
        //        make, model, company, name, engine_capacity, color, condition;

        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, name, ',');
            getline(f, city, ',');
            getline(f, number, ',');
            getline(f, cnic, '\n');
        }
        f.close();

        cout << " the ID is :" << id << endl;

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Number Plate of car :";
        cin >> cNumberPlate;
        setNumberPlate(cNumberPlate);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the make Year of car :";
        cin >> cMake;
        setMake(cMake);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Model (Name) of car :";
        cin >> cModel;
        setModel(cModel);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the company of car :";
        cin >> cCompany;
        setCompany(cCompany);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the engine capacity of car :";
        cin >> cEngine_capacity;
        setEngineCapacity(cEngine_capacity);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the color of car :";
        cin >> cColor;
        setColor(cColor);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the condition of car :";
        cin >> cCondition;
        setCondition(cCondition);
        f.open("cars.csv", ios::app);

        f << id << ","
          << carType << ","
          << numberPlate << ","
          << make << ","
          << model << ","
          << company << ","
          << engine_capacity << ","
          << color << ","
          << condition << "\n";

        f.close();
    }
    void showDetails() override
    {
        cout << "CarType : " << carType << endl;
        cout << "The make of car: " << cMake << endl;
        cout << "The model of car: " << cModel << endl;
        cout << "The company of car: " << cCompany << endl;
        cout << "The name of car: " << cName << endl;
        cout << "The Engine Caacity of car: " << cEngine_capacity << endl;
        cout << "The Color of car: " << cColor << endl;
        cout << "The condition of car: " << cCondition << endl;
        cout << endl;
    }

    void carSold(string sID)
    {
        //       id,type,numberplate,make,model,company,engine,color,condition
        status = "sold";
        Capacity = Capacity + 1;
        fstream f;
        // cout << "Please Enter the NUmber Plate of sold car :";
        // cin >> soldID;
        soldID = sID;
        f.open("cars.csv");
        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, carType, ',');
            getline(f, numberPlate, ',');
            getline(f, make, ',');
            getline(f, model, ',');
            getline(f, company, ',');
            getline(f, engine_capacity, ',');
            getline(f, color, ',');
            getline(f, condition, '\n');
            if (numberPlate == soldID)
            {
                ofstream of;
                of.open("carStatus.csv", ios::app);
                of << numberPlate << ","
                   << company << ","
                   << status << "\n";
            }
        }

        f.close();
    }
};

class suv : public cars
{
protected:
    string cNumberPlate, cMake, cModel, cCompany, cName, cEngine_capacity, cColor, cCondition, city, number, cnic;
    string soldID, data;
    int getid;

public:
    suv()
    {
        carType = "suv";
        Capacity = Capacity - 1;
    }
    void setData(int i, string n, string m, string mod, string c, string cap, string col, string cond)
    {
        // id, type, num, make, model, company, capacity, color, condition;
        getid = i;
        cNumberPlate = n,
        cMake = m;
        cModel = mod;
        cCompany = c;
        cEngine_capacity = cap;
        cColor = col;
        cCondition = cond;
    }

    void setCarDetails() override
    {
        fstream f;
        f.open("sellers.csv");
        //        make, model, company, name, engine_capacity, color, condition;

        // bool RunOnce = false;

        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, name, ',');
            getline(f, city, ',');
            getline(f, number, ',');
            getline(f, cnic, '\n');
        }
        f.close();

        cout << " the ID is :" << id << endl;

        //        make, model, company, name, engine_capacity, color, condition;

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Number Plate of car :";
        cin >> cNumberPlate;
        setNumberPlate(cNumberPlate);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the make Year of car :";
        cin >> cMake;
        setMake(cMake);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Model (Name) of car :";
        cin >> cModel;
        setModel(cModel);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the company of car :";
        cin >> cCompany;
        setCompany(cCompany);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the engine capacity of car :";
        cin >> cEngine_capacity;
        setEngineCapacity(cEngine_capacity);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the color of car :";
        cin >> cColor;
        setColor(cColor);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the condition of car :";
        cin >> cCondition;
        setCondition(cCondition);
        f.open("cars.csv", ios::app);

        f << id << ","
          << carType << ","
          << numberPlate << ","
          << make << ","
          << model << ","
          << company << ","
          << engine_capacity << ","
          << color << ","
          << condition << "\n";

        f.close();
    }
    void showDetails() override
    {
        cout << "CarType : " << carType << endl;
        cout << "The make of car: " << cMake << endl;
        cout << "The model of car: " << cModel << endl;
        cout << "The company of car: " << cCompany << endl;
        cout << "The name of car: " << cName << endl;
        cout << "The Engine Caacity of car: " << cEngine_capacity << endl;
        cout << "The Color of car: " << cColor << endl;
        cout << "The condition of car: " << cCondition << endl;
        cout << endl;
    }

    void carSold(string sID)
    {
        //       id,type,numberplate,make,model,company,engine,color,condition
        status = "sold";
        Capacity = Capacity + 1;
        fstream f;
        // cout << "Please Enter the NUmber Plate of sold car :";
        // cin >> soldID;
        soldID = sID;
        f.open("cars.csv");
        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, carType, ',');
            getline(f, numberPlate, ',');
            getline(f, make, ',');
            getline(f, model, ',');
            getline(f, company, ',');
            getline(f, engine_capacity, ',');
            getline(f, color, ',');
            getline(f, condition, '\n');
            if (numberPlate == soldID)
            {
                ofstream of;
                of.open("carStatus.csv", ios::app);
                of << numberPlate << ","
                   << company << ","
                   << status << "\n";
            }
        }

        f.close();
    }
};

class hatchback : public cars
{
protected:
    string cId, cNumberPlate, cMake, cModel, cCompany, cName, cEngine_capacity, cColor, cCondition, city, number, cnic;
    string soldID, data;
    int getid;

public:
    hatchback()
    {
        carType = "hatchback";
        Capacity = Capacity - 1;
    }
    void setData(int i, string n, string m, string mod, string c, string cap, string col, string cond)
    {
        // id, type, num, make, model, company, capacity, color, condition;
        getid = i;
        cNumberPlate = n,
        cMake = m;
        cModel = mod;
        cCompany = c;
        cEngine_capacity = cap;
        cColor = col;
        cCondition = cond;
    }

    void setCarDetails() override
    {
        fstream f;
        f.open("sellers.csv");
        //        make, model, company, name, engine_capacity, color, condition;

        // bool RunOnce = false;

        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, name, ',');
            getline(f, city, ',');
            getline(f, number, ',');
            getline(f, cnic, '\n');
        }
        f.close();
        cout << " the ID is :" << id << endl;

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Number Plate of car :";
        cin >> cNumberPlate;
        setNumberPlate(cNumberPlate);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the make Year of car :";
        cin >> cMake;
        setMake(cMake);

        cout << "-----------------------------" << endl;
        cout << "Please Enter the Model (Name) of car :";
        cin >> cModel;
        setModel(cModel);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the company of car :";
        cin >> cCompany;
        setCompany(cCompany);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the engine capacity of car :";
        cin >> cEngine_capacity;
        setEngineCapacity(cEngine_capacity);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the color of car :";
        cin >> cColor;
        setColor(cColor);

        cout << "-----------------------------" << endl;
        ;
        cout << "Please Enter the condition of car :";
        cin >> cCondition;
        setCondition(cCondition);

        f.open("cars.csv", ios::app);
        f << id << ","
          << carType << ","
          << numberPlate << ","
          << make << ","
          << model << ","
          << company << ","
          << engine_capacity << ","
          << color << ","
          << condition << "\n";

        f.close();
    }
    void showDetails() override
    {
        cout << "CarType : " << carType << endl;
        cout << "The make of car: " << cMake << endl;
        cout << "The model of car: " << cModel << endl;
        cout << "The company of car: " << cCompany << endl;
        cout << "The name of car: " << cName << endl;
        cout << "The Engine Caacity of car: " << cEngine_capacity << endl;
        cout << "The Color of car: " << cColor << endl;
        cout << "The condition of car: " << cCondition << endl;
        cout << endl;
    }

    void carSold(string sID)
    {
        //       id,type,numberplate,make,model,company,engine,color,condition
        status = "sold";
        Capacity = Capacity + 1;
        fstream f;
        // cout << "Please Enter the NUmber Plate of sold car :";
        // cin >> soldID;
        soldID = sID;
        f.open("cars.csv");
        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, carType, ',');
            getline(f, numberPlate, ',');
            getline(f, make, ',');
            getline(f, model, ',');
            getline(f, company, ',');
            getline(f, engine_capacity, ',');
            getline(f, color, ',');
            getline(f, condition, '\n');
            if (numberPlate == soldID)
            {
                ofstream of;
                of.open("carStatus.csv", ios::app);
                of << numberPlate << ","
                   << company << ","
                   << status << "\n";
            }
        }

        f.close();
    }
};

class seller
{
protected:
    int getid;
    string id, name, city, number, cnic;
    string data;

    // id - name - city - number - cnic

public:
    // void checkSeller()
    // {
    //     cout << " CNIC :";
    //     cin >> data;

    //     ifstream f;
    //     f.open("sellers.csv");
    //     while (getline(f, id, ',') && getline(f, name, ',') && getline(f, city, ',') &&
    //            getline(f, number, ',') && getline(f, cnic, '\n'))
    //     {
    //         if (data == cnic)
    //         {
    //             cout << id << "," << name << "," << city << "," << number << "," << cnic;
    //         }
    //     }
    //     if (data != cnic)
    //     {
    //         setDetails();
    //     }
    //     f.close();
    // }
    void setcnic(string c)
    {
        cnic = c;
    }
    void setDetails(string cn)
    {
        fstream f;
        f.open("sellers.csv");
        bool RunOnce = false;
        while (f.peek() != EOF)
        {
            getline(f, id, ',');
            getline(f, name, ',');
            getline(f, city, ',');
            getline(f, number, ',');
            getline(f, cnic, '\n');
            getid = stoi(id);
            getid++;
            id = to_string(getid);
            RunOnce = true;
        }
        f.close();
        f.open("sellers.csv", ios::app);

        if (!RunOnce)
        {
            id = "101";
        }
        string pass;
        fstream cf("credentials.csv");
        cout << "Enter Password For the user:";
        cin >> pass;
        cf << id << ','
        << pass << '\n';
        cf.close();

        cout << "ID of this user is :" << id << endl;
        cout << "Password of this user is :" << pass << endl;
        cout << "--------------------" << endl;

        cout << "Please Enter Your Name :";
        cin >> name;

        cout << "-----------------------------" << endl;
        cout << "Please Enter the City :";
        cin >> city;

        cout << "-----------------------------" << endl;
        cout << "Please Enter Your Mobile Number :";
        cin >> number;

        cout << "-----------------------------" << endl;

        f << id << ","
          << name << ","
          << city << ","
          << number << ","
          << cn << "\n";
        f.close();
    }
};
void AddCar()
{
    string id, name, city, number, cnic;
    string cCNIC;
    int data;

    ifstream f;
    f.open("sellers.csv");

    cout << "Please Enter Your CNIC: ";
    cin >> cCNIC;

    bool foundSeller = false;

    // Search for the seller in the seller.csv file
    while (f.peek() != EOF)
    {
        getline(f, id, ',');
        getline(f, name, ',');
        getline(f, city, ',');
        getline(f, number, ',');
        getline(f, cnic, '\n');
        if (cCNIC == cnic)
        {
            cout << id << " | " << name <<  " | "  << city << " | " << number <<  " | "  << cnic << endl;
            foundSeller = true;
            break;
        }
    }

    f.close();

    // If seller not found, add new seller
    if (!foundSeller)
    {
        seller obj;
        obj.setDetails(cCNIC);
    }

    cout << "What type of Car do you want to Enter " << endl;
    cout << "(1. Sedan, 2. Hatchback, 3. SUV): ";
    cin >> data;

    switch (data)
    {
    case 1:
    {
        sedan obj;
        obj.setId(id);
        obj.setCarDetails();
        break;
    }
    case 2:
    {
        hatchback obj;
        obj.setId(id);
        obj.setCarDetails();
        break;
    }
    case 3:
    {
        suv obj;
        obj.setId(id);
        obj.setCarDetails();
        break;
    }
    default:
        cout << "Please Enter a correct number (1. Sedan, 2. Hatchback, 3. SUV)." << endl;
    }
    f.close();
    cout << "Car Added Successfully!" << endl;
    cout << "0- Exit" << endl;
    cout << "1- Back" << endl;
    cin >> data;
    switch (data)
    {
    case 0:
        break;
    case 1:
        cout << "Entering Dashboard .........";
        loading();
        adminLogin();
        break;
    default:
        break;
    }
}
void ShowAllListings()
{
    cout << "Opening File...." << endl;
    loading();

    fstream file("cars.csv");

    string data, line, cartype;
    int select, proceed;
    sedan obj;
    hatchback obj1;
    suv obj2;
    string id, type, num, make, model, company, capacity, color, condition;

    if (file.is_open())
    {
        cout << " -------CAR DEALERSHIP | ALL CARS AVALIBALE AT SHOW ROOM-------" << endl;
        cout << "0- All" << endl;
        cout << "1- Sedans" << endl;
        cout << "2- Hatchbacks" << endl;
        cout << "3- SUV,s" << endl;
        cout << "Select Option : ";
        cin >> select;
        while (select > 3 || select < 0)
        {
            cout << "Invalid Input! Please Enter Again.";
            Sleep(500);
            system("CLS");
            cout << "0- All" << endl;
            cout << "1- Sedans" << endl;
            cout << "2- Hatchbacks" << endl;
            cout << "3- SUV,s" << endl;
            cout << "Select Option : ";
            cin >> select;
        }

        switch (select)
        {
        case 0:
            cout << endl;
            cout << "Showing All Cars" << endl;
            cout << endl;
            while (file.peek() != EOF)
            {
                cout << endl;
                getline(file, data, ',');
                cout << "ID: " << data << endl;
                getline(file, data, ',');
                cout << "CarType: " << data << endl;
                getline(file, data, ',');
                cout << "Number of car: " << data << endl;
                getline(file, data, ',');
                cout << "The Make Year of car: " << data << endl;
                getline(file, data, ',');
                cout << "The model of car: " << data << endl;
                getline(file, data, ',');
                cout << "The company of car: " << data << endl;
                getline(file, data, ',');
                cout << "The Engine Caacity of car: " << data << endl;
                getline(file, data, ',');
                cout << "The Color of car: " << data << endl;
                getline(file, data, '\n');
                cout << "The condition of car: " << data << endl;
                cout << endl;
            }
            break;
        case 1:
            cartype = "sedan";
            cout << "Showing Sedan Cars" << endl;
            cout << endl;

            while (file.peek() != EOF)
            {
                getline(file, id, ',');
                getline(file, type, ',');
                getline(file, num, ',');
                getline(file, make, ',');
                getline(file, model, ',');
                getline(file, company, ',');
                getline(file, capacity, ',');
                getline(file, color, ',');
                getline(file, condition, '\n');

                int sid = stoi(id);
                if (type == cartype)
                {
                    obj.setData(sid, num, make, model, company, capacity, color, condition);
                    obj.showDetails();
                }
            }
            break;
        case 2:
            cartype = "hatchback";
            cout << "Showing HatchBack Cars" << endl;
            cout << endl;

            while (file.peek() != EOF)
            {
                getline(file, id, ',');
                getline(file, type, ',');
                getline(file, num, ',');
                getline(file, make, ',');
                getline(file, model, ',');
                getline(file, company, ',');
                getline(file, capacity, ',');
                getline(file, color, ',');
                getline(file, condition, '\n');
                int sid = stoi(id);
                if (type == cartype)
                {
                    obj1.setData(sid, num, make, model, company, capacity, color, condition);
                    obj1.showDetails();
                }
            }
            break;
        case 3:
            cartype = "suv";
            cout << "Showing SUV Cars" << endl;
            cout << endl;

            while (file.peek() != EOF)
            {
                getline(file, id, ',');
                getline(file, type, ',');
                getline(file, num, ',');
                getline(file, make, ',');
                getline(file, model, ',');
                getline(file, company, ',');
                getline(file, capacity, ',');
                getline(file, color, ',');
                getline(file, condition, '\n');
                int sid = stoi(id);
                if (type == cartype)
                {
                    obj2.setData(sid, num, make, model, company, capacity, color, condition);
                    obj2.showDetails();
                }
            }
            break;
        }
        file.close();
        cout << "0- Exit " << endl;
        cout << "1- Back " << endl;
        cout << "Enter Value : ";
        cin >> proceed;
        switch (proceed)
        {
        case 0:
            exit(0);
            break;
        case 1:
            adminLogin();
            break;
        default:

            break;
        }
    }
    else if (!file.is_open())
    {
        cout << "Error ! File Not Found" << endl;
    }
}

void loginScreen(int &id, string &password)
{
    password = "";
    int ch;

    while (true)
    {
        cout << "************************************************" << endl;
        cout << "                Login Page" << endl;
        cout << "************************************************" << endl
             << endl;
        Sleep(900);

        cout << "ID: ";
        cin >> id;

        cout << "Password: ";
        ch = getch();

        while (ch != 13)
        {
            password.push_back(ch);
            cout << "*";
            ch = getch();
        }

        cout << endl;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID format";
            char c = 46;
            for (int i = 0; i < 5; i++)
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
    if (id == 0000)
    {
        adminLogin();
    }

    else
        return false;
}

void sellerDashboard(int id)
{

    cout << "---------------------------------------" << endl;
    cout << "|        Welcome to Seller Dashboard  |" << endl;
    cout << "---------------------------------------" << endl
         << endl;

    cout << "Options:" << endl;
    cout << "1. Show Cars" << endl;

    int option;
    cout << "\nEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
        ShowCars(id);
        break;
    default:
        cout << "\nInvalid option. Please choose again." << endl;
    }
}

bool checkID(int id)
{
    fstream infile;
    vector<string> row;
    // int id2;
    string line, word;

    infile.open("credentials.csv", ios::in);

    if (!infile.is_open())
        cout << "An error has occured" << endl;

    while (getline(infile, line))
    {
        if (search(line, to_string(id)))
        {
            infile.close();
            return true;
        }
    }

    infile.close();
    return false;
}

bool checkPassword(int id, string password)
{
    fstream infile;
    vector<string> row;
    int id2;
    string line, word, password2;

    infile.open("credentials.csv", ios::in);

    if (!infile.is_open())
        cout << "An error has occured" << endl;

    getline(infile, line);

    while (getline(infile, line))
    {
        row.clear();

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        id2 = stoi(row[0]);

        if (id2 == id)
        {
            password2 = row[1];
            if (password == password2)
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
    if (!login(ID))
    {
        if (checkID(ID) && checkPassword(ID, password))
        {
            cout << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << loading;
                Sleep(100);
            }
            system("cls");
            sellerDashboard(ID);
        }
        else
        {
            while (!checkID(ID) || !checkPassword(ID, password))
            {
                cout << "Invalid Password or ID" << endl;
                for (int i = 0; i < 20; i++)
                {
                    cout << loading;
                    Sleep(100);
                }
                system("cls");
                loginScreen(ID, password);
            }
            cout << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << loading;
                Sleep(100);
            }
            system("cls");
            sellerDashboard(ID);
        }
    }
}

bool search(string line, string word)
{
    return line.find(word) != string::npos;
}

void adminLogin()
{
    int i;
    system("cls");
    system("Color 0B");
    cout << "********************************************************************" << endl;
    cout << "**    ***        ******      *       *      ******      *      *  **" << endl;
    cout << "**   *   *       *     *     **     **         *        **     *  **" << endl;
    cout << "**  *     *      *     *     * *   * *         *        * *    *  **" << endl;
    cout << "**  *******      *     *     *  * *  *         *        *  *   *  **" << endl;
    cout << "**  *     *      *     *     *   *   *         *        *   *  *  **" << endl;
    cout << "**  *     *      ******      *       *      ******      *    * *  **" << endl;
    cout << "********************************************************************" << endl;
    cout << endl
         << endl;
    cout << "Please select an option to continue..." << endl;
    cout << "1-Add a Car" << endl;
    cout << "2-Show all Cars" << endl;
    cout << "3-Sell a Car" << endl;
    cout << "4-Check Showroom Capacity" << endl;
    cout << "Select: ";
    cin >> i;
    while (i <= 0 || i >= 5)
    {
        cout << "You have entered a wrong option..." << endl;
        cout << "Please select an avaliable option(1-4) to continue" << endl;
        cin >> i;
    }
    switch (i)
    {
    case 1:
        AddCar();
        break;
    case 2:
        ShowAllListings();
        break;
    case 3:
        SellCar();
        break;
    case 4:
        capacitycheck();
        break;
    }
}

void SellCar()
{

    string id, type, numplate, make, model, company, engine, color, condition, numberplate;
    int data;
    cout << "Enter Number Plate of Car: ";
    cin >> numberplate;

    fstream file("cars.csv");
    while (file.peek() != EOF)
    {
        getline(file, id, ',');
        getline(file, type, ',');
        getline(file, numplate, ',');
        getline(file, make, ',');
        getline(file, model, ',');
        getline(file, company, ',');
        getline(file, engine, ',');
        getline(file, color, ',');
        getline(file, condition, '\n');
        if (numplate == numberplate)
        {
            sedan obj;
            obj.carSold(numplate);
        }
        else if (numplate == numberplate)
        {
            hatchback obj;
            obj.carSold(numplate);
        }
        else if (numplate == numberplate)
        {
            suv obj;
            obj.carSold(numplate);
        }
    }
    file.close();
    loading();
    cout << "Status Updated to Sold Succeffully!" << endl;
    cout << "0- Exit " << endl;
    cout << "1- Back " << endl;
    cout << "Enter Value : ";
    cin >> data;
    switch (data)
    {
    case 0:
        exit(0);
        break;
    case 1:
        adminLogin();
        break;
    default:

        break;
    }
}

void ShowCars(int ide)
{
    string Id;
    string id, type, make, model, company, engine, color, condition, numberplate;
    string numpl, comp, status;
    int data;
    Id = to_string(ide);
    fstream file("cars.csv");
    fstream fs("carStatus.csv");

    while (file.peek() != EOF)
    {
        getline(file, id, ',');
        getline(file, type, ',');
        getline(file, numberplate, ',');
        getline(file, make, ',');
        getline(file, model, ',');
        getline(file, company, ',');
        getline(file, engine, ',');
        getline(file, color, ',');
        getline(file, condition, '\n');
        if (id == Id)
        {
            cout << "Car ID : " << id << endl;
            cout << "Type  : " << type << endl;
            cout << "Number Plate : " << numberplate << endl;
            cout << "Make   : " << make << endl;
            cout << "Model  : " << model << endl;
            cout << "Company: " << company << endl;
            cout << "Engine : " << engine << ", Color : " << color << ", Condition : " << condition << endl;
            cout << endl;
        }
    }
    file.close();
    while (fs.peek() != EOF)
    {
        getline(fs, numpl, ',');
        getline(fs, comp, ',');
        getline(fs, status, '\n');

        if (numpl == numberplate)
        {
            cout << "Number Plate : " << numpl << endl;
            cout << "Company      : " << comp << endl;
            cout << "Status : " << status << endl;
            cout << endl;
        }
    }
    fs.close();

    cout << "0- Exit " << endl;
    cout << "1- Back " << endl;
    cout << "Enter Value : ";
    cin >> data;
    switch (data)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("cls");
        sellerDashboard(ide);
        break;
    default:

        break;
    }
}

void capacitycheck()
{
    string data;
    int Total = 100;
    int count = 0;
    int countSell = 0;

    fstream file("cars.csv");
    while (getline(file, data)) // Read until end of file
    {
        count++;
    }
    file.close();

    fstream fs("carStatus.csv");
    while (getline(fs, data)) // Read until end of file
    {
        countSell++;
    }
    fs.close();
    cout << count << endl;
    cout << countSell << endl;

    int capacity = count - countSell;
    cout << capacity << endl;

    cout << "Show Room has Capacity of " << Total - capacity << " Cars Right Now" << endl;
}

void Start()
{
    system("cls");
    system("Color 0B");
    int ID;
    string password;
    cout << "_______________________________________________" << endl;
    cout << "          Welcome to Car Dealership" << endl;
    cout << "_______________________________________________" << endl;
    Sleep(900);

    loginScreen(ID, password);

    cout << endl;

    loggedIn(ID, password);
}

int main()
{
    Start();
}
