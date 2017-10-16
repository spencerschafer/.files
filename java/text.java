// ******************* start of file Intro.java ******************
// the overall class name must match the file prefix; i.e. the name of
// this file must be Intro.java
// usage:  java Intro nums
// introductory program; reads integers from the command line,
// storing them in a linear linked list, maintaining ascending order,
// and then prints out the final list to the screen

public class Intro
{  	//standalone Java programs must have a main() function, which is the
	//point where execution begins

	public static void main(String[] Args) {

		// note that locals have no public/private/... prefix; also, we
		// are using the fact that array objects, in this case Args, have
		// "length" variables built in
		int NumElements = Args.length;

		for (int I = 1; I <= NumElements; I++)  {
			int Num;
			// need to do C’s "atoi()"; use parseInt(), a class method of
			// the Integer class; inverse operation is toString()
			Num = Integer.parseInt(Args[I-1]);
			// create a new node
			NumNode NN = new NumNode(Num);
			NN.Insert();
		}

		System.out.println("final sorted list:");
		NumNode.PrintList();
	} 
}

// ****************** start of file NumNode.java ******************

// we have the class NumNode in the file NumNode.java

public class NumNode
{  // by making Nodes variable static, it will be common to all
	// instances of the class
	private static NumNode Nodes = null;

	// the rest of these variables are "local" to each instance of the
	// class

	// valued stored in this node
	int Value;

	// "pointer" to next item in list
	NumNode Next;

	// constructor
	public NumNode(int V)  {
		Value = V;
		Next = null; 
	}

	// make the following methods visible externally, e.g. to main(), via
	// public; the ones which are class methods rather than instance
	// methods also are static

	public static NumNode Head()  {
		return Nodes;
	}

	public void Insert()  {
		if (Nodes == null)  {
			Nodes = this;
			return; 
		}
		if (Value < Nodes.Value)  {
			Next = Nodes;
			Nodes = this;
			return;
		}
		else if (Nodes.Next == null)  {
			Nodes.Next = this;
			return; 
		}
		for (NumNode N = Nodes; N.Next != null; N = N.Next)  {
			if (Value < N.Next.Value)  {
				Next = N.Next;
				N.Next = this;
				return;
			}
			else if (N.Next.Next == null)  {
				N.Next.Next = this;
				return; 
			}
		}
	}

	public static void PrintList()  {
		if (Nodes == null) return;
		for (NumNode N = Nodes; N != null; N = N.Next)
			System.out.println(N.Value);
	}
}
