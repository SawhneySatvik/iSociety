#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;

class BankAccount{
    long int AccNo;
    char Name[50];
    char Type;
    double MoneyDep;

    public:
    void CreateAccount(){
        system("cls");
        cout<<"Enter the account number: ";
        cin>>AccNo;
        cout<<"Enter the name of account holder: ";
        cin.ignore();
        cin.getline(Name,50);
        cout<<"Enter the type of account you wish to open (savings-s/pf-p): ";
        Type=toupper(Type);
        cin>>Type;
        cout<<"Enter the initial amunt to be deposited: ";
        cin>>MoneyDep;
        cout<<"Congratulations!! Your account is know opened."<<endl;
        cout<<"=============================================="<<endl;
    }

    void DisplayAccount(){
        cout<<"Bank account number: "<<AccNo<<endl;
        cout<<"Account holdder name: "<<Name<<endl;
        cout<<"Type of your account: "<<Type<<endl;
        cout<<"Amount available: "<<MoneyDep<<endl;
    }

    void WriteAccount(){
        BankAccount ac;
        ofstream outfile;
        outfile.open("account.dat",ios::binary|ios::app);
        ac.CreateAccount();
        outfile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
        outfile.close();
    }

    int ReturnAccountNumber() const{
        return AccNo;
    } 

    void DeleteAccount(int n){
        BankAccount ac;
        ifstream infile;
        ofstream outfile;
        infile.open("account.dat",ios::binary|ios::app);
        if(infile){
            cout<<"File couldn't open, press any key!"<<endl;
            return;
        }
        outfile.open("temp.dat",ios::binary);
        infile.seekg(0,ios::beg);
        while(infile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount))){
            if(ac.ReturnAccountNumber()!=n){
                outfile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
            }
        }
        infile.close();
        outfile.close();
        remove("BankAccount.dat");
        rename("temp.dat","BankAccount.dat");
        cout<<"Your account has been successfully deleted."<<endl;
    }

    void Display(int n){
        BankAccount ac;
        
    }
};

int main(){
    char ch;
    int n;
    int pass_a;
    int pass=1201;
    int num_m,num_a,num_n,num_e;
    BankAccount ob;

    cout<<"=============================================="<<endl;
    cout<<"============ Welcome to ABC Bank ============="<<endl;
    cout<<"=============================================="<<endl;
    cout<<" "<<endl;

    do{
        cout<<"================= Main Menu =================="<<endl;
        cout<<" "<<endl;
        cout<<"1. Admin"<<endl;
        cout<<"2. Existing Account Holder LogIn"<<endl;
        cout<<"3. New Account Holder LogIn"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>num_m;

        if(num_m==1){
            cout<<" "<<endl;
            cout<<"=============================================="<<endl;
            cout<<"================= Admin Panel ================"<<endl;
            cout<<"=============================================="<<endl;
            cout<<" "<<endl;
            cout<<"Enter Password: ";
            cin>>pass_a;
            
            if(pass_a==pass){
                cout<<"LogIn as an admin successful!"<<endl;
                cout<<" "<<endl;
                cout<<"1. All account holder list"<<endl;
                cout<<"2. Modify an account"<<endl;
                cout<<"3. Close an account"<<endl;
                cout<<"4. Exit"<<endl;
                cout<<"Enter your choice:"<<endl;
                cin>>num_a;

                if(num_a==1){
                    cout<<"All account holder's list:";
                }
                else if(num_a==2){
                    cout<<"Modify the account-"<<endl;
                }
                else if(num_a==3){
                    cout<<"Close an account-"<<endl;
                    ob.DeleteAccount(n);
                }
                else{
                    cout<<"Wrong Option!!"<<endl;
                }
            }
            else{
                cout<<"Wrong Password!!"<<endl;
                break;
            }
        }

        else if(num_m==2){
            do{
                cout<<" "<<endl;
                cout<<"=============================================="<<endl;
                cout<<"================= User Login ================="<<endl;
                cout<<"=============================================="<<endl;
                cout<<"1. Deposit Money"<<endl;
                cout<<"2. Withdraw Money"<<endl;
                cout<<"3. Balance Enquiry"<<endl;
                cout<<"4. Modify account"<<endl;
                cout<<"5. Close an account"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>num_e;

                switch (num_e){
                case 1:
                    cout<<"Deposit Money"<<endl;
                    break;
                case 2:
                    cout<<"Withdraw Money"<<endl;
                    break;
                case 3:
                    cout<<"Balance Enquiry"<<endl;
                    break;
                case 4:
                    cout<<"Modify Account"<<endl;
                    break;
                case 5:
                    cout<<"Close the account"<<endl;
                    ob.DeleteAccount(n);
                default:
                    break;
                }

            }while (num_e==1||num_e==2||num_e==3||num_e==4||num_e==5);
        }

        else if(num_m==3){
            do{
                cout<<"=============================================="<<endl;
                cout<<"=============== User Sign Up ================="<<endl;
                cout<<"=============================================="<<endl;
                cout<<"1. Open an account"<<endl;
                cout<<"2. Deposit Money"<<endl;
                cout<<"3. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>num_n;

                if(num_n==1){
                    cout<<"Create a new bank account"<<endl;
                    ob.WriteAccount();
                }
            } while (num_n==1||num_n==2);
        }

        else{
            cout<<" "<<endl;
            cout<<"Thank you for banking with us!!"<<endl;
        }
    }while(num_m==1||num_m==2||num_m==3);
    
}