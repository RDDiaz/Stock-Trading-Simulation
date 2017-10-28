#include "trade.h"
#include <string>

namespace csis3700
{

trade::trade(std::string time, double price, double quantity, bool buy)
{
    this->time = time;
    this->price = price;
    this->quantity = quantity;
    this->buy = buy;
}

double trade::get_net_credit() const
{
    if(buy)
    {
        return -(price * quantity);
    }
    if(!buy)
    {
        return (price * quantity);
    }
}

}
