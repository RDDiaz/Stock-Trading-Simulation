#include "price_bar.h"
#include <string>

namespace csis3700
{

price_bar::price_bar(std::string time, double open, double high, double low, double close, double adjusted_close)
{
    this->time = time;
    this->open = open;
    this->high = high;
    this->low = low;
    this->close = close;
    this->adjusted_close = adjusted_close;
}

}
