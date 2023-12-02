#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	string mac_address = system("bash get_mac.sh")
	cout << mac_address << endl;
}
