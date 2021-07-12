#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const unsigned int DISTANCE_BETWEEN_SMALL_AND_BIG_LETTERS = 32;
const unsigned int HEADLINE_LENGTH = 50;
const char HEADLINE_SPACE_SYMBOL = '*';

bool isBigLetter(char);

char toSmallLetter(char);

void toLowercase(string&);

bool contains(string, string);

bool same(string, string);

bool isEmptyStr(string);

void headline(string);
void bottomLine(string);