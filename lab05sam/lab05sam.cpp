// lab05sam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Matrix.hpp"
#include <cstdlib>
#include <cstring>
using namespace std;

const string DEFAULT_OUTPUT_PATH = "output.txt";

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

static void readMatrices(const string& filename, Matrix& m1, Matrix& m2) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        throw(1);
    }

    int num;
    file >> num;
    m1.setSize(num);
    m2.setSize(num);

    m1.readFromFile(file);

    file.ignore(numeric_limits<streamsize>::max(), '\n');

    //file.ignore(numeric_limits<streamsize>::max, '\n');

    m2.readFromFile(file);

    file.close();

}
void print_args(int argc, char* argv[])
{
    cout << "Args:\n";
    for (int i = 0; i < argc; i++) {
        cout << " - Arg #" << i << " '" << argv[i] << "'\n";
    }
}

void print_help2() {
    cout << "usage: my_prog.exe -i INPUT_FILE [-o OUTPUT_FILE]\n"
        << "Args:\n"
        << "-i INPUT_FILE - path to input file\n"
        << "-o OUTPUT_FILE - path to output file, default '" << DEFAULT_OUTPUT_PATH << "'\n";
}

void get_args2(int argc, char* argv[], string& inf, string& ouf)
{
    if (argc < 3) {
        print_help2();
        std::exit(0);
    }

    inf = "";
    ouf = DEFAULT_OUTPUT_PATH;

    for (int i = 1; i < argc; i++) {
        if (std::strncmp("-i", argv[i], 2) == 0 && i + 1 < argc) {
            inf = argv[++i];
        }
        if (std::strncmp("-o", argv[i], 2) == 0 && i + 1 < argc) {
            ouf = argv[++i];
        }
    }

    if (inf == "" || ouf == "") {
        print_help2();
        std::exit(0);
    }
}

int main(int argc, char* argv[]) {
    intro();
    string inf, ouf;

    print_args(argc, argv);
    get_args2(argc, argv, inf, ouf);
    cout << "INF: " << inf << "\t OUF: " << ouf << endl;
    Matrix first_matrix;
    Matrix second_matrix;

    try {

        readMatrices(inf, first_matrix, second_matrix);
        first_matrix.print();
        second_matrix.print();
        vector<int> result2 = first_matrix.snake_right_left_triangle();
        vector<int> result1 = second_matrix.left_bottom_triangle_spiral();

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

        saveVectorToFile(result, ouf);
        cout << "Everything went fine. Have a nice day! Bye <3";
    }
    catch (...) {
        cerr << "\nMatrices haven't been read for some reasons. ";
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
