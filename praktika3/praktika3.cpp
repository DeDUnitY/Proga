#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
void number_of_inclusions(string x, string& buf)
{
    int c = 0;
    int mx = 0;
    char tmp = {};

    for (int i = 0; i < x.length(); i++)
    {
        for (int j = i + 1; j < x.length(); j++)
        {
            if (x[i] == x[j] && buf.find(x[i]) == -1)
            {
                c++;
            }
        }
        if (c > mx)
        {
            mx = c;
            tmp = x[i];
        }
        c = 0;
    }
    buf += tmp;

}
void simbol(string& a)
{
    char chars[] = ", .?:;'-()";
    for (int i = 0; i < strlen(chars); i++)
    {
        a.erase(remove(a.begin(), a.end(), chars[i]), a.end());
    }

}

bool Simbol(char ch)
{
    char chars[17] = ",.?:;'-()#¹%*_ ";
    for (int i = 0; i < 16; i++) {
        if (ch == chars[i]) {
            return true;
        }
    }
    return false;

}
string found(string str, string control, string CONTROL)
{
    string answer;
    for (int i = 0; i < control.length(); i++)
    {
        if (str.find(control[i]))
        {
            cout << str.find(control[i]);
            answer += str.find(control[i]);
        }
    }
    return answer;
}


int main()
{
    vector <string> arr;
    vector <string> chars;
    string simbols;
    ifstream f("input.txt");
    string temp = "";
    string s;
    string buf = "";
    while (!f.eof())
    {
        s = "";
        f >> s;
        simbols.append(s);
        simbol(s);
        arr.push_back(s);
    }

    char str[100];
    int k = 0;
    f.seekg(0);
    while (!f.eof()) {
        f.getline(str, 100);

        for (int i = 0; i < strlen(str); i++) {
            if (Simbol(str[i])) {
                temp.push_back(str[i]);
                k++;
            }

            if (strlen(str) == i + 1) {
                temp.push_back('\n');
            }

            if ((!Simbol(str[i]) && k != 0) || strlen(str) == i + 1) {
                chars.push_back(temp);
                k = 0;
                temp = "";
            }

        }
    }
    number_of_inclusions(simbols, buf);
    number_of_inclusions(simbols, buf);
    number_of_inclusions(simbols, buf);
    number_of_inclusions(simbols, buf);
    number_of_inclusions(simbols, buf);
    
    k = 0;
    string tmp = "";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].length(); j++)
        {
            if (buf.find(arr[i][j]) != -1)
            {
                k += 1;
                tmp += arr[i][j];
            }
            if (k == 4)
            {
                for (int g = 0; g < arr[i].length(); g++)
                {
                    if (arr[i][g] >= 65 && arr[i][g] <= 90)
                    {
                        continue;
                    }
                    arr[i][g] -= 32;
                }
                arr[i] += "(" + tmp + ")";
                k = 0;
                tmp = "";
                break;
            }
        }
        tmp = "";
        k = 0;
    }
    ofstream file("output.txt");
    for (int i = 0; i < arr.size(); i++) {
        file << arr[i] << chars[i];
    }
    file << chars[chars.size() - 1];
    file.close();
}