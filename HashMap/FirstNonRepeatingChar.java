import java.util.HashMap;
import java.util.Map;

//returns the first non-repeating char
//Iterate over the entire string; if the char is not in hash table then add it, 
//else increment the value associated with the char in hash table (count). char is key.
public class FirstNonRepeatingChar {
    public char FindFirstNonRepeatingChar(String input) {
        // key is each char, value is the # of times that char appears
        Map<Character, Integer> map = new HashMap<>();

        // finds out # of times each char appears and store in hash table ${map}
        for (int i = 0; i < input.length(); i++) {
            char character = input.charAt(i);

            if (map.containsKey(character)) {
                // gets the value of key, which is the # of times character appears
                var count = map.get(character);
                count++;
                map.put(character, count);
            } else {
                // else insert the char into hash table
                map.put(character, 1);
            }
        }

        // iterate over string to find first char that appear once
        for (int i = 0; i < input.length(); i++) {
            char character = input.charAt(i);

            // return first non-repeating char
            if (map.get(character) == 1) {
                return character;
            }
        }

        // case when every char is repeated at least twice
        return Character.MIN_VALUE;
    }
}
