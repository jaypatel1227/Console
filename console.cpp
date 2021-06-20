
// This is the file that contains the main loop of the console

#include "internal_functions.h"

using namespace std;
// using namespace std::experimental::filesystem;

int main() {
  string prompt = "prompt:/> ";
  string inp = "";
  while (inp != "exit"){
	cout << prompt;
	getline(cin, inp);
	if (ends_with(inp, "\\")){
	  string temp = "";
	  while(ends_with(inp, "\\") == 1){
		cout << "> ";
		cin >> temp;
		inp = inp + "\n" + temp;
	  }
	}
	evaluate(inp);
  }
}


