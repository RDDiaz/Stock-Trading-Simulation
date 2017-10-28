#ifndef __CDS_SIMULATOR_H
#define __CDS_SIMULATOR_H
#include <istream>
#include <vector>
#include "price_bar.h"
#include "trade.h"
#include "trading_strategy.h"

namespace csis3700
{
class simulator
{
public:
    /**
     * Create a simulator that makes trading decisions using the
     * supplied trading strategy.  The simulator will start the
     * account with the specified balance of cash.
     */
    simulator(trading_strategy *s, double balance);

    /**
     * Read price_bars from the supplied stream.  Note that the first
     * line of the stream will be a header and should be ignored.
     * Subsequent lines will be formatted:
     *   time open high low close volume adjusted_close
     *
     * Data in the stream will be in reverse chronological order.
     *
     * This method should populate the bars i-var with the contents of
     * this stream but in forward chronological order.
     */
    void read_bars(std::istream& is);

    /**
     * Perform the simulation by iterating through each bar with the
     * following steps:
     *
     * 1) tell the strategy to process the bar
     *
     * 2) ask the strategy how many shares it wants to buy or sell
     *
     * 3) if there is enough cash in the account
     *   3a) inform that strategy (trade_executed) that a trade was executed,
     *   3b) and update the cash available,
     *   3c) add the trade to the trades i-var
     *
     */
    void run();

    std::vector<trade> get_trades() const
    {
        return trades;
    }

    /**
     * Return the current account equity (cash plus holdings value).
     */
    double get_equity() const;

    /**
     * Return the number of shares held by this trading strategy.
     */
    int get_quantity_held() const;


    std::vector<price_bar> get_bars() const
    {
        return bars;
    }

    double get_cash() const
    {
        return cash;
    }

private:
    trading_strategy *strategy;
    double cash;
    std::vector<price_bar> bars;
    std::vector<trade> trades;
};
}

#endif
