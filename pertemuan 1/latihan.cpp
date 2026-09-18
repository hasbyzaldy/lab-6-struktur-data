#include <iostream>
using namespace std;

int main() {
    system("cls");
    int array3D[3][3][4];
    int nilai = 2;

    bool kurang = true;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            for (int k = 0; k < 4; k++) {

                array3D[i][j][k] = nilai;

                if (kurang == true) {
                    nilai = nilai - 1;
                    kurang = false;
                }

                else {
                    nilai = nilai + 2;
                    kurang = true;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {

        cout << "\nLAPIS " << i + 1 << endl;
        cout << "------------------------" << endl;

        for (int j = 0; j < 3; j++) {

            for (int k = 0; k < 4; k++) {
                cout << array3D[i][j][k] << "\t";
            }

            cout << endl;
        }

        cout << "------------------------" << endl;
    }

    return 0;
}