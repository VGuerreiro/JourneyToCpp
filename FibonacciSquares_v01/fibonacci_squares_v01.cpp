#include <iostream>

int main()
{
    int MAXSIDE_L = 10;
    unsigned int sideL = 0;
    char dot = '*';
    char space = ' ';
    int fi = 1;
    int n1 = 1;
    int n2 = 1;

    std::cout << "Welcome to the Fibonacci Square Creator.\n";
    std::cout << "Please insert the Maximum Length for the Largest Square:\n";
    std::cin >> MAXSIDE_L;

    while (MAXSIDE_L >= 0 && fi < MAXSIDE_L)
    {
        if (fi <= 1)
        {
            std::cout << "SideL: " << fi << std::endl;
            std::cout << dot << std::endl;
            fi++;
        }
        else
        {
            fi = n1 + n2;
            n1 = n2;
            n2 = fi;
            std::cout << "SideL: " << fi << std::endl;
            sideL = fi;
            char square[sideL][sideL];
            for (int i = 0; i < sideL; i++)
            {
                for (int j = 0; j < sideL; j++)
                {
                    square[i][j] = dot;
                    if (i > 0 && i < sideL - 1 && j > 0 && j < sideL - 1)
                    {
                        square[i][j] = space;
                    }
                    std::cout << square[i][j] << space;
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
    if (MAXSIDE_L < 0)
    {
        std::cout << "Please insert only positive values.\n";
    }
    system("pause");
    return 0;
}

