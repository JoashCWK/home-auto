client_ip=$(python3 server.py -n $1)
sudo arp | grep $client_ip | grep -oE '([0-9a-f]{2}:){5}[0-9a-f]{2}'
