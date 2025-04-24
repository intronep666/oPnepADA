#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

// Combines all words from two files and records unique ones separately
void combineFiles(const string& path1, const string& path2, const string& mergedPath, const string& uniquePath) {
    ifstream fin1(path1), fin2(path2);
    ofstream foutMerged(mergedPath), foutUnique(uniquePath);

    if (!fin1 || !fin2 || !foutMerged || !foutUnique) {
        cerr << "File access error!\n";
        return;
    }

    unordered_set<string> uniqueSet;
    string token;

    while (fin1 >> token) {
        foutMerged << token << " ";
        uniqueSet.insert(token);
    }

    while (fin2 >> token) {
        foutMerged << token << " ";
        uniqueSet.insert(token);
    }

    for (const auto& uword : uniqueSet) {
        foutUnique << uword << "\n";
    }

    cout << "Merged content saved to: " << mergedPath << "\n";
    cout << "Unique words stored in: " << uniquePath << "\n";
}

// Counts the number of words in a given file
int wordCount(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Failed to open " << fileName << "\n";
        return -1;
    }

    string temp;
    int count = 0;
    while (file >> temp) ++count;

    return count;
}

// Loads words from a file into a vector
void loadWords(const string& path, vector<string>& storage) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Unable to read from: " << path << endl;
        return;
    }

    string w;
    while (fin >> w) {
        storage.push_back(w);
    }
}

// Counts how many times each unique word appears in a file
void generateFrequencyVector(const vector<string>& textWords, const vector<string>& uniqueWords, vector<int>& freq) {
    for (const auto& word : uniqueWords) {
        int count = 0;
        for (const auto& txtWord : textWords) {
            if (txtWord == word) ++count;
        }
        freq.push_back(count);
    }
}

// Nicely print a string vector
void displayWords(const vector<string>& list) {
    cout << "[";
    for (size_t i = 0; i < list.size(); ++i) {
        cout << list[i];
        if (i < list.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Print frequency values
void showFrequencies(const vector<int>& freqVec) {
    cout << "[";
    for (size_t i = 0; i < freqVec.size(); ++i) {
        cout << freqVec[i];
        if (i < freqVec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Calculate cosine similarity between two frequency vectors
void calculateCosineSimilarity(const vector<int>& vecA, const vector<int>& vecB) {
    double dotProd = 0.0, magA = 0.0, magB = 0.0;

    for (size_t i = 0; i < vecA.size(); ++i) {
        dotProd += vecA[i] * vecB[i];
        magA += pow(vecA[i], 2);
        magB += pow(vecB[i], 2);
    }

    magA = sqrt(magA);
    magB = sqrt(magB);

    double similarity = (magA && magB) ? (dotProd / (magA * magB)) : 0.0;

    cout << "Cosine Similarity: " << similarity << "\n";
    cout << "Similarity Percentage: " << similarity * 100 << "%\n";
}

int main() {
    string path1 = "C:\\Users\\priya\\OneDrive\\Documents\\file1.txt";
    string path2 = "C:\\Users\\priya\\OneDrive\\Documents\\file2.txt";
    string mergedOut = "C:\\Users\\priya\\OneDrive\\Documents\\merged.txt";
    string uniqueOut = "C:\\Users\\priya\\OneDrive\\Documents\\unique.txt";

    combineFiles(path1, path2, mergedOut, uniqueOut);

    int wc1 = wordCount(path1);
    int wc2 = wordCount(path2);
    int wcUnique = wordCount(uniqueOut);

    cout << "File1 Word Count: " << wc1 << endl;
    cout << "File2 Word Count: " << wc2 << endl;
    cout << "Unique Word Count: " << wcUnique << endl;

    vector<string> wordsFile1, wordsFile2, uniqueWords;
    loadWords(path1, wordsFile1);
    loadWords(path2, wordsFile2);
    loadWords(uniqueOut, uniqueWords);

    cout << "Words from File1: ";
    displayWords(wordsFile1);

    cout << "Words from File2: ";
    displayWords(wordsFile2);

    cout << "List of Unique Words: ";
    displayWords(uniqueWords);

    vector<int> freqA, freqB;
    generateFrequencyVector(wordsFile1, uniqueWords, freqA);
    generateFrequencyVector(wordsFile2, uniqueWords, freqB);

    cout << "Frequencies from File1: ";
    showFrequencies(freqA);

    cout << "Frequencies from File2: ";
    showFrequencies(freqB);

    calculateCosineSimilarity(freqA, freqB);

    return 0;
}
