#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ofstream outFile; //output file stream variable
    ifstream infile;
    char buffer[256];
    //item name and price
    const string cas ="Carrot Sticks";
    const string aps ="Apple Slices";
    const string bas ="Bananas";
    const string ces ="Celery Sticks";
    const float  p_cas =0.87;
    const float  p_aps =0.95;
    const float  p_bas =0.55;
    const float  p_ces =1.02;
    const float discount = 0.1;
    //input
    string item_name, input_itemno,flag;
    int itemno,itemno1, itemqty;
    float input_money, sum_money=0, cost;
    bool b_flag=true;

    outFile.open("log.txt");
   // outFile << fixed << showpoint;
    outFile << setprecision(2);
    outFile <<"Item No"<<right<<setw(10)<<"Item Name"<<setw(10)<<"Quantity"<<setw(10)<<"Cash"<<setw(10)<<"Change"<<endl;

    //outFile <<"Item No" << "Item Name" <<"Quantity" <<"Cash"<<"Change"<< endl;
    cout << setprecision(2);
    while (cin >>input_itemno)
    {
        b_flag=true;
        if(input_itemno=="00")
        {
            break;
        }
        if(input_itemno=="99")
        {
            infile.open("log.txt");
            while(!infile.eof())
            {
               infile.getline(buffer,256,'\n');
               cout << buffer<<endl;
            }
            infile.close();
            break;

        }
        cost=sum_money=0;
        flag=" ";
        itemno = atoi(input_itemno.substr(0,1).c_str());
        itemqty = atoi(input_itemno.substr(1,1).c_str());
        itemno1 = itemno;
        while(itemno==1)
        {
            cost = p_cas*(1-discount)*itemqty;
            itemno =0;
            item_name=cas;
        }
        while(itemno==2)
        {
            cost = p_aps*(1-discount)*itemqty;
            itemno =0;
            item_name=aps;
        }
        while(itemno==3)
        {
            cost = p_bas*(1-discount)*itemqty;
            itemno =0;
            item_name=bas;
        }
        while(itemno==4)
        {
            cost = p_ces*(1-discount)*itemqty;
            itemno =0;
            item_name=ces;
        }
            while(b_flag)
            { cin>>input_money;
                //cout << "input_money: " << input_money;
                sum_money+= input_money;
                // cout << "sum_money: " << sum_money;
                while (sum_money>cost )
                {
                    b_flag=false;
                    break;
                }
            }
            //cout << "cost: "<<cost << "sum_money: " << sum_money <<endl;
            cout << "$"<<sum_money-cost<<endl;
            outFile <<itemno1<<setw(10)<<right<<item_name<<setw(10)<<itemqty<<setw(10)<<sum_money<<setw(10)<<sum_money-cost<<endl;
    }
        outFile.close();

        return 0;
    }
