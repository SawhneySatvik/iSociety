#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
#include "mysql_connection.h"
#include<cppconn/driver.h>
#include<cppconn/exception.h>
#include<cppconn/prepared_statement.h>
using namespace std;

class Resident
{
    public:
    long int aadharno, phno;
    string email, name;
    string user_password;
    int price;

    void residentLogin()
    {
        int choice;
        cout<<"============================================================== RESIDENT LOGIN============================================================="<<endl;
        cout<<"1. Show Personal Details "<<endl;
        cout<<"2. Edit Personal Details "<<endl;
        cout<<"3. Bills "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: displayInfo();
                    break;
            case 2: acceptUserInfo(1);
                    break;
            case 3: bills();
                    break;
        }
    }

    void bills()
    {
        //display bill from data base
    }

    void acceptUserInfo(int n)
    {
        cout<<"\x1b[1mENTER YOUR DETAILS\x1b[0m"<<endl;
        cout<<"Name:";
        getline(cin, name);
        cout<<"\nEmail Address: ";
        getline(cin,email);
        cout<<"\nPhone Number: ";
        cin>>phno;
        cout<<"\nAadhar Number: ";
        cin>>aadharno;
        if(n==0)
        {
            cout<<"\n Create Password: ";
            getline(cin,user_password);
        }
        else if(n==1)
        {
            password:
            string pass;
            cout<<"Enter password to save changes.";
            cin>>pass;
            if(pass.compare(user_password)!=0)
            {
                cout<<"Wrong password.";
                goto password;
            }
            else
            {
                cout<<"Saved Successfully!";
            }
        }
    }

    void displayInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Phone Number: "<<phno<<endl;
        cout<<"E-Mail: "<<email<<endl;
        cout<<"Aadhar Number: "<<aadharno<<endl; 
    }

};

class Admin:Resident
{
    public:
    int admin_password;
    

    void adminLogin()
    {
        cout<<"================================================================ ADMIN LOGIN =============================================================="<<endl;
        password:
        cout<<" Enter Password: ";
        cin>>admin_password;
        if(admin_password !=0000)
        {
            cout<<"Wrong password.";
            goto password;
        }
        else
        {
            int n;
            cout<<""<<endl;
            cout<<"1. Display Resident List"<<endl;
            cout<<"2. Update residents "<<endl;
            cout<<"3. Add bills for the residents "<<endl;
            cout<<"4. Add Apartments "<<endl;
            cout<<"5. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>n;
            switch(n)
            {
                case 1: dispResidents();
                        break;
                case 2: updateResidents();
                        break;
                case 3: addBills();
                        break;
                case 4: addApartments();
                        break;
                case 5: cout<<"Thank you!";
            }   
        }
    }

    void dispResidents()
    {
        cout<<"================================================================ Residents ==============================================================";
        //display from db
    }

    void updateResidents()
    {
       string name;
       cout<<"================================================================ Update Residents =============================================================="<<endl;
       cout<<"Enter name of resident to be removed."<<endl;
       getline(cin, name);
       //remove person from database

    }

    void addBills()
    {
        string name;
        cout<<"Enter name of the resident."<<endl;
        getline(cin, name);
        cout<<"Enter the amount to be payed for the month."<<endl;
        cin>>price;
        //enter price in db
    }

    void addApartments()
    {
        int choice,apartment_type, apartment_price, apartment_pincode;
        string apartment_name,apartment_address;
        float apartment_price;

        cout<<"================================================================ Manage Apartments =============================================================="<<endl;
        cout<<"1. Add apartment "<<endl;
        cout<<"2. Delete apartment "<<endl;
        cout<<"3. Edit apartment "<<endl;
        cout<<"4. Back"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        cout<<"================================================"<<endl;
        cout<<"Add Apartment"<<endl;
        cout<<"================================================"<<endl;
        cout<<"Enter Apartment Name: ";
        getline(cin, apartment_name);

        cout<<"Enter Apartment Address: ";
        getline(cin, apartment_address);

        cout<<"Enter Pincode: ";
        cin>>apartment_pincode;

        cout<<"Enter Apartment Type (BHK): ";
        cin>>apartment_type;

        cout<<"Enter Apartment Price: ";
        cin>>apartment_price;

        cout<<"================================================"<<endl;
        //add to apartments db
        cout<<"Room Added Successfully"<<endl;
        cout<<"================================================"<<endl;
    }

};

class Society
{
    public:
    string type;
    int pincode, price_range;
        void welcome()
        {
            cout<<"============================================================================================================================================================================="<<endl;
            cout<<R"(
                                                                 _  _____            _      _
                                                                (_)/ ____|          (_)    | |        
                                                                 _| (___   ___   ___ _  ___| |_ _   _ 
                                                                | |\___ \ / _ \ / __| |/ _ \ __| | | |
                                                                | |____) | (_) | (__| |  __/ |_| |_| |
                                                                |_|_____/ \___/ \___|_|\___|\__|\__, |
                                                                                                 __/ |
                                                                                                 |___/ )"<<endl;

            cout<<"============================================================================================================================================================================="<<endl;
        }

        void searchQuery()
        {
            cout<<"Let's get started on finding you an apartment. Depending on your preferences we will search high and low and find the perfect home for you!"<<endl;
            cout<<"Type:";
            getline(cin, type);
            cout<<"Pincode of the area: ";
            cin>>pincode;
            cout<<"Price range (Upper Limit): ";
            cin>>price_range;
        }



        void search()
        {
            //search algo to mach apartment(from db)
        }
};

int main()
{
    int choice;
    Society s1;
    Resident r1;
    Admin a1;
    s1.welcome(); 
    cout<<"";
    cout<<"================================================================= MAIN MENU ==============================================================="<<endl;
    cout<<"1. Resident Login "<<endl;
    cout<<"2. New User SignUp "<<endl;
    cout<<"3. Admin Login "<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter your choice.";
    cin>>choice;
    switch(choice)
    {
        case 1: r1.residentLogin();
                break;
        case 2: r1.acceptUserInfo(0);
                break;
        case 3: a1.adminLogin();
                break;
        case 4: exit(0);
                break;
    }
    return 0;
};