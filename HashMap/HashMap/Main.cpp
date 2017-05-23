/*
Author: Demetri Van Sickle
Date: 5/22/17
IDE: Visual Studio 2015
Program:
		Create a hash function which is used to generate a hash from a string, then test it and evaluate the results.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_OF_UNIQUE_WORDS = 45402;
const int DATA_SIZE = 30;

const string FILE_TO_READ = "words.txt";
const string FILE_TO_WRITE = "hashresults.csv";

ifstream fileRead;
ofstream fileWrite;

//Prototypes
int hasher(string wordToHash);
string convertToLower(string wordToConvert);
float findCollisions(const int* arrayToSearch);
void outputToFile(const int* arrayToOutput);

void main()
{


	//Variables
	int hashMap[NUM_OF_UNIQUE_WORDS] = {};
	int arrayIndx = 0;
	double hash = 0;
	int error = 0;
	int errorStr = 0;
	char wordFromLine[DATA_SIZE] = {};
	string wordFromLineStr = "";

	fileRead.open(FILE_TO_READ);

	//Make sure the file opened
	if (!fileRead.is_open())
	{
		cout << "ERROR! Cant open file to read." << endl;
		return;
	}
	else
	{
		//Cycle through the file
		while (!fileRead.eof())
		{
			fileRead.getline(wordFromLine, DATA_SIZE);

			//Convert back to string
			wordFromLineStr = wordFromLine;

			//Set all chars in the word to lowercase
			wordFromLineStr = convertToLower(wordFromLineStr);

			//Calculate the indx
			arrayIndx = hasher(wordFromLineStr) % NUM_OF_UNIQUE_WORDS;
			arrayIndx = abs(arrayIndx);

			if (arrayIndx < 0 || arrayIndx >= NUM_OF_UNIQUE_WORDS)
			{
				cout << "ERROR! index out of bounds" << endl;
				error++;
				errorStr = arrayIndx;
				continue;
			}

			hashMap[arrayIndx]++;
		}

		fileRead.close();

		outputToFile(hashMap);

		cout << "CS-260: A6 hashing, Demetri Van Sickle, " << findCollisions(hashMap) << "%" << "  error " << error << " " << errorStr << endl;
	}

	//Allow console to stay open
	cin.get();
	cin.ignore();
}

int hasher(string wordToHash)
{
	int hash = 0;


	for (int indx = 0; indx < wordToHash.length(); indx++)
	{
		hash += wordToHash[indx];
	}

	hash = (hash * (wordToHash[wordToHash.length() / 2])) + (hash * (wordToHash[wordToHash.length() / 5])) * (hash * (wordToHash[wordToHash.length() / 6]))
		* (hash * (wordToHash[wordToHash.length() / 3])) * (hash * (wordToHash[wordToHash.length() / 4])) * (hash * (wordToHash[wordToHash.length() / 7]))
		*(hash * (wordToHash[wordToHash.length() / 2])) + (hash * (wordToHash[wordToHash.length() / 5])) * (hash * (wordToHash[wordToHash.length() / 6]))
		* (hash * (wordToHash[wordToHash.length() / 3])) * (hash * (wordToHash[wordToHash.length() / 4])) * (hash * (wordToHash[wordToHash.length() / 7]))
		* (wordToHash[wordToHash.length() / 3]) + (wordToHash[wordToHash.length() / 3]) + (wordToHash[wordToHash.length() / 2]) + (hash * (wordToHash[wordToHash.length() / 9] + hash))
		+ (hash * (wordToHash[wordToHash.length() / 5])) + (hash * (wordToHash[wordToHash.length() / 9])) + (4 * (wordToHash[wordToHash.length() / 7])) + ((wordToHash[wordToHash.length() / 2]))
		* ((wordToHash[wordToHash.length() / 5])) + ((wordToHash[wordToHash.length() / 50]));
	
	return abs(hash);
}

string convertToLower(string wordToConvert)
{
	for (int indx = 0; indx < wordToConvert.length(); indx++)
	{
		//Make sure we only convert an uppercase letter
		if (wordToConvert[indx] >= 65 && wordToConvert[indx] <= 90)
		{
			wordToConvert[indx] = tolower(wordToConvert[indx]);
		}
		else
		{
			continue;
		}
	}

	return wordToConvert;
}

float findCollisions(const int * arrayToSearch)
{
	float numOfCollisions = 0;

	for (int indx = 0; indx < NUM_OF_UNIQUE_WORDS; indx++)
	{
		if (arrayToSearch[indx] > 1)
		{
			numOfCollisions += arrayToSearch[indx] - 1;
		}
	}

	return (numOfCollisions / NUM_OF_UNIQUE_WORDS) * 100;
}

void outputToFile(const int * arrayToOutput)
{
	fileWrite.open(FILE_TO_WRITE);

	for (int indx = 0; indx < NUM_OF_UNIQUE_WORDS - 1; indx++)
	{
		if (arrayToOutput[indx] != 0)
		{
			fileWrite << arrayToOutput[indx] << ",";
		}
	}

	fileWrite << arrayToOutput[NUM_OF_UNIQUE_WORDS - 1];

	fileWrite.close();
}
