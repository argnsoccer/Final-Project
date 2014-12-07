#include "driver.h"

Driver::Driver(char *fileName)
{
    int inputCommand;
    bool saver = false;
    bool load = true;
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
            load = false;
        }
        else if(inputCommand == 2)
        {
            i = new AVLTree();
            cout << "You will load from the file." << endl;
            saver = true;
        }
        else
        {
            cout << "You entered an incorrect command. Please try again." << endl;
            saver = false;
        }
    }
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
            if(load == true)
            {
                cout << "Index loading into AVLTree for you. Please Wait." << endl;
                i->load();
                cout << "Loading complete." << endl;
            }

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
