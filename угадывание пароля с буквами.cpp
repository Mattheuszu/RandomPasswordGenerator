#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> digitDistribution(0, 9);
    uniform_int_distribution<> letterDistribution(97, 122); 

    const int passwordLength = 8; // Длина пароля
    string password;

    for (int i = 0; i < passwordLength; ++i) {
        int choice = digitDistribution(gen) % 2; 
        if (choice == 0) {
            password += static_cast<char>(digitDistribution(gen) + '0'); 
        } else {
            password += static_cast<char>(letterDistribution(gen)); 
        }
    }

    cout << "Сгенерированный пароль: " << password << endl;

    return 0;
}
