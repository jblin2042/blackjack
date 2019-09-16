/*
 * player.cpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */
#include <vector>
#include <iostream>
#include <utility>
using namespace std ;
#include "player.hpp"
void Player::showAllCard ( void )
{
    for ( int i = 0 ; i < static_cast < int > ( _owned_card.size ( ) ) ; ++ i )
    {
        cout << "" << _owned_card [ i ].first ;
        cout << " " << _owned_card [ i ].second << " , " ;
    }
    cout << endl ;
    return ;
}
void Player::addCards ( pair < int , string > card )
{
    _owned_card.push_back ( card ) ;
    return ;
}
const vector < pair < int , string > > & Player::getAllCard ( void )
{
    return _owned_card ;
}
bool Player::askDealCard ( void )
{
    string ask_str ( "" ) ;
    cout << "是否繼續<y>:" ;
    cin >> ask_str ;
    if ( ask_str == "y" ) return true ;
    return false ;
}

void Player::clearOwnedCard ( void )
{
    _owned_card.clear ( ) ;
    return ;
}
