import java.util.*;

public class NearestSmallerToRight {
    public static List<Integer> smallToRight(List<Integer> input) {
        int n = input.size();
        List<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() >= input.get(i)) stack.pop();
            if (!stack.isEmpty()) result.set(i, stack.peek());
            stack.push(input.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> input = Arrays.asList(4, 5, 2, 10, 8);
        System.out.println(smallToRight(input)); // Output: [2, 2, -1, 8, -1]
    }
}
