#include "prof_strategy.h"

namespace csis3700{

prof_strategy::prof_strategy()
{
    int buy_count = 0;
}

void prof_strategy::process_bar(price_bar b)
{
    current_unit_price = b.get_adjusted_close();
}

int prof_strategy::quantity_to_buy() const
{
    if(quantity_held == 0)
    {
        return buy_count;
    }

    return 0;
}

int prof_strategy::quantity_to_sell() const
{
    if(quantity_held != 0 && trading_strategy::get_holdings_profit() > 10)
    {
        return quantity_held;
    }

    return 0;
}

void prof_strategy::set_buy_count(int bc)
{
    buy_count = bc;
}

}
