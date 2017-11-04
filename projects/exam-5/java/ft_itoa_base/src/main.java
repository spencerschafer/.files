import java.lang.String;
import java.util.ArrayList;
import java.util.List;

public class main {
	public static String ft_itoa_base(int value, int base) {
		List<Character> str = new ArrayList<Character>();
		char[] map = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

		if (!(base >= 2 && base <= 16)) {
			System.out.println("Error.");
			System.exit(1);
		}
		if (value == 0)
			str.add('0');
		else if (value < 0)
			value *= -1;
		while (value != 0) {
			str.add(map[(int) (value % base)]);
			value /= base;
		}
		if (value < 0 && base == 10)
			str.add('-');
		StringBuilder builder = new StringBuilder(str.size());
		for (Character ch : str)
			builder.append(ch);
		return (new StringBuilder(builder).reverse().toString());
	}

	public static void main(String[] args) {
		System.out.println(ft_itoa_base(Integer.parseInt(args[0]), Integer.parseInt(args[1])));
	}
}