/**
 * @author Khai Phan - 100901164
 */
package com.vogella.junit.first;

//import static org.junit.Assert.*;

import org.junit.Test;

import junit.framework.Assert;

@SuppressWarnings("deprecation")
public class MyClassTest2 {

	//test to check for thrown exception method
		@Test (expected = IllegalArgumentException.class)
		public void testExceptionIsThrown() {
			MyClass tester = new MyClass();
			tester.multiply1(1000,5);
		}
		
		@Test
		public void testMultiply1() {
			MyClass tester1 = new MyClass();
			Assert.assertEquals("34 x 17 must be 578", 578, 
					tester1.multiply1(34, 17));
		}
		
		@Test
		public void testMultiply2() {
			MyClass tester2 = new MyClass();
			Assert.assertEquals("34 / 17 must be 2", 2, 
					tester2.multiply1(34, 17));
		}
}
