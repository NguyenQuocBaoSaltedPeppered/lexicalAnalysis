#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;

const int ERROR_STATE = 100;
#define MAX 100
#define MAX_COL 256
typedef int state;
typedef string attri;
typedef string token;
string x;
int i = 0;
int table[MAX][MAX_COL];

void create_table()
{
    int i, j;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            table[i][j] = ERROR_STATE;
        }
    }

    fstream file;
    file.open("tableNew.txt", ios::in);
    if (file.is_open())
    {
        int state, next;
        string line;
        char token;
        while (getline(file, line))
        {
            istringstream ss(line);
            ss >> state >> token >> next;
            if (token == '#')
            {
                for (i = 0; i < 256; i++)
                {
                    table[state][i] = next;
                }
            }
            else
            {
                table[state][(char)token] = next;
            }
        }
    }
    else
    {
        cout << "Loi mo file";
    }
    file.close();
}
char readchar(string x, int i)
{
    char *str = &x[0];
    if (i < x.length())
    {
        return str[i];
    }
    else
    {
        return '\0';
    }
}
bool star_end_state(state s)
{
    switch (s)
    {
    case 4:
    case 8:
    case 11:
    case 14:
    case 19:
    case 23:
    case 26:
    case 29:
    case 33:
    case 36:
    case 40:
    case 43:
    case 58:
        return true;
    default:
        return false;
    }
}
bool nostar_end_state(state s)
{
    switch (s)
    {
    case 2:
    case 3:
    case 6:
    case 7:
    case 10:
    case 13:
    case 15:
    case 17:
    case 18:
    case 21:
    case 22:
    case 25:
    case 28:
    case 31:
    case 32:
    case 35:
    case 38:
    case 39:
    case 42:
    case 44:
    case 49:
    case 51:
    case 54:
    case 61:
    case 63:
        return true;
    default:
        return false;
    }
}
attri attribute(state s)
{
    string stt;
    switch (s)
    {
    case 2:
        stt.assign("So sanh lon hon hoac bang");
        break;
    case 3:
        stt.assign("dich phai");
        break;
    case 4:
        stt.assign("so sanh lon hon");
        break;
    case 6:
        stt.assign("so sanh nho hon bang");
        break;
    case 7:
        stt.assign("Dich trai");
        break;
    case 8:
        stt.assign("so sanh nho hon");
        break;
    case 10:
        stt.assign("so sanh khac");
        break;
    case 11:
        stt.assign("phu dinh");
        break;
    case 13:
        stt.assign("so sanh bang");
        break;
    case 14:
        stt.assign("gan");
        break;
    case 17:
        stt.assign("cong bang");
        break;
    case 18:
        stt.assign("tang 1");
        break;
    case 19:
        stt.assign("cong");
        break;
    case 21:
        stt.assign("tru bang");
        break;
    case 22:
        stt.assign("giam 1");
        break;
    case 23:
        stt.assign("tru");
        break;
    case 25:
        stt.assign("nhan bang");
        break;
    case 26:
        stt.assign("nhan");
        break;
    case 28:
        stt.assign("chia bang");
        break;
    case 29:
        stt.assign("chia");
        break;
    case 30:
        stt.assign("chia lay du");
        break;
    case 31:
        stt.assign("Chu thich");
        break;
    case 32:
        stt.assign("Chia lay du bang");
        break;
    case 33:
        stt.assign("Chia lay du");
        break;
    case 35:
        stt.assign("AND logic");
        break;
    case 36:
        stt.assign("AND bit");
        break;
    case 38:
        stt.assign("OR logic");
        break;
    case 39:
        stt.assign("OR bang");
        break;
    case 40:
        stt.assign("OR bit");
        break;
    case 42:
        stt.assign("OR loai tru bit");
        break;
    case 43:
        stt.assign("XOR");
        break;
    case 44:
        stt.assign("Dao bit");
        break;
    case 49:
        stt.assign("Chu thich nhieu dong");
        break;
    case 51:
        stt.assign("So nguyen khong dau");
        break;
    case 54:
        stt.assign("Ten bien");
        break;
    case 58:
        stt.assign("Kieu du lieu int");
        break;
    case 61:
        stt.assign("So thuc");
        break;
    case 63:
        stt.assign("Ten ham");
        break;
    default:
        stt.assign("token ko duoc doan nhan(tt ko dung) \0");
    }
    return stt;
}
void catchar_in_token(char c, string &tk)
{
    // ghep them ky tu c vao tu to tk
    tk += c;
}
token search_token(int &k, attri &tt, bool &endtoken)
{
    token tk;
    char c;
    state s = 0, cs;
    string stt;
    do
    {

        c = readchar(x, k);
        if (c == ' ')
            c = '@';
        cs = table[s][(int)c];

        if (cs == ERROR_STATE)
        {

            cout << "Loi tai vi tri: " << k << endl;
            tk.assign("Error");
            break;
        }

        else if (star_end_state(cs))
        {
            tt.assign(attribute(cs));
            endtoken = true;
            break;
        }
        else if (nostar_end_state(cs))
        {
            catchar_in_token(c, tk);
            k = k + 1;
            tt = attribute(cs);
            endtoken = true;
            break;
        }
        else if (k > x.length())
        {
            printf("het xau vao, ko roi vao TT ket thuc");
            tk.assign("Error");
            break;
        }
        else
        {
            catchar_in_token(c, tk);
            s = cs;
            k++;
        }
    } while (1);
    return tk;
}

void lexical_analysis(string x)
{
    token tk;
    attri a;
    bool endtk = false;

    do
    {
        tk = search_token(i, a, endtk);
        if (tk != "Error")
        {
            cout << "Token: " << tk << endl;
            cout << "Attribute:" << a << endl;
        }
        else
        {

            cout << "Input:" << x << endl;
            break;
        }

    } while ((i < x.length() && (!endtk)));
}

bool exitProgram = false;
void signalHandler(int signum)
{
    exitProgram = true;
}

int main()
{

    signal(SIGINT, signalHandler); // Đăng ký hàm signalHandler để bắt tín hiệu Ctrl+C

    create_table();

    while (!exitProgram)
    {
        cout << "Nhap token:";
        getline(cin, x);
        i = 0;

        lexical_analysis(x);

        cout << endl;
    }

    return 0;
}
