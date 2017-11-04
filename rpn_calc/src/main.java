import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class rpn_calc {
	private int strlen;
	private int stack_len;
	private int ret;
	private List<ArrayList> stack = new ArrayList<>();
	public static void main(String[] args) {

		if (args.length == 2) {
		char **stack;

			str_len = ft_strlen(argv[1]);
			stack = (char **)malloc(sizeof(char *) *(str_len + 1));
			ret = create_stack(stack, argv[1]);
			stack_len = ft_stacklen(stack);
			if (!ret || !count_op(stack, stack_len))
				printf("Error\n");
			else {
				ret = op(stack, stack_len);
				if (!ret)
					printf("Error\n");
				else
					printf("%i\n", ret);
			}
			free(stack);
		} else
			printf("Error\n");
		return (0);
	}
}