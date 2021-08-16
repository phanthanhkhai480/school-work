function main = (
	delete objects
	c1 = cone wirecolor:green pos:[-20,0,0] radius1:5
	c2 = cone wirecolor:blue pos:[0,0,0] radius1:5
	c3 = cone wirecolor:red pos:[20,0,0] radius1:5

	move c1[0,20,0]
	move c2[0,20,0]
	move c2[0,20,0]
	c3.position = [0,20,0]
	c3.position = [0,20,0]
)

main()