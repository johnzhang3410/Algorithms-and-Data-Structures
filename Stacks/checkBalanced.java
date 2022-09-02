import java.util.Stack;

public class checkBalanced {
    // push to stack when left bracket, pop when closing bracket
    // check validity in each iteration, if stack empty then balanced

    public boolean isBalanced(String input) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < input.length(); i++) {
            // push to stack if it's a left bracker
            if (input.charAt(i) == '(' || input.charAt(i) == '[' || input.charAt(i) == '{' || input.charAt(i) == '<') {
                stack.push(input.charAt(i));
            }
            // if right bracket, check if there is corresponding left bracket on top of
            // stack, and pop it if true (order/bracket type correct)
            if (input.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    return false;
                }

                var result = stack.peek();
                if (result != '(') {
                    return false;
                }
                stack.pop();

            } else if (input.charAt(i) == '>') {
                if (stack.isEmpty()) {
                    return false;
                }

                var result = stack.peek();
                if (result != '<') {
                    return false;
                }
                stack.pop();

            } else if (input.charAt(i) == '}') {
                if (stack.isEmpty()) {
                    return false;
                }

                var result = stack.peek();
                if (result != '{') {
                    return false;
                }
                stack.pop();

            } else if (input.charAt(i) == ']') {
                if (stack.isEmpty()) {
                    return false;
                }

                var result = stack.peek();
                if (result != '[') {
                    return false;
                }
                stack.pop();

            }
        }

        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }

    }
}
