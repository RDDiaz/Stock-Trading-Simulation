#ifndef __CDS_STRATEGY_H
#define __CDS_STRATEGY_H
#include "trade.h"
#include "price_bar.h"

namespace csis3700
{
/// BaseClass
class trading_strategy
{
public:

    /**
     * Construct a new trading strategy.
     */
    trading_strategy();

    /**
     * Returns the number of shares this trading strategy currently
     * holds.  This will be a positive number for a long position, a
     * negative number for a short position and zero when flat.
     */
    virtual int get_quantity_held() const
    {
        return quantity_held;
    }

    /**
     * The simulation sends this message to tell the trading strategy
     * about a new bar.  Each (simulated) day's bar is passed to this
     * strategy, one at a time, so that the stratgy can make
     * decisions.
     */
    virtual void process_bar(price_bar b)=0;

    /**
     * Return the number of shares this strategy wants to buy at the
     * current price (0 for none, of course).
     */
    virtual int quantity_to_buy() const=0;


    /**
     * Return the number of shares this strategy wants to sell at the
     * current price (0 for none, of course).
     */
    virtual int quantity_to_sell() const=0;

    /**
     * Once a strategy has indicated that it wants to trade (buy or
     * sell, see methods above), the simulation will try to execute
     * this trade.  If the trade is successful, the strategy will be
     * notified by this executed method.  The strategy should update
     * its quantity_held i-var and potentially any strategy-specific
     * variables.
     */
    virtual void executed(trade t);

    /**
     * Return the equity of this strategies current holdings based on
     * the last adjusted close price seen.
     */
    virtual double get_holdings_equity() const;

    /**
     * Return the profit made by the strategy ON ITS CURRENT HOLDINGS,
     * not throughout its existence.  Should use the current price
     * (last price seen) and the price at which the shares were
     * purchased or sold short.
     */
    virtual double get_holdings_profit() const;


protected:

    int quantity_held;
    double current_unit_price;
    double purchase_unit_price;

};

}


#endif
