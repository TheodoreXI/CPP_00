#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string m_first;
        std::string m_last;
        std::string m_nick;
        std::string m_num;
        std::string m_secret;
    public:
        void    set_first(std::string first)
        {
            m_first = first;
        }
        void    set_last(std::string last)
        {
            m_last = last;
        } 
        void    set_nick(std::string nick)
        {
            m_nick = nick;
        }
        void    set_num(std::string num)
        {
            m_num = num;
        }
        void    set_secret(std::string secret)
        {
            m_secret = secret;
        }
        std::string get_first(void)
        {
            return (m_first);
        }
        std::string get_last(void)
        {
            return (m_last);
        }
        std::string get_nick(void)
        {
            return (m_nick);
        }
        std::string get_num(void)
        {
            return (m_num);
        }
        std::string get_secret(void)
        {
            return (m_secret);
        }
};

class PhoneBook
{
    public:
        Contact contact[8];
};