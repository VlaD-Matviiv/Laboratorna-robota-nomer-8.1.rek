// Lab 8.1
// рекурс≥€

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

bool Include(const char* s, const char* cs)
{
    if (*cs == '\0')
        return true; 

    while (*s != '\0')
    {
        if (*s == *cs)
            return Include(s, cs + 1); 
        s++;
    }
    return false; 
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0')
    {
        if (strncmp(&str[i], "while", 5) == 0)
        {
            strcat(t, "**"); 
            return Change(dest, str, t + 2, i + 5); 
        }
        else
        {
            *t++ = str[i]; 
            *t = '\0';
            return Change(dest, str, t, i + 1); 
        }
    }
    *t = '\0'; 
    return dest; 
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s[100];
    cout << "¬вед≥ть р€док: ";
    cin.getline(s, sizeof(s));

    char cs[] = "while";
    if (Include(s, cs))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    char* dest = new char[100]; 
    dest[0] = '\0'; 
    char* modifiedString = Change(dest, s, dest, 0); 

    cout << "«м≥нений р€док: " << modifiedString << endl;

    delete[] dest; 
    return 0;
}

