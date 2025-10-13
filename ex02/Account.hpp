// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <iostream> //check if it should change

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );
	//accounts:8;total:20049;deposits:0;withdrawals:0

	Account( int initial_deposit );
	//[19920104_091532] index:0;amount:42;created
	~Account( void );
// [19920104_091532] index:1;amount:785;closed

	void	makeDeposit( int deposit );
	//index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	bool	makeWithdrawal( int withdrawal );
	//index:5;p_amount:23;withdrawal:refused
	int		checkAmount( void ) const;
	//gett _amount
	void	displayStatus( void ) const;
	//index:0;amount:47;deposits:1;withdrawals:0


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
