#include <iostream>
#include <cmath>
#include "coordinate.h"

using namespace std; // Using the standard namespace for convenience

int list_length(Coordinate *list_beginning) // returns the length of the list
{
    int count = 0;
    Coordinate *current = list_beginning;

    while(current != nullptr) // Traverse the list until the end
    {
        count++;
        current = current->next;
    }

    return count;
}

void add_coordinate(Coordinate *&list_beginning,
                    Coordinate *&list_end,
                    float x,
                    float y) // adds a new coordinate to the end of the list
{
    Coordinate *newNode = new Coordinate;

    newNode->x = x;
    newNode->y = y;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    if(list_beginning == nullptr) // If the list is empty, initialize it with the new node
    {
        newNode->coord_id = 1;
        list_beginning = newNode;
        list_end = newNode;
    }
    else
    {
        newNode->coord_id = list_length(list_beginning) + 1; // Assign a unique ID based on the current length of the list

        list_end->next = newNode;
        newNode->previous = list_end;
        list_end = newNode;
    }
}

void forward_display(Coordinate *list_beginning) // displays the list in forward order
{
    Coordinate *current = list_beginning;

    cout << "\nForward Display\n";

    while(current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " (" << current->x
             << ", " << current->y
             << ")" << endl;

        current = current->next;
    }
}

void backward_display(Coordinate *list_end) // displays the list in reverse order
{
    Coordinate *current = list_end;

    cout << "\nBackward Display\n";

    while(current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " (" << current->x
             << ", " << current->y
             << ")" << endl;

        current = current->previous;
    }
}

void delete_coordinate(Coordinate *&list_beginning,
                       Coordinate *&list_end,
                       int coord_id_to_delete) // deletes a coordinate from the list based on its coord_id
{
    Coordinate *current = list_beginning; // Start from the beginning of the list

    while(current != nullptr)
    {
        if(current->coord_id == coord_id_to_delete)
        {
            if(current->previous != nullptr)
                current->previous->next = current->next;
            else
                list_beginning = current->next;

            if(current->next != nullptr)
                current->next->previous = current->previous;
            else
                list_end = current->previous;

            delete current; // Free the memory of the deleted node

            cout << "\nCoordinate "
                 << coord_id_to_delete
                 << " deleted.\n";

            return;
        }

        current = current->next;
    }

    cout << "\nCoordinate not found.\n";
}

void closest_to(Coordinate *list_beginning, float x, float y) // finds the closest coordinate to the given x and y values
{
    if(list_beginning == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Coordinate *current = list_beginning; // Start from the beginning of the list
    Coordinate *closest = list_beginning; // Initialize the closest coordinate to the first node

    float minDistance =
        sqrt(pow(current->x - x, 2) +
             pow(current->y - y, 2));

    current = current->next;

    while(current != nullptr)
    {
        float distance =
            sqrt(pow(current->x - x, 2) +
                 pow(current->y - y, 2));

        if(distance < minDistance) // Update the closest coordinate if a closer one is found
        {
            minDistance = distance;
            closest = current;
        }

        current = current->next;
    }

    cout << "\nClosest Coordinate\n";
    cout << "ID: " << closest->coord_id
         << " (" << closest->x
         << ", " << closest->y
         << ")" << endl;

    cout << "Distance: "
         << minDistance << endl; // Display the distance to the closest coordinate
} 