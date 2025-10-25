#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    std::string s;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
            s.append(argv[i]);
        for (size_t i = 0; i < s.length(); i++)
        {
            if (std::islower(s[i]))
                s[i] = std::toupper(s[i]);
        }
        std::cout << s;
    }
    std::cout << std::endl;
}

