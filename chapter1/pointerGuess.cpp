#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

void getNum(vector< vector<int> > &ivvec, int &firstnum, int &secondnum, int &thirdnum)
{
    int randomseq = 0;
    int randombegin = 0;
    randomseq = rand() % 6;
    randombegin = rand() % 6;

    firstnum = ivvec[randomseq][randombegin];
    secondnum = ivvec[randomseq][randombegin + 1];
    thirdnum = ivvec[randomseq][randombegin + 2];
}

int main(void)
{
    int arrFib[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> fibvec(arrFib, arrFib + 8);
    int arrLuc[8] = {1, 3, 4, 7, 11, 18, 29, 47};
    vector<int> lucvec(arrLuc, arrLuc + 8);
    int arrPel[8] = {1, 2, 5, 12, 29, 70, 169, 408};
    vector<int> pelvec(arrPel, arrPel + 8);
    int arrTri[8] = {1, 3, 6, 10, 15, 21, 28, 36};
    vector<int> trivec(arrTri, arrTri + 8);
    int arrSqu[8] = {1, 4, 9, 16, 25, 36, 49, 64};
    vector<int> squvec(arrSqu, arrSqu + 8);
    int arrPen[8] = {1, 5, 12, 22, 35, 51, 70, 92};
    vector<int> penvec(arrPen, arrPen + 8);

    vector< vector<int> > ivvec;
    ivvec.push_back(fibvec);
    ivvec.push_back(lucvec);
    ivvec.push_back(pelvec);
    ivvec.push_back(trivec);
    ivvec.push_back(squvec);
    ivvec.push_back(penvec);

    bool bTry = true;
    const int maxTries = 5;
    int numTries = 0;
    int numRight = 0;

    while (bTry) {
        int firstNum = 0;
        int secondNum = 0;
        int thirdNum = 0;
        getNum(ivvec, firstNum, secondNum, thirdNum);
        cout << "the first number is: " << firstNum << "\nand the second number is: " << secondNum;
        cout << "\nPlease enter the thrid number: ";
        int userNum = 0;
        cin >> userNum;
        string userSelect;

        if (userNum == thirdNum) {
            numRight++;
            numTries++;
            cout << "you are right. do you want to try another numbers(y/n)";
            cin >> userSelect;
        } else {
            if (numTries > maxTries) {
                 cout << "sorry, you have tried max times." << endl;
                 break;
            }
            numTries++;
            cout << "you are wrong. do you want to try another numbers?(y/n)";
            cin >> userSelect;
        }
        if (userSelect == "n" || userSelect == "N") {
             break;
        }
     }
    cout << "the rate success is: " << (numRight * 1.0 / numTries) * 100 << "%" << endl;

    return 0;
}
