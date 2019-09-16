/*
 * dealer.cpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std ;
#include "player.hpp"
#include "banker.hpp"
#include "card.hpp"
#include "dealer.hpp"

#define BLACKJACK_MAX 21
Blackjack::Blackjack ( )
{
    _card = new Card ( 1 ) ;
    _card->shuffleCards ( ) ;
}
Blackjack::~Blackjack ( )
{
    delete _card ;
}
int Blackjack::initDealCard ( Player * & player , Banker * & banker )
{
    cout << "玩家第一張牌:" ;
    pair < int , string > card = this->dealCard ( true ) ;
    player->addCards ( card ) ;

    cout << "莊家第一張牌:" ;
    card = this->dealCard ( true ) ;
    banker->addCards ( card ) ;

    cout << "玩家第二張牌:" ;
    card = this->dealCard ( true ) ;
    player->addCards ( card ) ;

    cout << "莊家第二張牌:" ;
    card = this->dealCard ( false ) ;
    banker->addCards ( card ) ;
    return 0 ;
}
pair < int , string > Blackjack::dealCard ( bool show )
{
    pair < int , string > card = _card->dealCard ( ) ;
    if ( show )
    {
        cout << card.first ;
        cout << " " << card.second << endl ;
    }
    else cout << "-" << endl ;
    return card ;
}
bool Blackjack::isBusted ( vector < pair < int , string > > card_vec )
{
    if ( BLACKJACK_MAX < this->calculatePoints ( card_vec ) ) return true ;
    return false ;
}
bool Blackjack::isWin ( vector < pair < int , string > > card_vec )
{
    if ( BLACKJACK_MAX == this->calculatePoints ( card_vec ) ) return true ;
    return false ;
}
float Blackjack::calculatePoints ( vector < pair < int , string > > card_vec )
{
    int n = card_vec.size ( ) ;
    float points = 0 ;
    int ace_n = 0 ;
    for ( int i = 0 ; i < n ; ++ i )
    {
        pair < int , string > one = card_vec [ i ] ;
        switch ( one.first )
        {
            case 1 :
                ++ ace_n ;
                break ;
            case 11 :
            case 12 :
            case 13 :
                points += 10 ;
                break ;
            default :
                points += one.first ;
                break ;
        }
    }
    // 計算若是有 ace 則點數應該要如何分配才會最恰當
    int ace_11_ct = 0 ;
    if ( ace_n )
    {
        int less_points = BLACKJACK_MAX - static_cast < int > ( points ) ;
        for ( ace_11_ct = ace_n ; ace_11_ct > 0 ; -- ace_11_ct )
        {
            if ( 11 * ace_11_ct + ( ace_n - ace_11_ct ) <= less_points ) break ;
        }
    }
    return static_cast < float > ( points + ( ace_11_ct * 11 ) + ( ace_n - ace_11_ct ) ) ;
}
void Blackjack::showEnd ( vector < pair < int , string > > card_vec )
{
    int sz = static_cast < int > ( card_vec.size ( ) ) ;
    cout << "Game<Blackjack>此次點數 : " << this->calculatePoints ( card_vec ) << endl ;
    for ( int i = 0 ; i < sz ; ++ i )
        cout << card_vec [ i ].first << " , " << card_vec [ i ].second << endl ;
    return ;
}

#define TEN_POINT_5_MAX 10.5
TenPoint5::TenPoint5 ( )
{
    _card = new Card ( 1 ) ;
    _card->shuffleCards ( ) ;
}
TenPoint5::~TenPoint5 ( )
{
    delete _card ;
}
int TenPoint5::initDealCard ( Player * & player , Banker * & banker )
{
    cout << "玩家第一張牌:" ;
    pair < int , string > card = this->dealCard ( true ) ;
    player->addCards ( card ) ;

    cout << "莊家第一張牌:" ;
    card = this->dealCard ( false ) ;
    banker->addCards ( card ) ;
    return 0 ;
}
pair < int , string > TenPoint5::dealCard ( bool show )
{
    pair < int , string > card = _card->dealCard ( ) ;
    if ( show )
    {
        cout << card.first ;
        cout << " " << card.second << endl ;
    }
    else cout << "-" << endl ;
    return card ;
}
bool TenPoint5::isBusted ( vector < pair < int , string > > card_vec )
{

    if ( TEN_POINT_5_MAX < this->calculatePoints ( card_vec ) ) return true ;
    return false ;

}
bool TenPoint5::isWin ( vector < pair < int , string > > card_vec )
{
    if ( TEN_POINT_5_MAX == this->calculatePoints ( card_vec ) ) return true ;
    return false ;
}
float TenPoint5::calculatePoints ( vector < pair < int , string > > card_vec )
{
    int n = card_vec.size ( ) ;
    float points = 0 ;
    for ( int i = 0 ; i < n ; ++ i )
    {
        pair < int , string > one = card_vec [ i ] ;
        switch ( one.first )
        {
            case 11 :
            case 12 :
            case 13 :
                points += 0.5 ;
                break ;
            default :
                points += one.first ;
                break ;
        }
    }
    return points ;
}

void TenPoint5::showEnd ( vector < pair < int , string > > card_vec )
{
    int sz = static_cast < int > ( card_vec.size ( ) ) ;
    cout << "Game<TenPoint5>此次點數 : " << this->calculatePoints ( card_vec ) << endl ;
    for ( int i = 0 ; i < sz ; ++ i )
        cout << card_vec [ i ].first << " , " << card_vec [ i ].second << endl ;
    return ;
}
