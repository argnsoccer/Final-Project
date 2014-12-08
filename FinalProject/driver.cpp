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
            pageSaver = p.getPages();
            Pages papel;
            //code by Peter Alexander http://stackoverflow.com/questions/2469531/reading-and-writing-c-vector-to-a-file
            ofstream os;
            os.open("pagesSaver.txt");

            for(int x = 0; x < pageSaver.size(); ++x)
            {
                papel = pageSaver.at(x);
                cout << papel.getPage() << endl;
                os << papel.getPage() << endl;
                cout << papel.getText() << '\0';
                os << papel.getText() << '\0';
                cout << papel.getTitle() << '\0';
                os << papel.getTitle() << '\0';
            }

            os.close();

//            int size1 = pageSaver.size();
//            os.write((const char*)&size1, 4);
//            os.write((const char*)&pageSaver[0], size1 * sizeof(Pages));
//            os.close();

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
                ifstream is;
                Pages papel;
                is.open("pagesSaver.txt");
                int p1;
                char* buffer;
                while(!is.eof())
                {
                    is >> p1;
                    papel.setPage(p1);
                    is.get();//gets the '\n'
                    is.getline(buffer, '\0');
                    papel.setText(buffer);
                    is.getline(buffer, '\0');
                    papel.setTitle(buffer);
                    pages.push_back(papel);
                }



//                int size2;
//                is.read((char*)&size2, 4);
//                pages.resize(size2);

//                is.read((char*)&pages[0], size2 * sizeof(Pages));
                is.close();
            }
            cout << "Would you like to enter a query?" << endl;
            cout << "1: Yes\nAny other number to stop searching" << endl;
            cin >> inputCommand;
            if(inputCommand == 1)
            {

                if(load == true)
                {
                    Pages temp;
                    cout << "page Size1: " << pages.size() << endl;
                    for(int i = 0; i < pages.size(); ++i)
                    {
                        temp = pages.at(i);
                        cout << "Page: " << temp.getPage() << endl;
                        //cout << "Title: " << temp.getTitle() << endl;
                    }
                    q.run(i, pages);
                }
                else
                {
                    cout << "page Size2: " << pageSaver.size() << endl;
                    q.run(i, pageSaver);
                }
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
