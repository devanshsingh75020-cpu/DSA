class WordDictionary {
public:
    vector<string> words;

    WordDictionary() {
    }

    void addWord(string word) {
        words.push_back(word);
    }

    bool search(string word) {
        for (string &s : words) {

            if (s.size() != word.size())
                continue;

            bool match = true;

            for (int i = 0; i < word.size(); i++) {
                if (word[i] != '.' && word[i] != s[i]) {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }
        return false;
    }
};