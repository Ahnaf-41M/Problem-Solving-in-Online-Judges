class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        Map<Integer, Integer> mp2 = new HashMap<>();

        for (int x : arr) {
            if (mp.get(x) == null)
                mp.put(x, 1);
            else
                mp.put(x, mp.get(x) + 1);
        }
        for (int x : mp.values()) {
            if (mp2.get(x) != null)
                return false;
            mp2.put(x, 1);
        }
        return true;
    }
}