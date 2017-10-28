#ifndef _BLSH_STRATEGY_H
#define _BLSH_STRATEGY_H
#include "trading_strategy.h"

namespace csis3700{
class blsh_strategy : virtual public trading_strategy
{
private:
    int red_bar_count;
    int red_limit;
    int buy_count;

public:
    blsh_strategy();

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

#endif // _BLSH_STRATEGY_H
