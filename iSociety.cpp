#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>
using namespace std;

class Resident
{
    public:
    long int aadharno, phno;
    string email, name;
    int flat_number;
    string user_password;

    void residentLogin()
    {
        int choice;
        cout<<"============================================================== Resident LogIn ============================================================="<<endl;
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
        //display bills thru info frm admin

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
        cout<<"================================================================ Admin LogIn =============================================================="<<endl;
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
            cout<<"4. Exit"<<endl;
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
                case 4: cout<<"Thank you!";
            }   
        }
    }

    void dispResidents()
    {

    }

    void updateResidents()
    {

    }

    void addBills()
    {

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
            //can return a vector of potential apartments
        }

        void results()
        {
            //to display the search results
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