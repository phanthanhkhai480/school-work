fn generatePath pathArray = (
	delete objects
	
	--data members
	position_ = [0,0,0]				-- intitially at orgin
	heading_ = [0.37,0.9,0] 		-- initially pointing up
	rotationQuat_ = quat 0 0 0 1 	--identity quaternian
	turnAngle = 45 						--set default turning angle at 45 degree
	arrCounter = 1						--set array counter

	mLength = 70						--set default value for length
	mWidth = 30							--set default value for width
	mHeight = 10						--set default value for height
	mColor = color (random 0 255) (random 0 255) (random 0 255)
	
	while (arrCounter != pathArray.count+1) do (
		if (pathArray[arrCounter] == "left") 		
			do(	q = quat turnAngle[0,0,1]; 
					rotationQuat_ = q * rotationQuat_ ; 
					invq = inverse q; 
					heading_ = heading_ * invq	;
					
					a = box pos:position_ length:mLength width:mWidth height:mHeight   lengthsegs:10 widthsegs:1 wireColor:mColor;
					rotate a rotationQuat_;
					rotate a (turnAngle)[0,0,-1];
				
					addmodifier a(bend());
					a.bend.BendAxis = 1;
					a.bend.BendAngle = -turnAngle;
												
					x = [1,0,0]
					y = [0,1,0]
					move a(x*-15)
					move a(y*12)	
						
					position_ = position_ + (mLength-7)*heading_;		)
		
		if (pathArray[arrCounter] == "right") 	
			do(	q = quat turnAngle[0,0,-1]; 
					rotationQuat_ = q * rotationQuat_ ; 
					invq = inverse q; 
					heading_ = heading_ * invq;
					
					b = box pos:position_ length:mLength width:mWidth height:mHeight lengthsegs:10 widthsegs:1 wireColor:mColor;
					rotate b rotationQuat_;
					addmodifier b(bend());
					b.bend.BendAxis = 1;
					b.bend.BendAngle = turnAngle;
												
					--b_fence1 = box pos:position_ length:mLength width:(2) height:mHeight lengthsegs:10 widthsegs:1 wireColor:mColor;
					--rotate b_fence1 rotationQuat_;
					--addmodifier b_fence1(bend());
					--b_fence1.bend.BendAxis = 1;
					--b_fence1.bend.BendAngle = turnAngle;
					--b_fence1.pivot=[0,(mWidth/2),0];
					--b_fence1.height = mHeight*2;
						
					x = [1,0,0]
					y = [0,1,0]
					move b(x*4)
					move b(y*-9)	
					
					position_ = position_ + (mLength-7)*heading_;		)

		if (pathArray[arrCounter] == "straight") 
			do(	straightLength = mLength+40
					c = box pos:(position_) length:straightLength width:mWidth height:mHeight lengthsegs:1 widthsegs:1 wireColor:mColor; 
					rotate c rotationQuat_ ;
					rotate c (turnAngle*2/3)[0,0,-1];
					
					--c_fence1 = box pos:(position_ + (mHeight)) length:mLength width:1 height:(mWidth/2) lengthsegs:1 widthsegs:1 wireColor:mColor;
					--c_fence2 = box pos:(position_ - (mWidth/2)) length:mLength width:1 height:(mWidth/2) lengthsegs:1 widthsegs:1 wireColor:mColor;
					--rotate c_fence1 (turnAngle*3/2)[0,0,1];
					--rotate c_fence2 (turnAngle*3/2)[0,0,1];
					--x = [1,0,0]
					--y = [0,1,0]
					rotate c 8[0,0,1]
					--move c(x*-10)
					--move c(y*6)
				
					position_ = position_ + (mLength)*heading_; 	)
		
		arrCounter = arrCounter+1
	)
)

fn a2tester = (
	/*generates a figure 8 shape*/
	--thePath = #("left","left","left","left","left", "left", "straight", "straight", "right", "right", "right", "right", "right", "right", "straight", "straight")
	--thePath = #("right","right","straight","straight","right", "right","right","right","straight","straight","right", "right")
	thePath = #("left","left","left","left","left", "left", "left", "left")
 	generatePath thePath
)
a2tester()
