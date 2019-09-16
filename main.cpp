/*
 * main.cpp
 *
 *  Created on: 2019年9月16日
 *      Author: jb
 */

#include <iostream>
using namespace std ;
extern "C"
{
#include <unistd.h>
}
#include "dealer.hpp"
#include "player.hpp"
#include "banker.hpp"
int main ( void )
{

    Dealer * dealer = NULL ;
    Player * player = new Player ( ) ;
    Banker * banker = NULL ;
    cout << "選擇遊戲 <1:Blackjack> , <other:10點半>:" ;
    string s ( "" ) ;
    cin >> s ;
    if ( s == "1" )
    {
        cout << "選擇遊戲:Blackjack" << endl ;
        dealer = new Blackjack ( ) ;
        banker = new Banker ( true ) ;
    }
    else
    {
        cout << "選擇遊戲:10點半" << endl ;
        dealer = new TenPoint5 ( ) ;
        banker = new Banker ( false ) ;
    }

    string dummy_str ( "" ) ;
    while ( true )
    {
        cout << endl << "玩家遊戲開始<1:繼續> , <other:結束>:" ;
        cin >> dummy_str ;
        if ( dummy_str != "1" )
        {
            cout << "遊戲結束" << endl ;
            break ;
        }

        player->clearOwnedCard ( ) ;
        banker->clearOwnedCard ( ) ;

        bool banker_busted = false ;
        bool player_busted = false ;
        dealer->initDealCard ( player , banker ) ;

        // 玩家
        while ( true )
        {
            // 是否滿足此次最大值
            player->showAllCard ( ) ;
            if ( dealer->isWin ( player->getAllCard ( ) ) )
            {
                cout << "Max" << endl ;
                sleep ( 2 ) ;
                break ;
            }

            // 詢問玩家是否需要牌 //
            if ( player->askDealCard ( ) ) player->addCards ( dealer->dealCard ( true ) ) ;
            else break ;

            // 確認是否爆炸 //
            player_busted = dealer->isBusted ( player->getAllCard ( ) ) ;
            if ( player_busted )
            {
                cout << "玩家爆點" << endl ;
                sleep ( 2 ) ;
                break ;
            }
        }
        cout << "玩家:" << endl ;
        dealer->showEnd ( player->getAllCard ( ) ) ;
        cout << endl ;

        // 玩家爆炸 ,遊戲直接重來
        if ( player_busted )
        {
            cout << "莊家:" << endl ;
            dealer->showEnd ( banker->getAllCard ( ) ) ;
            cout << endl ;
            cout << "***** 莊家贏 *****" << endl ;
            continue ;
        }

        float player_points = dealer->calculatePoints ( player->getAllCard ( ) ) ;
        // 莊家
        while ( true )
        {
            cout << endl << "換莊家" << endl ;
            sleep ( 2 ) ;
            banker->showAllCard ( ) ;
            // 是否滿足此次最大值
            if ( dealer->isWin ( banker->getAllCard ( ) ) )
            {
                cout << "Max" << endl ;
                sleep ( 2 ) ;
                break ;
            }

            // 詢問玩家是否需要牌 //
            if ( banker->askDealCard ( player_points , dealer->calculatePoints ( banker->getAllCard ( ) ) ) ) banker->addCards ( dealer->dealCard ( true ) ) ;
            else break ;

            // 確認是否爆炸 //
            banker_busted = dealer->isBusted ( banker->getAllCard ( ) ) ;
            if ( banker_busted )
            {
                cout << "莊家爆點" << endl ;
                sleep ( 2 ) ;
                break ;
            }
        }
        cout << "莊家:" << endl ;
        dealer->showEnd ( banker->getAllCard ( ) ) ;
        cout << endl ;

        if ( banker_busted )
        {
            cout << "***** 玩家贏 *****" << endl ;
            continue ;
        }

        float banker_points = dealer->calculatePoints ( banker->getAllCard ( ) ) ;
        if ( player_points == banker_points ) cout << "***** 平手 *****" << endl ;
        else if ( player_points > banker_points ) cout << "***** 玩家贏 *****" << endl ;
        else cout << "***** 莊家:贏 *****" << endl ;
    }

    delete dealer ;
    dealer = NULL ;

    delete player ;
    player = NULL ;

    delete banker ;
    banker = NULL ;
    return 0 ;
}
