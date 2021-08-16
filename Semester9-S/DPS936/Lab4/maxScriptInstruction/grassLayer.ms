--generate random "blades of grass" within an area defined by 
--length and width argument centred at the origin

function drawGrass len wid numBlades = (
	for i = 1 to numBlades do(
		x = random -(len/2) (len/2)
		y = random -(wid/2) (wid/2)
		h = random 5 10
		c = cone pos:[x,y,0] radius1:1 wireColour:green height:h
		--c = box pos:[x,y,0] height:10 width:1 length:2
		addmodifier c(bend())
		--c.bend.BendAxis = 2;
		c.bend.bendangle = random -30 30
		c.bend.benddir = random 35 45
	)
)

function main = (
	--delete objects
	drawGrass 50 500 2000
)

main()