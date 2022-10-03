#include <iostream>

#include <string>
#include <string_view>

#include <cstdint>
using std::cout; using std::cin; using std::string; using std::getline; using std::ws;

// originally written by ROMAHKAO on 9/29/2022
// rewritten by chapel1337 on 10/2/2022
// took about an hour or so to rewrite, i had a friend come over which delayed the process
// i was going to add a file i/o but i'm a bit burnt out
// i'll probably add file i/o tomorrow after school

constexpr std::string_view variation{ "1 -> 1" };

// ------- \\

void menu();

void title(string title = "Encoder & Decoder")
{
    system(("title " + title).c_str());
}

void clear()
{
    system("cls");
}

void error(string message)
{
    clear();

    std::cerr << "Something went wrong: " << message << "\n\n";

    system("pause");
    menu();
}

// ------- \\

string encodeV1(string input, long key)
{
    string output{ "" };

    for (int i{ 0 }; i < input.length(); ++i)
    {
        char character{ input[i] };
        long number{ character * key };

        output += std::to_string(number) + '.';
    }

    return '.' + output;
}

string decodeV1(string input, long key)
{
    string output{ "" };
    int last{ 0 };

    for (int i{ 1 }; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            string sgm = input.substr(last + 1, i); // what is sgm???

            sgm = sgm.substr(0, sgm.find('.'));
            output += static_cast<char>(stoi(sgm) / key);

            last = i;
        }
    }
    return output;
}

// ------- \\

void encrypt()
{
    clear();
    title("Encrypt");

    string text{};
    long key{};

    cout << "--- Enter some text you want to encrypt ---\n\n> ";
    getline(cin >> ws, text);

    clear();

    cout << "--- Enter a key (an integer) ---\n\n> ";
    cin >> key;

    clear();

    string result{ encodeV1(text, key) };
    cout << "Result: " << result << "\n\n";

    system("pause");
    menu();
}

void encryptMenu()
{
    clear();
    title("Encrpyt Menu");

    char response{};

    cout << "--- Select one of the variations ---\n\n";
    cout << "\t" << variation << "\n\n> ";

    cin >> response;

    switch (response)
    {
        case '1':
            encrypt();
        break;

        default:
            cout << "Invalid choice, please input 1\n\n";
            system("pause");
        break;
    }
}

void decrypt()
{
    clear();
    title("Decrpyt");

    string text{};
    long key{};

    cout << "--- Enter the encrypted text ---\n\n> ";
    getline(cin >> ws, text);

    clear();

    cout << "--- Enter the key used during encryption ---\n\n> ";
    cin >> key;

    clear();

    string result{ decodeV1(text, key) };
    cout << "Result: " << result << "\n\n";

    system("pause");
    menu();
}

void decryptMenu()
{
    clear();
    title("Decrpyt Menu");

    char response{};

    cout << "--- Select one of the variations ---\n\n";
    cout << "\t" << variation << "\n\n> ";

    cin >> response;

    switch (response)
    {
        case '1':
            decrypt();
        break;

        default:
            cout << "Invalid choice, please input 1\n\n";
            system("pause");
        break;
    }
}

void help()
{
    clear();
    title("Help");

    char response{};

    cout << "--- What do you need help with? ---\n";

    cout << "\t1. Keys\n";
    cout << "\t2. Go Back\n\n> ";
    cin >> response;

    switch (response)
    {
        case '1':
            clear();

            cout << "Your key has to be an integer, otherwise unexpected things could happen.\n";
            cout << "If you need more help please contact the owners on Discord: <@671149601369096202>, <@885230441756516403>\n\n";

            system("pause");

            menu();
        break;

        case '2':
            menu();
        break;

        default:
            error("Invalid choice, please input 1 or 2");
        break;
    }

}

void credits()
{
    clear();
    title("Credits");

    cout << "Encoding & Decoding made by ROMAHKAO (github.com/AMilkyWay/)\n";
    cout << "Rewrite & File I/O made by chapel1337 (github.com/chapel1337/)\n\n";

    system("pause");
    menu();
}

// ------- \\

void menu()
{
    clear();
    title("Menu");

    char response{};

    cout << "--- Select one of the following ---\n\n";

    cout << "\t1. Encrypt\n";
    cout << "\t2. Decrypt\n";
    cout << "\t3. Help\n";
    cout << "\t4. Credits\n";
    cout << "\t5. Quit\n\n> ";

    cin >> response;

    switch (response)
    {
    case '1':
        clear();
        encrypt();
    break;

    case '2':
        decrypt();
    break;

    case '3':
        help();
    break;

    case '4':
        credits();
    break;

    case '5':
        exit(1);
    break;

    default:
        error("Invalid choice, please input 1, 2, 3, or 4");
    break;
    }
}

int main()
{
    menu();
}