#ifndef _PROF_STRATEGY_H
#define _PROF_STRATEGY_H
#include "trading_strategy.h"

namespace csis3700{
class prof_strategy : virtual public trading_strategy
{
private:
    int buy_count;

public:
    prof_strategy();

    virtual void process_bar(price_bar b);

    virtual int quantity_to_buy() const;

    virtual int quantity_to_sell() const;

    virtual void set_buy_count(int bc);

    virtual int get_buy_cout() const
    {
        return buy_count;
    }
};

}

#endif // _PROF_STRATEGY_H
