function main = (
	delete objects
	c1 = cone wirecolor:green pos:[-20,0,0] radius1:5
	c2 = cone wirecolor:blue pos:[0,0,0] radius1:5
	c3 = cone wirecolor:red pos:[20,0,0] radius1:5
	
	scale c1[1,2,1]
	scale c2[1,2,1]
	scale c2[1,2,1]
	
	c3.scale = [1,2,1]
	c3.scale = [1,2,1]
)

main()