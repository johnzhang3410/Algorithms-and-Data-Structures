import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class HashmapExercise {
    // returns the most repeated element in an given array
    // key is the element value, value is the number of times key has appeared
    public int mostFrequent(int[] numbers) {
        // initialize a map with both key/value as integers
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < numbers.length; i++) {
            // put in the key value pair if it's not in hashmap
            if (map.containsKey(numbers[i]) == false) {
                map.put(numbers[i], 1);
            }

            // if key already exists, increment its value by 1
            map.put(numbers[i], map.get(numbers[i]) + 1);
        }

        var max = -1;
        var key = numbers[0];
        // iterate over all key/value pairs to find the one with highest value
        for (int i = 0; i < map.size(); i++) {
            if (map.get(numbers[i]) > max) {
                max = map.get(numbers[i]);
                key = numbers[i];
            }
        }

        return key;
    }

    // return # of unique pairs of integers that have difference k
    public int countPairsWithDiff(int[] numbers, int difference) {
        // One way to do this is to use nested for loops, interating over all numbers in
        // the array while checking its difference (if there is a number +- difference
        // of selected number in the array) in inner loop, but that is O(n^2) operation.

        // Use a set which only stores keys, adds array entries to the set, no
        // duplication now
        // a set is faster because it has constant lookup, no iterate over array anymore
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < numbers.length; i++) {
            set.add(numbers[i]);
        }

        // check the set for each number of the array
        int count = 0;
        for (int i = 0; i < numbers.length; i++) {
            if (set.contains(numbers[i] + difference)) {
                count++;
            }
            if (set.contains(numbers[i] - difference)) {
                count++;
            }
            // remove already checked number to avoid duplication count
            set.remove(numbers[i]);
        }
        return count;
    }

    // returns indices of elements which add up to target, assume only one solution
    public int[] TwoSum(int[] numbers, int target) {
        // One solution is to do a nested for loop, and check each possible combination
        // if they add up to target; but that is O(n^2) operation.

        // key is number, value is their index
        // find keys that add up to target, and return their values
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        int[] result = new int[2];
        for (int i = 0; i < numbers.length; i++) {
            // if difference is in hash table, it means we found 2 numbers that add up to
            // target; we simply return their indices
            int difference = target - numbers[i];

            if (map.containsKey(difference)) {
                result[0] = i;
                result[1] = map.get(difference);
                break;
            }
            // hash table has no matching key that would add up to target, add current
            // element (key) to the hash table so it acts as 'difference' in future
            // iterations. I can also do an iteration to add all array numbers and their
            // index to the hash table first, but that is slower and we need to add the
            // condition && map.get(difference) != i because we may not use the same element
            // twice (must be two different numbers adding up to target).
            // Avoids case like [3, 2, 4] target 6 which would return [0, 0] if we allow
            // same index to be used (3+3=6 but we want 2+4=6 and index of 2 and 4).
            map.put(numbers[i], i);
        }
        return result;
    }

}
