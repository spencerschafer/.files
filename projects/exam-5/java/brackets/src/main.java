import java.util.ArrayList;
import java.util.List;

public class main {
	public static int brackets(String str) {
		List<Character> stack = new ArrayList<Character>();
		char[] str_c = str.toCharArray();
		int stackIndex = 0;

		for (int charIndex = 0; charIndex < str.length(); ++charIndex) {
			if (str_c[charIndex] == '(' || str_c[charIndex] == '[' || str_c[charIndex] == '{') {
				stack.add(str_c[charIndex]);
				++stackIndex;
			}
			else if (str_c[charIndex] == ')' || str_c[charIndex] == ']' || str_c[charIndex] == '}') {
				if (str_c[charIndex] == ')' && stack.get(stackIndex - 1) == '(')
					stack.remove(--stackIndex );
				else if (str_c[charIndex] == ']' && stack.get(stackIndex - 1) == '[')
					stack.remove(--stackIndex);
				else if (str_c[charIndex] == '}' && stack.get(stackIndex - 1) == '{')
					stack.remove(--stackIndex);
				else
					return (-1);
			}
		}
		return ((stack.size() != 0) ? -1 : 0);
	}

	public static void main(String[] args) {
		if (args.length >= 1) {
			for (int i = 0; i < args.length; ++i)
				System.out.println((brackets(args[i]) == -1 ? "Error": "OK"));
		}
		else
			System.out.println();
		System.exit(0);
	}
}
