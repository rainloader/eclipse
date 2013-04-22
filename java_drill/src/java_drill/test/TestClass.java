package java_drill.test;

public class TestClass {
	public void print(int param) {
		for (int i = 0; i < param; i++) {
			System.out.println(i + 1);
		}
	}

	public static void main(String[] args) {
		TestClass testC = new TestClass();
		testC.print(15);
	}
}
