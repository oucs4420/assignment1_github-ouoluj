#include <iostream>
#include <fstream>

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int countLines(char* fileName);

int main( int argc, char* argv[] )
{
    // just to get you started, this is how to refer to the arguments that were passed
    std::cout << "program: " << argv[0] << '\n';
    for (int arg = 1; arg < argc; ++arg) {
        std::cout << " " << argv[arg] << ": " << countLines(argv[arg]) <<'\n';
    }

    exit(0); // this means that the program executed correctly!
}


int countLines(char* fileName) {
    std::ifstream file;
    int result = -1;

    file.open(fileName);
    if (file.fail()) {
        return -1;
    }

    std::string dummy = "";

    while (getline(file, dummy)) {
        result++;
        if (file.peek() == EOF) {
            result ++;
        }
    }

    file.close();
    return result;
}