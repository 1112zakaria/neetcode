#include <string>
#include <vector>
#include <iostream>

using namespace std;
//
#define DELIMITER string("::")

class Solution {
public:
    /**
     * Approach: 
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string out = string("");
        for (int i=0; i<strs.size()-1; i++) {
            out += strs[i] + DELIMITER;
        }
        out += strs[strs.size()-1];
        return out;
    }

    /**
     * Approach:
     * - iterate all letters i in a string & keep track of a start and end ptr, i=1
     *      - start and end = 0
     * - if the substr at letter i is the delimiter, add the substr between start and end
     * to the output list
     *      - set current ptr forward up len(delimiter) + 1 steps (from i)
     *      - set start ptr forward up len(delimiter) steps (from i)
     *      - set end ptr forward up len(delimiter) steps (from i)
     * - else, increment the end ptr forward 1 step
     * - note: the delimiter cannot be at the first letter and cannot include the last letter
     *      - cant be i=0, can't be i=len(str)-1
     *      - therefore, iterate while i<str.size() && (i+len(DELIMITER)-1 < str.size()-1)
     * 
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> out = vector<string>();
        string delim;
        int start, end;

        start = 0;
        end = 0;
        int i = 1;

        while (i < str.size()-1 && (i+DELIMITER.length()-1 < str.size()-1) ) {
            delim = str.substr(i, DELIMITER.size());
            if (DELIMITER.compare(delim)) {
                // store the substr
                out.push_back(str.substr(start, end-start+1));

                start = i + DELIMITER.size();
                end = i + DELIMITER.size();
                i += DELIMITER.size()+1;
            } else {
                end++;
                i++;
            }
        }
        out.push_back(str.substr(start, end));
        return out;

    }
};

int main() {
	vector<string> in = {"lint","code","love","you"};
    string encodeOut;
    vector<string> decodeOut;
    Solution s;
    
    encodeOut = s.encode(in);
    decodeOut = s.decode(encodeOut);
    cout << encodeOut << "\n";
    //cout << decodeOut << "\n";
    for (string i : decodeOut)
    	cout << i << " ";
  	cout << "\n";
	return 0;
}