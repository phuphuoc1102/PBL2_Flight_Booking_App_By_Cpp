#ifndef lib_h
#define lib_h
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

bool laNamNhuan(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        return true;
    }
    return false;
}
int tinhSoNgayTrongThang(int nMonth, int nYear)
{
    int nNumOfDays;

    switch (nMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nNumOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        nNumOfDays = 30;
        break;
    case 2:
        if (laNamNhuan(nYear))
        {
            nNumOfDays = 29;
        }
        else
        {
            nNumOfDays = 28;
        }
        break;
    }

    return nNumOfDays;
}
bool laNgayHopLe(int nDay, int nMonth, int nYear)
{
    if (nYear < 0)
    {
        return false;
    }
    if (nMonth < 1 || nMonth > 12)
    {
        return false;
    }
    if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
    {
        return false;
    }

    return true;
}
void Lowercase(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}
string Upcase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return str;
}
void DeleteSpace(string &str)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i);
        }
}

void Normalize(string &str)
{
    if (str[0] != 32)
    {
        if (str[0] > 96 && str[0] < 123)
        {
            str[0] -= 32;
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 32)
        {
            if (str[i + 1] > 96 && str[i + 1] < 123)
            {
                str[i + 1] -= 32;
            }
        }
    }
}
string int_to_string(int x)
{
    ostringstream str;
    str<<x;
    return str.str();
}
bool checkName(string &str)
{
    if (str.length() == 0)
    {
        textcolor(4);
        cout << le << "Không được để trống phần này ! \n";
        textcolor(3);
        return false;
    }
    else
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                textcolor(4);
                cout << le << "Không được có kí tự là số !\n";
                textcolor(3);
                return false;
                break;
            }
        }
    return true;
}
bool checkDate(int nDay, int nMonth, int nYear)
{
    if (laNgayHopLe(nDay, nMonth, nYear))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkSex(string str)
{
    Lowercase(str);
    if (str == "nam" || str == "nu")
    {
        return true;
    }
    else
    {
        textcolor(4);
        cout << le << "Giới tính không hợp lệ !\n";
        textcolor(3);
        return false;
    }
}
bool checkid_phone(string &str)
{
    if (str.length() == 0)
    {
        textcolor(4);
        cout << le << "Không được để trống phần này ! \n";
        textcolor(3);
        return false;
    }
    else
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            {
                textcolor(4);
                cout << le << "Không được có kí tự là chữ !\n";
                textcolor(3);
                return false;
                break;
            }
        }
    return true;
}

#endif