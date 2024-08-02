#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void error_handle() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number." << endl;
}

int main() {
    char choice;
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case '1': {
				int n;
				while (true){
					cout << "How many numbers do you want to add? ";
					cin >> n;
					if (cin.fail() || n < 0){
						error_handle();
					}
					else{
						break;
					}
				}

					
				double sum = 0;
				double numbers[n];
				for (int i = 0; i < n; i++) {
					while(true){
						cout << "Enter number " << i + 1 << ": ";
						cin >> numbers[i];
						
						if(cin.fail()){
                            error_handle();
                        } else{
                            break;
                        }
					}
				sum += numbers[i];
				}
						
				cout << "\nSum: " << sum << endl;
				break;
			}
    
            

            case '2': {
                double a, b;
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "Difference: " << (a - b) << endl;
                break;
            }

            case '3': {
                int m;
                while(true){
					cout << "How many numbers do you want to multiply? ";
					cin >> m;
					if(cin.fail()){
						error_handle();
					}
					else{
							break;
						}
				}

                double product = 1;
                double numbers[m];
                for (int i = 0; i < m; i++) {
					while(true){
						cout << "Enter number " << i + 1 << ": ";
						cin >> numbers[i];
						if(cin.fail()){
							error_handle();
						}
						else{
							break;
						}					
					}
                    product *= numbers[i];
                }
                cout << "Product: " << product << endl;
                break;
            }

            case '4': {
                double x, y;
                cout << "Enter the numerator: ";
                cin >> x;
                cout << "Enter the denominator: ";
                cin >> y;
                if (y == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    cout << "\nQuotient: " << (x / y) << endl;
                }
                break;
            }

            case '5': {
                clearScreen();
                break;
            }

            case '6': {
                return 0;
            }

            default: {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    }

    return 0;
}
