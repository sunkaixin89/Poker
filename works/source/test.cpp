#include"common.h"
#include "ProCalculator.h"
#include<stdio.h>
#include <sys/time.h>
int main(int argc,char *argv[]){
    vector<Poker> myPokers;
    Poker pk;
    pk.point = POINT_10;
    pk.color = COLOR_DIAMONDS;
    myPokers.push_back(pk);
    pk.point = POINT_10;
    pk.color = COLOR_CLUBS;
    myPokers.push_back(pk);

    vector<Poker> commonPokers;
    pk.point = POINT_2;
    pk.color = COLOR_DIAMONDS;
    commonPokers.push_back(pk);
    pk.point = POINT_8;
    pk.color = COLOR_CLUBS;
    commonPokers.push_back(pk);
    pk.point = POINT_5;
    pk.color = COLOR_CLUBS;
    commonPokers.push_back(pk);
    pk.point = POINT_3;
        pk.color = COLOR_CLUBS;
        commonPokers.push_back(pk);
        pk.point = POINT_J;
            pk.color = COLOR_CLUBS;
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
    printf("P:%f\n", ProCalculator::CalProLessThanMe(myPokers, commonPokers, 7));
    gettimeofday(&te, 0);
    printf("time ms:%d\n",(int) ((1000000*(te.tv_sec -  tb.tv_sec) + te.tv_usec - tb.tv_usec)/1000));
    return 0;
}
