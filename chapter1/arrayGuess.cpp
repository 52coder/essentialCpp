#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int seq_size = 18;
    int elem_seq[18] = {
        1, 2, 3, 3, 4, 7, 2, 5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };
    int next_seq = true;
    int cur_tuple = 0;

    while (next_seq == true && cur_tuple < seq_size) {
        cout << "The first two elements of the sequence are: "
            << elem_seq[cur_tuple] << ", "
            << elem_seq[cur_tuple + 1]
            << "\nWhat is the next element?";
        int usr_guess;
        cin >> usr_guess;
        if (usr_guess == elem_seq[cur_tuple + 2]) {
            cout << "you guess right!\n.";
        } else {
            cout << "you guess wrong!\n";
        }
        cout << "do you want to continue?(y/n):\n";
        char usr_rsp;
        cin >> usr_rsp;
        if (usr_rsp == 'N' || usr_rsp == 'n') {
            next_seq = false;
        } else {
            cur_tuple += 3;
        }
    }

    return 0;
}
