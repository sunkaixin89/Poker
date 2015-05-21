#include "common.h"
#include <algorithm>
#include <map>
#include <stdio.h>
bool more_hold( Poker poker1,  Poker poker2){
    return poker1.point <= poker2.point;
}

int pokerType(vector<Poker> &pokers,int &highpt){
    if(pokers.size() != 5) return 0;
    //sort
    sort(pokers.begin(),pokers.end(),more_hold);
    map<int,int> pts;
    int flush = 1;
    int stright = 1;
    for(int i = 0;i < pokers.size();i++){
        if(!pts.count(pokers[i].point)){
            pts[pokers[i].point] = 1;
        }else{
            pts[pokers[i].point]++;
        }

        if(i > 0
        && pokers[i].color == pokers[i-1].color){
            flush++;
        }       
        
        if(i > 0
        && pokers[i].point == pokers[i-1].point+1){
            stright++;
        }

    }

    if(flush == 5 && stright == 5){
        highpt = pokers[pokers.size()-1].point;
        return POKER_STRAIGHT_FLUSH;
    }else if(flush == 5){
        highpt = pokers[pokers.size()-1].point;
        return POKER_FLUSH;
    }else if(stright == 5){
        highpt = pokers[pokers.size()-1].point;
        return POKER_STRAIGHT;
    }else{
        map<int,int>::iterator it = pts.begin(); 
        int three = 0; 
        int two = 0; int twopt = 0;
        while(it != pts.end()){
            if(it->second == 4){
                highpt = it->first;
                return POKER_FOUR_OF_A_KIND;
            } else if(it->second == 3){
                three = 1;
                highpt = it->first;
            }else if(it->second == 2){
                two++;
                highpt = it->first;
                twopt = (twopt > it->second) ? twopt : it->second;
            }
            it++;
        }

        if(three > 0 && two >0){
            return POKER_FULL_HOUSE;
        }else if(two == 2){
            return POKER_TWO_PAIR;
        }else if(three > 0){
            return POKER_THREE_OF_A_KIND;
        }else if(two == 1){
            return POKER_ONE_PAIR;
        }else{
            highpt = pokers[pokers.size()-1].point;  
            return POKER_HIGH_CARD;
        }
    }
}

int emumPokers(vector<Poker> &pokers,
               vector<vector<Poker> > &poker_types,
               vector<Poker> &current,
               int idx,
               int num){
    if(num == 5) {
        poker_types.push_back(current);
        return 1;
    }else if(idx == pokers.size()){
        return 1;
    }
    
   current.push_back(pokers[idx]);
   emumPokers(pokers,poker_types,current,idx+1,num+1);
   current.pop_back();
   emumPokers(pokers,poker_types,current,idx+1,num);
   return 1;
}

int pokerTypeAll(vector<Poker> &pokers,int &highpt){
    vector<vector<Poker> > poker_types;
    vector<Poker> pk;
    emumPokers(pokers,poker_types,pk,0,0);

    
    int chpt,maxtype = 0;
    for(int i = 0;i < poker_types.size();i++)
    {
        int ptype= pokerType(poker_types[i],chpt);
        if(ptype > maxtype){
            maxtype = ptype;
            highpt = chpt;
        }else if(ptype == maxtype){
            highpt = chpt;
        }   
       /* 
        for(int j = 0;j < 5;j++){
            printf("%d&%d ",poker_types[i][j].point,poker_types[i][j].color);
        }
    
        printf("\n");*/
    }
    return maxtype;
}
