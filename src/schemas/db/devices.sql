CREATE TABLE devices (
	ConfiguredName varchar(255) NOT NULL,
	DeviceName varchar(255) NOT NULL,
	MqttTopic varchar(255) NOT NULL,
	MacAddress varchar(255) NOT NULL,
	DeviceType enum('output', 'input', 'both') NOT NULL,
	IsAnalog boolean NOT NULL,
	Room varchar(255) NOT NULL,
	PRIMARY KEY (MqttTopic)
);
