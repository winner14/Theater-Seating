#include <iostream>
using namespace std;

int main()
{
    system("clear");
    int rowNumber, columNumber; 
    double row[50];

    cout << "Input the number of rows of seat available : ";
    cin >> rowNumber;
    cout << "Input the number of colums of seat in the rows : ";
    cin >> columNumber;

    for (int i = 0; i < rowNumber; i++)
    {
        cout << "Input price of seats at Row " << i + 1 << " : ";
        cin >> row[i];
    }

    int mat[50][50], num = 1;
    for (int i = 0; i < rowNumber; i++)
    {
        cout << "Row " << i + 1 << " == ";
        for (int j = 0; j < columNumber; j++)
        {
            mat[i][j] = num;
            cout << mat[i][j] << " ";
            num++;
        }

        cout << endl;
    }

    int seatNumber, count = 0;
    double price = 0;

    do
    {
        do
        {
            cout << endl
                 << "Input the seat number you wish to purchase : ";
            cin >> seatNumber;
        } while (seatNumber < 0 && seatNumber >= (rowNumber * columNumber) && seatNumber == 0);

        for (int i = 0; i < rowNumber; i++)
        {
            cout << "Row " << i + 1 << " == ";
            for (int j = 0; j < columNumber; j++)
            {
                if (mat[i][j] == seatNumber)
                {
                    price += row[i];
                    mat[i][j] = 0;
                    count += 1;
                }
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl
             << "Total amount of tickets purchased == Ghs" << price << endl;
    } while (count < (rowNumber * columNumber));

    return 0;
}