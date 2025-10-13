#include "Account.hpp"


// void Account::displayAccountsInfos( void )
// {
//     std::cout << "index:" << 
// }

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

Account::Account( int initial_deposit )
{
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += _amount;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
    _nbAccounts++;
}

void Account::displayAccountsInfos(void)
{
    int num_account = Account::getNbAccounts();
    int total = Account::getTotalAmount();
    int num_dep = Account::getNbDeposits();
    int num_draw = Account::getNbWithdrawals();
    std::cout << "accounts:" << num_account << ";total:" << total
                << ";deposits:" << num_dep << ";withdrawals:" << num_draw << "\n";
}

void    Account::makeDeposit(int deposit)
{
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit
                << ";amount:" << (_amount + deposit) << ";nb_deposits:" << ++_nbDeposits << "\n";
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused\n";
        return (false);
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:"
                << (_amount - withdrawal) << ";nb_withdrawals:" << ++_nbWithdrawals << "\n";
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    return (true);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

Account::~Account( void )
{
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

// void    displayStatus(void)