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
    while (1)
    {
        std::cout << "Enter one of the three commands: (ADD, SEARCH, EXIT): ";
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
            i++;
            if (i == 8)
                i = 0;
        }
        else if (input == "SEARCH")
        {
            if (i == 0)
            {
                std::cout << "Enter a contact first: (ADD)\n";
            }
            else
            {
                j = 0;
                std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "FirstName" << "|"
                << std::setw(10) << "LastName" << "|"
                << std::setw(10) << "NickName\n";
                while (j < i)
                {
                    std::cout << std::setw(10) << j << "|"
                    << std::setw(10) << phone.contact[j].get_first() << "|"
                    << std::setw(10) << phone.contact[j].get_last() << "|"
                    << std::setw(10) << phone.contact[j].get_nick() << "\n";
                    j++; 
                }
                std::cout << "Give me an index of a contact: (0 to " << (i-1) << "): ";
                std::cin >> index; //check if index got a string or a char i have a problem with two prompts
                if (index >= i || index >= 8)
                    std::cout << "The index can only be from 0 to " << (i-1) << "\n";
                else 
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