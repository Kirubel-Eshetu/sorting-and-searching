// Sorting of Movie Information using Linked List

#include <iostream>
#include <string.h>
using namespace std;
class movie_info
{
private:
    char movie_name[80];
    char movie_id[50];
    char movie_year[50];
    movie_info *next;

public:
    void addMovieAtStart();
    void addMovieAtEnd();
    void AddMovieAtSpecificPosition(int pos);
    void PrintMovie();
    void DeleteMovieAtStart();
    void DeleteMovieAtEnd();
    void DeleteMovieAtSpecificPosition(int z);
    movie_info *head = NULL, *current;
};

void movie_info::addMovieAtStart()
{
    system("CLS");
    current = new movie_info;
    cin.ignore();
    cout << "\n Please enter the movie name: ";
    cin.getline(current->movie_name, 50);
    cout << " Please enter the movie id: ";
    cin >> current->movie_id;
    cout << " Please enter year of the movie produced: ";
    cin >> current->movie_year;

    if (head == NULL)
    {
        head = current;
        current->next = NULL;
    }
    else
    {
        current->next = head;
        head = current;
    }
    cout << "\n Movie information was added at the start successfully!.";
}

void movie_info::addMovieAtEnd()
{
    system("CLS");
    movie_info *temp;
    movie_info *temp2;

    temp2 = new movie_info;
    cout << "\n Please enter movie name: ";
    cin >> temp2->movie_name;
    cout << " Please enter the movie id: ";
    cin >> temp2->movie_id;
    cout << " Please enter year of the movie produced: ";
    cin >> temp2->movie_year;
    temp2->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp2;
    }
}
void movie_info::AddMovieAtSpecificPosition(int pos)
{
    system("CLS");

    if (head != NULL)
    {
        movie_info *pre = new movie_info;
        movie_info *cur = new movie_info;
        movie_info *temp = new movie_info;
        cur = head;

        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        cout << "\n Please enter a movie name: ";
        cin >> temp->movie_name;
        cout << " Please enter the movie id: ";
        cin >> temp->movie_id;
        cout << " Please enter year of the movie produced: ";
        cin >> temp->movie_year;
        pre->next = temp;
        temp->next = cur;
    }
}

void movie_info::PrintMovie()
{
    system("CLS");
    int count = 0;
    if (head == NULL)
    {
        cout << "Unfourtunately, no movie was found :(\n";
    }
    else
    {
        current = head;
        cout << "\n"
             << "No.\tmovie name\tmovie id\tmovie year";
        cout << "\n----------------------------------------------------------------------------";
        while (current != NULL)
        {

            count++;
            cout << "\n"
                 << count << " \t ";
            cout << current->movie_name << " \t\t ";
            cout << current->movie_id << " \t\t ";
            cout << current->movie_year << " \t ";
            current = current->next;
        }
    }
}
void movie_info::DeleteMovieAtStart()
{
    system("CLS");
    current = head;
    if (current == NULL)
    {
        cout << "";
    }
    else
    {

        head = head->next;
        delete current;
    }
}
void movie_info::DeleteMovieAtEnd()
{
    system("CLS");
    movie_info *temp, *temp2;
    temp = head;

    if (head == NULL)
    {
        cout << "";
    }
    else if (temp->next == NULL)
    {
        head = NULL;
        delete temp;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        delete temp;
        temp2->next = NULL;
    }
}
void movie_info::DeleteMovieAtSpecificPosition(int z)
{
    system("cls");
    movie_info *temp;
    temp = head;
    if (head != NULL)
    {
        movie_info *pre, *current;
        current = head;
        for (int i = 1; i < z; i++)
        {
            pre = current;
            current = current->next;
        }
        pre->next = current->next;
        delete current;
        cout << "Data was deleted successfully.\n";
    }
    else
    {
        cout << "\n There seems to be noo data to delete\n";
    }
}

int main()
{
    movie_info M;
    char op;

menu:
    cout << "********************************************";
    cout << "\n Press 1 to add movie at the start";
    cout << "\n Press 2 to add movie at the end";
    cout << "\n Press 3 to add movie at a specific position";
    cout << "\n Press 4 to delete movie from the start";
    cout << "\n Press 5 to delete movie at the end";
    cout << "\n Press 6 to delete movie from a specific position";
    cout << "\n Press 7 to see team members";
    cout << "\n Press 0 to exit";

    cout << "\n\n Please select a task: ";
    cin >> op;
    switch (op)
    {
    case '1':
        system("color 2e");
        M.addMovieAtStart();
        M.PrintMovie();
        break;

    case '2':
        system("color 4e");
        M.addMovieAtEnd();
        M.PrintMovie();
        break;

    case '3':
        system("color 5e");
        int loc1;
        cout << "\n Please enter position: ";
        cin >> loc1;
        M.AddMovieAtSpecificPosition(loc1);
        M.PrintMovie();
        break;

    case '4':
        system("color 4b");
        M.DeleteMovieAtStart();
        M.PrintMovie();
        break;

    case '5':
        system("color 2e");
        M.DeleteMovieAtEnd();
        M.PrintMovie();
        break;

    case '6':
        system("color 5e");
        int loc;
        cout << " Please enter position: ";
        cin >> loc;
        M.DeleteMovieAtSpecificPosition(loc);
        M.PrintMovie();
        break;

    case '7':
        system("cls");
        system("color 2e");
        cout << "\n*****************************************************************************************" << endl;
        cout << "*\n*\t\t-----------Jimma Institute of Technology -----------                    *" << endl;
        cout << "*\n*\t\t--------Faculty of Computing and Informatics--------                    *" << endl;
        cout << "*\n*\t\t------------COMPUTER SCIENCE DEPARTMENT-------------                    *" << endl;
        cout << "*\n*\t\t------- DATA STRUCTURE AND ALGORITHM PROJECT--------                    *" << endl;
        cout << "*\n*\t\t   Year(Semester):2(II)   Section: 2   Group: II                        *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "* \t\t NAME \t\t\t\t\t\t  ID                    *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 1. Abdulkerim Faisal.......................................RU5330/12           *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 2. Ayantu  Neguse...........................................RU2171/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 3. Geremu  Kafo.............................................RU2549/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 4. Kirubel Belayneh........................................RU0057/13           *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 5. Kirubel Eshetu..........................................RU0114/13           *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 6. Zelalem Kabtamu.........................................RU0050/13           *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*****************************************************************************************" << endl;
        break;

    case '0':
        system("CLS");
        cout << "\n***********Exit successfully************\n";
        exit(0);
        
    default:
        system("cls");
        cout << "\n\n!!!!!!!!!!!!!!--Please Try Again--!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        cout << "\n************INCORRECT TASK Please select from(0-7)**********\n\n";
    }
    goto menu;

    return 1;
}
