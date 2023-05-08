extends YSort

onready var key_E_pressed = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	var wells
	for i in self.get_child_count():
		if i != 0:
			wells = self.get_child(i)
			print(wells)
			wells.connect("area_entered", self, "_on_Wells_area_entered")
			wells.connect("area_left", self, "_on_Wells_area_left")


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass


func _on_Wells_area_entered():
	$Control/Label.set_text("press [E]")


func _on_Wells_area_left():
	$Control/Label.set_text("")
