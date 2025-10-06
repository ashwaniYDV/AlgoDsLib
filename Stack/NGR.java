import java.util.*;

public class NearestGreaterToRight {
    public static List<Integer> bigToRight(List<Integer> input) {
        int n = input.size();
        List<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= input.get(i)) stack.pop();
            if (!stack.isEmpty()) result.set(i, stack.peek());
            stack.push(input.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> input = Arrays.asList(1, 3, 0, 0, 2, 4);
        System.out.println(bigToRight(input)); // Output: [3, 4, 2, 2, 4, -1]
    }
}
