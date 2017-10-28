#include "blsh_strategy.h"

namespace csis3700{

blsh_strategy::blsh_strategy()
{
    int red_bar_count = 0;
    int red_limit = 2;
    int buy_count = 0;
}

void blsh_strategy::process_bar(price_bar b)
{
    current_unit_price = b.get_adjusted_close();

    if(b.get_open() < b.get_adjusted_close())
    {
        ++red_bar_count;
    }
    else
    {
        red_bar_count = 0;
    }
}

int blsh_strategy::quantity_to_buy() const
{
    if(red_bar_count >= red_limit)
    {
        return buy_count;
    }

    return 0;
}

int blsh_strategy::quantity_to_sell() const
{
    if(current_unit_price > (purchase_unit_price + 15) && quantity_held != 0)
    {
        return quantity_held;
    }

    return 0;
}

void blsh_strategy::set_buy_count(int bc)
{
    buy_count = bc;
}

}
