class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> ans = new ArrayList<>(2);
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        Map<Integer, Integer> mp1 = new HashMap<>();
        Map<Integer, Integer> mp2 = new HashMap<>();

        for (int x : nums1) {
            mp1.put(x, 1);
        }
        for (int x : nums2) {
            mp2.put(x, 1);
        }
        for (int x : mp1.keySet()) {
            if (!mp2.containsKey(x))
                list1.add(x);
        }
        for (int x : mp2.keySet()) {
            if (!mp1.containsKey(x))
                list2.add(x);
        }
        ans.add(list1);
        ans.add(list2);
        return ans;
    }
}