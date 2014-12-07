#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    i = new AVLTree(p.parse(fileName));
    cout << "Index has been parsed" << endl;
    i->save();
    cout << "Which mode would you like to be in? (Please only integer answers)" << endl;
    cout << "1: Maintenance Mode \n2: Interactive Mode " << endl;
    cin >> inputCommand;
    switch(inputCommand)
    {
        //Maintenance Mode
        case 1:
            cout << "What would you like to do in Maintenance Mode?" << endl;
            cout << "1: Clear Index \n2: Append a file" << endl;
            cin >> inputCommand;
            switch(inputCommand)
            {
            case 1:
                i->clearIndex();
                break;

            case 2:
                //i->appendFile();
                break;

            }

            //i->clearIndex();
            //i->appendFile();
            break;

        //Interactive Mode
        case 2:
            cout << "Index loaded into AVLTree for you. Sorry for the lack of variety...and speed." << endl;
            i->load();


            break;

    }

}
