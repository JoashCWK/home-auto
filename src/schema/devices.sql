CREATE TABLE devices (
	MqttTopic varchar(255) NOT NULL,
	MacAddress varchar(255) NOT NULL,
	Type enum('output', 'input') NOT NULL,
	IsAnalog boolean NOT NULL,
	ClusterID int NOT NULL,
	PRIMARY KEY (MqttTopic)
);
