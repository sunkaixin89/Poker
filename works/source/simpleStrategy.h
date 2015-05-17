#include "strategy.h"
#include "common.h"
#include <algorithm>

/*
 *SimpleStrategy
 *focus only holds
 *crerate by skx
 *2015/5/17
 * */
class SimpleStrategy : public strategy{
public:
    string action();
    static const int TOP_LEVEL = 0;
    static const int HIGH_LEVEL = 1;
    static const int MID_LEVEL = 2;
    static const int BUTTOM_LEVEL = 3;
private:
    int holdType();
};
