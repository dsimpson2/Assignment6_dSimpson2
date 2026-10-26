#ifndef COORDINATE_H // Check if COORDINATE_H is not defined
#define COORDINATE_H // Include guard to prevent multiple inclusions of this header file

struct _coordinate // defines a structure to represent a coordinate with x and y values, an ID, and pointers to the next and previous coordinates in a doubly linked list
{
    float x;
    float y;
    int coord_id;
    struct _coordinate *next;
    struct _coordinate *previous;
};

typedef struct _coordinate Coordinate; // typedef for the struct _coordinate

int list_length(Coordinate *list_beginning); // returns the length of the list

void add_coordinate(Coordinate *&list_beginning,
                    Coordinate *&list_end,
                    float x,
                    float y); // adds a new coordinate to the end of the list

void forward_display(Coordinate *list_beginning); // displays the list in forward order

void backward_display(Coordinate *list_end); // displays the list in reverse order

void delete_coordinate(Coordinate *&list_beginning, 
                       Coordinate *&list_end,  
                       int coord_id_to_delete); // deletes a coordinate from the list based on its coord_id

void closest_to(Coordinate *list_beginning,
                float x,
                float y); // finds the closest coordinate to the given x and y values

#endif