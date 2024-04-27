CREATE TABLE clusters(
	ClusterID int NOT NULL AUTO_INCREMENT,
	ClusterName varchar(255) NOT NULL,
	NumDevices int DEFAULT 0,
	PRIMARY KEY (ClusterID)
);
