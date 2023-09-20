#ifndef passenger_h
#define passenger_h
#include<string>
#include "InfoFlight.h"
#include "NumberTicket.h"
using namespace std;
class Passenger : public InfoFlight 
{
    protected: 
        string name,dateOfBirth, phoneNumber, idCard,sex;
    public:
        Passenger();
        ~Passenger();
        void InputPassengerInfo();
        void SavePassengerInfo(InfoFlight *info,NumberTicket *num);
};
#endif