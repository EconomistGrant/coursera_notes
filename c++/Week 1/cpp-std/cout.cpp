/**
 * C++ program for a simple "Hello, world!"
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

/*
#include <iostream>
int main() {
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
*/

#include <iostream>
using namespace std;

int raiseToPower (int n ,int k);

int main(){
  int limit;
  cout <<"enter";
  cin >> limit;
  for (int i =0; i<= limit; i++){
    cout <<  "2 to the "<< i << " = "
         << raiseToPower(2,i) << endl;
  } 
  return 0;
}

int raiseToPowe (int n, int k){
  int result = 1;
  for (int i = 0; i < k; i++){
    result *= n;
  }
  return result;
}