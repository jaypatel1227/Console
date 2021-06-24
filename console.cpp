
// This is the file that contains the main loop of the console

#include "commands.h"
#include "internal_functions.h"

using namespace std;
// using namespace std::experimental::filesystem;

const string prompt = "prompt:/> ";

int main() {
  int i = read_hist_num();
  string inp = "";
  string x;
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
	append_hist(i, inp);
	increment_num();
	i++;
	evaluate(inp);
  }
}


