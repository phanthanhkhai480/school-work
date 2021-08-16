function drawFence xAxis yAxis direction numSegment fenceColor = (
	m_color = fenceColor
	m_xAxis = xAxis	
	m_yAxis = yAxis	
	m_zAxis = 0
	m_direction = direction
	m_length = 60		
	m_width = 5			
	m_height = 5
	m_planks = 10
	m_fenceLength = 10*(m_planks+1)
	delete objects
	
	for a = 1 to numSegment do (
		b1 = box pos:[m_xAxis, m_yAxis, m_length/2] length:m_length width:m_width height:m_height wireColor:m_color
		rotate b1 90[1,0,0]
		rotate b1 m_direction[0,0,1]
		
		b2 = box pos:[m_fenceLength/2 + m_xAxis, m_yAxis, 10] length:(m_width-1) width:m_fenceLength height:(m_height-1) wireColor:m_color
		rotate b2 90[1,0,0]
		rotate b2 m_direction[0,0,1]
		
		b3 = box pos:[m_fenceLength/2 + m_xAxis, m_yAxis, 35] length:(m_width-1)  width:m_fenceLength height:(m_height-1) wireColor:m_color
		rotate b3 90[1,0,0]
		rotate b3 m_direction[0,0,1]
			
		for i = 1 to m_planks do (
			m_xAxis = m_xAxis + 10
			segment = box pos:[m_xAxis, m_yAxis-(m_width-1), m_length/2] length:m_length width:m_width height:(m_height-4) wireColor:m_color
			rotate segment 90[1,0,0]
			rotate segment m_direction[0,0,1]
			
			if i < m_planks/2 do (m_length = m_length - 3; m_zAxis = m_zAxis-1.5)
			if i > m_planks/2 do (m_length = m_length + 3; m_zAxis = m_zAxis+1.5)
			
		)
		
		m_xAxis = m_xAxis + 10
		b4 = box pos:[m_xAxis, m_yAxis, m_length/2] length:m_length width:m_width height:m_height wireColor:m_color
		rotate b4 90[1,0,0]
		rotate b4 m_direction[0,0,1]
	)
	
)

try(destroyDialog myFence ) catch()
rollout myFence "Fence Creation Tool Drawer" (
    group "Location Coordinator" (
		spinner xAxis fieldWidth:50 height: 25 align:#left offset:[2.5,15] type:#integer text:0
		spinner yAxis fieldWidth:50 height: 25 align:#center offset:[5,-30] type:#integer text:0
		groupBox group1 "X-Axis" pos:[10,20] width:100 height:40
		groupBox group2 "Y-Axis" pos:[120,20] width:100 height:40
    )
	
	group "Direction (zAxis)" (
		Angle ang1 diameter:50 align:#left range:[-180,180,45] startdegrees:0  color:red across:3 --dir:#cw
		spinner direction fieldWidth:50 height: 25 align:#left offset:[0,20] type:#integer range: [0,360,0] text:0
		on ang1 changed val do direction.value = val
			on direction changed val do ang1.degrees = val
    )
	
	spinner numSegment "Number of Segments:" fieldWidth:50 height: 25 pos: [10,160] type:#integer range:[1,100,10]
	colorpicker fenceColor "Colour:" color:[177,156,217] pos:[200, 160]
	button createFence "Generate"
	
    on createFence pressed do(
        drawFence xAxis.value yAxis.value direction.value numSegment.value fenceColor.color    
	)
)
createDialog myFence 300 300