package com.vogella.junit.first;

public class MyClass {
	public int multiply1(int x, int y) {
		if (x > 999) {
			throw new IllegalArgumentException("X should be less than 1000");
		}
		return x/y;
	}
	
	public int multiply2(int i, int j) {
		return i * j;
	}
}
