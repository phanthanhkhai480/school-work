--function    functionName arguments
function drawCones numCones = (
		coneRadius = 25*numCones
		for i = 1 to numCones do (
				cone pos:[0,0,(i-1)*100] height:100 radius1: coneRadius
				coneRadius = coneRadius-25
		)
)

function main = (
	delete objects
	drawCones 5
)


try(destroyDialog myUIExample ) catch()
rollout myUIExample "Awesome Box Drawer" (
    group "Controls" (
        spinner numSegmentsSpinner "Number of Segments:" type:#integer
        --colorpicker boxColourPicker "Box Colour:"
        button createBoxButton "Generate"
    )
    on createBoxButton pressed do(
        drawCones numSegmentsSpinner.value --boxColourPicker.color
    )
)
createDialog myUIExample 200 300