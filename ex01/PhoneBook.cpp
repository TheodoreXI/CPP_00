#include "PhoneBook.hpp"

int parsing(int i, int *index)
{
    std::string s;
    int j = 0;

    if (!getline(std::cin >> std::ws , s))
    {
        std::cout << std::endl;
        exit (1);
    }
    while (s[j+1] && s[j] == '0')
        j++;
    s = &s[j];
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
    *index = s[0] - 48;
    if (*index >= i || *index >= 8)
    {
        std::cout << "The index can only be from 0 to " << (i-1) << "\n";
        return (1);
    }
    return (0);
}

int ft_check_string(std::string var, int check)
{
    int j = 0;
    if (check == 1)
    {
        while (var[j])
        {
            if (!isalpha(var[j]) && var[j] != ' ')
                return (1);
            j++;
        }
    }
    else if (check == 2)
    {
        while (var[j])
        {
            if (!isdigit(var[j]))
                return (1);
            j++;
        }
    }
    return (0);
}

std::string    ft_fill_var(std::string prompt, int check, int *error)
{
    std::string var;

    if (check == 1)
    {
        while (1)
        {
            std::cout << prompt;
            if (!getline(std::cin >> std::ws, var))
            {
                std::cout << std::endl;
                *error = 1;
                break ;
            }
            if (ft_check_string(var, 1))
                std::cout << "Only alphabetical characters.\n";
            else
                break ;
        }
    }
    else if (check == 2)
    {
        while (1)
        {
            std::cout << "Enter your phone number: ";
            if (!getline(std::cin >> std::ws, var))
            {
                std::cout << std::endl;
                *error = 1;
                break ;
            }
            if (ft_check_string(var, 2))
                std::cout << "Only numbers are accepted.\n";
            else
                break ;
        }
    }
    return (var);
}

void    ft_print(PhoneBook &phone, int index)
{
    std::cout << "Index: " << index << "\n";
    std::cout << "FirstName: " << phone.contact[index].get_first() << "\n";
    std::cout << "LastName: " << phone.contact[index].get_last() << "\n";
    std::cout << "NickName: " << phone.contact[index].get_nick() << "\n";
    std::cout << "Number: " << phone.contact[index].get_num() << "\n";
    std::cout << "Secret: " << phone.contact[index].get_secret() << "\n";
}

int main()
{
    std::string input;
    PhoneBook   phone;
    std::string var;
    int error = 0;
    int i = 0;
    int j = 0;
    int index = 0;
    int limiter = 0;
    while (1)
    {
        std::cout << "Enter one of the three commands: (ADD, SEARCH, EXIT): ";
        if (!getline(std::cin, input))
        {
            std::cout << std::endl;
            break ;
        }
        if (input == "ADD")
        {
            if (i == 8)
                i = 0;
            var = ft_fill_var("Enter your first name: ", 1, &error);
            if (error)
                return (1);
            phone.contact[i].set_first(var);
            var = ft_fill_var("Enter your last name: ", 1, &error);
            if (error)
                return (1);
            phone.contact[i].set_last(var);
            var = ft_fill_var("Enter your nickname: ", 1, &error);
            if (error)
                return (1);
            phone.contact[i].set_nick(var);
            var = ft_fill_var("Enter your phone number: ", 2, &error);
            if (error)
                return (1);
            phone.contact[i].set_num(var);
            var = ft_fill_var("Enter your darkest secret: ", 1, &error);
            if (error)
                return (1);
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
                << std::setw(10) << "NickName" << "|\n";
                while (j < limiter)
                {
                    std::cout << std::setw(10) << j << "|";
                    if (phone.contact[j].get_first().length() > 10)
                        std::cout << std::setw(10) << phone.contact[j].get_first().substr(0,9) + '.' << "|";
                    else
                        std::cout << std::setw(10) << phone.contact[j].get_first() << "|";
                    if (phone.contact[j].get_last().length() > 10)
                        std::cout << std::setw(10) << phone.contact[j].get_last().substr(0,9) + '.' << "|";
                    else
                        std::cout << std::setw(10) << phone.contact[j].get_last() << "|";
                    if (phone.contact[j].get_nick().length() > 10)
                        std::cout << std::setw(10) << phone.contact[j].get_nick().substr(0,9) + '.' << "|" << "\n";
                    else
                        std::cout << std::setw(10) << phone.contact[j].get_nick() << "|" << "\n";
                    j++;
                }
                std::cout << "Give me an index of a contact: (0 to " << (limiter-1) << "): ";
                if (!parsing(limiter, &index))
                    ft_print(phone, index);
            }
        }
        else if (input == "EXIT")
        {
            std::cout << "Exiting\n";
            exit(0);
        }
    }
}