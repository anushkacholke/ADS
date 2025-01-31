#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class MusicTrack {
public:
    string title;
    string artist;
    string album;
    string genre;
    int duration; // in seconds
    int releaseYear;
    MusicTrack* next; // Pointer to the next track in the circular linked list

    MusicTrack(string t, string ar, string al, string gn, int du, int re)
    {
        title = t;
        artist = ar;
        album = al;
        genre = gn;
        duration = du;
        releaseYear = re;
        next = NULL;
    }
};
    void addTrack(MusicTrack* &head) {
    MusicTrack* temp = NULL;
    bool flag = true;
    char ans;
    do {
        string title, artist, album, genre;
        int duration, releaseYear;
        
        cout << "\nEnter title: ";
        cin>>title;
        cout << "Enter artist: ";
        cin>>artist;
        cout << "Enter album: ";
        cin>>album;
        cout << "Enter genre: ";
        cin>>genre;
        cout << "Enter duration (in seconds): ";
        cin >> duration;
        cout << "Enter release year: ";
        cin >> releaseYear;

        MusicTrack* new_track = new MusicTrack(title, artist, album, genre, duration, releaseYear);
        if (new_track == NULL) {
            cout << "\nMemory allocation failed\n";
            return;
        }

        if (flag==true) {
            head = new_track;
            new_track->next = head;
            flag = false;
        } 
        else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_track;
            new_track->next = head;
        }
        cout << "\nDo you want to continue (y/n)? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    cout << "\nCircular linked list of music tracks created\n";
}

void addTrackAt_head(MusicTrack* &head, string t, string ar, string al, string gn, int du, int re) {
    MusicTrack* new_track = new MusicTrack(t, ar, al, gn, du, re);
    if (head == NULL) {
        new_track->next = new_track;
        head = new_track;
    } else {
        MusicTrack* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_track;
        new_track->next = head;
        head = new_track;
    }
}
void deleteAtHead(MusicTrack* &head)
{
    MusicTrack* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    MusicTrack* toDelete=head;
    temp->next=head->next;
    head=head->next;
    delete toDelete;
}
void deletion(MusicTrack* &head)
{
    int pos;
    /*cout<<"\nEnter position which we want to delete: ";
    cin>>pos;
    if(pos==1)
    {
        deleteAtHead(head);
    }*/
    MusicTrack* temp=head;
    int count = 1;
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    MusicTrack* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    cout<<"\nDeleted successfully";
}
bool search(MusicTrack* head)
{
    string title;
    cout<<"\nEnter title to search: ";
    cin>>title;
    if (head == NULL)
    {
        cout<<"\nEmpty list, so the title cannot be found ";
        return false; 
    }

    MusicTrack* temp = head;
    do {
        if (temp->title == title)
        {
            cout<<"\nTitle is found ";
            return true; // Title found
        }
        temp = temp->next;
    } while (temp != head);
    cout<<"\nTitle not found ";
    return false; 
}

void update(MusicTrack* head) 
{
    string key_title;
    cout<<"\nEnter the title which is to be updated: ";
    cin>>key_title;
    if (head == NULL) 
    {
        cout << "\nList is empty\n";
        return;
    }

    MusicTrack* temp = head;
    do {
        if (temp->title == key_title)
        {
            //enter new info for the music track
            string newTitle, newArtist, newAlbum, newGenre;
            int newDuration, newReleaseYear;
            
            cout << "Enter new title: ";
            cin>>newTitle;
            cout << "Enter new artist: ";
            cin>>newArtist;
            cout << "Enter new album: ";
            cin>>newAlbum;
            cout << "Enter new genre: ";
            cin>>newGenre;
            cout << "Enter new duration (in seconds): ";
            cin >> newDuration;
            cout << "Enter new release year: ";
            cin >> newReleaseYear;

            // Update the info of the music track
            temp->title = newTitle;
            temp->artist = newArtist;
            temp->album = newAlbum;
            temp->genre = newGenre;
            temp->duration = newDuration;
            temp->releaseYear = newReleaseYear;

            cout << "\nMusic track updated successfully\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    // If the track with the given title is not found
    cout << "\nMusic track with title '" << key_title << "' not found\n";
}

void display(MusicTrack* head)
{
    MusicTrack* temp = head;
    if (temp == NULL) {
        cout << "\nList is empty";
        return;
    }
    do {
        cout << "Title: " << temp->title << endl;
        cout << "Artist: " << temp->artist << endl;
        cout << "Album: " << temp->album << endl;
        cout << "Genre: " << temp->genre << endl;
        cout << "Duration: " << temp->duration << " seconds" << endl;
        cout << "Release Year: " << temp->releaseYear << endl << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() 
{
    MusicTrack* head = NULL;
    int ch;
    char press;
    do{
        cout<<"\nEnter your choice: ";
        cout<<"\n1.Add music Track\n2.Remove Music track\n3.Search Music Track\n4.Update Music Track\n5.Display\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            addTrack(head);
            break;
            case 2:
            int pos;
            cout<<"\nEnter position which we want to delete: ";
            cin>>pos;
            if(pos==1)
            {
                deleteAtHead(head);
            }
            else
            {
                deletion(head);
            }
            break;
            case 3:
            cout<<search(head);
            break;
            case 4:
            update(head);
            break;
            case 5:
            display(head);
            break;
        }
        cout<<"\nDo you want to continue: (y or n): ";
        cin>>press;
    }while(press=='y'||press=='Y');
}
