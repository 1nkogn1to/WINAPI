#include "funtions.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <charconv>

#pragma warning (disable : 4996)

using namespace MyFunctions;

void sendMessage(FILE* file, const char* message)
{
	int length = strlen(message) + 1;
	fwrite(&length, sizeof(length), 1, file);
	for (int i = 0; i < length; i++)
	{
		fwrite(&message[i], sizeof(char), 1, file);
	}
}

void readMessage(FILE* file, char* readHere)
{
	int length = 0;
	fread(&length, sizeof(length), 1, file);
	char* destination = new char[length];
	for (int i = 0; i < length; i++)
	{
		fread(&destination[i], sizeof(char), 1, file);
	}
	strcpy(readHere, destination);
	delete[] destination;
}

bool all_zero(const int* threads, int emount)
{
	for (size_t i = 0; i < emount; i++)
	{
		if (threads[i] == 1)
		{
			return false;
		}
	}
	return true;
}