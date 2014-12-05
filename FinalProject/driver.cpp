#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    i = p.parse(fileName);
    cout << "Which mode would you like to be in? (Please only integer answers)" << endl;
    cout << "1: Maintenance Mode \n 2: Interactive Mode " << endl;
    cin >> inputCommand;
    switch(inputCommand)
    {
        //Maintenance Mode
        case 1:


            i.save();

        //Interactive Mode
        case 2:

            i.append();
    }

}
