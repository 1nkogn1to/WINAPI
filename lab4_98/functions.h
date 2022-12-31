#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <charconv>

void sendMessage(FILE* file, const char* message);
void readMessage(FILE* file, char* readHere);
bool all_zero(const int* threads, int emount);