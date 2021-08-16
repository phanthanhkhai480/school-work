/* place your code into a file called a2.ms, a2.ms should not have an a2tester function nor any sort of main type function that gets called*/

filein("a2.ms")
fn a2tester = (
	/*generates a figure 8 shape*/
	 thePath = #("left","left","left","left","left", "left", "straight", "straight", "right", "right", "right", "right", "right", "right", "straight", "straight")

 	generatePath thePath
)
a2tester()