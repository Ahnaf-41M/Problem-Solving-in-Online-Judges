class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        /*First hire k lowest wage/quality workers. Then see if remaining
        higher wage/quality workers can replace existing highest wage/quality
        worker while lowering cost */
        List<List<Double>> ratio = new ArrayList<>();
        PriorityQueue<Double> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int n = wage.length;

        for (int i = 0; i < n; i++) {
            Double val = wage[i] * 1.0 / quality[i];
            ratio.add(new ArrayList<>(List.of(val, i * 1.0)));
        }
        Comparator<List<Double>> comparator = Comparator.comparingDouble(list -> list.get(0));
        Collections.sort(ratio, comparator);

        Double qualitySum = 0.0, ans = 0.0;
        for (int i = 0; i < k; i++) {
            int index = ratio.get(i).get(1).intValue();
            qualitySum += 1.0 * quality[index];
            maxHeap.offer(1.0 * quality[index]);
        }
        ans = qualitySum * ratio.get(k - 1).get(0);
        for (int i = k; i < n; i++) {
            int index = ratio.get(i).get(1).intValue();
            qualitySum -= maxHeap.poll();
            qualitySum += quality[index];
            maxHeap.offer(1.0 * quality[index]);
            ans = Math.min(ans, qualitySum * ratio.get(i).get(0));
        }
        return ans.doubleValue();
    }
}