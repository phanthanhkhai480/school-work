struct Turtle( --struct Turtle
	--data members
	position_ = [0,0,0], -- intitially at orgin
	heading_ = [0,0,1], -- initially pointing up
	rotationQuat_ = quat 0 0 0 1, --identity quaternian
	
	--member functions
	fn forward amount=(
		c = cone pos:position_ radius1:10 height:amount
		rotate c rotationQuat_
		position_ = position_ + amount*heading_
	),
	
	fn left turnAngle=(
		q = quat turnAngle [0,-1,0] --creates a quaternian representing a turn of turnAngle around the yAxis
		rotationQuat_ = q * rotationQuat_ --update the rotationQuat_ represents the rotation need to apply to all object
		invq = inverse q	--calculate the inverse quarternian to update the turtle
		heading_ = heading_ * invq
	),
	
	fn right turnAngle=(
		q = quat turnAngle [0,1,0] --creates a quaternian representing a turn of turnAngle around the yAxis
		rotationQuat_ = q * rotationQuat_ --update the rotationQuat_ represents the rotation need to apply to all object
		invq = inverse q	--calculate the inverse quarternian to update the turtle
		heading_ = heading_ * invq
	)
)
	
fn main = (
	delete objects;
	t = Turtle()
	t.forward 50
	t.left 45
	t.forward 100
	t.left 45
	t.forward 150
	t.right 45
	t.forward 200
)

main()