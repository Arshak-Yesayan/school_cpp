#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    char encoded_chars[65536] = {' '};
    int n = 0, len = 0;
    string input_txt, input_file, output_file;
    int key, last_int = 0;

    // cin >> input_txt >> input_file >> output_file >> key;
    input_txt = "input.txt";
    input_file = "hover.jpg";
    output_file = "output.jpg";
    key = 248;

    ifstream input;
    input.open(input_txt, ios::binary);

    ifstream input_jpg;
    input_jpg.open(input_file, ios::binary);

    ofstream output;
    output.open(output_file, ios::binary);

    string input_string;
    char input_char;
    int input_int;

    if( input.is_open() ) {
        while( getline(input, input_string) ) {
            len += input_string.length();
            for(int i = 0; i < input_string.length(); i++) {
                input_char = input_string[i];
                input_int = int(input_char);
                if( input_int < 0 )
                    input_int += 256;
                
                int encoded_int = input_int ^ key ^ last_int;
                char encoded_char = char(encoded_int);
                encoded_chars[n] = encoded_char;
                n++;

                key ++;
                key %= 256;
                last_int = encoded_int;
            }
            int encoded_int = 10 ^ key ^ last_int;
            char encoded_char = char(encoded_int);
            encoded_chars[n] = encoded_char;
            n++;
            len++;

            key ++;
            key %= 256;
            last_int = encoded_int;
        }
    }

    int jpg_position = 0, first_comment = 0, second_comment = 0, jpg_n = 0;

    if( input_jpg.is_open() ){
        while( getline(input_jpg, input_string) ) {
            for(int i = 0; i < input_string.length(); i++) {
                input_char = input_string[i];
                input_int = int(input_char);
                if( jpg_n == 4 ) {
                    first_comment = input_int;
                }
                else if( jpg_n == 5 ) {
                    second_comment = input_int + 5;
                    first_comment += second_comment / 256;
                    second_comment %= 256;
                    jpg_position = first_comment * 256 + second_comment - 1;
                    output << char(len / 256) << char(len % 256);
                    for(int j = 0; j <= len; j++) {
                        output << encoded_chars[j];
                    }
                }
                else if( jpg_n >= jpg_position ) {
                    output << input_char;
                }

                jpg_n++;
            }
            output << '\n';
        }
    }

    input.close();
    input_jpg.close();
    output.close();
    return 0;
}