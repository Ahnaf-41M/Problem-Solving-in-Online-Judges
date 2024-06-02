class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, ArrayList<String>> mp = new HashMap<>();

        for (int i = 0; i < strs.length; i++) {
            char[] s = strs[i].toCharArray();
            Arrays.sort(s);
            String key = new String(s);
            if (!mp.containsKey(key)) {
                mp.put(key, new ArrayList<>());
            }
            mp.get(key).add(strs[i]);
        }

        for (ArrayList<String> ar : mp.values()) {
            ans.add(ar);
        }
        return ans;
    }
}