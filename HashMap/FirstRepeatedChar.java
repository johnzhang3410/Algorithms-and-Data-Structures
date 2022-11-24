import java.util.HashSet;
import java.util.Set;

public class FirstRepeatedChar {
    public char FindFirstRepeatedChar(String input) {
        // A set stores keys and allows no duplication
        Set<Character> set = new HashSet<>();

        // if character is already in set, it means the character is repeated, return it
        // else add the character to the set
        for (int i = 0; i < input.length(); i++) {
            char character = input.charAt(i);

            if (set.contains(character)) {
                return character;
            } else {
                set.add(character);
            }
        }

        return Character.MIN_VALUE;
    }
}
