/*
 * card.hpp
 *
 *  Created on: 2019年9月4日
 *      Author: jb
 */

#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

class Card
{
        vector < pair < int , string > > _card_vec ;
        int _deal_num ;   // 目前發牌的數量
        int _card_num ;   // 撲克牌的組數
        int _cards_max ;   // 撲克牌的上限數量
        void showAll ( void ) ;
        void showDeal ( void ) ;
        void showNondeal ( void ) ;
    public:
        /**產生牌組數量
         *
         * @param poker_num : 撲克牌組數
         */
        Card ( int card_num ) ;
        void shuffleCards ( void ) ;
        pair < int , string > dealCard ( void ) ;
} ;


#endif /* CARD_HPP_ */
