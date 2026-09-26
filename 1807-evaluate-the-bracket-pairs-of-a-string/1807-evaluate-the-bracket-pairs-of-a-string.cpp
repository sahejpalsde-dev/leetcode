class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Populate hash map for O(1) average lookup time
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        string tempKey = "";
        bool insideBracket = false;

        // Step 2: Traverse string s and build result
        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
                tempKey = "";
            } else if (c == ')') {
                insideBracket = false;
                // Lookup key in dict
                if (dict.count(tempKey)) {
                    result += dict[tempKey];
                } else {
                    result += '?';
                }
            } else {
                if (insideBracket) {
                    tempKey += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};