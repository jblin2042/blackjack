/*
 * player.hpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include <iostream>
#include <utility>
using namespace std ;

class Player
{
        vector < pair < int , string > > _owned_card ;
    public:
        void addCards ( pair < int , string > card ) ;
        const vector < pair < int , string > > & getAllCard ( void ) ;
        bool askDealCard ( void ) ;
        void clearOwnedCard ( void ) ;
        void showAllCard ( void ) ;
} ;

#endif /* PLAYER_HPP_ */
