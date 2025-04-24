#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

// Function to merge unique words from two files and write them to output
void mergeUniqueWords(const string& file1, const string& file2, const string& outputFile, const string& uniqueFile) {
    ifstream inputFile1(file1);
    ifstream inputFile2(file2);
    ofstream output(outputFile);
    ofstream uniqueOutput(uniqueFile);

    if (!inputFile1 || !inputFile2 || !output || !uniqueOutput) {
        cerr << "Error: Unable to open one or more files!" << endl;
        return;
    }
    
    unordered_set<string> uniqueWords;
    string word;

    while (inputFile1 >> word) {
        output << word << " ";
        uniqueWords.insert(word);
    }

    while (inputFile2 >> word) {
        output << word << " ";
        uniqueWords.insert(word);
    }

    for (const string& word : uniqueWords) {
        uniqueOutput << word << "\n";
    }

    cout << "Merged words saved to '" << outputFile << "'\n";
    cout << "Unique words saved to '" << uniqueFile << "'\n";
}

// Function to count words in a file
int countWordsInFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return -1;
    }

    string word;
    int wordCount = 0;
    while (file >> word) {
        wordCount++;
    }

    return wordCount;
}

// Function to read words from a file into an array
void wordarray(const string& file, vector<string>& words) {
    ifstream inputFile(file);
    if (!inputFile) {
        cerr << "Error: Unable to open file: " << file << endl;
        return;
    }

    string word;
    while (inputFile >> word) {
        words.push_back(word);
    }
}

void occurarray(vector<int>&arr,vector<string>& words, vector<string>& uniqueWords) {
    for (int i = 0; i < uniqueWords.size(); i++) {
        int count = 0;
        for (int j = 0; j < words.size(); j++) {
            if (uniqueWords[i] == words[j]) {
                count++;
            }
        }
        arr.push_back(count);
    }
    
}

void printoccurarray(vector<int>&arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}

// Function to print words in an array neatly
void printWordArray(const vector<string>& words) {
    cout << "[";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i < words.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void findcosinsimilarity(vector<int>&arrayA,vector<int>&arrayB){
    float dotProduct = 0, magA = 0, magB = 0;
    for(int i = 0; i < arrayA.size(); i++){
        dotProduct += arrayA[i] * arrayB[i];
        magA += arrayA[i] * arrayA[i];
        magB += arrayB[i] * arrayB[i];
    }
    magA = sqrt(magA);
    magB = sqrt(magB);
    float cosinsimilarity = dotProduct / (magA * magB);
    cout << "Cosine similarity: " << cosinsimilarity << endl;
    cout<< cosinsimilarity * 100 << "%" <<" Similarity"<< endl;
}

int main() {
    string file1 = "C:\\Users\\priya\\OneDrive\\Documents\\file1.txt";
    string file2 = "C:\\Users\\priya\\OneDrive\\Documents\\file2.txt";
    string output = "C:\\Users\\priya\\OneDrive\\Documents\\merged.txt";
    string unique = "C:\\Users\\priya\\OneDrive\\Documents\\unique.txt";

    // Merge unique words from the files
    mergeUniqueWords(file1, file2, output, unique);

    // Count words in files
    int totalWordsf1 = countWordsInFile(file1);
    int totalWordsf2 = countWordsInFile(file2);
    int totalWordsu = countWordsInFile(unique);

    cout << "Total words in file1: " << totalWordsf1 << endl;
    cout << "Total words in file2: " << totalWordsf2 << endl;
    cout << "Total unique words: " << totalWordsu << endl;

    // Use dynamic arrays (vector)
    vector<string> wordArrayf1, wordArrayf2, wordArrayu;

    wordarray(file1, wordArrayf1);
    wordarray(file2, wordArrayf2);
    wordarray(unique, wordArrayu);

    // Print Wordarrays
    cout << "Words in file1: ";
    printWordArray(wordArrayf1);

    cout << "Words in file2: ";
    printWordArray(wordArrayf2);

    cout << "Unique words: ";
    printWordArray(wordArrayu);

    // Compute word occurrences
    vector<int>arrayA,arrayB;
    occurarray(arrayA,wordArrayf1,wordArrayu);
    occurarray(arrayB,wordArrayf2,wordArrayu);

    cout<< "Array A:";
    printoccurarray(arrayA);

    cout<< "Array B:";
    printoccurarray(arrayB);

    // Calculate cosine similarity
    findcosinsimilarity(arrayA,arrayB);

    return 0;
}
