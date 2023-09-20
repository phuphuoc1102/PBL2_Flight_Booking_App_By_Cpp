#include <bits/stdc++.h>
#include <conio.h>
#include "../header/InfoFlight.h"
using namespace std;

InfoFlight::InfoFlight()
{

}
InfoFlight:: ~InfoFlight()
{
     delete [] info;
}

string InfoFlight::getDeparture(InfoFlight *info, int i)
{
    return info[i].departure;
}
string InfoFlight::getDate(InfoFlight *info, int i)
{
    return info[i].date;
}
string InfoFlight::getDestination(InfoFlight *info, int i)
{
    return info[i].destination;
}
string InfoFlight:: getFlyingcode(InfoFlight *info, int i)
{
     return info[i].flyingcode;
}
string InfoFlight:: getFlyingtime(InfoFlight *info, int i){
     return info[i].flyingtime;
}
string InfoFlight:: getLandingtime(InfoFlight *info, int i){
     return info[i].landingtime;
}
void InfoFlight::setDate(InfoFlight *&info, int i, string x)
{
    info[i].date = x;
}
int InfoFlight::getFlightChoose()
{
    return flightChoose;
}
void InfoFlight::setDeparture(InfoFlight *&info, int i, string x)
{
    info[i].departure = x;
}

void InfoFlight::setDestination(InfoFlight *&info, int i, string x)
{
    info[i].destination = x;
}
void InfoFlight:: setFlyingcode(InfoFlight *&info, int i, string x)
{
    info[i].flyingcode=x;
}
void InfoFlight::setFlyingtime(InfoFlight *&info, int i, string x)
{
    info[i].flyingtime=x;
}
void InfoFlight::setLandingtime(InfoFlight *&info, int i, string x)
{
    info[i].landingtime=x;
}

void InfoFlight :: setFlightChoose(int x)
{
    flightChoose = x;
}
void InfoFlight::InputDataFlight(InfoFlight *&info)
{
    ifstream input("../database/FlightInformation.txt");
    info = new InfoFlight[15];
    char c;
    input>>c;
    vector<string> ds;
    string str;
    while (getline(input, str, '-'))
    {
        ds.push_back(str);
    }
    int count = 0;
     while (count < ds.size())
     {
        setDeparture  (info, n, ds[count]);
        setDestination(info, n, ds[count + 1]);
        setDate       (info, n, ds[count + 2]);
        setFlyingcode (info, n, ds[count+3]);
        setFlyingtime (info, n, ds[count+4]);
        setLandingtime(info, n, ds[count+5]);

        string tmpDeparture = getDeparture(info, n);
        setDeparture(info, n, tmpDeparture);

        string tmpDestination = getDestination(info, n);
        setDestination(info, n, tmpDestination);
        n++;
        count += 6;
     }
    input.close();
}
void InfoFlight::mainInputDataInfoFlight(InfoFlight *&info)
{
    box(40,3,50,6,11,1,FindFlight,0);
    ListFlight(info);
    cout << "Bạn muốn bay chuyến nào ?\n";
    int x;
    cin >> x;
    if(x > n || x < 0)
    {
        textcolor(12);
        cout <<le3<< "Chuyến bay không tồn tại\n\n";
        textcolor(3);
        cout <<le3<< "1.Thử lại.\n" ;
        cout<<le3<<"0.Thoát.\n";
        cout<<le3<<"TRẢ LỜI: ";
        int lc;
        cin>>lc;
        if (lc==0)
        {
            cout << endl;
            cout <<le3<< "Xin cam on";
            system("cls");
            exit(0);
        }
        info -> mainInputDataInfoFlight(info);
    }
    else
    {
        textcolor(10);
        cout<<le3<<"Tìm chuyến bay thành công \n\n";
        textcolor(3);
        cout<<le3<<"1.Tiếp tục.\n";
        cout<<le3<<"0.Thoát\n";
        cout<<le3<<"TRẢ LỜI: ";
        int lc;
        cin>>lc;
        if (lc==0)
        {  
            cout<<"Xin cảm ơn";
            exit(0);
        }
        else {
            setFlightChoose(x);
            system("cls");
        }
    }
}
void InfoFlight:: ListFlight(InfoFlight *info){
    int x=3,y=3,j=1;
    system("cls");
    cout<< setw(50) << left << "Index"; 
    cout<< setw(50) << left << "Departure";       
    cout<< setw(50) << left << "Destination";
    cout << setw(50) << left << "Flyingtime";
    cout << endl;
    for (int i=0;i<n;i++)
    {
        cout << setw(50) << i + 1 << left << setw(50) << left << getDeparture(info,i);
        cout << setw(50) << left << getDestination(info,i);
        cout << setw(50) << left << getDate(info,i);
        cout << endl;
    }
}
