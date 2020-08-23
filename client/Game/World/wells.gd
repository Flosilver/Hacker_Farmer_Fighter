extends StaticBody2D


signal area_entered
signal area_left
signal open_terminal

export(bool) var activable = false
onready var key_E_pressed = false

# Called when the node enters the scene tree for the first time.
func _ready():
	pass

func _process(_delta):
	# appuyer sur la touche E + ne pas etre enfoncé sur la touche E + le puits doit etre activable
	if Input.is_key_pressed(KEY_E) and !key_E_pressed and activable:
		# on enfonce la touche E
		key_E_pressed = true
		
		# on demande d'ouvrir le terminal
		print("ouvrir le terminal")
		emit_signal("open_terminal")
	
	elif !Input.is_key_pressed(KEY_E):
		key_E_pressed = false

func _on_InteractZone_body_entered(body):
	print(body)
	if body != self:
		activable = true
		print(activable)
		emit_signal("area_entered")


func _on_InteractZone_body_exited(body):
	if body != self:
		activable = false
		print(activable)
		emit_signal("area_left")
