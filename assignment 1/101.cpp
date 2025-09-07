#include <iostream>
using namespace std;
const int m = 100;
int arr[m];
int n = 0;
void create()
{

    cout << "ENTER THE NUMBER OF ELEMENTS IN THE ARRAY:";
    cin >> n;
    cout << endl;
    cout << "ENTER THE ELEMENTS OF THE ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << endl;
    }
}
void display()
{

    cout << "The elements of the array are";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return;
}
void insert()
{
    int pos;
    cout << "ENTER AT THE POSTION TO ADD THE ELEMENT";
    cin >> pos;
    cout << endl;
    if (pos >= 0 && pos <= n)
    {
        cout << "INVALID POSTION\n";
    }
    int num;
    cout << "ENTER THE NUMBER TO BE ADDED";
    cin >> num;
    cout << endl;
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    n++;
    return;
}
void deleteElement()
{
    int pos;
    cout << "enter the psotion to delete";
    cin >> pos;
    cout << endl;
    if (pos >= n || pos < 0)
    {
        cout << "INVALID POSITION\n";
        return;
    }
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "ELEMENT DELTED";
    return;
}
int searchelement()
{
    int search;
    cout << "ENTER THE ELEMENT TO SEARCH";
    cin >> search;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            cout << "Element found at:" << i << endl;
            break;
        }
    }
    cout << "Element not found.\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            searchelement();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}