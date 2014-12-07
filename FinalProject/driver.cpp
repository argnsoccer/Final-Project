#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    i = new AVLTree(p.parse(fileName));
    cout << "Index has been parsed" << endl;
    cout << "github modifications.";
    i->save();
    cout << "Which mode would you like to be in? (Please only integer answers)" << endl;
    cout << "1: Maintenance Mode \n2: Interactive Mode " << endl;
    cin >> inputCommand;
    switch(inputCommand)
    {
        //Maintenance Mode
        case 1:
            //i->clearIndex();
            //i->appendFile();
            break;

        //Interactive Mode
        case 2:
            i->load();

            break;

    }

}
