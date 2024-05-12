// lab05sam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Matrix.hpp"
using namespace std;

void intro() {
    cout << "Laboratory work 05, variant 55 made by Oleksandr Tymchenko K-13\n";
    cout << "Traversing the lower left corner of the matrix with a counterclockwise \nspiral starting from the lower left corner of the matrix\n";
    cout << "Traversing the upper left corner of the matrix by snaking from bottom to right\n";
}

void saveVectorToFile(const vector<int>& vec, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (size_t i = 0; i < vec.size(); ++i) {
            outputFile << vec[i];
            if (i != vec.size() - 1) { 
                outputFile << " ";
            }
        }
        outputFile.close();
        cout << "Vector saved to " << filename << " successfully." << endl;
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
}


int main() {
    intro();
    Matrix matrix;
    if (matrix.readFromFile("data1.txt")) {
        matrix.print();
        vector<int> result2 = matrix.snake_right_left_triangle();
        vector<int> result1 = matrix.left_bottom_triangle_spiral();
        
        cout << "Results of reading: " << endl;
        cout << "Spiral: ";
        for (int i = 0; i < result1.size(); i++) {
            cout << result1[i] << ' ';
        }
        cout << '\n';
            cout << "Snake: ";
            for (int i = 0; i < result2.size(); i++) {
                cout << result2[i] << ' ';
            }
        cout << '\n';
        cout << "Remainder: ";
        vector<int> result;
        for (int i = 0; i < result2.size(); i++) {
            result.push_back(result1[i] % result2[i]);
            cout << result[i] << ' ';
        }
        cout << '\n';
        
        saveVectorToFile(result, "output.txt");
        
    }
    
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
