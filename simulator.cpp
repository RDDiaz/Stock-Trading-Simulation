#include "simulator.h"
#include "price_bar.h"
#include "trade.h"
#include "trading_strategy.h"
#include <vector>
#include <istream>
#include <algorithm>
#include <iostream>

namespace csis3700
{

simulator::simulator(trading_strategy *s, double balance)
{
    strategy = s;
    cash = balance;
}

void simulator::read_bars(std::istream& is)
{
    char first_line[50];
    is.getline(first_line, 50);
    std::string date;
    double open, high, low, close, volume, adjusted_close;

    if(is.good())
    {
        while(is >> date >> open >> high >> low >> close >> volume >> adjusted_close)
        {
            price_bar b(date, open, high, low, close, adjusted_close);
            bars.push_back(b);
        }
        reverse(bars.begin(), bars.end());
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

}

void simulator::run()
{
    for(std::vector<price_bar>::iterator it = bars.begin(); it != bars.end(); ++it)
    {
        strategy->process_bar(*it);
//        std::cout << "RBC: " << strategy->get_red_bar_count() << std::endl;

        if(strategy->quantity_to_buy() != 0 && cash >= (strategy->quantity_to_buy() * it->get_adjusted_close()))
        {
            trade t(it->get_time(), it->get_adjusted_close(), strategy->quantity_to_buy(), true);
            strategy->executed(t);
            trades.push_back(t);
            cash -= (t.get_price()*t.get_quantity());
            std::cout << "PURCHSED " << t.get_quantity() << " share(s) at " << t.get_price() << std::endl;
            std::cout << "PURCHSED: cash = " << cash << std::endl;
        }

        if(strategy->quantity_to_sell() != 0)
        {
            trade t(it->get_time(), it->get_adjusted_close(), strategy->quantity_to_sell(), false);
            strategy->executed(t);
            trades.push_back(t);
            cash += (t.get_price()*t.get_quantity());
            std::cout << "SOLD " << t.get_quantity() << " share(s) at " << t.get_price() << std::endl;
            std::cout << "SOLD: cash = " << cash << std::endl;
        }
    }
}

double simulator::get_equity() const
{
    return cash + strategy->get_holdings_equity();
}

int simulator::get_quantity_held() const
{
    return strategy->get_quantity_held();
}

}
