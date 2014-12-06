#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    i = new AVLTree(p.parse(fileName));
    i.save();
    i.load();
    cout << "Which mode would you like to be in? (Please only integer answers)" << endl;
    cout << "1: Maintenance Mode \n 2: Interactive Mode " << endl;
    cin >> inputCommand;
    switch(inputCommand)
    {
        //Maintenance Mode
        case 1:
            i.clearIndex();
            i.appendFile();

        //Interactive Mode
        case 2:

    }

}
