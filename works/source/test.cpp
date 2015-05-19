#include"common.h"
#include<stdio.h>

int main(int argc,char *argv[]){
    vector<Poker> pokers;
    Poker pk;
    pk.point = POINT_A;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_K;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_Q;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk); 
    pk.point = POINT_J;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_10;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_9;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
    pk.point = POINT_7;
    pk.color = COLOR_CLUBS;
    pokers.push_back(pk);
   
    int point = 0;
    int type = pokerTypeAll(pokers,point);
    printf("%d %d",point,type);
    return 0;
}
