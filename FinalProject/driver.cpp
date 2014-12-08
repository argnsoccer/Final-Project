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
            ofstream os;
            os.open("pagesSaver.txt");
            os << pageSaver.size() << endl;
            for(int x = 0; x < pageSaver.size(); ++x)
            {
                papel = pageSaver.at(x);

                os << papel.getPage() << endl;

                os << papel.getText() << '\0';

                os << papel.getTitle() << '\0';
                os << endl;
            }

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
            ifstream is;

            is.open("pagesSaver.txt");
            int pageNum=0;
            is >> pageNum;
            is.get();//gets the '\n'
            buffer = new string[pageNum];
            buffer1 = new string[pageNum];
//            string buffy[50];
//            string buffy1[50];
            if(load == true)
            {
                cout << "Index loading into AVLTree for you. Please Wait." << endl;
                i->load();
                cout << "Loading complete." << endl;


                int p1;

                Pages page;
                char*buf;
                char*buf1;
                int count=0;

                while(is.peek()!= '\n')//loads the Pages
                {

                    is >> p1;
                    page.setPage(p1);
                    is.get();//gets the '\n'
                    getline(is, buffer[count], '\0');
                    buf = const_cast<char*>(buffer[count].c_str());
                    page.setText(buf);
                    getline(is, buffer1[count], '\0');
                    buf1 = const_cast<char*>(buffer1[count].c_str());
                    page.setTitle(buf1);
                    pages.push_back(page);
                    is.get();//gets the '\n'
                    if(is.peek()== -1)
                    {
                        break;
                    }
                    count++;
                }

                is.close();
            }
            cout << "Would you like to enter a query?" << endl;
            cout << "1: Yes\nAny other number to stop searching" << endl;
            cin >> inputCommand;
            if(inputCommand == 1)
            {

                if(load == true)
                {
                    for(int i = 0; i < pages.size(); ++i)
                    {
                        papel = pages.at(i);
                    }
                    q.run(i, pages);
                    pages.clear();
                }
                else
                {
                    q.run(i, pageSaver);
                    pageSaver.clear();
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
