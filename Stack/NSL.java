import java.util.*;

public class NearestSmallerToLeft {
    public static List<Integer> smallToLeft(List<Integer> input) {
        int n = input.size();
        List<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peek() >= input.get(i)) stack.pop();
            if (!stack.isEmpty()) result.set(i, stack.peek());
            stack.push(input.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> input = Arrays.asList(1, 3, 0, 2, 5);
        System.out.println(smallToLeft(input)); // Output: [-1, 1, -1, 0, 2]
    }
}
