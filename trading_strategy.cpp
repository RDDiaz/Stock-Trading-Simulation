#include "trading_strategy.h"
#include "trade.h"
#include "price_bar.h"
#include "simulator.h"


namespace csis3700
{
/// Base Class Methods
trading_strategy::trading_strategy()
{
    quantity_held = 0;
    current_unit_price = 0;
    purchase_unit_price = 0;
}

void trading_strategy::executed(trade t)
{
    if(t.is_buy())
    {
        quantity_held += quantity_to_buy();
        purchase_unit_price = current_unit_price;
    }
    else
    {
        quantity_held -= quantity_to_sell();
    }
}

double trading_strategy::get_holdings_equity() const
{
    return quantity_held * current_unit_price;
}

double trading_strategy::get_holdings_profit() const
{
    return (quantity_held * current_unit_price)-(quantity_held * purchase_unit_price);
}


}

