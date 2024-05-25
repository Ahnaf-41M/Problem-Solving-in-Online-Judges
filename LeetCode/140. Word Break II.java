class Solution {
    Set<String> set = new HashSet<>();
    List<String> ans = new ArrayList<>();
    int n;

    private void backtrack(int pos, String s, List<String> wordDict, List<String> curList) {
        if (pos >= n) {
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < curList.size(); i++) {
                res.append(curList.get(i));
                if (i != curList.size() - 1)
                    res.append(" ");
            }
            ans.add(res.toString());
            return;
        }
        StringBuilder tmp = new StringBuilder();
        for (int i = pos; i < n; i++) {
            tmp.append(s.charAt(i));
            if (set.contains(tmp.toString())) {
                curList.add(tmp.toString());
                backtrack(i + 1, s, wordDict, curList);
                curList.remove(curList.size() - 1);
            }
        }
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        n = s.length();
        for (int i = 0; i < wordDict.size(); i++) {
            set.add(wordDict.get(i));
        }

        backtrack(0, s, wordDict, new ArrayList<String>());
        return ans;
    }
}