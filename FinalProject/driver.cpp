#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    bool saver = false;
    while(saver == false)
    {
        cout << "Parse and save a new file or load from file?" << endl;
        cout << "1: Save\n2: Load" << endl;
        cin >> inputCommand;
        if(inputCommand == 1)
        {
            i = new AVLTree(p.parse(fileName));
            cout << "Index has been parsed" << endl;
            i->save();
            saver = true;
        }
        else if(inputCommand == 2)
        {
            i = new AVLTree();
            cout << "You will load from the file." << endl;
            saver = true;
        }
        else
        {
            saver = false;
        }
    }
    bool cleared = false;
    bool looper=false;
    while(looper == false)
    {
        cout << "Which mode would you like to be in? (Please only integer answers)" << endl;
        cout << "1: Maintenance Mode \n2: Interactive Mode\nAny other number to quit" << endl;
        cin >> inputCommand;

        switch(inputCommand)
        {
        //Maintenance Mode
        case 1:
        {
            bool maintLoop = false;
            while(maintLoop == false)
            {
                cout << "What would you like to do in Maintenance Mode?" << endl;
                cout << "1: Clear Index \n2: Append a file\nAny other number to quit" << endl;

                cin >> inputCommand;
                switch(inputCommand)
                {
                case 1:
                    i->clearIndex();
                    cleared = true;
                    break;

                case 2:
                    //i->appendFile();
                    break;

                default:
                    maintLoop = true;
                    break;

                }
            }

            break;
        }

        //Interactive Mode
        case 2:
        {
            cout << "Index loaded into AVLTree for you. Sorry for the lack of variety...and speed." << endl;
            i->load();
            break;
        }

        default:
        {
            looper = true;
            break;
        }

        }
    }

}
