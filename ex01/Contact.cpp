#include "Contact.hpp"

void    Contact::set_first(std::string first)
{
    m_first = first;
}
void    Contact::set_last(std::string last)
{
    m_last = last;
} 
void    Contact::set_nick(std::string nick)
{
    m_nick = nick;
}
void    Contact::set_num(std::string num)
{
    m_num = num;
}
void    Contact::set_secret(std::string secret)
{
    m_secret = secret;
}
std::string Contact::get_first(void)
{
    return (m_first);
}
std::string Contact::get_last(void)
{
    return (m_last);
}
std::string Contact::get_nick(void)
{
    return (m_nick);
}
std::string Contact::get_num(void)
{
    return (m_num);
}
std::string Contact::get_secret(void)
{
    return (m_secret);
}