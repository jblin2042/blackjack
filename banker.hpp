/*
 * banker.hpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */

#ifndef BANKER_HPP_
#define BANKER_HPP_

#include <vector>
#include <iostream>
#include <utility>
using namespace std ;

class Banker
{
        bool _is_black_jack ;
        vector < pair < int , string > > _owned_card ;
    public:
        Banker ( bool is_black_jack ) ;
        void addCards ( pair < int , string > card ) ;
        const vector < pair < int , string > > & getAllCard ( void ) ;
        bool askDealCard ( float player_points , float self_points ) ;
        void showAllCard ( void ) ;
        void clearOwnedCard ( void ) ;
} ;


#endif /* BANKER_HPP_ */
