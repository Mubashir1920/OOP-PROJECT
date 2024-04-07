CAR DEALERSHIP MANAGEMENT SYSTEM
TASKS FOR PROJECT

LOGIN SCREEN
CHECK FOR ADMIN AND USER (SEPARATE DASHBOARDS FOR SELLER AND ADMIN)

LOGGED IN AS ADMIN :

1- ADD A CAR
	1.1-  ADD SELLER ( CHECK IF SELLER ALREADY EXIST )
	1.2- FUNCTION FOR CAR INCREMENT
2- SHOW ALL CARS LISTINGS
	1- SEDAN
	2- HATCHBACK
	3- SUV
	4- ALL
	2-1- RETURN ALL CARS DATA FROM EXCEL FILE
3- SELL A CAR
3.1- ENTER BUYER DETAILS
4- CHECK CAPACITY OF SHOWROOM


LOGGED IN AS SELLER:

1- SHOW CARS

CLASSES AND FUNCTIONS:

1- CARS (ABSTRACT CLASS) / SELLER(variable -> id,name,city,phoneno) BUYER CLASSES(name,city,phoneno)
	1.1- CLASS VARIABLES (protected: string (id, make, model , company ,             enginecapacity,status, color , condition,numberplate)
1.2- SET AND GET FUNCTIONS - > void setter getter getMake   setMake
1.3- ( PURE VIRTUAL FUNCTION ) - >  setCarDetails()=0, showDetails()=0		
2- CLASSES INHERIT CARS SEDAN,SUV,HATCHBACK 
	2.1- const VARIABLE string ( cartype)
	2.2- PURE VIRTUAL FUNCTION DEFINITION   setCarDetails(){},showDetails(){}


FUNCTIONS PROTOTYPES

FUNCTION FOR LOGIN SCREEN AND MENU 
ADMIN LOGIN()
SELLERLOGIN()
LOGIN()-> VALIDATION FOR ADMIN / SELLER

ADMIN PAGE MENU FUNCTIONS
ADD A CAR()
SHOW ALL CARS LISTINGS()
SELL A CAR()
CHECK CAPACITY OF SHOWROOM()
GET SELLER DETAILS()
SELLER PAGE MENU FUNCTIONS
SHOW CARS()

FILE NAMES
	sellers.csv
	buyer.csv
	credentials.csv
	Cars.csv
FILES FORMAT
Cars.csv
Id,numberplate,cartype,model,make,company,color,condition,enginecapacity,status
Seller.csv
id,name,city,phoneno,cnic
Buyer.csv
Name,city,phoneno,cnic
Credentials.csv
id,password
Status.csv   -> id,number,status


New Function to add:
setcredentials(id); → Contain Variable Password and Output it in credentials.csv

Two Scenarios In Add A Car Function 
Seller Does’nt Exist → Set id Dynamically , Set Password through setCredentials() 
Seller Exist → Match CNIC and return id and assign it to car object variable id and output in cars.csv file




In Case of Any Help required you can email me at : mubashir417@outlook.com
