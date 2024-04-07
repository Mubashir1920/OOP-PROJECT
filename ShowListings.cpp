// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <string>
// #include <fstream>
// #include <windows.h>
// using namespace std;

// class cars
// {
// public:
//     string carType;
//     string id,  numberPlate, make, model, company, name, engine_capacity_capacity, color, condition, condition;

//     void setData(string i, string n, string b, string m, string c, string cap, string s)
//     {
//         id = i;
//         name = n;
//         brand = b;
//         make = m;
//         colour = c;
//         capacity = cap;
//         condition = s;
        
//     }
//     void ShowDetails()
//     {
//         cout << endl;
//         cout << "Name: " << name << endl;
//         cout << "Brand: " << brand << endl;
//         cout << "Make: " << make << endl;
//         cout << "Color: " << colour << endl;
//         cout << "Capacity: " << capacity << endl;
//         cout << "condition: " << condition << endl;
//         cout << endl;
//     }
// };

// void loading()
// {
//     char loading = 219;
//     for (int i = 0; i < 20; i++)
//     {
//         cout << loading;
//         Sleep(100);
//     }
//     cout << endl;
// }

// void ShowAllListings()
// {
//     cout << "Opening File...." << endl;
//     loading();
//     fstream file("cars.csv");
//     int select,proceed;
//     string id, type, name, brand, make, color, capacity, condition;
//     if (file.is_open())
//     {
//         cout << " -------CAR DEALERSHIP | ALL CARS AVALIBALE AT SHOW ROOM-------" << endl;
//         cout << "0- All" << endl;
//         cout << "1- Sedans" << endl;
//         cout << "2- Hatchbacks" << endl;
//         cout << "3- SUV,s" << endl;
//         cout << "Select Option : ";
//         cin >> select;
//         while (select > 3 || select < 0)
//         {
//             cout << "Invalid Input! Please Enter Again.";
//             Sleep(500);
//             system("CLS");
//             cout << "0- All" << endl;
//             cout << "1- Sedans" << endl;
//             cout << "2- Hatchbacks" << endl;
//             cout << "3- SUV,s" << endl;
//             cout << "Select Option : ";
//             cin >> select;
//         }

//         switch (select)
//         {
//         case 0:
//             cout << "Showing All Cars" << endl;
//             while (file.peek() != EOF)
//             {
//                 cars car;
//                 getline(file, id, ',');
//                 getline(file, type, ',');
//                 getline(file, numberPlate,',');
//                 getline(file, make, ',');
//                 getline(file, model, ',');
//                 getline(file, company, ',');
//                 getline(file, engine_capacity, ',');
//                 getline(file, color, ',');
//                 getline(file, condition, '\n');
//                 car.ShowDetails();
//             }
//             break;
//         case 1:
//             cout << "Showing Sedan Cars" << endl;
//             while (file.peek() != EOF)
//             {
//                 cars car;
//                  getline(file, id, ',');
//                 getline(file, type, ',');
//                 getline(file, numberPlate,',');
//                 getline(file, make, ',');
//                 getline(file, model, ',');
//                 getline(file, company, ',');
//                 getline(file, engine_capacity, ',');
//                 getline(file, color, ',');
//                 getline(file, condition, '\n');
//                 if (type == "sedan")
//                 {
//                     car.ShowDetails();
//                 }
//             }
//             break;
//         case 2:
//             cout << "Showing Hatchbacks Cars" << endl;
//             while (file.peek() != EOF)
//             {
//                 cars car;
//                  getline(file, id, ',');
//                 getline(file, type, ',');
//                 getline(file, numberPlate,',');
//                 getline(file, make, ',');
//                 getline(file, model, ',');
//                 getline(file, company, ',');
//                 getline(file, engine_capacity, ',');
//                 getline(file, color, ',');
//                 getline(file, condition, '\n');
//                 if (type == "Hatchback")
//                 {
//                     car.ShowDetails();
//                 }
//             }
//             break;
//         case 3:
//             cout << "Showing SUV,s Cars" << endl;
//             while (file.peek() != EOF)
//             {
//                 cars car;
//                  getline(file, id, ',');
//                 getline(file, type, ',');
//                 getline(file, numberPlate,',');
//                 getline(file, make, ',');
//                 getline(file, model, ',');
//                 getline(file, company, ',');
//                 getline(file, engine_capacity, ',');
//                 getline(file, color, ',');
//                 getline(file, condition, '\n');
//                 if (type == "SUV")
//                 {
//                     car.ShowDetails();
//                 }
//             }
//             break;
//         }
//         cout << "0- Exit " << endl;
//         cout << "1- Back " << endl;
//         cout <<"Enter Value : " ;
//         cin >> proceed;
       
//         file.close();
//     }
//     else if (!file.is_open())
//     {
//         cout << "Error ! File Not Found" << endl;
//     }
// }

// int main()
// {

//     ShowAllListings();

//     return 0;
// }