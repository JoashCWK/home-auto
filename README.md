# Home-Auto Subscription and Scheduling Manager
*This project is still Work In Progress*

This is a subscription and scheduling management service for Home-Auto.

## Home-Auto Architecture
Home-Auto is an MQTT-based, horizontally scalable system that aims to provide fully configurable home automation.

At the core of it, a Raspberry Pi 3B+ is used as the central hub of the system,
hosting the MQTT broker, database, and this subscription-and-shceduling service.
The Pi also acts as a Wireless Access Point and Router for the network to ensure that the system is entirely self contained and independent.

The high level system design is as such:
![System Design](https://github.com/JoashCWK/home-auto/blob/main/home-auto_system-design.png)

### MQTT Broker
The MQTT Broker acts as the middleware for intra-network communication between the devices, UI and subscription/scheduling service (further explained below).

At the moment, the idea is for each device to have its own topic prefix that is used to receive tasks and publish its status.
For example, a device with a prefix of "living-room-lights" would subscribe to `living-room-lights/task` to receive commands, 
and publish its status to `living-room-lights/status`. 
The UI would be publishing to `living-room-lights/task` and subscribing to `living-room-lights/status` to provide user feedback after a task successfully completes.

### Subscription and Scheduling Service (SSS)
#### Subscription
New devices can be added to the system by publishing a message to the `setDevice` topic which this service subscribes to. 
The message must contain the user-defined device prefix, the device type (input/output) and whether the device is digital/analog. 
For input devices, the user can also define a "link" to any device in the network so that a message is published when a condition is met.

When the SSS receives a new message on this topic, it hosts a simple http server and waits for the new device to connect to it as a client.
This is to the new device with the prefix of the MQTT topics to subscribe and publish to.
Optionally for input devices, the server also provides the topic(s), message(s) and condition(s) to publish to if a "link" is setup.

#### Scheduling
This service also handles scheduling edits. When a new message is published to `setSchedule` to add/change/remove a schedule, 
the SSS will parse the message, store the relevant information in the database, and also create a cronjob for it. 
It then response with a return code to `setScheduleStatus`

### Database
The database consists of two tables, `devices` and `schedules`.
