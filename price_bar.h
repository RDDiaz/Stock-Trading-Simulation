#ifndef __CDS_PRICE_BAR_H
#define __CDS_PRICE_BAR_H
#include <string>

namespace csis3700
{
class price_bar
{
public:
    price_bar(std::string time, double open, double high,
              double low, double close, double adjusted_close);

    std::string get_time() const
    {
        return time;
    }

    double get_open() const
    {
        return open;
    }

    double get_high() const
    {
        return high;
    }

    double get_low() const
    {
        return low;
    }

    double get_close() const
    {
        return close;
    }

    double get_adjusted_close() const
    {
        return adjusted_close;
    }

private:
    std::string time;
    double open;
    double high;
    double low;
    double close;
    double adjusted_close;
};
}


#endif
