all: update_upgrade install_mosquitto

update_upgrade:
	sudo apt update && sudo apt upgrade

install_mosquitto:
	sudo apt install -y mosquitto mosquitto-clients
	sudo systemctl enable mosquitto.service
	sudo cp conf/mosquitto.conf /etc/mosquitto/mosquitto.conf

install_paho_mqtt:
	sudo apt install build-essential gcc make cmake cmake-gui cmake-curses-gui
	sudo apt-get install libssl-dev
	sudo apt-get install doxygen graphviz
