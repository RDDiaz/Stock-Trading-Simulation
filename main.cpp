#include "simulator.h"
#include "price_bar.h"
#include "trading_strategy.h"
#include "trade.h"
#include "blsh_strategy.h"
#include "prof_strategy.h"
#include <string>
#include <algorithm>
#include <vector>
#include <istream>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace csis3700;
using namespace std;

int main()
{
    double start_cash = 100;
    string file_name = "aapl.dat";
    ifstream in(file_name);

    blsh_strategy ps;
    ps.set_buy_count(start_cash * 0.01);
    trading_strategy *TS = &ps;


    simulator S(TS, start_cash);

    S.read_bars(in);

    S.run();

    cout << "Data file: " << file_name << endl
         << "Start date: " << (S.get_bars().begin())->get_time() << endl
         << "End date: " << (S.get_bars().rbegin())->get_time() << endl
         << "Bars: " << S.get_bars().size() << endl
         << "Trades: " << S.get_trades().size() << endl
         << "Initial equity: " << start_cash << endl
         << "Final equity: " << S.get_equity() << endl
         << "Percent profit: " << (S.get_equity() - start_cash) / start_cash * 100 << '%' << endl
         << "\n\n\n\n************************";

    in.close();


    return 0;
}
