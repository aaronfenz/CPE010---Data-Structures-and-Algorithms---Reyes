#include <iostream>
#include <string>

class SongNode
{
public:
    std::string title;
    SongNode* next;
    SongNode* prev;

    SongNode(std::string songTitle)
    {
        title = songTitle;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist
{
private:
    SongNode* head;
    SongNode* current;

public:
    Playlist()
    {
        head = nullptr;
        current = nullptr;
    }

    // Add song to playlist
    void insertSong(std::string title)
    {
        SongNode* newNode = new SongNode(title);

        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            current = head;
        }
        else
        {
            SongNode* last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
        }

        std::cout << "\"" << title << "\" added to playlist.\n";
    }

    // Remove a song
    void removeSong(std::string title)
    {
        if (head == nullptr)
        {
            std::cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;

        do
        {
            if (temp->title == title)
            {
                if (temp->next == temp)
                {
                    delete temp;
                    head = nullptr;
                    current = nullptr;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = temp->next;

                    if (temp == current)
                        current = temp->next;

                    delete temp;
                }

                std::cout << "\"" << title << "\" removed.\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        std::cout << "Song not found.\n";
    }

    // Next song
    void nextSong()
    {
        if (current == nullptr)
        {
            std::cout << "Playlist is empty.\n";
            return;
        }

        current = current->next;
        std::cout << "Now Playing: " << current->title << std::endl;
    }

    // Previous song
    void previousSong()
    {
        if (current == nullptr)
        {
            std::cout << "Playlist is empty.\n";
            return;
        }

        current = current->prev;
        std::cout << "Now Playing: " << current->title << std::endl;
    }

    // Display current song
    void currentSong()
    {
        if (current == nullptr)
        {
            std::cout << "Playlist is empty.\n";
        }
        else
        {
            std::cout << "Current Song: " << current->title << std::endl;
        }
    }

    // Play all songs once
    void playAllSongs()
    {
        if (head == nullptr)
        {
            std::cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;

        std::cout << "\n--- Playlist ---\n";

        do
        {
            std::cout << temp->title << std::endl;
            temp = temp->next;
        }
        while (temp != head);

        std::cout << "----------------\n";
    }
};

int main()
{
    Playlist playlist;

    int choice;
    std::string song;

    do
    {
        std::cout << "\n===== SONG PLAYLIST =====\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Next Song\n";
        std::cout << "4. Previous Song\n";
        std::cout << "5. Current Song\n";
        std::cout << "6. Play All Songs\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        std::cin.ignore();

        switch(choice)
        {
        case 1:
            std::cout << "Enter song title: ";
            std::getline(std::cin, song);
            playlist.insertSong(song);
            break;

        case 2:
            std::cout << "Enter song title to remove: ";
            std::getline(std::cin, song);
            playlist.removeSong(song);
            break;

        case 3:
            playlist.nextSong();
            break;

        case 4:
            playlist.previousSong();
            break;

        case 5:
            playlist.currentSong();
            break;

        case 6:
            playlist.playAllSongs();
            break;

        case 7:
            std::cout << "Exiting Playlist...\n";
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while(choice != 7);

    return 0;
}