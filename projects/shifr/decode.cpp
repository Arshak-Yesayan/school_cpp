#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string input_txt, output_txt;
    int key, last_int = 0;

    cin >> input_txt >> output_txt >> key;

    ifstream input;
    input.open(input_txt, ios::binary);
    ofstream output;
    output.open(output_txt, ios::binary);

    string input_stirng;
    char input_char;
    int input_int;

    if(input.is_open() && output.is_open()) {
        while( getline(input, input_stirng) ) {
            for(int i = 0; i < input_stirng.length(); i++) {
                input_char = input_stirng[i];
                input_int = int(input_char);
                if( input_int < 0 )
                    input_int += 256;
                
                int encoded_int = (input_int ^ key) ^ last_int;
                char encoded_char = char(encoded_int);
                
                cout << input_int << "  " << key << "  " << last_int << "  " << encoded_int << "  " << input_char << "  " << encoded_char << endl;
                output << encoded_char;

                key ++;
                key %= 256;
                last_int = input_int;
            }
        }
    }

    input.close();
    output.close();
    return 0;
}