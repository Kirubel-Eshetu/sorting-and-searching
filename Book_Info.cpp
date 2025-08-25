// Sorting and Searching of Book information here we go!

#include <iostream>
#include <string.h >
using namespace std;

struct student
{
    int id;
    char name[20];
    int age;
};

void enterData(struct student list[100], int n)
{
    int i;
    cout << "--------------------------------------------------------------------" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "    Enter ID of student: ";
        cin >> list[i].id;
        cout << "    Enter NAME of student: ";
        cin >> list[i].name;
        cout << "    Enter AGE of student: ";
        cin >> list[i].age;
        cout << "----------------------------------------------------------------" << endl;
    }

    if (i == n)
        cout << "\n***********You entered " << n << " student data successfully*************";
}

void displayData(struct student list[100], int n)
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t  ID...........Name...........Age" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ".\t" << list[i].id << "..............." << list[i].name << "............." << list[i].age << endl;
    }
}

void bubbleSort(struct student list[100], int n)
{
    int i, j;
    struct student temp;

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - 1 - i; j++)
        {

            if (list[j].id > list[j + 1].id)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void insertionSort(struct student list[100], int n)
{
    int k, j;
    struct student temp;
    for (k = 1; k < n; k++)
    {
        temp = list[k];
        j = k - 1;
        while (strcmp(list[j].name, temp.name) > 0 && j >= 0)
        {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = temp;
    }
}

void selectionSort(struct student list[100], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (list[j].age < list[min].age)
            {
                min = j;
            }
        }
        if (min != i)
        {
            struct student temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }
    }
}

void linearSearch(struct student list[100], int n)
{
    int i, num, arrTemp[100], j = 0, chk = 0;
    cout << "\nEnter the student AGE to Search: ";
    cin >> num;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "\t  ID...........Name...........Age" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (i = 0; i < n; i++)
    {
        if (list[i].age == num)
        {
            arrTemp[j] = i;
            j++;
            chk = 1;
            cout << i + 1 << ".\t" << list[i].id << "............." << list[i].name << "............." << list[i].age << " " << endl;
        }
    }
    if (chk > 0)
    {
    }
    else
    {
        cout << "\t Student age: '" << num << " 'does not found!!!!" << endl;
    }
}

void binarySearch(struct student list[100], int n)
{
    int k, lower, upper, middle;
    char search[80];
    cout << "\n Enter the NAME of student you want to search: ";
    cin >> search;
    lower = 0;
    upper = n - 1;
    middle = (upper + lower) / 2;
    while (lower <= upper)
    {
        if (strcmp(list[middle].name, search) < 0)
            lower = middle + 1;
        else if (strcmp(list[middle].name, search) == 0)
        {
            cout << "--------------------------------------------------------------------------------------------------" << endl;
            cout << "\t  ID  ...........  Name  ...........  Age" << endl;
            cout << "--------------------------------------------------------------------------------------------------" << endl;
            cout << "\n\t  " << list[middle].id << "  ...........  " << list[middle].name << "  ...........  " << list[middle].age << endl;
            break;
        }
        else
            upper = middle - 1;
        middle = (lower + upper) / 2;
    }
    if (lower > upper)
        cout << "\nStudent '" << search << "' is Not found in the list \n";
}

void Deletion(struct student list[100], int n)
{
    int i, elem, j, f, found = 0;
    cout << "\nEnter ID to Delete: ";
    cin >> elem;
    for (i = 0; i < n; i++)
    {
        if (list[i].id == elem)
        {
            for (j = i; j < (n - 1); j++)
                list[j] = list[j + 1];
            found = 1;
            i--;
            n--;
        }
    }
    if (found == 0)
        cout << "\n ID doesn't found in the list!";
    else
    {
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "\t  ID...........Name...........Age" << endl;
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "1.\t" << list[i].id << "..............." << list[i].name << "............." << list[i].age << endl;
        }
        cout << "\n**************List Deleted Successfully!********************";
        cout << endl;
    }
}
int main()
{
    char ch;
    int i, n;
    struct student data[100];
    cout << "\tHello! everyone welcome to SORTING and SEARCHING \n\t\tstudent data project" << endl;
    system("color 5e");
    system("cls");
Top:
    cout << "\n\n***************************************************************" << endl;
    cout << "********************** PLEASE SELECT TASKS ********************" << endl;
    cout << "\t 1. Please enter number #1 to Enter data" << endl;
    cout << "\t 2. Please enter number #2 to Display data" << endl;
    cout << "\t 3. Please enter number #3 to Bubble sort by ID" << endl;
    cout << "\t 4. Please enter number #4 to Insertion Sort by NAME" << endl;
    cout << "\t 5. Please enter number #5 to Selection Sort BY AGE" << endl;
    cout << "\t 6. Please enter number #6 to Linear Search by AGE" << endl;
    cout << "\t 7. Please enter number #7 to Binary Search by NAME" << endl;
    cout << "\t 8. Please enter number #8 to Delete " << endl;
    cout << "\t 9. About Us /GROUP NAME/" << endl;
    cout << "\t 0. Exit" << endl;
    cout << "***************************************************************" << endl;
    cin >> ch;
    switch (ch)
    {
    case '1':
        system("cls");
        system("color 4e");
        cout << "\n************************************************************";
        cout << "\n************************************************************\n";
        cout << "\tPlease enter the size of data: ";
        cin >> n;
        enterData(data, n);
        break;
        
    case '2':
        system("cls");
        system("color 5e");
        displayData(data, n);
        break;

    case '3':
        system("cls");
        system("color 2e");
        bubbleSort(data, n);
        displayData(data, n);
        break;

    case '5':
        system("cls");
        system("color 6e");
        selectionSort(data, n);
        displayData(data, n);
        break;

    case '4':
        system("cls");
        system("color 4e");
        insertionSort(data, n);
        displayData(data, n);
        break;

    case '6':
        system("cls");
        system("color 4b");
        linearSearch(data, n);
        break;

    case '7':
        system("cls");
        system("color 2e");
        binarySearch(data, n);
        break;

    case '8':
        system("cls");
        system("color 5e");
        Deletion(data, n);
        break;

    case '9':
        system("cls");
        system("color 5e");
        cout << "\n*****************************************************************************************" << endl;
        cout << "*\n*\t\t-----------Jimma Institute of Technology -----------                    *" << endl;
        cout << "*\n*\t\t--------Faculty of Computing and Informatics--------                    *" << endl;
        cout << "*\n*\t\t------------COMPUTER SCIENCE DEPARTMENT-------------                    *" << endl;
        cout << "*\n*\t\t------- DATA STRUCTURE AND ALGORITHM PROJECT--------                    *" << endl;
        cout << "*\n*\t\t   Year(Semester):2(II)   Section: 2   Group: II                        *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "* \t\t ..NAME.. \t\t\t\t\t\t ..ID..         *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 1. Abdulkerim Faisal........................................RU5330/12          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 2. Ayantu  Neguse...........................................RU2171/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 3. Geremu  Kafo.............................................RU2549/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 4. Kirubel Belayneh.........................................RU0057/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 5. Kirubel Eshetu...........................................RU0114/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*\t 6. Zelalem Kabtamu..........................................RU0050/13          *" << endl;
        cout << "*                                                                                       *" << endl;
        cout << "*****************************************************************************************" << endl;
        break;

    case '0':
        system("cls");
        system("color 3f");
        cout << "\n************************************************************";
        cout << "\n**********Thanks For Watching***********";
        cout << "\n***********Exit successfully************\n\n";
        cout << "\a\a\a\a\a\a\a";
        exit(0);

    default:
        system("cls");
        cout << "\n************************************************************";
        cout << "\n************INCORRECT TASK Please select from(0-9)**********";
        cout << "\n!!!!!!!!!!!!!!-- Try Again--!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        cout << "\a\a\a\a\a\a\a";
    }
    goto Top;
}
