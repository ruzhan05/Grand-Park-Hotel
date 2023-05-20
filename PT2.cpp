#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
//global variable declaration
int a=9,b=1,flag=1;

COORD coord = {1, 1};

void gotoxy(int i, int j)
{
    COORD coord;
    coord.X = i;
    coord.Y = j;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

ofstream fout;
ifstream fin;

class item
{
    int itemNum;
    char name[25];
    int mm,dd,yy;
public:
    void getItem()
    {
        cout<<"\n\n\tItem No: ";
        cin>>itemNum;
        cout<<"\n\n\tName of the item: ";
        cin>>name;
//gets(name);
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>dd>>mm>>yy;
    }
    void showItem()
    {
        cout<<"\n\tItem No: ";
        cout<<itemNum;
        cout<<"\n\n\tName of the item: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<dd<<mm<<yy;
    }
    void itemReport()
    {
        gotoxy(3,a);
        cout<<itemNum;
        gotoxy(13,a);
        puts(name);
    }
    int retNum()
    {
        return(itemNum);

    }

};

class amount: public item
{
    float price,qnty,taxpcnt,total,disc,netAmnt;
public:
    void setInfo();
    void showInfo();
    void report();
    void calc();
    void payAmnt();
    float retrnNetAmnt()
    {
        return(netAmnt);
    }
} amt;

void amount::setInfo()
{
    item::getItem();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qnty;
    cout<<"\n\n\tTax percent: ";
    cin>>taxpcnt;
    cout<<"\n\n\tDiscount percent: ";
    cin>>disc;
    calc();
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}
void amount::calc()
{
    total=price+(price*(taxpcnt/100));
    netAmnt=qnty*(total-(total*(disc/100)));
}
void amount::showInfo()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    item::showItem();
    cout<<"\n\n\tNet amount: ";
    cout<<netAmnt;
    fin.close();
}

void amount::report()
{
    item::itemReport();
    gotoxy(23,a);
    cout<<price;
    gotoxy(33,a);
    cout<<qnty;
    gotoxy(44,a);
    cout<<taxpcnt;
    gotoxy(52,a);
    cout<<disc;
    gotoxy(64,a);
    cout<<netAmnt;
    a=a+1;
    if(a==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        a=7;
        system("cls");
        gotoxy(30,3);
        cout<<" ITEM DETAILS ";
        gotoxy(3,5);
        cout<<"NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"PRICE";
        gotoxy(33,5);
        cout<<"QUANTITY";
        gotoxy(44,5);
        cout<<"TAX";
        gotoxy(52,5);
        cout<<"DEDUCTION";
        gotoxy(64,5);
        cout<<"NET AMOUNT";
    }
}

void amount::payAmnt()
{
    showInfo();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                     :"<<price;
    cout<<"\n\n\t\tQUANTITY                  :"<<qnty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<taxpcnt;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<disc;
    cout<<"\n\n\n\t\tNET AMOUNT              :Rs."<<netAmnt;
    cout<<"\n\t\t*********************************************";
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
menu:
    system("cls");
    gotoxy(25,2);
    cout<<"Super Market Billing ";
    gotoxy(25,3);
    cout<<"===========================\n\n";
    cout<<"\n\t\t1.Bill Report\n\n";
    cout<<"\t\t2.Add/Remove/Edit Item\n\n";
    cout<<"\t\t3.Show Item Details\n\n";
    cout<<"\t\t4.Exit\n\n";
    cout<<"\t\tPlease Enter Required Option: ";
    int ch,ff;
    float gtotal;
    cin>>ch;
    switch(ch)
    {
    case 1:
ss:
        system("cls");
        gotoxy(25,2);
        cout<<"Bill Details";
        gotoxy(25,3);
        cout<<"================\n\n";
        cout<<"\n\t\t1.All Items\n\n";
        cout<<"\t\t2.Back to Main menu\n\n";
        cout<<"\t\tPlease Enter Required Option: ";
        int cho;
        cin>>cho;
        if(cho==1)
        {
            system("cls");
            gotoxy(30,3);
            cout<<" BILL DETAILS ";
            gotoxy(3,5);
            cout<<"ITEM NO";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"PRICE";
            gotoxy(33,5);
            cout<<"QUANTITY";
            gotoxy(44,5);
            cout<<"TAX %";
            gotoxy(52,5);
            cout<<"DISCOUNT %";
            gotoxy(64,5);
            cout<<"NET AMOUNT";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            gtotal=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report();
                    gtotal+=amt.retrnNetAmnt();
                    ff=0;
                }
                if(ff!=0) gtotal=0;
            }
            gotoxy(17,a);
            cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
            getch();
            fin.close();
        }
        if(cho==2)
        {
            goto menu;
        }
        goto ss;
    case 2:
db:
        system("cls");
        gotoxy(25,2);
        cout<<"Bill Editor";
        gotoxy(25,3);
        cout<<"=================\n\n";
        cout<<"\n\t\t1.Add Item Details\n\n";
        cout<<"\t\t2.Edit Item Details\n\n";
        cout<<"\t\t3.Delete Item Details\n\n";
        cout<<"\t\t4.Back to Main Menu ";
        int apc;
        cin>>apc;
        switch(apc)
        {
        case 1:
            fout.open("itemstore.dat",ios::binary|ios::app);
            amt.setInfo();
            cout<<"\n\t\tItem Added Successfully!";
            getch();
            goto db;

        case 2:
            int ino;
            flag=0;
            cout<<"\n\n\tEnter Item Number to be Edited :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            fout.open("itemstore.dat",ios::binary|ios::app);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            b=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    int i=amt.item::retNum();
                    if(i==ino)
                    {
                        flag=1;
                        fout.seekp(b*sizeof(amt));
                        system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        amt.showInfo();
                        cout<<"\n\n\t\tEnter New Details\n";
                        amt.setInfo();
                        cout<<"\n\t\tItem Details editted";
                    }
                }
                b++;
            }
            if(flag==0)
            {
                cout<<"\n\t\tItem No does not exist...Please Retry!";
                getch();
                goto db;
            }
            fin.close();
            getch();
            goto db;

        case 3:
            flag=0;
            cout<<"\n\n\tEnter Item Number to be deleted :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
//fstream tmp("temp.dat",ios::binary|ios::out);
            fin.seekg(0);
            while(fin.read((char*)&amt, sizeof(amt)))
            {
                int i=amt.item::retNum();
                if(i!=ino)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    flag=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("itemstore.dat",ios::trunc|ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat",ios::binary|ios::in);
            if(!tmp)
            {
                cout<<"Error in File";
                goto db;
            }
            while(tmp.read((char*)&amt,sizeof(amt)))
                fout.write((char*)&amt,sizeof(amt));
            tmp.close();
            fout.close();
            if(flag==1)
                cout<<"\n\t\tItem Succesfully Deleted";
            else if (flag==0)
                cout<<"\n\t\tItem does not Exist! Please Retry";
            getch();
            goto db;
        case 4:
            goto menu;
        default:
            cout<<"\n\n\t\tWrong Choice!!! Retry";
            getch();
            goto db;
        }
    case 3:
        system("cls");
        flag=0;
        int ino;
        cout<<"\n\n\t\tEnter Item Number :";
        cin>>ino;
        fin.open("itemstore.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int i=amt.item::retNum();
            if(i==ino)
            {
                amt.payAmnt();
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tItem does not exist....Please Retry!";
        getch();
        fin.close();
        goto menu;
    case 4:
        system("cls");
        gotoxy(20,20);
        cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
            gotoxy(12,20);
            system("cls");
            cout<<"************************** THANKS **************************************";
            getch();
            exit(0);
        }
        else if((yn=='N')||(yn=='n'))
            goto menu;
        else
        {
            goto menu;
        }
    default:
        cout<<"\n\n\t\tWrong Choice....Please Retry!";
        getch();
        goto menu;
    }
    return 0;
}
