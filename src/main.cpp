#include <iostream>
#include <fstream>
#include "../include/fraction.hpp"
#include "../include/matrix.hpp"
#include "../include/elimination.hpp"
#include "../include/spaces.hpp"

using namespace std;


int main(int argc, char* argv[]){

	if(argc == 1){

		cout << "You must provide the file name of the testcase as an argument!" << endl;

		return 1;

	}else if(argc > 2){

		cout << "usage: " << argv[0] << " <file name of the testcase>" << endl;

		return 1;

	}

	ifstream testcase(argv[1]);

	if(!testcase){

		cout << "Failed to open file: " << argv[1] << endl;

		return 1;

	}


	int m, n;

	int case_num = 1;

	while(testcase >> m >> n){

		Matrix M(m, n);

		for(int i = 0; i < m; i++){

			for(int j = 0; j < n; j++){

				int tmp;

				testcase >> tmp;

				M[i][j] = tmp;

			}

		}

		cout << "#Testcase " << case_num << endl << endl;

		case_num++;

		cout << "[Original Matrix]" << endl;

		cout << M;

		cout << "[Eliminated Matrix]" << endl;

		cout << eliminate(M);
		
		cout << "[Column Space Matrix]" << endl;

		cout << column_space(M);

		cout << "[Row Space Matrix]" << endl;

		cout << row_space(M);

		cout << "[Nullspace Matrix]" << endl;

		cout << nullspace(M);

		cout << "[Left Nullspace Matrix]" << endl;

		cout << left_nullspace(M);

	}

	return 0;
}
