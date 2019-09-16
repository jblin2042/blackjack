/*
 * banker.cpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */
#include <vector>
#include <iostream>
#include <utility>
using namespace std ;
#include "banker.hpp"
Banker::Banker ( bool is_black_jack )
{
    _is_black_jack = is_black_jack ;
}
void Banker::showAllCard ( void )
{
    for ( int i = 0 ; i < static_cast < int > ( _owned_card.size ( ) ) ; ++ i )
    {
        cout << "" << _owned_card [ i ].first ;
        cout << " " << _owned_card [ i ].second << endl ;
    }
    return ;
}
void Banker::addCards ( pair < int , string > card )
{
    _owned_card.push_back ( card ) ;
    return ;
}
const vector < pair < int , string > > & Banker::getAllCard ( void )
{
    return _owned_card ;
}
bool Banker::askDealCard ( float player_points , float self_points )
{
    return player_points >= self_points ? true : false ;
}

void Banker::clearOwnedCard ( void )
{
    _owned_card.clear ( ) ;
    return ;
}
