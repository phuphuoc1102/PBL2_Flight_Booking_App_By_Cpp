#ifndef Summary_h
#define Summary_h
#include  <string.h>
#include "InfoFlight.h"
#include "TicketPrice.h"
#include "Checkin.h"
using namespace std;
class Summary : public InfoFlight
{   
    private:
        Summary *sum;
        int TicketAmount,CheckinTicketAmount,TotalMoney;
    public:
        Summary();
        ~Summary();
        int getTicketAmount(Summary *sum,int i);
        int getCheckinTicketAmount(Summary *sum,int i);
        long long getTotalMoney(Summary *sum,int i);
        void setTicketAmount(Summary *&sum,int i,int x);
        void setCheckinTicketAmount(Summary *&sum,int i,int x);
        void setTotalMoney(Summary *&sum,int i,long long x);
        void SummaryFunc(Summary *&sum,InfoFlight *info,Checkin *c,NumberTicket *num,TicketPrice *t);
};
#endif