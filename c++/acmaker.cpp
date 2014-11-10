//sg
#include<stdio.h>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
#define MAX 160
#define MAXIGNORED 100
#define MARKER $
#define UNDEF -1
using namespace std;
set<string> ignored;
int dp[MAX][MAX];
int wordsTill[MAX];
string sentence, abbr;
int sentenceLen, abbrLen, numWords;
#define tr(v, i) for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
vector<string> significantWords;
class OccurrenceCounter {
    int lenPhrase, lenPattern;
    string phrase, pattern;
public:
    OccurrenceCounter(string phrase, string pattern) {
        this->phrase = phrase;
        this->pattern = pattern;
        lenPattern = pattern.length();
        lenPhrase = phrase.length();
    }
    int getCount(int pr, int pt) {
        if(pr == lenPhrase) {
            if(pt == lenPattern) {
                return 1;
            } else {
                return 0;
            }
        }
        if(phrase[pr] == pattern[pt]) {
            return getCount(pr + 1, pt + 1) + getCount(pr + 1, pt);
        } else {
            return getCount(pr + 1, pt);
        }
    }
};

void init() {
    numWords = 0;
    for(int i = 0; i < MAX; i++) {
        wordsTill[i] = 0;
        for(int j = 0; j < MAX; j++) {
            dp[i][j] = UNDEF;
        }
    }
    significantWords.clear();
}
int solve(int wordIndex, int abbrIndex) {
    int wordsLeft = numWords - wordIndex; //to go
    int abbrLeft = abbrLen - abbrIndex;
    //printf("solve(%d, %d)\n", wordIndex, abbrIndex);
    //printf("Wordsleft = %d, abbrLeft = %d\n", wordsLeft, abbrLeft);
    if(dp[wordIndex][abbrIndex] != UNDEF) {
        //printf("Returning dp[%d][%d] = %d\n", wordIndex, abbrIndex, dp[wordIndex][abbrIndex]);
        return dp[wordIndex][abbrIndex];
    }
    if(wordIndex == numWords && abbrIndex == abbrLen) { //done for this case
        //printf("1. solve(%d, %d) >", wordIndex, abbrIndex);
        //printf("Setting dp[%d][%d] to  %d\n", wordIndex, abbrIndex, 1);
        return (dp[wordIndex][abbrIndex] = 1);
    }
    if(abbrLeft < wordsLeft) { //won't be able to give atleast one char to each of the words
        //printf("2. solve(%d, %d) >", wordIndex, abbrIndex);
        //printf("Setting dp[%d][%d] to  %d\n", wordIndex, abbrIndex, 0);

        return (dp[wordIndex][abbrIndex] = 0);
    }
    if(wordIndex != numWords && abbrIndex == abbrLen || wordIndex == numWords && abbrIndex != abbrLen) {
        //printf("3. solve(%d, %d) >", wordIndex, abbrIndex);
        //printf("Setting dp[%d][%d] to  %d\n", wordIndex, abbrIndex, 0);
        return (dp[wordIndex][abbrIndex] = 0);
    }
    int loopEnd = abbrLen - abbrIndex - wordsLeft;
    //printf("loopEnd = %d\n", loopEnd);
    int res = 0;
    string word = significantWords[wordIndex];
    /*Now we will loop from the abbrvIndex to the allowable range*/
    for(int i = abbrIndex; i <= abbrIndex + loopEnd; i++) {
        string pattern = abbr.substr(abbrIndex, (i - abbrIndex) + 1);
        OccurrenceCounter oc(word, pattern);
        //printf("Finding occurrences of %s in %s : ", pattern.c_str(), word.c_str());
        //printf("%d\n", oc.getCount(0, 0));
        //printf("5. dp[%d][%d] = %d\n", wordIndex + 1, i + 1, dp[wordIndex + 1][i + 1]);
        if(dp[wordIndex + 1][i  + 1] == UNDEF) {
            //printf("calling solve(%d, %d)\n", wordIndex + 1, i + 1);
            dp[wordIndex + 1][i + 1] = solve(wordIndex + 1, i + 1);
        }
        //printf("4. solve(%d, %d) -> dp[%d][%d] = %d\n", wordIndex, abbrIndex, wordIndex + 1, i + 1, dp[wordIndex + 1][i + 1]);
        res = res + oc.getCount(0, 0) * dp[wordIndex + 1][i + 1];
    }
    return (dp[wordIndex][abbrIndex] = res);
}
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
int main() {
    int ignoredWords;
    string temp;
    string phrase = "academicacouncil";
    string pattern = "ac";
    OccurrenceCounter oc(phrase, pattern);
    //printf("%d\n", oc.getCount(0, 0));
    string endCase = "LAST CASE";
    while(true) {  //while the scenarios end
        scanf("%d", &ignoredWords);
        if(ignoredWords == 0) {
            return 0;
        }
        for(int i = 0; i < ignoredWords; i++) {
            cin >> temp;
            ignored.insert(string(temp));
        }
        cin.ignore(); //eat the newline after the last word
        while(true) { //while the cases end
            getline(cin, sentence);
            if(sentence.compare(endCase) == 0) {
                break;
            }
            init();
            //cout << "Sentence : " << sentence << endl;
            vector<string> words = split(sentence, ' ');
            abbr = words[0];
            string abbr_bu = abbr;
            transform(abbr.begin(), abbr.end(), abbr.begin(), ::tolower);
            abbrLen = words[0].length();
            //cout << "abbr : " << abbr << endl;
            for(int i = 1; i < words.size(); i++) {
                if(ignored.find(words[i]) == ignored.end()) {
                    significantWords.push_back(words[i]);
                    numWords++;
                }
            }
            //printf("nw = %d, alen = %d\n", numWords, abbrLen);
            int res = solve(0, 0);
            if(res == 0) {
                printf("%s is not a valid abbreviation\n", abbr_bu.c_str());
            } else {
                printf("%s can be formed in %d ways\n", abbr_bu.c_str(), res);
            }

        }
        ignored.clear();
    }
    return 0;
}
