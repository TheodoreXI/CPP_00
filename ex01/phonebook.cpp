#include "phonebook.hpp"


int parsing(int i, int *index)
{
    std::string s;

    getline(std::cin >> std::ws , s);
    if (s.length() > 1)
    {
        std::cout << "The index can only be from 0 to " << (i-1) << "\n";
        return (1);
    }
    if (!isdigit(s[0]))
    {
        std::cout << "Only numbers are accepted.\n";
        return (1);
    }
    std::cout << "Give me an index of a contact: (0 to " << (i-1) << "): ";
    *index = s[0] - 48;
    if (*index >= i || *index >= 8)
    {
        std::cout << "The index can only be from 0 to " << (i-1) << "\n";
        return (1);
    }
    return (0);
}

int main()
{
    std::string input;
    PhoneBook   phone;
    std::string var;
    int i = 0;
    int j = 0;
    int check = 0;
    int index = 0;
    int limiter = 0;
    while (1)
    {
        std::cout << "Enter one of the three commands: (ADD, SEARCH, EXIT): ";
        getline(std::cin, input);
        if (input == "ADD")
        {
            if (i == 8)
                i = 0;
            while (1)
            {
                std::cout << "Enter your first name: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]) && var[j] != ' ' && var[j] != ' ')
                        check = 1;
                    j++;
                }
                if (check == 0)
                    break;
                std::cout << "Only alphabetical characters.\n";
            }
            if (var.length() > 10)
            {
                var = var.substr(0, 9);
                var += '.';
            }
            phone.contact[i].set_first(var);
            while (1)
            {
                std::cout << "Enter your last name: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]) && var[j] != ' ')
                        check = 1;
                    j++;
                }
                if (check == 0)
                    break;
                std::cout << "Only alphabetical characters.\n";
            }
            if (var.length() > 10)
            {
                var = var.substr(0, 9);
                var += '.';
            }
            phone.contact[i].set_last(var);
            while (1)
            {
                std::cout << "Enter your nickname: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]) && var[j] != ' ')
                        check = 1;
                    j++;
                }
                if (check == 0)
                    break;
                std::cout << "Only alphabetical characters.\n";
            }
            if (var.length() > 10)
            {
                var = var.substr(0, 9);
                var += '.';
            }
            phone.contact[i].set_nick(var);
            while (1)
            {
                std::cout << "Enter your phone number: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isdigit(var[j]))
                        check = 1;
                    j++;
                }
                if (check == 0)
                    break;
                std::cout << "Only numbers are accepted.\n";
            }
            if (var.length() > 10)
            {
                var = var.substr(0, 9);
                var += '.';
            }
            phone.contact[i].set_num(var);
            while (1)
            {
                std::cout << "Enter your darkest secret: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]) && var[j] != ' ')
                        check = 1;
                    j++;
                }
                if (check == 0)
                    break;
                std::cout << "Only alphabetical characters.\n";
            }
            if (var.length() > 10)
            {
                var = var.substr(0, 9);
                var += '.';
            }
            phone.contact[i].set_secret(var);
            if (limiter < 8)
                limiter += 1;
            i++;
        }
        else if (input == "SEARCH")
        {
            if (!limiter)
                std::cout << "Enter a contact first: (ADD)\n";
            else
            {
                j = 0;
                std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "FirstName" << "|"
                << std::setw(10) << "LastName" << "|"
                << std::setw(10) << "NickName\n";
                while (j < limiter)
                {
                    std::cout << std::setw(10) << j << "|"
                    << std::setw(10) << phone.contact[j].get_first() << "|"
                    << std::setw(10) << phone.contact[j].get_last() << "|"
                    << std::setw(10) << phone.contact[j].get_nick() << "\n";
                    j++;
                }
                std::cout << "Give me an index of a contact: (0 to " << (limiter-1) << "): ";//this prints twice
                if (!parsing(limiter, &index))
                {
                    std::cout << std::setw(10) << "Index" << "|"
                    << std::setw(10) << "FirstName" << "|"
                    << std::setw(10) << "LastName" << "|"
                    << std::setw(10) << "NickName" << "|"
                    << std::setw(10) << "Number" << "|"
                    << std::setw(10) << "Secret\n";
                    std::cout << std::setw(10) << index << "|"
                    << std::setw(10) << phone.contact[index].get_first() << "|"
                    << std::setw(10) << phone.contact[index].get_last() << "|"
                    << std::setw(10) << phone.contact[index].get_nick() << "|"
                    << std::setw(10) << phone.contact[index].get_num() << "|"
                    << std::setw(10) << phone.contact[index].get_secret() << "\n";
                }
            }
        }
        else if (input == "EXIT")
        {
            std::cout << "Exiting\n";
            exit(0);
        }
    }
}