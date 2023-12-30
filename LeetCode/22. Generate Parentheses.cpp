class Solution {
public:
    vector<string> ans;
    string tmp;

    void call(int st, int ed) {
        if (st == 0 && ed == 0) {
            ans.push_back(tmp);
            return;
        }

        if (st) {
            tmp.push_back('(');
            call(st - 1, ed);
            tmp.pop_back();
        }
        if (st != ed && ed) {
            tmp.push_back(')');
            call(st, ed - 1);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        call(n, n);

        return ans;
    }
};