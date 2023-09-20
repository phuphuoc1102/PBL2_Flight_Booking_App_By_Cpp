#include "bits/stdc++.h"
#include "../header/Passenger.h"
#include "../header/NumberTicket.h"
#include "../header/Login.h"
using namespace std;

Passenger ::Passenger()
{
    name = "";
    dateOfBirth = "";
    phoneNumber = "";
    idCard = "";
    sex = "";
}
Passenger ::~Passenger()
{
    
}
void Passenger ::InputPassengerInfo()
{
    string day, month, year;
    int d,m,y;
    while (1)
    {
        fflush(stdin);
        cout << "\n";
        cout << le << "Họ và tên: ";
        textcolor(7);
        getline(cin, name);
        textcolor(3);
        if (checkName(name))
        {
            break;
        }
    }
    while (1)
    {
        fflush(stdin);
        int kt=1;
        cout << "\n";
        cout << le << "Ngày sinh\n";
        cout << le << "\t   Ngày ( dd ): ";
        textcolor(7);
        getline(cin,day);
        textcolor(3);
        if (atof(day.c_str()) || day == "0") 
        {kt=1; d=atoi(day.c_str());}
        else kt=0;
        
        cout << le << "\t   Tháng ( mm ): ";
        textcolor(7);
        getline(cin,month);
        textcolor(3);
        if (atof(month.c_str()) || month == "0") 
        {kt=1; m=atoi(month.c_str());}
        else kt=0;

        cout << le << "\t   Năm ( yyy ): ";
        textcolor(7);
        getline(cin,year);
        textcolor(3);
        if (atof(year.c_str()) || year == "0")
        {kt=1; y=atoi(year.c_str());}
        else kt=0;

        if (kt==1 && checkDate(d, m, y))
        {
            dateOfBirth = day + '/' + month + '/' + year;
            break;
        }
        else{
            textcolor(4);
        cout << le << "Ngày không hợp lệ !\n";
        textcolor(3);
        }
    }
    while (1)
    {
        fflush(stdin);
        cout << "\n";
        cout << le << "Giới tính( Nam / Nu ): ";
        textcolor(7);
        getline(cin, sex);
        textcolor(3);
        if (checkSex(sex) && checkName(sex))
            break;
    }
    while (1)
    {
        fflush(stdin);
        cout << "\n";
        cout << le << "Số CCCD: ";
        textcolor(7);
        getline(cin, idCard);
        textcolor(3);
        if (checkid_phone(idCard))
            break;
    }
    while (1)
    {
        fflush(stdin);
        cout << "\n";
        cout << le << "Số điện thoại: ";
        textcolor(7);
        getline(cin, phoneNumber);
        textcolor(3);
        if (checkid_phone(phoneNumber))
            break;
    }
    system("cls");
    box(40, 3, 50, 6, 11, 1, PassengerInfo, 0);
    
    box(40, 12, 50, 2, 11, 1, PassengerNameInput, 0);
    gotoXY(53, 13);
    Normalize(name);
    textcolor(6);
    cout << name;
    textcolor(3);

    box(40, 15, 50, 2, 11, 1, PassengerDateOfBirthInput, 0);
    gotoXY(53, 16);
    textcolor(6);
    cout << dateOfBirth;
    textcolor(3);

    box(40, 18, 50, 2, 11, 1, PassengerSexInput, 0);
    gotoXY(53, 19);
    Normalize(sex);
    textcolor(6);
    cout << sex;
    textcolor(3);

    box(40, 21, 50, 2, 11, 1, PassengerIDCardInput, 0);
    gotoXY(64, 22);
    textcolor(6);
    cout << idCard;
    textcolor(3);

    box(40, 24, 50, 2, 11, 1, PassengerPhoneNumberInput, 0);
    gotoXY(57, 25);
    textcolor(6);
    cout << phoneNumber;
    textcolor(3);
}

void Passenger::SavePassengerInfo(InfoFlight *info, NumberTicket *num)
{
    string fileName = "InPassenger" + info->getFlyingcode(info, info->getFlightChoose() - 1) + ".txt";
    string filePath = "../database/dataInPassenger/" + fileName;
    char tmp_filePath[filePath.length() + 1];
    strcpy(tmp_filePath, filePath.c_str());
    fstream filePas;
    filePas.open(tmp_filePath, ios::out | ios::app);
    filePas << "-" << num->getTicketID(info->getFlightChoose() - 1, posID);
    filePas << "-" << name;
    filePas << "-" << dateOfBirth;
    filePas << "-" << sex;
    filePas << "-" << idCard;
    filePas << "-" << phoneNumber;
    filePas << endl;
    filePas.close();

    string fileName1 = "Passenger" + info->getFlyingcode(info, info->getFlightChoose() - 1) + ".txt";
    string filePath1 = "../database/dataPassenger/" + fileName1;
    char tmp_filePath1[filePath1.length() + 1];
    strcpy(tmp_filePath1, filePath1.c_str());
    fstream output;
    output.open(tmp_filePath1, ios::out | ios::app);
    output << endl;
    output << setw(20) << left << num->getTicketID(info->getFlightChoose() - 1, posID);
    output << setw(25) << left << name;
    output << setw(20) << left << dateOfBirth;
    output << setw(15) << left << sex;
    output << setw(25) << left << idCard;
    output << setw(25) << left << phoneNumber;
    output.close();
} 
