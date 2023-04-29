#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Society
{
    private:
        string name,address,city,state,type;
        int pincode, phno, price, price_range, user_pin;
        vector <string> type;

    public:
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

        void acceptUserInfo()
        {
            cout<<"\x1b[1mENTER YOUR DETAILS\x1b[0m"<<endl;
            cout<<"Name:";
            getline(cin, name);
            cout<<"\nAddress: ";
            getline(cin,address);
            cout<<"\nCity: ";
            getline(cin,city);
            cout<<"\nState: ";
            getline(cin,state);
            cout<<"\nPhone Number: ";
            cin>>phno;
            cout<<"\nPincode: ";
            cin>>pincode;
        }

        void searchQuery()
        {
            cout<<"Let's get started on finding you an apartment. Depending on your preferences we will search high and low and find the perfect home for you!"<<endl;
            cout<<"Type:";
            getline(cin, type);
            cout<<"Pincode of the area: ";
            cin>>user_pin;
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
    Society s1;
    s1.welcome(); 
    cout<<"";
    s1.acceptUserInfo();
    s1.searchQuery();
    // s1.search();
    // s1.results();
    return 0;
};