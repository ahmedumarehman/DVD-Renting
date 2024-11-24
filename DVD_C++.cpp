
/*

Name : Ahmed Umar & Zainab Kayani
Roll No : i221580 & i227424
Section ' A '





*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DVDtype
{
public:
    string movie_title;
    string movie_stars;
    string moive_director;
    string production_company;
    int number_copies_in_store;

    // default constructor

    DVDtype()
    {
    }
    // parameter constructor

    DVDtype(string title, string stars, string director, string production, int no_copies) : movie_title(title),
                                                                                             movie_stars(stars), moive_director(director), production_company(production), number_copies_in_store(no_copies)
    {
    }

    // display information

    void print_information_DVD()
    {
        cout << "\n\n\t\tDVD INFORMATION\n\n";
        cout << "Movie Name         : " << this->movie_title << endl;
        cout << "Movie Stars        : " << this->movie_stars << endl;
        cout << "Movie Director     : " << this->moive_director << endl;
        cout << "Production Company : " << this->production_company << endl;
        cout << "No. Of Copies      : " << this->number_copies_in_store << endl;

        return;
    }

    // for printing only titles of DVD
    void print_title()
    {

        cout << "Movie Name : " << this->movie_title << endl;
    }

    // for printing onlly number of copies
    void print_totalnocopies()
    {
        cout << "Movie Name : "
             << " ' " << movie_title << " '\t\t ";
        cout << " Total Number of Copies : "
             << " ' " << number_copies_in_store << " ' " << endl;
    }

    // using operator overloading for displaying information
    // in file
    friend ostream &operator<<(ostream &print, DVDtype &other)
    {
        print << "Movie Name              : " << other.movie_title << endl;
        print << "Movie Stars             : " << other.movie_stars << endl;
        print << "Movie Director          : " << other.moive_director << endl;
        print << "Production Company      : " << other.production_company << endl;
        print << "No. of copies           : " << other.number_copies_in_store << endl;

        return print;
    }

    void operator--() // for decrementing number of copies
    {
        number_copies_in_store--;
    }

    void operator++() // for incrementing number of copies
    {
        number_copies_in_store++;
    }
};

class customertype
{
private:
    string first_name;
    string last_name;
    int account_number;
    int total_DVD_rented;

public:
    // default constructor
    customertype()
    {
    }

    // parameter constructor
    customertype(string fn, string ln, int an, int Dvd) : first_name(fn), last_name(ln),
                                                          account_number(an), total_DVD_rented(Dvd)
    {
    }

    //.... for input istream operator asking information about
    // customer

    friend istream &operator>>(istream &ask, customertype &other)
    {
        cout << "Enter First Name           : ";
        ask >> other.first_name;

        cout << "Enter Last Name            : ";
        ask >> other.last_name;

        cout << "Enter Account Number       : ";
        ask >> other.account_number;

        cout << "Enter Number Of Dvd Rented : ";
        ask >> other.total_DVD_rented;

        return ask;
    }

    friend ostream &operator<<(ostream &print, customertype &other)
    {
        print << "\n\n\t\tCUSTOMER INFORMATION\n\n";
        print << "First Name              : " << other.first_name << endl;
        print << "Last Name               : " << other.last_name << endl;
        print << "Account Number          : " << other.account_number << endl;
        print << "Number of DVD's rented  : " << other.total_DVD_rented << endl;

        return print;
    }
};

class node
{
public:
    DVDtype dvd_ka_data; // DVD information
    node *next_node;     // for next node

    // default constructor
    node()
    {
        next_node = NULL;
    }
};

class container
{

private:
    node *head; // making head in linkedlist
    node *tail; // making Tail in linkedlist

public:
    // default constructor
    container()
    {
        head = NULL;
        tail = NULL;
    }

    //.. function to insert data into node

    void insert_data(DVDtype DVD_data)
    {
        // making a new node to insert data of DVD

        node *newnode = new node();

        // shifting data to new node

        newnode->dvd_ka_data = DVD_data;

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next_node = newnode;
            tail = newnode;
        }
    }

    void print()
    {
        // making current node

        node *current_node = head;

        // traverse the list throughout node

        while (current_node != NULL)
        {
            current_node->dvd_ka_data.print_information_DVD();
            current_node = current_node->next_node;
        }
    }

    // check function for checkin (return DVD)

    bool checkinDVD(string DVD_name)
    {
        // node *previous_node = NULL;
        node *current_node = head;

        // checking if the list is empty

        if (current_node == NULL)
        {
            return false;
        }

        while (current_node != NULL)
        {

            if (current_node->dvd_ka_data.movie_title == DVD_name)
            {
                return true;
            }

            current_node = current_node->next_node;
        }

        return false;
    }

    // bool function to check wether if DVD is available or not
    bool isDVDavailable(string DVD_name)
    {
        node *current_node = head;

        while (current_node != NULL)
        {
            if (current_node->dvd_ka_data.movie_title == DVD_name)
            {
                if (current_node->dvd_ka_data.number_copies_in_store > 0)
                {
                    return true;
                }
            }
            current_node = current_node->next_node; // the node will traverse the list
        }

        return false;
    }

    // function to print number of copies of DVD
    void print_nocopies()
    {
        node *current_node = head;
        while (current_node != NULL)
        {
            if (current_node->dvd_ka_data.number_copies_in_store)
            {
                current_node->dvd_ka_data.print_totalnocopies();
            }
            current_node = current_node->next_node; // move to next node
        }
    }
};

int main()
{

    cout << "\t\tWELCOME TO FAST DVD STORE\n\n";

    cout << "First fill the information \n\n";

    // making DVD_list objects and giving it's details
    DVDtype action_movie_1("MAFIA", "Tom", "Nolan", "WR", 654);
    DVDtype action_movie_2("SPIDERMAN", "Tobey", "Webb", "Marvels", 4456);
    DVDtype horror_movie_1("IT", "Khan", "Sarim", "SR8", 25);
    DVDtype horror_movie_2("MAMA", "Rabia", "Ahmed", "PPO99", 8);

    // inserting data into nodes

    container l1;                   // making linkedlist object
    l1.insert_data(action_movie_1); // inserting data in node
    l1.insert_data(action_movie_2); // inserting data in node
    l1.insert_data(horror_movie_1); // inserting data in node
    l1.insert_data(horror_movie_2); // inserting data in node

    customertype information_1; // making customer objects
    cin >> information_1;       // input operator overloading
    cout << information_1;      // output operator overloading

    int options;

    /*NOTE: i have done implementation through nested if-else condition
    because it was showing me errors in switch case*/

    do
    {

        cout << "\t\tWELCOME TO FAST DVD STORE\n\n";
        cout << "[1]. Check out(Rent a DVD)\n";
        cout << "[2]. Check in DVD(Return a DVD)\n";
        cout << "[3]. Check if DVD is in Stock\n";
        cout << "[4]. Print only titles of DVD\n";
        cout << "[5]. Print the list of all DVD\n";
        cout << "[6]. Exit\n";

        cout << "Choose Option Wisely (1-6) : ";
        cin >> options;

        /*-------------------------------------------------------------------------------------------------------------------------------*/

        if (options == 1) // for check out DVD // rent a dvd

        {
            int rent_options;

            cout << "[1]. Action\n[2]. Horror\nSelect the option wisely(1-2) : ";
            cin >> rent_options;

            if (rent_options == 1) // for choosing action movies
            {

                int option_action;
                cout << "\n\n\t\tACTION MOVIES LIST\n\n";

                container l1; // making linkedlist

                l1.insert_data(action_movie_1); // inserting data into node
                l1.insert_data(action_movie_2); // inserting data into node

                l1.print(); // print function of nodes

                cout << "\n\n[1]. MAFIA\n[2]. SPIDERMAN\n";
                cout << "\nEnter option wisely (1-2) :";
                cin >> option_action;

                if (option_action == 1) // for MAFIA
                {
                    fstream new_movie_file_action_1; // making files and strong information
                    new_movie_file_action_1.open("information.txt", ios::out);
                    new_movie_file_action_1 << information_1 << endl; // displaying information of customer

                    --action_movie_1; // decrementing number of copies
                    new_movie_file_action_1 << "\t\tDVD INFORMATION\n\n";
                    new_movie_file_action_1 << action_movie_1 << endl;
                    cout << "Your rented movie and information has been stored ! ! ! " << endl;
                    new_movie_file_action_1.close();
                }

                else
                {
                    fstream new_movie_file_action_2;
                    new_movie_file_action_2.open("information.txt", ios::out);
                    new_movie_file_action_2 << information_1 << endl; // displaying information of customer

                    --action_movie_2;

                    new_movie_file_action_2 << "\t\tDVD INFORMATION\n\n";
                    new_movie_file_action_2 << action_movie_2 << endl;
                    cout << "Your rented movie and information has been stored ! ! ! " << endl;
                    new_movie_file_action_2.close();
                }
            }

            else // HORROR section DVD list
            {

                int option_horror;
                cout << "\n\n\t\tHORROR MOVIES LIST\n\n";

                container l1; // making linkedlist object

                l1.insert_data(horror_movie_1); // inserting data in node
                l1.insert_data(horror_movie_2); // inserting data in node

                l1.print(); // printing data through node

                cout << "\n\n[1]. IT\n[2]. MAMA\n";
                cout << "\nEnter option wisely (1-2) :";
                cin >> option_horror;

                if (option_horror == 1) // for IT movie section
                {
                    fstream new_movie_file_horror_1;
                    new_movie_file_horror_1.open("information.txt", ios::out);
                    new_movie_file_horror_1 << information_1 << endl; // displaying information of customer

                    --horror_movie_1; // decrementing number of copies
                    new_movie_file_horror_1 << "\t\tDVD INFORMATION\n\n";
                    new_movie_file_horror_1 << horror_movie_1 << endl;
                    cout << "Your rented movie and information has been stored ! ! ! " << endl;
                    new_movie_file_horror_1.close();
                }

                else // MAMA Section
                {
                    fstream new_movie_file_horror_2;
                    new_movie_file_horror_2.open("information.txt", ios::out);
                    new_movie_file_horror_2 << information_1 << endl; // displaying information of customer

                    --horror_movie_2; // decrementing number of copies
                    new_movie_file_horror_2 << "\t\tDVD INFORMATION\n\n";
                    new_movie_file_horror_2 << horror_movie_2 << endl;
                    cout << "Your rented movie and information has been stored ! ! ! " << endl;
                    new_movie_file_horror_2.close();
                }
            }
        }

        else if (options == 2) // for check in ( return a DVD)
        {
            string movie_name_for_return;

            cout << "Enter moive which you want to return : ";
            cin >> movie_name_for_return;

            if (l1.checkinDVD(movie_name_for_return))
            {
                cout << "Your DVD has successfully returned back ! ! !\n\n\n ";

                if (movie_name_for_return == "MAFIA")
                {
                    fstream returnDVDfile;
                    returnDVDfile.open("ReturnDVD_information.txt", ios::out);
                    returnDVDfile << information_1 << endl; // customer's information
                    ++action_movie_1;
                    returnDVDfile << "\t\tDVD INFORMATION\n\n";
                    returnDVDfile << action_movie_1;
                    cout << "\n\nAlso, it has been saved into file\n\n";
                    returnDVDfile.close();
                }

                else if (movie_name_for_return == "SPIDERMAN")
                {
                    fstream returnDVDfile;
                    returnDVDfile.open("ReturnDVD_information.txt", ios::out);
                    returnDVDfile << information_1 << endl; // customer's information
                    ++action_movie_2;
                    returnDVDfile << "\t\tDVD INFORMATION\n\n";
                    returnDVDfile << action_movie_2;
                    cout << "\n\nAlso, it has been saved into file\n\n";
                    returnDVDfile.close();
                }

                else if (movie_name_for_return == "IT")
                {
                    fstream returnDVDfile;
                    returnDVDfile.open("ReturnDVD_information.txt", ios::out);
                    returnDVDfile << information_1 << endl; // customer's information
                    ++horror_movie_1;
                    returnDVDfile << "\t\tDVD INFORMATION\n\n";
                    returnDVDfile << horror_movie_1;
                    cout << "\n\nAlso, it has been saved into file\n\n";
                    returnDVDfile.close();
                }

                if (movie_name_for_return == "MAMA")
                {
                    fstream returnDVDfile;
                    returnDVDfile.open("ReturnDVD_information.txt", ios::out);
                    returnDVDfile << information_1 << endl; // customer's information
                    ++horror_movie_2;
                    returnDVDfile << "\t\tDVD INFORMATION\n\n";
                    returnDVDfile << horror_movie_2;
                    cout << "\n\nAlso, it has been saved into file\n\n";
                    returnDVDfile.close();
                }
            }

            else
            {
                cout << "I am sorry, but there is no " << movie_name_for_return << "  in our store ! ! ! \n\n";
            }
        }

        else if (options == 3) //  check if DVD is in stock or not
        {

            string DVD;

            cout << "Enter movie name : ";
            cin >> DVD;

            if (l1.isDVDavailable(DVD)) // l1 is container
            {
                cout << "Yes, it is available and has copies ! ! !\n\n\n";

                char option_y_n;

                cout << "Do you want to see copies of this DVD? (y/n) : ";
                cin >> option_y_n;

                if (option_y_n == 'y' || option_y_n == 'Y')
                {
                    l1.print_nocopies();
                }
            }

            else
            {
                cout << "No it is not available. Sorry ! ! !\n\n\n";
            }
        }

        else if (options == 4) // print only titles of dvd
        {
            cout << "\n\n\t\tACTION CATEGORY\n\n";
            action_movie_1.print_title();
            action_movie_2.print_title();
            cout << "\n\n\t\tHORROR CATEGORY\n\n";
            horror_movie_1.print_title();
            horror_movie_2.print_title();
        }

        else if (options == 5) // print the list of DVDs
        {

            container L1;

            L1.insert_data(action_movie_1);
            L1.insert_data(action_movie_2);
            L1.insert_data(horror_movie_1);
            L1.insert_data(horror_movie_2);

            cout << "\n\n\t\tLIST'S OF DVD\n\n";

            L1.print();
        }

        else
        {
        }

        // end of switch case

    } while (options != 6);

    cout << "Thank You. Visit Again !!!" << endl;
}