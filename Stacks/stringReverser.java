import java.util.Stack;

//An application of stack
public class stringReverser {
    // reverses the input string
    public String reverse(String input) {
        if (input == null) {
            throw new IllegalArgumentException();
        }

        // create a stack and push each char input in, then pop them off to new string
        Stack<Character> stack = new Stack<>();

        // push each character in the string onto the stack
        for (int i = 0; i < input.length(); i++) {
            stack.push(input.charAt(i));
        }

        // more efficient for string manipulation
        StringBuffer reversed = new StringBuffer();
        while (!stack.empty()) {
            reversed.append(stack.pop());
        }

        return reversed.toString();
    }
}
