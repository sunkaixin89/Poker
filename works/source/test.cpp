#include"common.h"
#include "ProCalculator.h"
#include<stdio.h>
#include <sys/time.h>
int main(int argc,char *argv[]){
    vector<Poker> myPokers;
    Poker pk;
    pk.point = POINT_10;
    pk.color = 1;
    myPokers.push_back(pk);
    pk.point = POINT_9;
    pk.color = 4;
    myPokers.push_back(pk);

    vector<Poker> commonPokers;
    pk.point = POINT_5;
    pk.color = 2;
    commonPokers.push_back(pk);
    pk.point = POINT_10;
    pk.color = 4;
    commonPokers.push_back(pk);
    pk.point = 12;
    pk.color = 2;
    commonPokers.push_back(pk);
    pk.point = 12;
        pk.color = 4;
        commonPokers.push_back(pk);
        pk.point = 5;
            pk.color = 1;
            commonPokers.push_back(pk);
    /*
    pk.point = POINT_9;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_7;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
   */
    struct timeval  tb;
    struct timeval te;
   gettimeofday(&tb, 0);
    printf("P:%f\n", ProCalculator::CalProLessThanMe(myPokers, commonPokers, 3));
    gettimeofday(&te, 0);
    printf("time ms:%d\n",(int) ((1000000*(te.tv_sec -  tb.tv_sec) + te.tv_usec - tb.tv_usec)/1000));
    return 0;
}
