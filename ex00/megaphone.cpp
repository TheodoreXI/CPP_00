#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (islower(argv[i][j]))
                argv[i][j] -= 32;
            j++;
        }
        std::cout << argv[i];
        i++;
    }
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}
