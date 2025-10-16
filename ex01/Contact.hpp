#ifndef CONTACT_HPP
#define CONTACT_HPP

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
        void    set_first(std::string first);
        void    set_last(std::string last);
        void    set_nick(std::string nick);
        void    set_num(std::string num);
        void    set_secret(std::string secret);
        std::string get_first(void);
        std::string get_last(void);
        std::string get_nick(void);
        std::string get_num(void);
        std::string get_secret(void);
};

#endif