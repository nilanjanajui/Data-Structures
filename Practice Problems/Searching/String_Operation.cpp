#include <iostream>
#include <cstring>

using namespace std;

// Function for the length
int getLength(const char str[])
{
    int length = strlen(str);
    return length;
}

// Function for substring
char *getSubstring(const char str[], int start, int length)
{
    char *result = new char[length + 1];
    int i;
    for (i = 0; i < length && str[start + i] != '\0'; i++)
    {
        result[i] = str[start + i];
    }
    result[i] = '\0';
    return result;
}

// Function for Indexing
int getIndex(const char str[], const char pattern[])
{
    int strLen = getLength(str);
    int pattLen = getLength(pattern);

    for (int i = 0; i <= strLen - pattLen; i++)
    {
        int j;
        for (j = 0; j < pattLen; j++)
        {
            if (str[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == pattLen)
        {
            return i; // Found the pattern
        }
    }
    return -1; // Pattern not found
}

// Function for Concatenation
char *concatenateStrings(const char str1[], const char str2[], char result[])
{
    int i, j;

    for (i = 0; str1[i] != '\0'; i++)
    {
        result[i] = str1[i];
    }

    for (j = 0; str2[j] != '\0';)
    {
        result[i++] = str2[j++];
    }

    result[i] = '\0';

    return result;
}

// Function for inserting a substring
char *insertSubstring(const char str[], const char sub[], int position)
{
    int strLength = getLength(str);
    int subLength = getLength(sub);

    int resultLength = strLength + subLength + 1; // +1 for null terminator
    char *result = new char[resultLength];

    int i = 0, j = 0, k = 0;

    while (i < position && str[i] != '\0')
    {
        result[k++] = str[i++];
    }

    while (sub[j] != '\0')
    {
        result[k++] = sub[j++];
    }

    while (str[i] != '\0')
    {
        result[k++] = str[i++];
    }

    result[k] = '\0';

    return result;
}

// Function for Deletation
char *deleteSubstring(const char str[], int start, int length)
{
    int strLength = getLength(str);
    char *result = new char[strLength - length + 1];

    int i, k = 0;

    for (i = 0; i < strLength; i++)
    {
        if (i < start || i >= start + length)
        {
            result[k++] = str[i];
        }
    }

    result[k] = '\0'; // Null-terminate
    return result;
}

// Function for replacement
char *replaceSubstring(const char str[], const char pattern[], const char replacement[])
{
    int index = getIndex(str, pattern); // Find the starting index of the pattern in the string.

    int resultLength = getLength(str) - getLength(pattern) + getLength(replacement) + 1;
    char *result = new char[resultLength];

    int i = 0, k = 0;

    while (i < index)
    {
        result[k++] = str[i++];
    }

    int j = 0;
    while (replacement[j] != '\0')
    {
        result[k++] = replacement[j++];
    }

    i += getLength(pattern);
    while (str[i] != '\0')
    {
        result[k++] = str[i++];
    }

    result[k] = '\0';
    return result;
}

int main()
{
    char str1[] = "TO BE OR NOT TO BE";
    char str2[] = " THAT IS THE QUESTION.";
    char str3[] = "HAMLET ";
    char result[100];

    cout << "String length: " << getLength(str1) << endl;

    cout << "Substring: " << getSubstring(str1, 3, 9) << endl;

    cout << "Pattern found at index: " << getIndex(str1, "NOT") << endl;

    cout << "Concatenated String: " << concatenateStrings(str1, str2, result) << endl;

    cout << "Inserting substring: " << insertSubstring(str1, str3, 3) << endl;

    cout << "Deleting charaters: " << deleteSubstring(str1, 3, 4) << endl;

    cout << "Replace the string pattern: " << replaceSubstring(str1, "NOT", "YES") << endl;

    return 0;
}
