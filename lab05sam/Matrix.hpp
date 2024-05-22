#ifndef  MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class State{
public:
    // if state == 1 go right
    // if state == 2 go diagonal
    // if state == 3 go down 
    int direction = 1;
    void change_state() {
        if (direction == 3) {
            direction = 1;
            
        }
        else {
            direction++;
        }
        
    }

};

class Matrix {
private:
    vector<vector<int>> data;
    int size;
public:
    Matrix() {
        vector<vector<int>> data;
    }

    void setSize(int newsize) {
        this->size = newsize;
    }

    void readFromFile(ifstream& file) {
        data.resize(size);
        for (int i = 0; i < size; i++) {
            data[i].resize(size);
            for (int j = 0; j < size; j++) {
                file >> data[i][j];
            }
        }
    }

    // Read matrix from a text file
    

    // Print the matrix
    void print() {
        cout << "Your matrix: " << endl;
        for (int i = 0; i < data.size(); i++){
            for (int j = 0; j < data.size(); j++) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void clear_data() {
        data.clear();
        data.shrink_to_fit();
    }

    vector<int> snake_right_left_triangle() {
        vector<int> res;
        int number_to_go = 2;
        int size_of_triangle = size / 2;
        int i = size / 2 - 2;
        int direction = 1;
        int to_be_pushed = data[size/2-1][0];
        res.push_back(to_be_pushed);
        int j = 0;
        for (i; i > -1; i--) {
            for (int k = 0; k < number_to_go; k++) {
                to_be_pushed = data[i][j];
                res.push_back(to_be_pushed);
                j += direction;
            }
            number_to_go++;
            direction = direction * -1;
            if (direction == -1) {
                j;
            }
            else {
                j = 0; 
            }
        }
        
        return res; 
    }

    vector<int> left_bottom_triangle_spiral() {
        vector<int> res;
        int size_of_triangle = this->size / 2;
        int number_of_steps = size_of_triangle;
        State state;
        int i = size-1; 
        int j = 0;

        int to_be_pushed;
        while (number_of_steps != 0) {
            
            if (state.direction == 1) {
            
                    for (int k = 0; k < number_of_steps; k++) {
                        
                        //cout << "Value to be push backed" << (data[i][j]) << '\n';
                        to_be_pushed = data[i][j];
                        res.push_back(to_be_pushed);
                        j++;
                    }
                    number_of_steps--;
                    state.change_state();
                

            }
            else if (state.direction == 2) {
                j--;
                for (int k = 0; k < number_of_steps; k++) {
                    i--;     
                    j--;
                    to_be_pushed = data[i][j];
                    res.push_back(to_be_pushed);
                }
                state.change_state();
                number_of_steps--;
                
            }
            else if (state.direction == 3) {
                
                for (int k = 0; k < number_of_steps; k++) {  // error??
                    i++;
                    to_be_pushed = data[i][j];
                    res.push_back(to_be_pushed);
                    
                }
                state.change_state();
                number_of_steps--;
                j++;
                
                
                
            }
            
        }
        return res;
    }



        

    
};


#endif // ! MATRIX_H
