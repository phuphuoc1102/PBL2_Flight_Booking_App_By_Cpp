#ifndef TicketPrice_h
#define TicketPrice_h
#include "InfoFlight.h"
#include "Passenger.h"
class TicketPrice : public InfoFlight
{
     private:
          TicketPrice *a;
          long long Economy;
          long long Deluxe_Economy;
          long long Business;
          long long Price;
          int option;
          int gate;
     public:
     TicketPrice();
     ~TicketPrice();
     void TicketOptions(TicketPrice *a,InfoFlight *info);
     void  inputTicketPrice(TicketPrice *&a);
     void mainTicketPrice(TicketPrice *a,InfoFlight *info);
     void setEconomy(TicketPrice *&a,int i,long long x);
     void setDeluxe_Economy(TicketPrice *&a,int i,long long x);
     void setBusiness(TicketPrice *&a,int i,long long x);
     void setGate(int x);
     long long getEconomy(TicketPrice *a,int i);
     long long getDeluxe_Economy(TicketPrice *a,int i);
     long long getBusiness(TicketPrice *a,int i);
     long long getTicketprice(TicketPrice *a,InfoFlight *info);
     int       getOption();
     void      setOption(int  x);
     int       getGate();
     
};
#endif