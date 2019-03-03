#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1]++;
		for (int i = digits.size() - 1; i > 0; i--)
		{
			if (digits[i] == 10)
			{
				digits[i] = 0;
				digits[i - 1]++;
			}
			else
				break;		//�𰸣� return digits;
		}
		vector<int> result;
		if (digits[0] == 10)
		{
			result.push_back(1);
			digits[0] = 0;
		}
		for (int num : digits)
		{
			result.push_back(num);
		}
		return result;














		/*		0ms����
		int carry = 1;
        for(int i = digits.size()-1;i >= 0;i--){
            int tmp = (digits[i] + carry);
            digits[i] = tmp%10;
            carry = tmp/10;
        }
        
        if(carry == 1){
            digits.insert(digits.begin(),1);
        }
        
        return digits;
		*/
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> digits = stringToIntegerVector(line);

		vector<int> ret = Solution().plusOne(digits);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}