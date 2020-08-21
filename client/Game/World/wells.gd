extends StaticBody2D


signal area_entered

onready var activable = false

# Called when the node enters the scene tree for the first time.
func _ready():
	pass


func _on_InteractZone_body_entered(body):
	if body != self:
		print("\nyou can interact")
		activable = true
		print(activable)


func _on_InteractZone_body_exited(body):
	if body != self:
		print("end of interaction")
		activable = false
		print(activable)
