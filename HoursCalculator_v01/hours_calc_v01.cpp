#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int nItems = 10;
    int itemIndex = 0;
    enum fields
    {
        HOURS,
        MINUTES
    };
    float totalH = 0.0;
    float totalM = 0.0;
    float hRate = 0.0;
    float price = 0.0;
    //ask for user to input number of hours
    std::cout << "Set number of items: \n";
    std::cin >> nItems;

    std::cout << "Please insert Hourly Rate: \n";
    std::cin >> hRate;

    int list[nItems][2];
    std::string labelList[nItems];

    int hours[nItems];
    int mins[nItems];

    //input
    for (int i = 0; i < nItems; ++i)
    {
        int item = i + 1;
        std::cout << "Label for Item #" << item << ": \n";
        std::cin >> labelList[i];

        std::cout << "N of hours: \n";
        std::cin >> hours[i];
        list[i][0] = hours[i];

        std::cout << "N of minutes: \n";
        std::cin >> mins[i];
        list[i][1] = mins[i];
    }
    //calc
    for (int i = 0; i < nItems; i++)
    {
        totalH += list[i][HOURS];
        totalM += list[i][MINUTES];
    }
    //print
    std::cout << "\n\nBudget_____________List\n\n";
    for (int i = 0; i < nItems; i++)
    {
        float taskH = list[i][HOURS];
        float taskM = list[i][MINUTES];
        float taskTM = taskM / 60;
        float taskT = taskH + taskTM;
        float priceTask = taskT * hRate;

        std::cout << labelList[i] << ": \n";
        std::cout << "Hours\t"
                  << "Minutes\t"
                  << "Total\t"
                  << "Price\n";
        std::cout << list[i][HOURS] << "\t" << list[i][MINUTES] << "\t" << taskT << "\t"
                  << "$" << priceTask << "\n\n";
    }
    std::cout << "_____________\n";
    float totalm = totalM / 60;
    float total = totalm + totalH;
    std::cout << "\nTotal Decimal Hours: " << total << std::endl;

    price = hRate * total;
    std::cout << "Final Budget: "
              << "$" << price << std::endl;
    std::cout << "_____________\n\n";

    system("pause");
    return 0;
}
