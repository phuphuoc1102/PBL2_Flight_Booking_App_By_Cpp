#include <bits/stdc++.h>
#include "../header/TicketPrice.h"
#include "../header/lib.h"
#include <stdlib.h>
using namespace std;
TicketPrice::TicketPrice(){
    this->Economy=0;
    this->Deluxe_Economy=0;
    this->Business=0;
}
TicketPrice:: ~TicketPrice(){
    delete [] a;
}
void TicketPrice:: setOption(int x)
{
    option = x;
}
ifstream filePrice("../database/TicketPrice.txt");
int TicketPrice:: getOption()
{
    return option;
}
int TicketPrice::getGate()
{
    return gate;
}
void TicketPrice::setGate(int x)
{
    this->gate = x;
}
void TicketPrice::TicketOptions(TicketPrice *a,InfoFlight *info)
{
    box(26,12,75,10,11,1,Null,0);
    gotoXY(28,14);
    cout << "Bạn muốn chọn hạng vé nào : ";
    gotoXY(28,16);
    cout<<"1.Hạng Phổ Thông "<<"( "<<a[info->getFlightChoose() - 1].Economy<<" VND )";
    gotoXY(28,18);
    cout<<"2.Hạng Phổ Thông Đặt Biệt "<<"( "<< a[info->getFlightChoose() - 1].Deluxe_Economy<<" VND )";
    gotoXY(28,20);
    cout<<"3.Hạng Thương Gia "<<"( "<<a[info->getFlightChoose() - 1].Business<<" VND )";
    box(26,23,20,2,11,1,Answer,0);
    int lc;
    gotoXY(37,24);
    cin>>lc;
    setGate(lc);
    setOption(lc);
   
    box(26,26,20,2,11,1,Count,0);
    gotoXY(38,27);
    cin>>countticket;


}
long long TicketPrice:: getEconomy(TicketPrice *a,int i){
    return a[i].Economy;
}
long long TicketPrice:: getDeluxe_Economy(TicketPrice *a,int i)
{ 
    return a[i].Deluxe_Economy;
}

long long TicketPrice:: getBusiness(TicketPrice *a,int i){
    return a[i].Business;
}
long long TicketPrice:: getTicketprice(TicketPrice *a,InfoFlight *info)
{
    if(getOption() == 1)
    {
        return a[info->getFlightChoose() - 1].Economy;
    }
    else if( getOption() == 2)
        return a[info->getFlightChoose() - 1].Deluxe_Economy;
    else if( getOption() == 3)
        return a[info->getFlightChoose() - 1].Business;
    
}
void TicketPrice:: setEconomy(TicketPrice *&a,int i,long long x){
      a[i].Economy=x;
}
void TicketPrice:: setDeluxe_Economy(TicketPrice *&a,int i,long long x){
     a[i].Deluxe_Economy=x;
}
void TicketPrice:: setBusiness(TicketPrice *&a,int i,long long x){
    a[i].Business=x;
}

void TicketPrice:: inputTicketPrice(TicketPrice *&a)
{
    a=new TicketPrice[15];
     char c;
     filePrice>>c;
     vector <string> dsach1;
     string str2;
     while (getline(filePrice, str2, '-'))
     {
        dsach1.push_back(str2);
     }
     int count=0;
     while (count<dsach1.size())
     {
        a[k].Economy=atol(dsach1[count+1].c_str());
        a[k].Deluxe_Economy=atol(dsach1[count+2].c_str());
        a[k].Business=atol(dsach1[count+3].c_str());
        k++;
        count+=4;
     }
    filePrice.close();
}
void TicketPrice:: mainTicketPrice(TicketPrice *a,InfoFlight *info)
{
    TicketOptions(a,info);
}
