#ifndef Checkin_h
#define Checkin_h
#include "InfoFlight.h"
#include "NumberTicket.h"
#include "Passenger.h"
#include "BookingData.h"
#include "TicketPrice.h"
class Checkin : public InfoFlight
{
    private:
    Checkin *c;
    int CheckinRow, CheckinCol,CheckinFlight,CheckinArray[105];
    public:
        Checkin();
        ~Checkin();
        void CheckinFunc(Checkin *c,NumberTicket *num,InfoFlight *info,Passenger psg,TicketPrice *t,BookingData *b);
        void CheckinMap(Checkin *c,InfoFlight *info);
        void SaveCheckinMap(InfoFlight *info,int v);
        void InputCheckinData(Checkin *&c,InfoFlight *info,int v);
        int  getCheckinRow(Checkin *c,int i);
        int  getCheckinCol(Checkin *c,int i);
        int getCheckinArray(Checkin *c,int i,int j);
        void setCheckinCol(Checkin *c,int i,int x);
        void setCheckinArray(Checkin *&c,int i,int j,int x);
        void setCheckinRow(Checkin *c, int i, int x);
        void InputSeat(Checkin *c, InfoFlight *info);
    
};
#endif