#include "phonebook.hpp"


int main()
{
    std::string input;
    PhoneBook   phone;
    std::string var;
    int i = 0;
    int j = 0;
    int check = 0;
    int index = 0;
    while (i < 8)
    {
        getline(std::cin, input);
        if (input == "ADD")
        {
            while (1)
            {
                std::cout << "Enter your first name: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]))
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
                var[10] = '.';
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
                    if (!isalpha(var[j]))
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
                var[10] = '.';
            }
            phone.contact[i].set_last(var);
            while (1)
            {
                std::cout << "Enter your nickname name: ";
                getline(std::cin >> std::ws, var);
                check = 0;
                j = 0;
                while (var[j])
                {
                    if (!isalpha(var[j]))
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
                var[10] = '.';
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
                var[10] = '.';
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
                    if (!isalpha(var[j]))
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
                var[10] = '.';
            }
            phone.contact[i].set_num(var);
        }
        else if (input == "SEARCH")
        {
            j = 0;
            std::cout << std::setw(10) << "Index:" << "|"
            << std::setw(10) << "FirstName:" << "|"
            << std::setw(10) << "LastName:" << "|"
            << std::setw(10) << "NickName:\n";
            while (j <= i)
            {
                std::cout << std::setw(10) << j << "|"
                << std::setw(10) << phone.contact[j].get_first() << "|"
                << std::setw(10) << phone.contact[j].get_last() << "|"
                << std::setw(10) << phone.contact[j].get_nick() << "\n";
                j++; 
            }
            

        }
        else if (input == "EXIT")
        {
            exit(0);
        }
        i++;
        if (i == 8)
            i = 0;
    }
}