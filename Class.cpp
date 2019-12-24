// Array-based List Class for Playlists
// Max Luttrell CS 110C
//
// Chris Cruz
//
//


#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE=100;
    ItemType *list;
    int numItems;
    int maxItems;
public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE]; }
    ~List() { delete [] list; }
    
    // list member functions
    bool isEmpty()  const { return numItems==0; }
    int getLength() const { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }
    
    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;
    
    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd;
    canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));

    //Dynamically allocates more memory if array already full
    if((pos > 0) && (numItems < maxItems))
    {
        ItemType *newData;
        newData = new ItemType[CHUNK_SIZE * 2]; //Double the size of old array
        for (int i = 0; i < numItems; i++)
        {
            newData[i] = list[i];
        }
        delete [] list;
        list = newData;
        newData = NULL;
    }

    if (canAdd)
    {
        // first, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // position 1.
        for(int i=numItems; i>=pos; i--)
            list[i] = list[i-1];
        
        // now put our item at position pos-1
        list[pos-1] = item;

        numItems++;
    }
    
    return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if(pos < 1 || pos > getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}

//This function overwrites items in your array. Doesn't allocate more memory
template<class ItemType> 
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
    if(pos < 1 || pos > getLength()) //Don't need List.getLength()
    {
        throw logic_error("Position out of bounds!");
    }
    else
    {
        list[pos - 1] = item; //list has to be LOWERCASE. The template ptr is list
    }
}

/*
Inefficient function
template<class ItemType> //Need to declare this, and the namespace resolution operator
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
    if(pos < 1 || pos > List.getLength()) //Get length returns the actual length of the array
    {
        throw logic_error("Position out of bounds!");
    }
    bool success = List.remove(pos);
    if(success)
    {
        List.insert(pos, item);
    }
}  
*/

template<class ItemType> 
bool List<ItemType>::remove(int pos)
{
    if(pos < 1 || pos > getLength()) //Don't need List.getLength()
    {
        throw logic_error("Position out of bounds!");
    }
    else
    {
        //Want pos - 1 because pos (the parameter) is not in array notation.
        //pos is in ADT format
        for(int i = pos - 1; i < (getLength() - 1); i++) //getLength - 1 so doesn't go out of array
        {
            list[i] = list[i+1];
        }
        numItems--;
        return true;
    }
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
    bool inputCheck;
    int trackNumber;
    
    do
    {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}


int main()
{
    List<string> songs;
    char goAgain = 'y';
    int trackNumber;
    string trackName;
    
    // Insert some songs into our list
    songs.insert(1, "One More Saturday Night");
    songs.insert(1, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(1, "California Love");
    
    cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
    while (goAgain!='n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    //My extra code to test the new functions
    cout << "Enter the track number to overwrite: ";
    cin >> trackNumber;
    cout << "Enter the new track name: ";
    cin >> trackName;
    try
    {
        songs.setEntry(trackNumber, trackName);
    }
    catch(logic_error)
    {
        cout << "Out of bounds! Try again." << endl;
    }
    
    //Running this again to test if it overwrites.
    cout << "The tracklist has been updated" << endl;
    goAgain = 'y';
    while (goAgain!='n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    cout << "Enter a track number to remove: ";
    cin >> trackNumber;
    try
    {
        songs.remove(trackNumber);
    }
    catch(logic_error)
    {
        cout << "Error: Out of bounds!" << endl;
    }
    
    //Running this again to test if remove works.
    cout << "The tracklist has been updated" << endl;
    goAgain = 'y';
    while (goAgain!='n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    cout << "Enter where to put the new track: ";
    cin >> trackNumber;
    cout << "Enter the new track name: ";
    cin >> trackName;

    songs.insert(trackNumber, trackName);
    
    //Running to see if insert works
    cout << "The tracklist has been updated" << endl;
    goAgain = 'y';
    while (goAgain!='n')
    {
        trackNumber = getTrack();
        try
        {
            trackName = songs.getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    cout << "Rock on!\n";

    return 0;
}

/*
Sample output:
[ccruz9@hills CS110C]$ ./a.out
Welcome!  There are 4 tracks.
Please enter the track number you'd like to view: 1
Your track name is California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is Friday I'm in Love
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is One More Saturday Night
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is Sunday Morning Coming Down
Go again? (y/n) n
Enter the track number to overwrite: 2
Enter the new track name: ChangeItUp
The tracklist has been updated
Please enter the track number you'd like to view: 1
Your track name is California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is ChangeItUp
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is One More Saturday Night
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is Sunday Morning Coming Down
Go again? (y/n) n
Enter a track number to remove: 2
The tracklist has been updated
Please enter the track number you'd like to view: 1
Your track name is California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is One More Saturday Night
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is Sunday Morning Coming Down
Go again? (y/n) y
Please enter the track number you'd like to view: 4
ERROR: getEntry() using invalid position
Your track name is No Track
Go again? (y/n) n
Enter where to put the new track: 2
Enter the new track name: BackAgain
The tracklist has been updated
Please enter the track number you'd like to view: 1
Your track name is California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is BackAgain
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is One More Saturday Night
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is Sunday Morning Coming Down
Go again? (y/n) n
Rock on!
*/