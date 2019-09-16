/*
 * dealer.hpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */

#ifndef DEALER_HPP_
#define DEALER_HPP_

#include <iostream>
#include <vector>
#include <utility>
using namespace std ;
#include "player.hpp"
#include "banker.hpp"
#include "card.hpp"

#define interface  struct
#define implements public
#define extends    public
#define abstract

interface Dealer
{
    virtual ~Dealer ( ) { }
    virtual int initDealCard ( Player * &player , Banker * &banker ) = 0 ;
    virtual pair < int , string > dealCard ( bool show ) = 0 ;
    virtual bool isBusted ( vector < pair < int , string > > card_vec ) = 0 ;
    virtual bool isWin ( vector < pair < int , string > > card_vec ) = 0 ;
    virtual float calculatePoints ( vector < pair < int , string > > card_vec ) = 0 ;
    virtual void showEnd ( vector < pair < int , string > > card_vec ) = 0 ;
} ;

class Blackjack : implements Dealer
{
        Card * _card ;
    public:
        Blackjack ( ) ;
        ~Blackjack ( ) ;
        int initDealCard ( Player * &player , Banker * &banker ) ;
        pair < int , string > dealCard ( bool show ) ;
        bool isBusted ( vector < pair < int , string > > card_vec ) ;
        bool isWin ( vector < pair < int , string > > card_vec ) ;
        float calculatePoints ( vector < pair < int , string > > card_vec ) ;
        void showEnd ( vector < pair < int , string > > card_vec ) ;
} ;

class TenPoint5 : implements Dealer
{
        Card * _card ;
    public:
        TenPoint5 ( ) ;
        ~TenPoint5 ( ) ;
        int initDealCard ( Player * &player , Banker * &banker ) ;
        pair < int , string > dealCard ( bool show ) ;
        bool isBusted ( vector < pair < int , string > > card_vec ) ;
        bool isWin ( vector < pair < int , string > > card_vec ) ;
        float calculatePoints ( vector < pair < int , string > > card_vec ) ;
        void showEnd ( vector < pair < int , string > > card_vec ) ;

} ;
#endif /* DEALER_HPP_ */
