#include <iostream> // Include the input-output stream library for console output
#include <cmath> // Include the cmath library for mathematical functions like sqrt and pow
#include <cstdlib> // Include the C standard library for random number generation
#include <ctime> // Include the ctime library for seeding the random number generator
#include "coordinate.h" // Include the header file for the Coordinate structure and related functions

using namespace std; // Using the standard namespace for convenience

int main(int argc, char *argv[]) // Main function to demonstrate the functionality of the coordinate list
{
    if(argc != 2) // Check if the correct number of command-line arguments is provided
    {
        cout << "Usage: ./main number_of_coordinates" << endl; // Check for correct number of command-line arguments
        return 1; // Return an error code if the number of arguments is incorrect
    }

    int numCoords = atoi(argv[1]); // Convert the command-line argument to an integer representing the number of coordinates to generate

    Coordinate *list_beginning = nullptr;
    Coordinate *list_end = nullptr;

    srand(time(0)); // Seed the random number generator with the current time to ensure different random values on each run

    for(int i = 0; i < numCoords; i++) // Loop to generate random coordinates and add them to the list
    {
        float x = rand() % 100; // Generate random x and y values between 0 and 99
        float y = rand() % 100; // Generate random x and y values between 0 and 99

        add_coordinate(list_beginning,
                       list_end,
                       x,
                       y); // Add a new coordinate to the list with random x and y values
    }

    cout << "List Length: "
         << list_length(list_beginning)
         << endl; // Display the length of the list

    forward_display(list_beginning); // Display the list in forward order

    backward_display(list_end); // Display the list in reverse order

    delete_coordinate(list_beginning,
                      list_end,
                      3); // Delete the coordinate with coord_id 3

    cout << "\nAfter Delete:\n";
    forward_display(list_beginning); // Display the list after deleting a coordinate with coord_id 3

    closest_to(list_beginning, 50, 50); // Find the closest coordinate to the point (50, 50)

    while(list_beginning != nullptr) // Clean up the list to free allocated memory
    {
        Coordinate *temp = list_beginning; // Store the current node to delete
        list_beginning = list_beginning->next; // Move to the next node in the list
        delete temp; // Free the memory of the deleted node
    }

    return 0;
}