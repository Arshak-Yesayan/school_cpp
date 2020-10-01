#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string input_txt, output_txt;
    int key, last_int = 0, n = 0, position = 0;

    // cin >> input_txt >> output_txt >> key;
    input_txt = "output.jpg";
    output_txt = "result.txt";
    key = 248;

    ifstream input;
    input.open(input_txt, ios::binary);
    ofstream output;
    output.open(output_txt, ios::binary);

    string input_string;
    char input_char;
    int input_int;

    int first_comment = 0, second_comment = 0;

    if(input.is_open() && output.is_open()) {
        while( getline(input, input_string) ) {
            for(int i = 0; i < input_string.length(); i++) {
                input_char = input_string[i];
                input_int = int(input_char);
                if( input_int < 0 )
                    input_int += 256;

                int encoded_int = input_int ^ key ^ last_int;
                char encoded_char = char(encoded_int);

                if( n == 4 )
                    first_comment = input_int;
                else if( n == 5 ) {
                    second_comment = input_int + 6;
                    first_comment += second_comment / 256;
                    second_comment %= 256;
                    position = first_comment * 256 + second_comment - 1;
                }
                else if( n < position) {
                    output << encoded_char;

                    key++;
                    key %= 256;
                    last_int = input_int;
                }

                if( n < 100 )
                n++;
            }
        }
    }

    input.close();
    output.close();
    return 0;
}