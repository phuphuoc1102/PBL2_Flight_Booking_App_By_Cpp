#include <bits/stdc++.h>
#include "../header/BookingData.h"
#include "Passenger.cpp"
#include "NumberTicket.cpp"

int size = 0;
using namespace std;

BookingData::BookingData()
{
    this->ticketid = 0;
}
BookingData::~BookingData()
{
    delete[] b;
}
long long BookingData::get_ticketid(BookingData *b, int i)
{
    return b[i].ticketid;
}
string BookingData::GetName(BookingData *b, int i)
{
    return b[i].name;
}
string BookingData::GetDateofbirth(BookingData *b, int i)
{
    return b[i].dateOfBirth;
}
string BookingData::GetSex(BookingData *b, int i)
{
    return b[i].sex;
}
string BookingData::GetIDcard(BookingData *b, int i)
{
    return b[i].idCard;
}
string BookingData::GetPhonenumber(BookingData *b, int i)
{
    return b[i].phoneNumber;
}
void BookingData::InputBookingData(BookingData *&b, InfoFlight *info, int v)
{
    // doc file khi checkin khi dang nhap de tranh so ve bi trung
    string fileName = "InPassenger" + info->getFlyingcode(info, v) + ".txt";
    string filePath = "../database/dataInPassenger/" + fileName;
    char tmp_filePath[filePath.length() + 1];
    strcpy(tmp_filePath, filePath.c_str());
    fstream file1;
    file1.open(tmp_filePath, ios::in);
    b = new BookingData[1000];
    char c;
    file1 >> c;
    vector<string> ds;
    string str;
    while (getline(file1, str, '-'))
    {
        ds.push_back(str);
    }
    int count = 0, i = 0;
    size = 0;
    // cout<<ds[0];
    while (count < ds.size())
    {
        b[i].ticketid = atol(ds[count].c_str());
        b[i].name = ds[count + 1];
        b[i].dateOfBirth = ds[count + 2];
        b[i].sex = ds[count + 3];
        b[i].idCard = ds[count + 4];
        b[i].phoneNumber = ds[count + 5];
        i++;
        if (atol(ds[count].c_str()) % 1000 > 90)
        {
            ThuongGia[v]++;
        }
        else if (atol(ds[count].c_str()) % 1000 > 70)
            PhoThongDB[v]++;
        else if (atol(ds[count].c_str()) % 1000 <= 70)
            PhoThong[v]++;
        size++;
        count += 6;
    }
    if (PhoThong[v] + PhoThongDB[v] + ThuongGia[v] > 100)
    {
        system("cls");
        box(40, 3, 50, 6, 11, 1, Notify, 0);
        textcolor(4);
        cout << "\n";
        cout << le << "Chuyến bay này đã hết chỗ";
        textcolor(3);
        cout << "\n"
             << le;
        return;
    }
    b[i].ticketid = -1;
    file1.close();
}
