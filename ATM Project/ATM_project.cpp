#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
class bank{
    private:
    string id,pass,name,fname,address,phone,pin; //
    double balance; //
public:
void menu();
void bank_management();
void atm_management();
void new_user();
void allready_user();
void deposit();
void withdraw();
void transfer();
void payment();
void user_balance();
void atm_withdraw();
void atm_deposit();
void search();
void edit();
void del();
}; 

void bank::menu()
{

    p:
    system("cls");
    int choice;
    char ch;
    string pin,pass,email;
    cout<<"\n\n\t\t\t  Bank Control panel";
    cout<<endl;
    cout<<endl;
    cout<<"\n 1. Bank Management";
    cout<<endl;
    cout<<" 2. Atm Management";
    cout<<endl;
    cout<<" 3. Exit";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter Your  Choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
    cout<<"\n\n\t\tLOG IN Account";
    cout<<"\n\n Email Address:" ;
    cin>>email;
    cout<<"\n\n Pin Code : ";
    for(int i=1; i<=5;i++)
    {
        ch=getch();
        pin+=ch;
        cout<<"*";
    }
    cout<<"\n\n Password : ";
    for(int i=1; i<=5;i++)
    {
        ch=getch();
        pass+=ch;
        cout<<"*";
    }
    if(email =="mahadi@gmail.com" && pin=="13366" && pass=="14366")
    {
        bank_management();
    }
    else{
        cout<<"wrong!";
    }
        break;

    case 2:
    atm_management();
    break;
    case 3:
    exit(0);
    default:
    cout<<"Wrong Choice please try again."<<endl;
      getch();
      goto p;
    }

    //getch();
   //goto p;

}
void bank::bank_management()
{
     p:
    system("cls");
    int choice;
    cout<<"\n\n \t \t \t \tBank Management System";
    cout<<endl;
    cout<<endl;
    cout<<"1. Create New User"<<endl;
    cout<<"2. Already User"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdraw"<<endl;
    cout<<"5. Balance Transfer"<<endl;
    cout<<"6. Payment"<<endl;
    cout<<"7.Search User Record"<<endl;
    cout<<"8. Edit User Record"<<endl;
    cout<<"9. Delete User Record"<<endl;
    cout<<"10. Show All Record"<<endl;
    cout<<"11.Payment of All Record"<<endl;
    cout<<"12. Go Back"<<endl;
    cout<<"Enter Your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
    new_user();
    break;
    case 2:
    allready_user();
    break;
    case 3:
    deposit();
    break;
    case 4:
    withdraw();
    break;
    case 5:
    transfer();
    break;
    case 6:
        payment();
        break; 
    break;
    case 7:
    break;
    case 8:
    edit();
    break;
    case 9:
    del();
    break;
    case 10:
    break;
    case 11:
    break;
    case 12:
    menu();

    default:
        cout<<"Wrong!"<<endl;
    }
    getch();
    goto p;


}
void bank::atm_management()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n \t \t \t \tATM Management System";
    cout<<endl;
    cout<<endl;
    cout<<"1. Login & Check Balence"<<endl;
    cout<<"2. Withdraw Amount"<<endl;
    cout<<"3. Account Details"<<endl;
    cout<<"4. Back To Main Menu"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        user_balance();
        break;
        case 2:
        atm_withdraw(); 
        break;
        case 3:
        atm_deposit();
        break;
        case 4:
        menu();
        default:
        cout<<"Wrong Choice"<<endl;
    }
    getch();
    goto p;
}
void bank :: new_user()
{
    p:
    system("cls");
    fstream file;
    float b;
    int p;
    string n,f,pa,a,ph,i;
    cout<<"Add New User";
    cout<<endl;
    cout<<endl;
    cout<<"User ID: ";
    cin>>id;
    cout<<endl;
    cout<<"User Name:";
    cin>>name;
    cout<<endl;
    cout<<"Father Name: ";
    cin>>fname;
    cout<<endl;
    cout<<"Address:";
    cin>>address;
    cout<<endl;
    cout<<"Pin Code (5 digit) :";
    cin>>pin;
    cout<<endl;
    cout<<"Password (5 digit):";
    cin>>pass;
    cout<<"Phone Number: ";
    cin>>phone;
    cout <<endl;
    cout<<"Current Balance: ";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        file.close();
    }
    else{
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        while (!file.eof())
        {
            
            if(i== id)
            {
                cout<<"User ID allready Exist..";
                getch();
                goto p;
            }
             file>>i>>n>>f>>a>>p>>pa>>ph>>b;

        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        file.close();

    }
    cout<<endl;
    cout<<"New user has been added successfull.";
    
}
void bank::allready_user()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"Already an User Account"<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<endl;
        cout<<"File opening error";

    }
    else
    {
       cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id)
        {
            system("cls");
            cout<<"\n Allready an User Account";
            cout<<endl;
            cout<<"\n \n User ID: "<<id<<endl;
            cout<<endl;
            cout<<"Pin Code"<<pin<<endl;
            cout<<"Password: "<<pass<<endl;
        }

        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";

    }


}
void bank::deposit(){
    system("cls");
    fstream file,file1;
    string t_id;
    float dep;
    //file1.open("bank.txt",ios::app|ios::out);
    int found=0 ;
    cout<<"Deposit Money";
    cout<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else
    {
       //cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       file1.open("bank.txt",ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id)
        {
            cout<<endl;
            cout<<"Enter Amount For Deposit:";
            cin>>dep;
            balance+=dep;
            //file>>dep;
            
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
             found++;
            cout<<"\nYour Amount BDT: "<<dep<<"deposited succesfully"<<endl;
        }
        else
        {
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        }
        
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";

    }
}

void bank::withdraw(){
    system("cls");
    fstream file,file1;
    string t_id;
    float with;
    //file1.open("bank.txt",ios::app|ios::out);
    int found= 0;
    cout<<"Withdraw";
    cout<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else
    {
       //cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       file1.open("bank.txt",ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id)
        {
            cout<<endl;
            cout<<"Enter Amount For Withdraw:";
            cin>>with;
            if(with<=balance)
            {
            balance-=with;
            
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
             found++;
            cout<<"\nYour Amount BDT: "<<with<<"Withdrawed succesfully"<<endl;
            }
            else
            {
                cout<<"You Don't have enough money to withdraw"<<endl;
            }
            found++; 
        }
        else
        {
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        }
        
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";

    }
}


void bank:: transfer()
{
    fstream file,file1;
    system("cls");
    string s_id,r_id;
    float amount;
    int found =0;
    cout <<"\n\n\t\t Payment Transfer:";
    file.open("bank.txt");
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else{
        cout<<"Sender User ID:";
        cin>>s_id;
        cout<<"Reciever User ID:";
        cin>>r_id;
        cout<<"Enter Transaction Amount:";
        cin>>amount;
       
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
           if(s_id==id && amount<=balance)
             found++;
             else if(r_id==id)
             found++;
             
           
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file1.close();
        if(found==2)
        {
            file1.open("bank.txt",ios::in);
             file1.open("bank1.txt",ios::app|ios::out);
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
              while(!file.eof())
              {
                if(s_id==id)
                {
                    balance-=amount;
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
                }
                else if(r_id==id)
                {
                    balance+=amount;
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;

                }
                else
                {
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
                }
                 file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
              }
              file1.close();
              file1.close();
              remove("bank.txt");
              rename("bank1.txt","bank.txt");
              cout<<"------Transaction Successful------"<<endl;
              
        }
        else{
            cout<<"Both Transaction user ID not found or balance invalid!"<<endl;
        }
     }
    
}
void bank::payment()
{
    system("cls");
    fstream file,file1;
    int found=0;
    float amount;
    string t_id,b_name;
    SYSTEMTIME x;
    cout<<"Pay Bills"<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
    else
    {
        cout<<"User ID:";
        cin>>t_id;
        cout<<"\n\n Bill Name";
        cin>>b_name;
        cout<<"Bill Amount:";
        cin>>amount;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id==id && amount<=balance)
            {
                balance-=amount;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
                found++;
            }
            else
            {
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
              remove("bank.txt");
              rename("bank1.txt","bank.txt");
        if(found == 1)
        {
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            file.close();
            cout<<" "<<b_name<<"Bill paid succesfully"<<endl;
        }

    }
    
}
void bank::user_balance()
{
    system("cls");
    fstream file;
    string t_id,t_pin,t_pass;
    int found = 0;
    char ch;
    cout<<"User Login and Check Balance"<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
    else
    {
        cout<<"\n\n  User ID: ";
        cin>>t_id;
        cout<<"\n\n Pin Code:";
        for(int i=1;i<=5;i++){
            ch=getch();
            t_pin+=ch;
            cout<<"*";
        }
        cout<<"\n\n Password :";
         for(int i=1;i<=5;i++){
            ch=getch();
            t_pass+=ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(file.eof())
        {
            if(t_id==id)
            {
                if(t_pass==t_pass)
                {
                    if(t_pin==t_pin){
                cout<<endl;
                cout<<endl;
                cout<<"Your Current Balance is : "<<balance;
                found++;
                    }
                }
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
        cout<<endl;
        cout<<endl;
        cout<<"User ID and Password invalid"<<endl;
    }
}
void bank::atm_withdraw()
{
    fstream file,file1;
    string t_id,t_pin,t_pass;
    char ch;
    float with;
    //file1.open("bank.txt",ios::app|ios::out);
    int found= 0;
    system("cls");
    cout<<"Withdraw";
    cout<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else
    {
       //cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       cout<<"\n\n Pin Code:";
        for(int i=1;i<=5;i++){
            ch=getch();
            t_pin+=ch;
            cout<<"*";
        }
        cout<<"\n\n Password :";
         for(int i=1;i<=5;i++){
            ch=getch();
            t_pass+=ch;
            cout<<"*";
        }
        //file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       file1.open("bank.txt",ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id && t_pin==pin && t_pass==pass)
        {
            cout<<endl;
            cout<<"Enter Amount For Withdraw:";
            cin>>with;
            if(with<=balance)
            {
            balance-=with;
            
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
             found++;
            cout<<"\nYour Amount BDT: "<<with<<"Withdrawed succesfully"<<endl;
            }
            else
            {
                cout<<"You Don't have enough money to withdraw"<<endl;
                cout<<"Your Amount BDT: "<<balance<<endl;
            }
            found++; 
        }
        else
        {
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        }
        
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";

    }
}

void bank:: atm_deposit()
{
    fstream file,file1;
    string t_id,t_pin,t_pass;
    char ch;
    float dep;
    //file1.open("bank.txt",ios::app|ios::out);
    int found=0 ;
    cout<<"Deposit Money";
    cout<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else
    {
       //cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       cout<<"\n\n Pin Code:";
        for(int i=1;i<=5;i++){
            ch=getch();
            t_pin+=ch;
            cout<<"*";
        }
        cout<<"\n\n Password :";
         for(int i=1;i<=5;i++){
            ch=getch();
            t_pass+=ch;
            cout<<"*";
        }
       file1.open("bank.txt",ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id && t_pin==pin && t_pass==pass)
        {
            cout<<endl;
            cout<<"Enter Amount For Deposit:";
            cin>>dep;
            balance+=dep;
            //file>>dep;
            
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
             found++;
            cout<<"\nYour Amount BDT: "<<dep<<"deposited succesfully"<<endl;
        }
        else
        {
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<phone<<" "<<endl;
        }
        
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";

    }
}
void bank :: search()
{
    system("cls");
}
void bank::edit()
{
    /*
    system("cls");
    cout<<"\n\nEdit User Record"<<endl;
    fstream file;
    string t_id;
    int found = 0;
    file.open("bank.txt"ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
    else
    {
        cout<<"User ID:";
        cin>>t_id;
    }
    */
}
void bank::del()
{

}
int main()
{
    system("color B9 ");
    bank obj;
    obj.menu();
}
