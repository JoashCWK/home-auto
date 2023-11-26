all: update_upgrade install_mosquitto

update_upgrade:
	sudo apt update && sudo apt upgrade

# https://randomnerdtutorials.com/how-to-install-mosquitto-broker-on-raspberry-pi/
install_mosquitto:
	sudo apt install -y mosquitto mosquitto-clients
	sudo systemctl enable mosquitto.service
	sudo cp conf/mosquitto.conf /etc/mosquitto/mosquitto.conf

# https://github.com/eclipse/paho.mqtt.cpp
install_paho_mqtt:
	sudo apt install build-essential gcc make cmake cmake-gui cmake-curses-gui
	sudo apt-get install libssl-dev
	sudo apt-get install doxygen graphviz

# https://learn.sparkfun.com/tutorials/setting-up-a-raspberry-pi-3-as-an-access-point/all
setup_wap:
	sudo apt -y install hostapd dnsmasq

mariadb:
	sudo apt install mariadb-server
	sudo mysql_secure_installation
