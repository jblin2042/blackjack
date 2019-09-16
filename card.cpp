/*
 * poker.cpp
 *
 *  Created on: 2019年9月4日
 *      Author: jb
 */

#include <iostream>
#include <vector>
#include <utility>

#include "card.hpp"

extern "C"
{
    #include <stdlib.h>
    #include <time.h>
}
using namespace std ;


Card::Card ( int card_num )
{
    _card_vec.clear ( ) ;
    _deal_num = 0 ;
    _card_num = card_num ;

    string brand_color [ ] = { "黑桃" , "紅心" , "方塊" , "梅花" } ;
    for ( int n = 0 ; n < card_num ; ++ n )
        for ( int i = 0 ; i < 4 ; ++ i )
            for ( int j = 1 ; j < 14 ; ++ j )
                _card_vec.push_back ( make_pair ( j , brand_color [ i ] ) ) ;

    _cards_max = _card_vec.size ( ) ;
}
void Card::shuffleCards ( void )
{
    srand ( clock ( ) ) ;
    int porker_num = static_cast < int > ( _card_vec.size ( ) ) ;
    int shuffle_times = ( rand ( ) % 50000 ) + 100 ;
    int s = 0 ;
    int t = 0 ;

    for ( int i = 0 ; i < shuffle_times ; ++ i )
    {
        s = rand ( ) % porker_num ;
        t = rand ( ) % porker_num ;

        pair < int , string > data = _card_vec [ s ] ;
        _card_vec [ s ] = _card_vec [ t ] ;
        _card_vec [ t ] = data ;
    }
    return ;
}
void Card::showAll ( void )
{
    for ( int i = 0 ; i < static_cast < int > ( _card_vec.size ( ) ) ; ++ i )
    {
        cout << _card_vec [ i ].first ;
        cout << " " << _card_vec [ i ].second << endl ;
    }
    return ;
}
void Card::showDeal ( void )
{
    for ( int i = 0 ; i < _deal_num ; ++ i )
    {
        cout << _card_vec [ i ].first ;
        cout << " " << _card_vec [ i ].second << endl ;
    }
    return ;
}
void Card::showNondeal ( void )
{
    for ( int i = _deal_num ; i < static_cast < int > ( _card_vec.size ( ) ) ; ++ i )
    {
        cout << _card_vec [ i ].first ;
        cout << " " << _card_vec [ i ].second << endl ;
    }
    return ;
}
pair < int , string > Card::dealCard ( void )
{
    return _cards_max <= _deal_num ? make_pair ( 0 , "-" ) : _card_vec [ _deal_num ++ ] ;
}





















//Poker::Poker ( bool ghost_card )
//{
//    string brand_color [ ] = { "黑桃" , "紅心" , "方塊" , "梅花" } ;
//    for ( int i = 0 ; i < 4 ; ++ i )
//        for ( int j = 1 ; j < 14 ; ++ j )
//            _p.push_back ( make_pair ( j , brand_color [ i ] ) ) ;
//
//    if ( ghost_card )
//    {
//        _p.push_back ( make_pair ( 1 , "Joker" ) ) ;
//        _p.push_back ( make_pair ( 2 , "Joker" ) ) ;
//    }
//}

//void Poker::shuffleCards ( void )
//{
//    srand ( clock ( ) ) ;
//    int porker_num = static_cast < int > ( _p.size ( ) );
//    int shuffle_times = ( rand ( ) % 50000 ) + 100 ;
//    int s = 0 ;
//    int t = 0 ;
//
//    for ( int i = 0 ; i < shuffle_times ; ++ i )
//    {
//        s = rand ( ) % porker_num ;
//        t = rand ( ) % porker_num ;
//
//        pair < int , string > data = _p [ s ] ;
//        _p [ s ] = _p [ t ] ;
//        _p [ t ] = data ;
//    }
//    return ;
//}
//void Poker::show ( void )
//{
//    for ( int i = 0 ; i < static_cast < int > ( _p.size ( ) ) ; ++ i )
//    {
//        cout << "" << _p [ i ].first ;
//        cout << " " << _p [ i ].second << endl ;
//    }
//    return ;
//}


int main_card_test ( void )
{
    Card p ( 5 ) ;

//    p.showAll ( ) ;
    p.shuffleCards ( ) ;

    cout << endl << endl ;
//    cout << "ssssssssssssss" << endl ;
//    while ( 1 )
//    {
//        pair < int , string > pp = p.dealCard ( ) ;
//        if ( ! pp.first ) break ;
//        cout << pp.first << " , " << pp.second << endl ;
//    }


    pair < int , string > tmp = p.dealCard ( ) ;
    cout << endl ;
    cout << "1:" << tmp.first << endl ;
    cout << "2:" << tmp.second << endl ;
    cout << endl ;


    return 0 ;
}


























