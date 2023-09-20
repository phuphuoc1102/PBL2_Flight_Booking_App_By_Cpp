#include "../header/Summary.h"
#include <bits/stdc++.h>
using namespace std;

Summary:: Summary(){
     this->TicketAmount=0;
     this->CheckinTicketAmount=0;
     this->TotalMoney=0;
}
Summary:: ~Summary(){
     delete [] sum;
}
void Summary::SummaryFunc(Summary *&sum, InfoFlight *info,Checkin *c,NumberTicket *num,TicketPrice *t)
{
    sum = new Summary[15];
    box(0,0,140,2,11,1,SummaryChar,0);
    for (int i = 0; i < 15; i++)
    {
        string fileNamePass = "InPassenger" + info->getFlyingcode(info, i) + ".txt";//tên của file
        string filePathPass = "../database/dataInPassenger/" + fileNamePass; //đường dẫn + tên file
        char tmp_filePathPass[filePathPass.length() + 1]; 
        strcpy(tmp_filePathPass, filePathPass.c_str()); //cop qua cho tmp
        ifstream fileInPas(tmp_filePathPass);
        int countPass=0;
        string str;
        char tmpchar;
        fileInPas >> tmpchar;
        vector<string> ds;
        string str1;
        while (getline(fileInPas, str1, '-'))
        {
            ds.push_back(str1);
        }
        int count = 0, idx = 0;
        long long tempTicketCode = 0;
        while (count < ds.size())
        {
            tempTicketCode = atol(ds[count].c_str());
            if(tempTicketCode - num->getFirst(num,i) >= 90)
            {
                setTotalMoney(sum,i,getTotalMoney(sum,i) + t->getBusiness(t,i));
            }
            else if(tempTicketCode - num->getFirst(num,i) <90 && tempTicketCode - num->getFirst(num,i) >= 70)
            {
                setTotalMoney(sum,i,getTotalMoney(sum,i) + t->getDeluxe_Economy(t,i));
            }
            else
            {
                setTotalMoney(sum,i,getTotalMoney(sum,i) + t->getEconomy(t,i)); 
            }
            
            idx++;
            count += 6;
        }

        setTicketAmount(sum,i,idx);
        fileInPas.close();

        
       // doc so luong ve da check in
        string fileNameCheck = "Checkin" + info->getFlyingcode(info, i) + ".txt";
        string filePathCheck = "../database/dataCheckin/" + fileNameCheck;
        char tmp_filePathCheck[filePathCheck.length() + 1];
        strcpy(tmp_filePathCheck, filePathCheck.c_str());
        cout<<tmp_filePathCheck<<endl;
        fstream fileCheck;
        fileCheck.open(tmp_filePathCheck, ios::in);
        int countCheck=0,y;
        while(!fileCheck.eof()){
             fileCheck>>y;
             countCheck++;
        }
        setCheckinTicketAmount(sum,i,countCheck-1);
        fileCheck.close();
   }
   fstream fileSum("../database/Summary.txt",ios::out|ios:: app);
        srand(time(NULL));
       time_t hientai = time(0);
    char *dt = ctime(&hientai);
    tm *ltm = localtime(&hientai);
    fileSum<<"Ngày tổng kết: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    fileSum<<"Vào lúc "<< 1 + ltm->tm_hour << ":"<< 1 + ltm->tm_min << ":"<<1 + ltm->tm_sec << endl<<endl;
    fileSum<<setw(20)<<left<<"Mã hành trình";
    fileSum<<setw(30)<<left<<"Tổng số lượng vé";
    fileSum<<setw(32)<<left<<"Số lượng vé đã bán";
    fileSum<<setw(34)<<left<<"Số lượng vé chưa bán";
    fileSum<<setw(38)<<left<<"Số lượng vé đã checkin";
    fileSum<<setw(38)<<left<<"Số lượng vé chưa checkin";
    fileSum<<setw(40)<<left<<"Tổng doanh thu"<<endl;
    for (int i = 0; i < 15; i++)
    {
        box(0, 2 + i * 2, 140, 2, 11, 1, Null, 0);
        textcolor(7);
        gotoXY(1, 3 + i * 2);
        cout << "      " << setw(11) << left << info->getFlyingcode(info, i) << "|";
        gotoXY(25, 2 + i * 2 + 1);
        cout << "   " << 100 << "        |";
        cout << "       " << setw(9) << left << getTicketAmount(sum, i) << "|";
        cout << "       " << setw(11) << left << 100 - getTicketAmount(sum, i) << "|";
        cout << "        " << setw(12) << left << getCheckinTicketAmount(sum, i) << "|";
        cout << "        " << setw(14) << left << getTicketAmount(sum, i) - getCheckinTicketAmount(sum, i) << "|";
        cout << "     " << setw(15) << left << getTotalMoney(sum, i);

        fileSum<<"    "<<setw(19)<<left<<info->getFlyingcode(info,i);
        fileSum<<setw(23)<<left<<100;
        fileSum<<setw(24)<<left<<getTicketAmount(sum,i);
        fileSum<<setw(27)<<left<<100-getTicketAmount(sum,i);
        fileSum<<setw(32)<<left<<getCheckinTicketAmount(sum,i);
        fileSum<<setw(20)<<left<<getTicketAmount(sum,i) - getCheckinTicketAmount(sum,i);
        fileSum<<left<<getTotalMoney(sum,i);
        fileSum<<endl;
        if (i==14) fileSum<<"____________________________________________________________________________________________________________________________________________________________________";
        fileSum<<endl;
   }
   fileSum.close();
}
int Summary::getTicketAmount(Summary *sum, int i)
{
    return sum[i].TicketAmount;
}
int Summary::getCheckinTicketAmount(Summary *sum, int i)
{
    return sum[i].CheckinTicketAmount;
}
long long Summary::getTotalMoney(Summary *sum, int i)
{
    return sum[i].TotalMoney;
}
void Summary::setTicketAmount(Summary *&sum, int i, int x)
{
    sum[i].TicketAmount = x;
}
void Summary::setCheckinTicketAmount(Summary *&sum, int i, int x)
{
    sum[i].CheckinTicketAmount = x;
}
void Summary::setTotalMoney(Summary *&sum, int i, long long x)
{
    sum[i].TotalMoney= x;
}
