#include <iostream>
#include "Utility.h"

bool isBigLetter(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

char toSmallLetter(char symbol) {
    return symbol + DISTANCE_BETWEEN_SMALL_AND_BIG_LETTERS;
}

void toLowercase(string& str) {
    unsigned int length = str.length();

    for (int i = 0; i < length; i++) {
        if (isBigLetter(str[i]))
            str[i] = toSmallLetter(str[i]);
    }
}

bool contains(string container, string target) {
    unsigned int containerLength = container.length();
    unsigned int targetLength = target.length();

    if (containerLength < targetLength)
        return 0;

    string toInspect = container;
    toLowercase(toInspect);

    string toFind = target;
    toLowercase(toFind);

    int i = 0;
    int j = 0;

    while (toInspect[i] != '\0') {
        if (toInspect[i] == toFind[j]) {
            int init = i;
            while (toInspect[i] == toFind[j] && toFind[j] != '\0') {
                j++;
                i++;
            }
            if (toFind[j] == '\0')
                return true;

            j = 0;
        }

        i++;
    }

    return false;
}

bool same(string str1, string str2) {
    unsigned int len1 = str1.length();
    unsigned int len2 = str2.length();

    if (len1 != len2)
        return 0;

    string lowerStr1 = str1;
    toLowercase(lowerStr1);

    string lowerStr2 = str2;
    toLowercase(lowerStr2);

    for (int i = 0; i < len1; i++) {
        if (lowerStr1[i] != lowerStr2[i])
            return false;
    }

    return true;
}

void headline(string title) {
    unsigned int length = title.length();
    unsigned int symbolsAmount = (HEADLINE_LENGTH - length - 2) / 2;

    for (unsigned int i = 0; i < symbolsAmount; i++)
        cout << HEADLINE_SPACE_SYMBOL;
    cout << ' ' << title << ' ';
    for (unsigned int i = 0; i < symbolsAmount; i++)
        cout << HEADLINE_SPACE_SYMBOL;
    cout << endl;
}
void bottomLine(string title) {
    unsigned int length = title.length();
    unsigned int symbolsAmount = (HEADLINE_LENGTH - length - 2) / 2;
    unsigned int total = 2 * symbolsAmount + length + 2;

    for (unsigned int i = 0; i < total; i++)
        cout << HEADLINE_SPACE_SYMBOL;
    cout << endl;
}