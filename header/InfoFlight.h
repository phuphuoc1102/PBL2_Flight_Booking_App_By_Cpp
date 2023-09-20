#ifndef InfoFlight_h
#define InfoFlight_h
#include "LinkedList.h"
#include "lib.h"
using namespace std;
class InfoFlight 
{
    private:
        InfoFlight *info;
        string departure;
        string destination;
        string date;
        string flyingcode;
        string flyingtime;
        string landingtime;
        int flightChoose;
    public:
        InfoFlight();
        ~InfoFlight();
        void InputDataFlight(InfoFlight *&info);
        void mainInputDataInfoFlight(InfoFlight* &info);
        void ListFlight(InfoFlight *info);
        string getDestination(InfoFlight *info, int i);
        string getDeparture(InfoFlight *info, int i);
        string getDate(InfoFlight *info, int i);
        string getFlyingcode(InfoFlight *info, int i);
        string getFlyingtime(InfoFlight *info, int i);
        string getLandingtime(InfoFlight *info, int i);
        int    getFlightChoose();
        void   setDestination(InfoFlight *&info, int i, string x);
        void   setDeparture(InfoFlight *&info, int i, string x);
        void   setDate(InfoFlight *&info, int i, string x);
        void   setFlyingcode(InfoFlight *&info, int i, string x);
        void   setFlyingtime(InfoFlight *&info, int i, string x);
        void   setLandingtime(InfoFlight *&info, int i, string x);
        void   setFlightChoose(int x);
};
#endif