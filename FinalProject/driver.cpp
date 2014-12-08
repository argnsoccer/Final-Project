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
            vector<Pages> pageSaver = p.getPages();
            //code by Peter Alexander http://stackoverflow.com/questions/2469531/reading-and-writing-c-vector-to-a-file
            ofstream os ("pagesSaver.txt", ios::binary);

            int size1 = pageSaver.size();
            os.write((const char*)&size1, 4);
            os.write((const char*)&pageSaver[0], size1 * sizeof(Pages));
            os.close();

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
                //code by Peter Alexander http://stackoverflow.com/questions/2469531/reading-and-writing-c-vector-to-a-file
                ifstream is("pagesSaver.txt", ios::binary);
                int size2;
                is.read((char*)&size2, 4);
                pages.resize(size2);

                     // Is it safe to read a whole array of structures directly into the vector?
                is.read((char*)&pages[0], size2 * sizeof(Pages));
                is.close();
                load = false;
            }
            cout << "Would you like to enter a query?" << endl;
            cout << "1: Yes\nAny other number to stop searching" << endl;
            cin >> inputCommand;
            if(inputCommand == 1)
            {
                cout << "page Size 102319023912: " << pages.size() << endl;
                q.run(i, pages);
            }
            else
            {
                //break;
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
