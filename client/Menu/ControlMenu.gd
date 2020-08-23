extends Control

onready var next_scene

# Called when the node enters the scene tree for the first time.
func _ready():
	$FadeIn.show()
	$FadeIn.fade_out()


func installNetworkCallback():
	global.network=NetworkedMultiplayerENet.new()
	global.network.create_client(global.serverAddress,4242)
	get_tree().set_network_peer(global.network)
	global.mplayer=get_tree().multiplayer
	global.mplayer.connect("network_peer_packet",self,"_on_packet_received")


func _on_packet_received(id, packet):
	var mess=packet.get_string_from_ascii()
	#print (mess)
	global.controlGameNode._networkMessage(mess)


func _on_ConnectButton_pressed():
	next_scene = global.controlConnexionNode
	$FadeIn.show()
	$FadeIn.fade_in()
	var connectMessage="C"+str(global.direction)
	global.mplayer.send_bytes(connectMessage.to_ascii())


func _on_OptionsButton_pressed():
	next_scene = global.controlOptionsNode
	$FadeIn.show()
	$FadeIn.fade_in()


func _on_TestReseauButton_pressed():
	global.mplayer.send_bytes("ABCDEFGH".to_ascii())


func _on_FadeIn_fade_finished():
	$FadeIn.fade_out()
#	$FadeIn.hide()
	global.change_scene(next_scene)


func _on_FadeIn_fade_out_finished():
	$FadeIn.hide()
