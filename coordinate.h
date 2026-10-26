#ifndef COORDINATE_H
#define COORDINATE_H

struct _coordinate
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
                    float y);

void forward_display(Coordinate *list_beginning); // displays the list in forward order

void backward_display(Coordinate *list_end); // displays the list in reverse order

void delete_coordinate(Coordinate *&list_beginning, // deletes a coordinate from the list based on its coord_id
                       Coordinate *&list_end,  // deletes a coordinate from the list based on its coord_id
                       int coord_id_to_delete); // deletes a coordinate from the list based on its coord_id

void closest_to(Coordinate *list_beginning,
                float x,
                float y); // finds the closest coordinate to the given x and y values

#endif