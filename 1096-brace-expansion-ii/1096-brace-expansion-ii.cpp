class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpr(expression, i);
        return vector<string>(result.begin(), result.end());
    }

private:
    // Parses a concatenation of terms: e.g. "a{b,c}d"
    // Stops when it hits ',' or '}' or end of string
    set<string> parseExpr(const string& s, int& i) {
        vector<set<string>> terms;

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            terms.push_back(parseTerm(s, i));
        }

        set<string> result = {""};
        for (auto& termSet : terms) {
            set<string> combined;
            for (const string& prefix : result) {
                for (const string& word : termSet) {
                    combined.insert(prefix + word);
                }
            }
            result = combined;
        }
        return result;
    }

    // Parses a single term: either a letter, or a {...} union group
    set<string> parseTerm(const string& s, int& i) {
        if (s[i] == '{') {
            i++; // consume '{'
            set<string> unionSet;

            while (true) {
                set<string> part = parseExpr(s, i);
                unionSet.insert(part.begin(), part.end());

                if (s[i] == ',') {
                    i++; // consume ',' and parse next part
                } else {
                    break; // must be '}'
                }
            }

            i++; // consume '}'
            return unionSet;
        } else {
            string letter(1, s[i]);
            i++;
            return {letter};
        }
    }
};